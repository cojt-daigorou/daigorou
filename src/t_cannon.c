#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "randMT.h"
#include "export.h"
#include "global.h"
#include "t_cannon.h"
#include "rect.h"

/******************************************************************/
/*                              キャノン                          */
/******************************************************************/
static s32 CalcCannon( struct TaskData* pTask , u32 Flag ) {
  switch( pTask->Data.cannon.mode ) {
    default :
    case 0 :		//　通常待機状態
      pTask->Data.cannon.count++;

      if ( pTask->Data.cannon.count == 30 ) {
        // 弾発射
        int x , y, dx;
        x = pTask->x;
        y = pTask->y;

        if( pTask->Data.cannon.direction == 0 ) {
          x -= 120;
          dx = -10;
        }
        else {
          x += 120;
          dx = 10;
        };

        {
          struct TaskData* pBTask;
          pBTask = AllocTask();
          if (pBTask != NULL) {
            InitTaskEBullet( pBTask , x, y - 30, AG_RP_OBJ_EBULLET, dx,0, 0,0 );
            AddlLink( pBTask , DISP_LEVEL_EBULLET );
            if( (g_PlayerX-pTask->x)*(g_PlayerX-pTask->x)<1024*1024
              ||(g_PlayerX<pTask->x&&pTask->Data.cannon.direction==0)
              ||(g_PlayerX>pTask->x&&pTask->Data.cannon.direction!=0)){
              ageSndMgrPlayOneshot( AS_SND_CANNON , 0 , 0xff , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
            };
          };
        };
      };

      if( pTask->Data.cannon.count > 60 ) {
        pTask->Data.cannon.count = 0;
        pTask->Data.cannon.mode = 1;		//　ジャンプ状態
      };
      break;

		case 1 :		//　ジャンプ状態
			if( pTask->Data.cannon.direction == 0 ) {		//　左向き
				pTask->x -= 1;
			}
			else {
				pTask->x += 1;
			};

			pTask->Data.cannon.count++;
			if( pTask->Data.cannon.count >= 20 ) {
				pTask->Data.cannon.count = 0;
				pTask->Data.cannon.mode = 2;
			};
			break;

		case 2 :		//　潰れ状態
			pTask->Data.cannon.count++;
			if( pTask->Data.cannon.count > 30 ) {
				pTask->Data.cannon.count = 0;
				pTask->Data.cannon.mode = 0;		//　通常状態

					//　三回飛んだら反対向き
				pTask->Data.cannon.sub_count++;
				if( pTask->Data.cannon.sub_count > 3 ) {
					pTask->Data.cannon.sub_count = 0;

					if( pTask->Data.cannon.direction == 0 ) {
						pTask->Data.cannon.direction = 1;
					}
					else {
						pTask->Data.cannon.direction = 0;
					};
				};
			};
			break;
	};


  // 自機の弾の判定
  {
    struct TaskData* pBTask;
    pBTask = GetDispLink( DISP_LEVEL_PBULLET );
    while ( pBTask != NULL ) {
      if (pBTask->type == TASK_PBULLET) {
        if ( (pTask->x - pBTask->x) * (pTask->x - pBTask->x) + (pTask->y - pBTask->y) * (pTask->y - pBTask->y) < 50*50) {
          struct TaskData* pATask;

          pATask = AllocTask();
          InitTaskAttack( pATask , pTask->x , pTask->y );
          AddlLink( pATask , DISP_LEVEL_ATTACK );


          AddScore( pTask->Data.cannon.score );

          pBTask->visible = 0;
          pBTask->flag = TASK_FLAG_DESTROY;
          break;
        }
      }

      pBTask = pBTask->Next;
    }
  }

	return( 0 );
}

static s32 DrawCannon( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
  int w,h;
  u8 flip = 0;

  if( pTask->Data.frog.direction == 1 ) {
    flip = 1;
  };

  if( (pTask->x + 100) > g_OffsetX && (pTask->x - 100) < (g_OffsetX + 1024) ) {
    agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
    ageTransferAAC( pDBuf, AG_CG_OBJ_CANNON, 0, &w, &h );

    if( flip == 0 ) {
      agDrawSPRITE( pDBuf, 1, (pTask->x - g_OffsetX - w/2)<<2 , (pTask->y-g_OffsetY - h)<<2 , (pTask->x - g_OffsetX + w/2)<<2, (pTask->y-g_OffsetY)<<2 );
    }
    else {
      agDrawSPRITE_UV( pDBuf, (pTask->x - g_OffsetX - w/2)<<2 , (pTask->y-g_OffsetY - h)<<2 , 0x1000 , 0 , (pTask->x - g_OffsetX + w/2)<<2, (pTask->y-g_OffsetY)<<2 , 0 , 0x1000 );
    };
  };
}

static s32 HitCannon( struct TaskData* pTask , const struct RECT* pRect ) {
  int w,h;
  struct RECT rect;

  w = ageRM[ AG_CG_OBJ_CANNON ].Width;
  h = ageRM[ AG_CG_OBJ_CANNON ].Height;

  rect.x0 = pTask->x - w/2;
  rect.y0 = pTask->y - h;
  rect.x1 = pTask->x + w/2;
  rect.y1 = pTask->y;

  return( IsHitRect( pRect , &rect ) );
}

void InitTaskCannon( struct TaskData* pTask , s32 x , s32 y , u16 Score , u8 Direction ) {
	memset( pTask , 0 , sizeof( *pTask ) );

	pTask->type = TASK_ENEMY;
	pTask->visible = 1;
	pTask->x = x;
	pTask->y = y;
	pTask->Calc = CalcCannon;
	pTask->Draw = DrawCannon;
	pTask->Data.cannon.count = 0;
	pTask->Data.cannon.sub_count = 0;
	pTask->Data.cannon.score = Score;
	pTask->Data.cannon.direction = Direction;
	pTask->Data.cannon.mode = 0;
}
