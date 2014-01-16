#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "randMT.h"
#include "export.h"
#include "global.h"
#include "t_player.h"

static void AddScore( u32 n ) {
  g_Score += n;
}

/******************************************************************/
/*                                player                          */
/******************************************************************/
struct RECT BBox[] = {
  { -50 , -88 , 50 , 116 },// PLAYER_MODE_WAIT		  (0)
  { -50 , -88 , 50 , 116 },// PLAYER_MODE_WALKSTART	(1)
  { -50 , -88 , 50 , 116 },// PLAYER_MODE_WALK			(2)
  { -50 , -88 , 50 , 116 },// PLAYER_MODE_WALKEND		(3)
  { -50 , -88 , 50 , 116 },// PLAYER_MODE_JUMPSTART	(4)
  { -50 , -128 , 50 , 50 },// PLAYER_MODE_JUMP		  (5)
  { -50 , -88 , 50 , 116 },// PLAYER_MODE_JUMPEND		(6)
  { -50 , -128 , 50 , 50 },// PLAYER_MODE_FALL		  (7)
  { -50 , -88 , 50 , 116 },// PLAYER_MODE_ATTACK		(8)
  { -50 , -88 , 50 , 116 },// PLAYER_MODE_RUNSTART	(1+8)
  { -50 , -88 , 50 , 116 },// PLAYER_MODE_RUN			  (2+8)
  { -50 , -88 , 50 , 116 },// PLAYER_MODE_RUNEND		(3+8)
  { -50 , -88 , 50 , 116 },// PLAYER_MODE_GAMEOVER  (12)
};

static int MovePlayer( struct TaskData* pTask , int dx , int dy , int move_flag ) {
  struct TaskData* pWTask;
  int w = ageRM[ AG_CG_WORKSTAND ].Width;
  int h = ageRM[ AG_CG_WORKSTAND ].Height;
  int isHit = 0;
  int x,y;
  struct RECT csize;
  struct RECT crect;

  pWTask = GetDispLink( DISP_LEVEL_OBJECT );

  x = g_PlayerX + dx;
  y = g_PlayerY + dy;

  if( x < (g_OffsetX+32) ) {
    x = (g_OffsetX+32);
  };

  crect = csize = BBox[ pTask->Data.player.mode ];
  AddRect( &crect , x , y );

  while( pWTask != NULL ) {
#if 0
    struct RECT wrect;

    wrect.x0 = pWTask->x - w/2;
    wrect.y0 = pWTask->y + h/2;
    wrect.x1 = pWTask->x + w/2;
    wrect.y1 = pWTask->y + h;

    if( IsHitRect( &crect , &wrect ) ) {
      isHit = 1;
      break;
    };
#endif

    if( pWTask->Hit != NULL ) {
      if( pWTask->Hit( pWTask , &crect ) ) {

        if (pWTask->Data.object.is_harmful) {
          g_Life = 0;
        }

        // 横から衝突したら落とす
        if (y > pWTask->y ) {
          int tw = ageRM[ pWTask->Data.object.image ].Width;
          if ( (x + w/2) < (pWTask->x + tw/2) ) {
            // left
            x = pWTask->x - tw/2 + csize.x0 - 1;
          } else {
            // right
            x = pWTask->x + tw/2 + csize.x1;
          }
        } else {
          y = pWTask->y - csize.y1 + 1;
        }

        switch (pWTask->Data.object.motion) {
          case ObjectMotion_None:
            break;
          case ObjectMotion_Horizon:
            x += (pWTask->x - pWTask->Data.object.pre_x);
            break;
          case ObjectMotion_Vertical:
            y += (pWTask->y - pWTask->Data.object.pre_y);
            break;
        }

        isHit = 1;
        break;
      };
    };

    pWTask = pWTask->Next;
  };

  if( move_flag) {
    g_PlayerX = x;
    g_PlayerY = y;
  };

  return( isHit );
}

static int GetFood( struct TaskData* pTask ) {
  struct TaskData* pFTask;
  int x,y;
  int isGet = 0;

  pFTask = GetDispLink( DISP_LEVEL_FOOD );

  x = g_PlayerX;
  y = g_PlayerY + BBox[ pTask->Data.player.mode ].y1;

  while( pFTask != NULL ) {
    if( (pFTask->x - x)*(pFTask->x - x) + (pFTask->y - y)*(pFTask->y - y) < 90*90 ) {
      pFTask->visible = 0;
      pFTask->flag = TASK_FLAG_DESTROY;

      AddScore( pFTask->Data.food.score );
      isGet++;
    };

    pFTask = pFTask->Next;
  };

  return( isGet );
}

