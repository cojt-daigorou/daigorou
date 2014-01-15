#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "randMT.h"
#include "export.h"
#include "global.h"
#include "t_frog.h"
#include "rect.h"

static void AddScore( u32 n ) {
  g_Score += n;
}

/******************************************************************/
/*                              かえる                            */
/******************************************************************/
static s32 CalcFrog( struct TaskData* pTask , u32 Flag ) {
	switch( pTask->Data.frog.mode ) {
		default :
		case 0 :		//　通常待機状態
			pTask->Data.frog.count++;
			if( pTask->Data.frog.count > 60 ) {
				pTask->Data.frog.count = 0;
				pTask->Data.frog.mode = 1;		//　ジャンプ状態
			};
			break;

		case 1 :		//　ジャンプ状態
			if( pTask->Data.frog.direction == 0 ) {		//　左向き
				pTask->x -= 3;
			}
			else {
				pTask->x += 3;
			};

			if( pTask->Data.frog.count < 10 ) {
				pTask->y -= 5;
			}
			else {
				pTask->y += 5;
			};

			pTask->Data.frog.count++;
			if( pTask->Data.frog.count >= 20 ) {
				pTask->Data.frog.count = 0;
				pTask->Data.frog.mode = 2;
			};
			break;

		case 2 :		//　潰れ状態
			pTask->Data.frog.count++;
			if( pTask->Data.frog.count > 30 ) {
				pTask->Data.frog.count = 0;
				pTask->Data.frog.mode = 0;		//　通常状態

					//　三回飛んだら反対向き
				pTask->Data.frog.sub_count++;
				if( pTask->Data.frog.sub_count > 3 ) {
					pTask->Data.frog.sub_count = 0;

					if( pTask->Data.frog.direction == 0 ) {
						pTask->Data.frog.direction = 1;
					}
					else {
						pTask->Data.frog.direction = 0;
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
          AddlLink( pATask , DISP_LEVEL_ENEMY );

          pTask->visible = 0;
          pTask->flag = TASK_FLAG_DESTROY;

          AddScore( pTask->Data.frog.score );

          pBTask->visible = 0;
          pBTask->flag = TASK_FLAG_DESTROY;
          break;
        }
      }

      pBTask = pBTask->Next;
    }
  }

  // 自機との判定
  if ( (pTask->x - g_PlayerX) * (pTask->x - g_PlayerX) + (pTask->y - g_PlayerY - 100) * (pTask->y - g_PlayerY - 100 ) < 80*80) {
  //if ( g_pPlayerRect != NULL && HitFrog(pTask, g_pPlayerRect) ) {
    g_Life = 0;
  }

	return( 0 );
}

static s32 DrawFrog( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
	int w, h;
	int a = 255;

	if( (pTask->x + 50) > g_OffsetX && (pTask->x - 50) < (g_OffsetX + 1024) ) {
		u8 flip = 0;

		if( pTask->Data.frog.direction == 1 ) {
			flip = 1;
		};

		agPictureSetBlendMode( pDBuf , 0 , a , 0 , 0 , 2 , 1 );

		if( pTask->Data.frog.mode == 0 ) {
			ageTransferAAC( pDBuf, AG_CG_ENEMY_FROGA1, 0, &w, &h );
		}
		else if( pTask->Data.frog.mode == 1 ) {
			ageTransferAAC( pDBuf, AG_CG_ENEMY_FROGA2, 0, &w, &h );
		}
		else {
			ageTransferAAC( pDBuf, AG_CG_ENEMY_FROGA3, 0, &w, &h );
		};

		if( flip == 0 ) {
			agDrawSPRITE( pDBuf, 1, (pTask->x - g_OffsetX - w/2)<<2 , (pTask->y - h)<<2 , (pTask->x - g_OffsetX + w/2)<<2, (pTask->y)<<2 );
		}
		else {
			agDrawSPRITE_UV( pDBuf, (pTask->x - g_OffsetX - w/2)<<2 , (pTask->y - h)<<2 , 0x1000 , 0 , (pTask->x - g_OffsetX + w/2)<<2, (pTask->y)<<2 , 0 , 0x1000 );
		};
	};
}

static s32 HitFrog( struct TaskData* pTask , const struct RECT* pRect ) {
  int w,h;
  struct RECT rect;

  w = 60;
  h = 60;

  rect.x0 = pTask->x - w/2;
  rect.y0 = pTask->y;
  rect.x1 = pTask->x + w/2;
  rect.y1 = pTask->y + h;

  return( IsHitRect( pRect , &rect ) );
}

void InitTaskFrog( struct TaskData* pTask , s32 x , s32 y , u16 Score , u8 Direction ) {
	memset( pTask , 0 , sizeof( *pTask ) );

	pTask->type = TASK_ENEMY;
	pTask->visible = 1;
	pTask->x = x;
	pTask->y = y;
	pTask->Calc = CalcFrog;
	pTask->Draw = DrawFrog;
	pTask->Data.frog.count = 0;
	pTask->Data.frog.sub_count = 0;
	pTask->Data.frog.score = Score;
	pTask->Data.frog.direction = Direction;
	pTask->Data.frog.mode = 0;
}
