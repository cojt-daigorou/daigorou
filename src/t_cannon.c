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
/*                              ������                            */
/******************************************************************/
static s32 CalcCannon( struct TaskData* pTask , u32 Flag ) {
  switch( pTask->Data.cannon.mode ) {
    default :
    case 0 :		//�@�ʏ�ҋ@���
      pTask->Data.cannon.count++;
      if( pTask->Data.cannon.count > 60 ) {
        pTask->Data.cannon.count = 0;
        pTask->Data.cannon.mode = 1;		//�@�W�����v���

        if (FALSE) {	//�e����
          int x , y;
          x = pTask->x;
          y = pTask->y;

          if( pTask->Data.cannon.direction == 0 ) {
            x += 60;
          }
          else {
            x -= 60;
          };

          {
            struct TaskData* pBTask;
            int dx = ( pTask->Data.cannon.direction == 0 ) ? -20 : 20;
            pBTask = AllocTask();
            if (pBTask != NULL) {
              InitTaskEBullet( pBTask , x, y, AG_RP_OBJ_EBULLET, dx,0, 0,0 );
              AddlLink( pBTask , DISP_LEVEL_EBULLET );
            };
          };
        };
      };
      break;

		case 1 :		//�@�W�����v���
			if( pTask->Data.cannon.direction == 0 ) {		//�@������
				pTask->x -= 3;
			}
			else {
				pTask->x += 3;
			};

			if( pTask->Data.cannon.count < 10 ) {
				pTask->y -= 5;
			}
			else {
				pTask->y += 5;
			};

			pTask->Data.cannon.count++;
			if( pTask->Data.cannon.count >= 20 ) {
				pTask->Data.cannon.count = 0;
				pTask->Data.cannon.mode = 2;
			};
			break;

		case 2 :		//�@�ׂ���
			pTask->Data.cannon.count++;
			if( pTask->Data.cannon.count > 30 ) {
				pTask->Data.cannon.count = 0;
				pTask->Data.cannon.mode = 0;		//�@�ʏ���

					//�@�O���񂾂甽�Ό���
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


  // ���@�̒e�̔���
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

          pTask->visible = 0;
          pTask->flag = TASK_FLAG_DESTROY;

          AddScore( pTask->Data.cannon.score );

          pBTask->visible = 0;
          pBTask->flag = TASK_FLAG_DESTROY;
          break;
        }
      }

      pBTask = pBTask->Next;
    }
  }

  // ���@�Ƃ̔���
  if ( (pTask->x - g_PlayerX) * (pTask->x - g_PlayerX) + (pTask->y - g_PlayerY - 100) * (pTask->y - g_PlayerY - 100 ) < 40*40) {
  //if ( g_pPlayerRect != NULL && HitCannon(pTask, g_pPlayerRect) ) {
    KillPlayer( g_pPlayerTask );
  }

	return( 0 );
}

static s32 DrawCannon( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
	int w, h;
	int a = 255;

	if( (pTask->x + 50) > g_OffsetX && (pTask->x - 50) < (g_OffsetX + 1024) ) {
		u8 flip = 0;

		if( pTask->Data.cannon.direction == 1 ) {
			flip = 1;
		};

		agPictureSetBlendMode( pDBuf , 0 , a , 0 , 0 , 2 , 1 );

		if( pTask->Data.cannon.mode == 0 ) {
			ageTransferAAC( pDBuf, AG_CG_OBJ_CANNON, 0, &w, &h );
		}
		else if( pTask->Data.cannon.mode == 1 ) {
			ageTransferAAC( pDBuf, AG_CG_OBJ_CANNON, 0, &w, &h );
		}
		else {
			ageTransferAAC( pDBuf, AG_CG_OBJ_CANNON, 0, &w, &h );
		};

		if( flip == 0 ) {
			agDrawSPRITE( pDBuf, 1, (pTask->x - g_OffsetX - w/2)<<2 , (pTask->y - h)<<2 , (pTask->x - g_OffsetX + w/2)<<2, (pTask->y)<<2 );
		}
		else {
			agDrawSPRITE_UV( pDBuf, (pTask->x - g_OffsetX - w/2)<<2 , (pTask->y - h)<<2 , 0x1000 , 0 , (pTask->x - g_OffsetX + w/2)<<2, (pTask->y)<<2 , 0 , 0x1000 );
		};
	};
}

static s32 HitCannon( struct TaskData* pTask , const struct RECT* pRect ) {
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