static int GetKey( struct TaskData* pTask ) {
  struct TaskData* pKTask;
  int x,y;
  int isGet = 0;

  pKTask = GetDispLink( DISP_LEVEL_KEY );

  x = g_PlayerX;
  y = g_PlayerY + BBox[ pTask->Data.player.mode ].y1;

  while( pKTask != NULL ) {
    if( (pKTask->x - x)*(pKTask->x - x) + (pKTask->y - y)*(pKTask->y - y) < 90*90 ) {
      pKTask->visible = 0;
      pKTask->flag = TASK_FLAG_DESTROY;

      //AddScore( pKTask->Data.food.score );
      g_StageClear = TRUE;
      isGet++;
    };

    pKTask = pKTask->Next;
  };

  return( isGet );
}

const static u16 MotionMap[] = {
  AG_RP_DAIGOROU_WAIT,
  AG_RP_DAIGOROU_WALKSTART,
  AG_RP_DAIGOROU_WALK,
  AG_RP_DAIGOROU_WALKEND,
  AG_RP_DAIGOROU_JUMPSTART,
  AG_RP_DAIGOROU_JUMP,
  AG_RP_DAIGOROU_JUMPEND,
  AG_RP_DAIGOROU_JUMP,
  AG_RP_DAIGOROU_ONIGIRI,
  AG_RP_DAIGOROU_RUNSTART,
  AG_RP_DAIGOROU_RUN,
  AG_RP_DAIGOROU_RUNEND,
  AG_RP_DAIGOROU_GAMEOVER,
};

static int isRun = 0;

static s32 CalcPlayerSpeed() {
  return isRun ? PLAYER_RUN_SPEED : PLAYER_WALK_SPEED;
}

//　地面にいる場合
//　一番下でなく、足場が無くなった場合は下降モードへ。
//　ボタンが押された場合はジャンプモードへ。
//　左右キーが押された場合は走る。

//　飛んでいる場合
//　上昇モードの場合、ボタンが離されるか、一定時間が立ったら下降モードへ。
//　左右キーをある程度受け付ける。
//　下降モードで地面に着いたら、地面モードへ。

