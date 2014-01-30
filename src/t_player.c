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

void KillPlayer( struct TaskData* pTask ) {
  if ( pTask->Data.player.mode != PLAYER_MODE_GAMEOVER && !g_isGetKeyItem ) {
    pTask->Data.player.mode = PLAYER_MODE_GAMEOVER;
    pTask->Data.player.count = 0;

    ageSndMgrPlayOneshot( AS_SND_B07 , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
  }
}

// 大五郎が地面に着地しているときのY座標
#define PLAYER_GROUND_LINE (GROUND_LINE - 64)

// スピード
#define PLAYER_WALK_SPEED   (4)
#define PLAYER_RUN_SPEED    (8)

enum{
  NONE_HIT = 0,
  TOP_HIT = 0x1,
  BOTTOM_HIT = 0x2,
  LEFT_HIT = 0x4,
  RIGHT_HIT = 0x8,
};
/******************************************************************/
/*                                player                          */
/******************************************************************/
struct RECT BBox[] = {
  { -50/2 , 0,  50/2 , 130/2 },// PLAYER_MODE_WAIT      (0)
  { -50/2 , 0,  50/2 , 130/2 },// PLAYER_MODE_WALKSTART (1)
  { -50/2 , 0,  50/2 , 130/2 },// PLAYER_MODE_WALK      (2)
  { -50/2 , 0,  50/2 , 130/2 },// PLAYER_MODE_WALKEND   (3)
  { -50/2 , 0,  50/2 , 130/2 },// PLAYER_MODE_JUMPSTART (4)
  { -50/2 , 0,  50/2 , 130/2 },// PLAYER_MODE_JUMP      (5)
  { -50/2 , 0,  50/2 , 130/2 },// PLAYER_MODE_JUMPEND   (6)
  { -50/2 , 0,  50/2 , 130/2 },// PLAYER_MODE_FALL      (7)
  { -50/2 , 0,  50/2 , 130/2 },// PLAYER_MODE_ATTACK    (8)
  { -50/2 , 0,  50/2 , 130/2 },// PLAYER_MODE_RUNSTART  (1+8)
  { -50/2 , 0,  50/2 , 130/2 },// PLAYER_MODE_RUN       (2+8)
  { -50/2 , 0,  50/2 , 130/2 },// PLAYER_MODE_RUNEND    (3+8)
  { -50/2 , 0,  50/2 , 130/2 },// PLAYER_MODE_GAMEOVER  (12)
  { -50/2 , 0,  50/2 , 130/2 },// PLAYER_MODE_RETWEET   (13)
};

static int MovePlayer( struct TaskData* pTask , int dx , int dy , int move_flag ) {
  struct TaskData* pWTask;
  struct TaskData* pTTask=NULL; //上から当たっているobject
  struct TaskData* pBTask=NULL; //下から当たっているobject
  struct TaskData* pLTask=NULL; //左から当たっているobject
  struct TaskData* pRTask=NULL; //右から当たっているobject


  u8 isHit = NONE_HIT;
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
  g_pPlayerRect = &crect;

  while( pWTask != NULL ) {
    u8 thisHit = NONE_HIT;
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
        if ( pWTask->Data.object.is_harmful ) {
          KillPlayer( pTask );
        }

        // 食い込まないように補正を 上→下→左→右 の順番に行う
        if ( y > pWTask->y ) {
          int tw = ageRM[ pWTask->Data.object.image ].Width;
          int th = ageRM[ pWTask->Data.object.image ].Height;
          if ( (y - dy)  > pWTask->y + th ){
            int xx = x + (pTask->y + th - y)*dx/dy;
            if(xx<pWTask->x - tw/2 + csize.x0 &&dx>0){ //左
              pLTask = pWTask;
              thisHit = LEFT_HIT;
            }
            else if(xx>pWTask->x + tw/2 + csize.x1 && dx<0){ //右
              pRTask = pWTask;
              thisHit = RIGHT_HIT;
            }
            else{ // 下
              pBTask = pWTask;
              thisHit = BOTTOM_HIT;
            };
          }
          else if ( (x-dx + csize.x1) < (pWTask->x - tw/2) && (x + csize.x1) > (pWTask->x - tw/2)) {
            // 左
            pLTask = pWTask;
            thisHit = LEFT_HIT;
          } 
          else if ( (x-dx + csize.x0) > (pWTask->x + tw/2) && (x + csize.x0) < (pWTask->x + tw/2)){
            // 右
            pRTask = pWTask;
            //x = pWTask->x + tw/2 + csize.x1 + 1;
            thisHit = RIGHT_HIT;
          }
        }else {
          // 上
          pTTask = pWTask;
          //y = pWTask->y - csize.y1 + 1;
          thisHit = TOP_HIT;
        }
        isHit = isHit | thisHit;
      };
    };  
    pWTask = pWTask->Next;
  };
  switch(pTask->Data.player.mode){
    case PLAYER_MODE_JUMP:
    case PLAYER_MODE_JUMPSTART:
    case PLAYER_MODE_FALL:
      if(isHit&LEFT_HIT){
        x = pLTask->x - ageRM[ pLTask->Data.object.image ].Width/2 + csize.x0 - 1;
        isHit = LEFT_HIT;
      }else if(isHit&RIGHT_HIT){
        x = pRTask->x + ageRM[ pRTask->Data.object.image ].Width/2 + csize.x1 + 1;
        isHit = RIGHT_HIT;
      }else if(isHit==(TOP_HIT|BOTTOM_HIT)){
        if(x-dx<=pBTask->x){x = pBTask->x - ageRM[ pBTask->Data.object.image ].Width/2 + csize.x0 - 1;isHit = LEFT_HIT;}
        else{x = pBTask->x + ageRM[ pBTask->Data.object.image ].Width/2 + csize.x1 + 1;isHit = RIGHT_HIT;}
      }else if(isHit&TOP_HIT){
        y = pTTask->y - csize.y1 + 1;
        isHit = TOP_HIT;
      }else if(isHit&BOTTOM_HIT){
        y = pBTask->y +  ageRM[ pBTask->Data.object.image ].Height -csize.y0 - 1;
        isHit = BOTTOM_HIT;
      };
      break;
    default:
      if(isHit&LEFT_HIT){
        x = pLTask->x - ageRM[ pLTask->Data.object.image ].Width/2 + csize.x0 - 1;
      }else if(isHit&RIGHT_HIT){
        x = pRTask->x + ageRM[ pRTask->Data.object.image ].Width/2 + csize.x1 + 1;
      };
      if(isHit&TOP_HIT){
        y = pTTask->y*2 - csize.y1 + 1 - pTTask->Data.object.pre_y;
        if(pTTask->Data.object.motion==ObjectMotion_Horizon){
          int objM = pTTask->x - pTTask->Data.object.pre_x;
          if((objM>0&&!(isHit&RIGHT_HIT))||(objM<0&&!(isHit&LEFT_HIT))){
            x += objM;
          }
        };
        isHit = TOP_HIT;
      } else if(isHit&BOTTOM_HIT){
        y = pBTask->y +  ageRM[ pBTask->Data.object.image ].Height -csize.y0 + 1;
        isHit = BOTTOM_HIT;
      }
  }
  /*/ 動く床の移動
    switch (pWTask->Data.object.motion) {
    case ObjectMotion_None:
    break;
    case ObjectMotion_Horizon:
    if(thisHit!=BOTTOM_HIT){
    x += (pWTask->x - pWTask->Data.object.pre_x);
    }
    break;
    case ObjectMotion_Vertical:
    if(thisHit==TOP_HIT ||thisHit==BOTTOM_HIT){
    y += (pWTask->y - pWTask->Data.object.pre_y);
    }
    break;
    }*/
  if( move_flag) {
    g_PlayerX = x;
    g_PlayerY = y;
  };
  return( isHit );
}

static int GetItem( struct TaskData* pTask ) {
  struct TaskData* pITask;
  int x,y;
  int isGet = 0;

  pITask = GetDispLink( DISP_LEVEL_ITEM );

  x = g_PlayerX;
  y = g_PlayerY + BBox[ pTask->Data.player.mode ].y1;

  while( pITask != NULL ) {
    if( (pITask->x - x)*(pITask->x - x) + (pITask->y - y)*(pITask->y - y) < 90*90 ) {
      pITask->visible = 0;
      pITask->flag = TASK_FLAG_DESTROY;

      if (pITask->Data.item.is_keyitem) {
        g_isGetKeyItem = TRUE;
      }

      AddScore( pITask->Data.item.score );
      AddStar( pITask->Data.item.star );
      AddTime( pITask->Data.item.time );

      isGet++;
    };

    pITask = pITask->Next;
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
  0,
  AG_RP_DAIGOROU_RUNSTART,
  AG_RP_DAIGOROU_RUN,
  AG_RP_DAIGOROU_RUNEND,
  AG_RP_DAIGOROU_GAMEOVER,
  AG_RP_DAIGOROU_RT,
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
  int mx = 0,my = 0;  //移動量

  // 大五郎が生存かつゲームクリアでない
  if (pTask->Data.player.mode != PLAYER_MODE_GAMEOVER && !g_isGetKeyItem ) {

    // 通常攻撃(Star Attack)
    if( g_Star >= 1 && ( PadTrg()&PAD_X ) ) {
      int x , y, dx;

      g_Star -= 1;
      x = g_PlayerX;
      y = g_PlayerY + BBox[ pTask->Data.player.mode ].y1;

      if( pTask->Data.player.direction == 0 ) {
        x += 60;
        dx = 10;
      }
      else {
        x -= 60;
        dx = -10;
      };

      {
        struct TaskData* pBTask;
        pBTask = AllocTask();
        if (pBTask != NULL) {
          InitTaskPBullet( pBTask , x, y, AG_RP_OBJ_PBULLET, dx,0, 0,0 );
          AddlLink( pBTask , DISP_LEVEL_PBULLET );
        };
      };
      ageSndMgrPlayOneshot( AS_SND_B03 , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
    };

    // 強攻撃(Star Machine Gun) 発動開始
    if( g_Star >= 5 && ( PadTrg()&PAD_Y ) && !pTask->Data.player.starMachineGun_count ) {
      g_Star -= 5;
      pTask->Data.player.starMachineGun_count = 300;
      ageSndMgrPlayOneshot( AS_SND_B04 , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
    };

    // 強攻撃(Star Machine Gun) 発動中
    if ( pTask->Data.player.starMachineGun_count > 0) {
      int interval;
      pTask->Data.player.starMachineGun_count--;

      if (pTask->Data.player.starMachineGun_count >= 250) {
        interval = 8;
      } else if (pTask->Data.player.starMachineGun_count >= 200) {
        interval = 5;
      } else if (pTask->Data.player.starMachineGun_count < 50) {
        interval = 10;
      } else {
        interval = 5;
      }

      if (pTask->Data.player.starMachineGun_count%interval == 0 ) {
        struct TaskData* pBTask;
        int x = g_PlayerX;
        int y = g_PlayerY + BBox[ pTask->Data.player.mode ].y1;
        int dx, dy;
        float angle = (double)(rand() % 30) / 30 * 1.0 - 0.5;
        if( pTask->Data.player.direction == 0 ) {
          x += 60;
          angle += 0;
        }
        else {
          x -= 60;
          angle += PI;
        };
        dx = 20 * cosf( angle );
        dy = 20 * sinf( angle );
        pBTask = AllocTask();
        if (pBTask != NULL) {
          InitTaskPBullet( pBTask , x, y, AG_RP_OBJ_PBULLET, dx,dy, 0,0 );
          AddlLink( pBTask , DISP_LEVEL_PBULLET );
        };
      };
    };

    //　アイテム取得
    if( GetItem( pTask ) ) {
      ageSndMgrPlayOneshot( AS_SND_GET3 , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
    };

  };// END:大五郎が生存かつゲームクリアでない


  switch( pTask->Data.player.mode ) {
    //　地面にいる場合
    case PLAYER_MODE_WAIT :
      mx = 0; my = 0;
    case PLAYER_MODE_WALKSTART :
    case PLAYER_MODE_WALK :
    case PLAYER_MODE_WALKEND :
      isRun = (PadLvl()&PAD_B) == PAD_B;
      /*
         if( g_PlayerY < PLAYER_GROUND_LINE && !MovePlayer( pTask , 0 , 10 , 0 )) {
      //　一番下でなく、足場が無くなった場合は下降モードへ。
      g_PlayerY += BBox[ PLAYER_MODE_WAIT ].y1 - BBox[ PLAYER_MODE_FALL ].y1;

      pTask->Data.player.mode = PLAYER_MODE_FALL;
      pTask->Data.player.count = 0;

      }
      */
      if( PadTrg()&PAD_A ) {   //　ボタンが押された場合はジャンプモードへ。
        pTask->Data.player.mode = PLAYER_MODE_JUMPSTART;
        pTask->Data.player.count = 0;
        pTask->Data.player.jump_power = isRun ? 25 : 20;
        ageSndMgrPlayOneshot( AS_SND_JUMP , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
        ageSndMgrPlayOneshot( AS_SND_B06 , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
      }
      else if( PadTrg()&PAD_DOWN && g_Star >= 3&& !g_isGetKeyItem){   //  パッド↓でリツイートモードへ
        g_Star -= 3;
        ageSndMgrPlayOneshot( AS_SND_B05 , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
        pTask->Data.player.mode = PLAYER_MODE_RETWEET;
        pTask->Data.player.count = 0;
        {
          struct TaskData* pRTTask;
          int dx = ( pTask->Data.player.direction == 0 ) ? 20 : -20;
          pRTTask = AllocTask();
          if (pRTTask != NULL) {
            InitTaskRetweet( pRTTask , g_PlayerX, g_PlayerY ,pTask->Data.player.direction);
            AddlLink( pRTTask , DISP_LEVEL_BG_FRONT );
          };
        };
      }
      else if( PadLvl()&PAD_RIGHT || PadLvl()&PAD_LEFT ) {
        if( PadLvl()&PAD_RIGHT ) {
          pTask->Data.player.direction = 0;
          mx = CalcPlayerSpeed();
        }
        else {
          pTask->Data.player.direction = 1;
          mx = -CalcPlayerSpeed();
        };
        my = 0;
        if( pTask->Data.player.mode == PLAYER_MODE_WAIT ) {   //　止まってたら走り始める
          pTask->Data.player.mode = PLAYER_MODE_WALKSTART;
          pTask->Data.player.count = 0;
        }
        else if( pTask->Data.player.mode == PLAYER_MODE_WALKEND ) {   //　止まりかけだったなら走る
          pTask->Data.player.mode = PLAYER_MODE_WALK;
          pTask->Data.player.count = 0;
        }
        else {
          pTask->Data.player.count++;

          if( (pTask->Data.player.count>>1) >= ageRM3[ MotionMap[ pTask->Data.player.mode + isRun*8 ] ].Frames ) {
            pTask->Data.player.count = 0;

            if( pTask->Data.player.mode == PLAYER_MODE_WALKSTART ) {    //　走り始めが終わったら走りモードへ。
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
      else {    //　キー入力なし
        if( pTask->Data.player.mode == PLAYER_MODE_WALKSTART ) {    //　走り始めは停止へ。
          pTask->Data.player.mode = PLAYER_MODE_WAIT;
          pTask->Data.player.count = 0;
        }
        else if( pTask->Data.player.mode == PLAYER_MODE_WALK ) {    //　走ってたら走り終わりへ。
          pTask->Data.player.mode = PLAYER_MODE_WALKEND;
          pTask->Data.player.count = 0;

        }
        else {    //　止まってるか走り終わり
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
        mx = CalcPlayerSpeed();
      };
      if( PadLvl()&PAD_LEFT ) {
        pTask->Data.player.direction = 1;
        mx = -CalcPlayerSpeed();
      };
      my = 0;

      pTask->Data.player.count++;

      if( (pTask->Data.player.count>>1) >= ageRM3[ MotionMap[ pTask->Data.player.mode ] ].Frames ) {
        pTask->Data.player.count = 0;
        pTask->Data.player.mode = PLAYER_MODE_JUMP;
      };

      break;

    case PLAYER_MODE_JUMP :
      if( PadLvl()&PAD_RIGHT ) {
        pTask->Data.player.direction = 0;
        mx = CalcPlayerSpeed();
      };
      if( PadLvl()&PAD_LEFT ) {
        pTask->Data.player.direction = 1;
        mx = -CalcPlayerSpeed();
      };

      if( pTask->Data.player.jump_power > 0 ) {
        my = -pTask->Data.player.jump_power;
        pTask->Data.player.jump_power -= 2;// 重力加速度的な何か

        if( (pTask->Data.player.count>>1) >= ageRM3[ MotionMap[ pTask->Data.player.mode ] ].Frames - 1 ) {
          // 最大フレームに達したらカウントを止める
        } else {
          pTask->Data.player.count++;
        }
      }
      else {// jump_power が 0 になったら落下モードへ。
        my = 0;
        pTask->Data.player.mode = PLAYER_MODE_FALL;
        pTask->Data.player.count = 0;
      };


      break;

    case PLAYER_MODE_FALL :
      if( PadLvl()&PAD_RIGHT ) {
        pTask->Data.player.direction = 0;
        mx = CalcPlayerSpeed();
      };
      if( PadLvl()&PAD_LEFT ) {
        pTask->Data.player.direction = 1;
        mx = -CalcPlayerSpeed();
      };
      my=15;
      /*
         if( MovePlayer( pTask , 0 , 15 , 1 ) ) {
         g_PlayerY -= BBox[ PLAYER_MODE_WAIT ].y1 - BBox[ PLAYER_MODE_FALL ].y1;

         pTask->Data.player.mode = PLAYER_MODE_JUMPEND;
         pTask->Data.player.count = 0;
         }

         if( g_PlayerY >= PLAYER_GROUND_LINE ) {
         g_PlayerY = PLAYER_GROUND_LINE;
         pTask->Data.player.mode = PLAYER_MODE_JUMPEND;
         pTask->Data.player.count = 0;
         }
         */

      pTask->Data.player.count++;

      if( (pTask->Data.player.count>>1) >= ageRM3[ MotionMap[ pTask->Data.player.mode ] ].Frames ) {
        pTask->Data.player.count = 0;
      };


      break;

    case PLAYER_MODE_JUMPEND :

      pTask->Data.player.count++;
      if( PadLvl()&PAD_RIGHT ) {
        pTask->Data.player.direction = 0;
        mx = CalcPlayerSpeed();
      };
      if( PadLvl()&PAD_LEFT ) {
        pTask->Data.player.direction = 1;
        mx = -CalcPlayerSpeed();
      };
      my = 0;

      if( (pTask->Data.player.count>>1) >= ageRM3[ MotionMap[ pTask->Data.player.mode ] ].Frames ) {
        pTask->Data.player.count = 0;
        pTask->Data.player.mode = PLAYER_MODE_WAIT;
        ageSndMgrPlayOneshot( AS_SND_LANDING , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
      };
      if( PadTrg()&PAD_A ) {   //　ボタンが押された場合はジャンプモードへ。（着キャン）
        pTask->Data.player.mode = PLAYER_MODE_JUMPSTART;
        pTask->Data.player.count = 0;
        pTask->Data.player.jump_power = isRun ? 25 : 20;
        ageSndMgrPlayOneshot( AS_SND_JUMP , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
        ageSndMgrPlayOneshot( AS_SND_B06 , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
      }
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
      /*
         if( !MovePlayer( pTask , 0 , 15 , 1 ) && g_PlayerY >= PLAYER_GROUND_LINE ) {
         g_PlayerY = PLAYER_GROUND_LINE;
         }
         */
      my = 15;
      if( (pTask->Data.player.count>>1) >= ageRM3[ MotionMap[ pTask->Data.player.mode ] ].Frames - 1 ) {
        // 最大フレームに達したらカウントを止める
        if ( !g_isGameOver ) {
          --g_Life;
        }
        if ( g_Life > 0) {
          ageSndMgrRelease( g_pSenarioTask->Data.senario.bgm_handle );
          GotoMode( MODE_GAME );
        }
      } else {
        pTask->Data.player.count++;
      }

      break;

    case PLAYER_MODE_RETWEET:

      pTask->Data.player.count++;
      if( PadLvl()&PAD_RIGHT ) {
        mx = CalcPlayerSpeed()-pTask->Data.player.count/8;
        if(mx<0)mx=0;
      };
      if( PadLvl()&PAD_LEFT ) {
        mx = -CalcPlayerSpeed()+pTask->Data.player.count/8;
        if(mx>0)mx=0;
      };
      my = 0;
      if( (pTask->Data.player.count>>1) >= ageRM3[ MotionMap[ pTask->Data.player.mode ] ].Frames ) {
        pTask->Data.player.count = 0;
        pTask->Data.player.mode = PLAYER_MODE_WAIT;
      };
      break;


    default :
      break;
  };
  {
    int m = pTask->Data.player.mode;
    switch( MovePlayer( pTask , mx , my , 1 ) ) {
      case NONE_HIT:
        if( g_PlayerY < PLAYER_GROUND_LINE){
          switch(m){
            case PLAYER_MODE_WAIT :
            case PLAYER_MODE_WALKSTART :
            case PLAYER_MODE_WALK :
            case PLAYER_MODE_WALKEND :
              pTask->Data.player.mode = PLAYER_MODE_FALL;
              pTask->Data.player.count = 0;
              break;
          }
        }
        else{
          g_PlayerY = PLAYER_GROUND_LINE;
          if(m==PLAYER_MODE_FALL){
            pTask->Data.player.mode = PLAYER_MODE_JUMPEND;
            pTask->Data.player.count = 0;
          }
        };
        break;
      case TOP_HIT:
        if(m==PLAYER_MODE_FALL){
          pTask->Data.player.mode = PLAYER_MODE_JUMPEND;
          pTask->Data.player.count = 0;
        };
        break;
      case BOTTOM_HIT:
        pTask->Data.player.jump_power = 0;
        if(g_PlayerY > PLAYER_GROUND_LINE){
          g_PlayerX -= mx;
          g_PlayerY = PLAYER_GROUND_LINE;
        }
        break;
      case LEFT_HIT:
        if(g_PlayerY>PLAYER_GROUND_LINE){
          g_PlayerY = PLAYER_GROUND_LINE;
          g_PlayerX -=1;
          if(m==PLAYER_MODE_FALL){
            pTask->Data.player.mode = PLAYER_MODE_JUMPEND;
            pTask->Data.player.count = 0;
          }
        }
        break;
      case RIGHT_HIT:
        if(g_PlayerY>PLAYER_GROUND_LINE){
          g_PlayerY = PLAYER_GROUND_LINE;
          g_PlayerX +=1;
          if(m==PLAYER_MODE_FALL){
            pTask->Data.player.mode = PLAYER_MODE_JUMPEND;
            pTask->Data.player.count = 0;
          }
        }

    };
  };

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

  agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );

  x = g_PlayerX - g_OffsetX;
  y = g_PlayerY - g_OffsetY;
  if( flip == 0 ) {
    agDrawSPRITE( pDBuf, 1 , (x-w/2)<<2 , (y-h/2)<<2 , (x+w/2)<<2, (y+h/2)<<2 );
  }
  else {
    agDrawSPRITE_UV( pDBuf, (x-w/2)<<2 , (y-h/2)<<2 , 0x1000 , 0 , (x+w/2)<<2, (y+h/2)<<2 , 0 , 0x1000 );
  };

#if 0
  agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 0 , 1 );
  agDrawSETFCOLOR( pDBuf , ARGB( 0x80 , 0xff , 0xff , 0xff ) );
  agDrawSPRITE( pDBuf, 0, (x-w/2)<<2 , (y-h/2)<<2 , (x+w/2)<<2, (y+h/2)<<2 );

  agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 0 , 1 );
  agDrawSETFCOLOR( pDBuf , 0xff000000);
  agDrawSPRITE( pDBuf, 0, (x-4)<<2 , (y-4)<<2 ,(x+4)<<2 , (y+4)<<2 );

  agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
  agDrawSETFCOLOR( pDBuf , 0xffffffff);

#endif


  return( 0 );
}

void InitTaskPlayer( struct TaskData* pTask ) {
  memset( pTask , 0 , sizeof( *pTask ) );

  g_pPlayerTask = pTask;

  pTask->type = TASK_PLAYER;
  pTask->visible = 1;
  g_PlayerX = AGE_FB_WIDTH/2;
  g_PlayerY = PLAYER_GROUND_LINE;
  pTask->Calc = CalcPlayer;
  pTask->Draw = DrawPlayer;

  pTask->Data.player.direction = 0;
  pTask->Data.player.count = 0;
  pTask->Data.player.mode = 0;
  pTask->Data.player.jump_power = 0;
  pTask->Data.player.starMachineGun_count = 0;
}