static s32 CalcPlayer( struct TaskData* pTask , u32 Flag ) {
  struct TaskData* pWTask;
  struct RECT rect;

  rect = BBox[ pTask->Data.player.mode ];
  AddRect( &rect , g_PlayerX , g_PlayerY );
  g_pPlayerRect = &rect;

  if (g_GameOver && pTask->Data.player.mode != PLAYER_MODE_GAMEOVER) {
    pTask->Data.player.mode = PLAYER_MODE_GAMEOVER;
    pTask->Data.player.count = 0;
  }

  // 攻撃
  if (pTask->Data.player.mode != PLAYER_MODE_GAMEOVER) {
    if( PadTrg()&PAD_X ) {
      int x , y;

      x = g_PlayerX;
      y = g_PlayerY + BBox[ pTask->Data.player.mode ].y1;

      if( pTask->Data.player.direction == 0 ) {
        x += 120;
      }
      else {
        x -= 120;
      };

      {
        struct TaskData* pBTask;
        int dx = ( pTask->Data.player.direction == 0 ) ? 20 : -20;

        pBTask = AllocTask();
        if (pBTask != NULL) {
          InitTaskPBullet( pBTask , x, y, AG_RP_OBJ_PBULLET, dx,0, 0,0 );
          AddlLink( pBTask , DISP_LEVEL_PBULLET );
        };
      };
      ageSndMgrPlayOneshot( AS_SND_B03 , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
    };
  }

  switch( pTask->Data.player.mode ) {
    //　地面にいる場合
    case PLAYER_MODE_WAIT :
      MovePlayer( pTask, 0, 0, 1 );
    case PLAYER_MODE_WALKSTART :
    case PLAYER_MODE_WALK :
    case PLAYER_MODE_WALKEND :
      isRun = (PadLvl()&PAD_B) == PAD_B;
      if( g_PlayerY < GROUND_LINE && !MovePlayer( pTask , 0 , 10 , 0 )) {
        //　一番下でなく、足場が無くなった場合は下降モードへ。
        g_PlayerY += BBox[ PLAYER_MODE_WAIT ].y1 - BBox[ PLAYER_MODE_FALL ].y1;

        pTask->Data.player.mode = PLAYER_MODE_FALL;
        pTask->Data.player.count = 0;
      }
      else if( PadTrg()&PAD_A ) {		//　ボタンが押された場合はジャンプモードへ。
        pTask->Data.player.mode = PLAYER_MODE_JUMPSTART;
        pTask->Data.player.count = 0;
        pTask->Data.player.jump_power = isRun ? 35 : 25;
        ageSndMgrPlayOneshot( AS_SND_JUMP , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
        ageSndMgrPlayOneshot( AS_SND_B06 , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
      }
      else if( PadLvl()&PAD_RIGHT || PadLvl()&PAD_LEFT ) {
        if( PadLvl()&PAD_RIGHT ) {
          pTask->Data.player.direction = 0;
          MovePlayer( pTask , CalcPlayerSpeed() , 0 , 1 );
        }
        else {
          pTask->Data.player.direction = 1;
          MovePlayer( pTask , -CalcPlayerSpeed() , 0 , 1 );
        };

        if( pTask->Data.player.mode == PLAYER_MODE_WAIT ) {		//　止まってたら走り始める
          pTask->Data.player.mode = PLAYER_MODE_WALKSTART;
          pTask->Data.player.count = 0;
        }
        else if( pTask->Data.player.mode == PLAYER_MODE_WALKEND ) {		//　止まりかけだったなら走る
          pTask->Data.player.mode = PLAYER_MODE_WALK;
          pTask->Data.player.count = 0;
        }
        else {
          pTask->Data.player.count++;

          if( (pTask->Data.player.count>>1) >= ageRM3[ MotionMap[ pTask->Data.player.mode + isRun*8 ] ].Frames ) {
            pTask->Data.player.count = 0;

            if( pTask->Data.player.mode == PLAYER_MODE_WALKSTART ) {		//　走り始めが終わったら走りモードへ。
              pTask->Data.player.mode = PLAYER_MODE_WALK;
            };
          };
        };

        if( (pTask->Data.player.count & 0x1f) == 0 ) {
          ageSndMgrPlayOneshot( AS_SND_WALK_RIGHT , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
        }
        else if( (pTask->Data.player.count & 0x1f) == 0x0f ) {
          ageSndMgrPlayOneshot( AS_SND_WALK_LEFT , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
        };
      }
      else {		//　キー入力なし
        if( pTask->Data.player.mode == PLAYER_MODE_WALKSTART ) {		//　走り始めは停止へ。
          pTask->Data.player.mode = PLAYER_MODE_WAIT;
          pTask->Data.player.count = 0;
        }
        else if( pTask->Data.player.mode == PLAYER_MODE_WALK ) {		//　走ってたら走り終わりへ。
          pTask->Data.player.mode = PLAYER_MODE_WALKEND;
          pTask->Data.player.count = 0;

        }
        else {		//　止まってるか走り終わり
          pTask->Data.player.count++;

          if( (pTask->Data.player.count>>1) >= ageRM3[ MotionMap[ pTask->Data.player.mode + isRun*8 ] ].Frames ) {
            pTask->Data.player.count = 0;

            if( pTask->Data.player.mode == PLAYER_MODE_WALKEND ) {
              pTask->Data.player.mode = PLAYER_MODE_WAIT;
            };
          };
        };
      };
      break;

    case PLAYER_MODE_JUMPSTART :
      if( PadLvl()&PAD_RIGHT ) {
        pTask->Data.player.direction = 0;
        MovePlayer( pTask , CalcPlayerSpeed() , 0 , 1 );
      };
      if( PadLvl()&PAD_LEFT ) {
        pTask->Data.player.direction = 1;
        MovePlayer( pTask , -CalcPlayerSpeed() , 0 , 1 );
      };

      pTask->Data.player.count++;

      if( (pTask->Data.player.count>>1) >= ageRM3[ MotionMap[ pTask->Data.player.mode ] ].Frames ) {
        pTask->Data.player.count = 0;
        pTask->Data.player.mode = PLAYER_MODE_JUMP;
      };

      break;

    case PLAYER_MODE_JUMP :
      if( PadLvl()&PAD_RIGHT ) {
        pTask->Data.player.direction = 0;
        MovePlayer( pTask , CalcPlayerSpeed() , 0 , 1 );
      };
      if( PadLvl()&PAD_LEFT ) {
        pTask->Data.player.direction = 1;
        MovePlayer( pTask , -CalcPlayerSpeed() , 0 , 1 );
      };

      if( pTask->Data.player.jump_power > 0 ) {
        MovePlayer( pTask , 0 , -pTask->Data.player.jump_power , 1 );
        pTask->Data.player.jump_power -= 2;// 重力加速度的な何か

        if( (pTask->Data.player.count>>1) >= ageRM3[ MotionMap[ pTask->Data.player.mode ] ].Frames - 1 ) {
          // 最大フレームに達したらカウントを止める
        } else {
          pTask->Data.player.count++;
        }
      }
      else {// jump_power が 0 になったら落下モードへ。
        pTask->Data.player.mode = PLAYER_MODE_FALL;
        pTask->Data.player.count = 0;
      };
      break;

    case PLAYER_MODE_FALL :
      if( PadLvl()&PAD_RIGHT ) {
        pTask->Data.player.direction = 0;
        MovePlayer( pTask , CalcPlayerSpeed() , 0 , 1 );
      };
      if( PadLvl()&PAD_LEFT ) {
        pTask->Data.player.direction = 1;
        MovePlayer( pTask , -CalcPlayerSpeed() , 0 , 1 );
      };

      if( MovePlayer( pTask , 0 , 15 , 1 ) ) {
        g_PlayerY -= BBox[ PLAYER_MODE_WAIT ].y1 - BBox[ PLAYER_MODE_FALL ].y1;

        pTask->Data.player.mode = PLAYER_MODE_JUMPEND;
        pTask->Data.player.count = 0;
      }
      else if( g_PlayerY >= GROUND_LINE ) {
        g_PlayerY = GROUND_LINE;
        pTask->Data.player.mode = PLAYER_MODE_JUMPEND;
        pTask->Data.player.count = 0;
      }
      else {
        pTask->Data.player.count++;

        if( (pTask->Data.player.count>>1) >= ageRM3[ MotionMap[ pTask->Data.player.mode ] ].Frames ) {
          pTask->Data.player.count = 0;
        };
      };
      break;

    case PLAYER_MODE_JUMPEND :
      if( PadLvl()&PAD_RIGHT ) {
        pTask->Data.player.direction = 0;
        MovePlayer( pTask , CalcPlayerSpeed() , 0 , 1 );
      };
      if( PadLvl()&PAD_LEFT ) {
        pTask->Data.player.direction = 1;
        MovePlayer( pTask , -CalcPlayerSpeed() , 0 , 1 );
      };

      pTask->Data.player.count++;

      if( (pTask->Data.player.count>>1) >= ageRM3[ MotionMap[ pTask->Data.player.mode ] ].Frames ) {
        pTask->Data.player.count = 0;
        pTask->Data.player.mode = PLAYER_MODE_WAIT;
        ageSndMgrPlayOneshot( AS_SND_LANDING , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
      };
      break;

    case PLAYER_MODE_ATTACK :

      // スターマシンガン用のMODE

      ///*<s01151238>攻撃中の左右移動*/
      //if( PadLvl()&PAD_RIGHT ) {
      //  pTask->Data.player.direction = 0;
      //  MovePlayer( pTask , CalcPlayerSpeed() , 0 , 1 );
      //};
      //if( PadLvl()&PAD_LEFT ) {
      //  pTask->Data.player.direction = 1;
      //  MovePlayer( pTask , -CalcPlayerSpeed() , 0 , 1 );
      //};
      //pTask->Data.player.count++;

      //if( pTask->Data.player.count > 10 ) {
      //  int x , y;
      //  struct TaskData* pFTask;

      //  pFTask = GetDispLink( DISP_LEVEL_ENEMY );

      //  x = g_PlayerX;
      //  y = g_PlayerY + BBox[ pTask->Data.player.mode ].y1;

      //  if( pTask->Data.player.direction == 0 ) {
      //    x += 120;
      //  }
      //  else {
      //    x -= 120;
      //  };

      //  if (pTask->Data.player.count == 11){
      //    struct TaskData* pBTask;
      //    int dx = ( pTask->Data.player.direction == 0 ) ? 20 : -20;

      //    pBTask = AllocTask();
      //    if (pBTask != NULL) {
      //      InitTaskPBullet( pBTask , x, y, 1, dx,0, 0,0 );
      //      AddlLink( pBTask , DISP_LEVEL_PBULLET );
      //    }
      //  };
      //};

      //if( (pTask->Data.player.count>>1) >= ageRM3[ MotionMap[ pTask->Data.player.mode ] ].Frames ) {
      //  pTask->Data.player.count = 0;
      //  pTask->Data.player.mode = PLAYER_MODE_WAIT;
      //};
      break;

    case PLAYER_MODE_GAMEOVER :

      if( !MovePlayer( pTask , 0 , 15 , 1 ) && g_PlayerY >= GROUND_LINE ) {
        g_PlayerY = GROUND_LINE;
      }

      if( (pTask->Data.player.count>>1) >= ageRM3[ MotionMap[ pTask->Data.player.mode ] ].Frames - 1 ) {
        // 最大フレームに達したらカウントを止める
      } else {
        pTask->Data.player.count++;
      }

      break;

    default :
      break;
  };

  //　アイテム取得
  if( GetFood( pTask ) ) {
    ageSndMgrPlayOneshot( AS_SND_GET3 , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
  };

  // クリアアイテム取得
  if ( GetKey( pTask ) ) {
    ageSndMgrPlayOneshot( AS_SND_B08 , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
  }

  //　画面オフセット補正
  if( g_PlayerX > (1024-512) ) {
    int nx = g_PlayerX - (1024-512);
    if( nx > g_OffsetX ) {
      g_OffsetX = nx;
    };
  };
  if ((g_PlayerX - g_OffsetX) < 512) {
    g_OffsetX = g_PlayerX - 512;
    if (g_OffsetX < 0 ) {
      g_OffsetX = 0;
    }
  }

  if( (g_PlayerY - g_OffsetY) < 128 ) {
    g_OffsetY = g_PlayerY - 128;
  }
  else if( (g_PlayerY - g_OffsetY) >= (768-512) ) {
    g_OffsetY = g_PlayerY - (768-512);
    if( g_OffsetY > 0 ) {
      g_OffsetY = 0;
    };
  };

  return( 0 );
}

static s32 DrawPlayer( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
  int w, h;
  int pat;
  u8 flip;
  int x, y;
  int isRun2 = isRun;

  agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );

  pat = pTask->Data.player.count >> 1;

  if( pTask->Data.player.direction == 0 ) {
    flip = 0;
  }
  else {
    flip = 1;
  };

  if (pTask->Data.player.mode < PLAYER_MODE_WALKSTART || pTask->Data.player.mode > PLAYER_MODE_WALKEND) {
    isRun2 = 0;
  }
  ageTransferAAC_RM3( pDBuf, MotionMap[ pTask->Data.player.mode + isRun2*8 ] , 0, &w, &h , pat );

  x = g_PlayerX - g_OffsetX;
  y = g_PlayerY - g_OffsetY;
  if( flip == 0 ) {
    agDrawSPRITE( pDBuf, 1 , (x-w/2)<<2 , (y-h/2)<<2 , (x+w/2)<<2, (y+h/2)<<2 );
  }
  else {
    agDrawSPRITE_UV( pDBuf, (x-w/2)<<2 , (y-h/2)<<2 , 0x1000 , 0 , (x+w/2)<<2, (y+h/2)<<2 , 0 , 0x1000 );
  };

  return( 0 );
}

void InitTaskPlayer( struct TaskData* pTask ) {
  memset( pTask , 0 , sizeof( *pTask ) );

  pTask->type = TASK_PLAYER;
  pTask->visible = 1;
  g_PlayerX = AGE_FB_WIDTH/2;
  g_PlayerY = GROUND_LINE;
  pTask->Calc = CalcPlayer;
  pTask->Draw = DrawPlayer;
  pTask->Data.player.direction = 0;
  pTask->Data.player.count = 0;
  pTask->Data.player.mode = 0;
}
