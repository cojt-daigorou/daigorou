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

/******************************************************************/
/*                              ������                            */
/******************************************************************/
static s32 CalcFrog( struct TaskData* pTask , u32 Flag ) {
	switch( pTask->Data.frog.mode ) {
		default :
		case 0 :		//�@�ʏ�ҋ@���
			pTask->Data.frog.count++;
			if( pTask->Data.frog.count > 60 ) {
				pTask->Data.frog.count = 0;
				pTask->Data.frog.mode = 1;		//�@�W�����v���
			};
			break;

		case 1 :		//�@�W�����v���
			if( pTask->Data.frog.direction == 0 ) {		//�@������
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

		case 2 :		//�@�ׂ���
			pTask->Data.frog.count++;
			if( pTask->Data.frog.count > 30 ) {
				pTask->Data.frog.count = 0;
				pTask->Data.frog.mode = 0;		//�@�ʏ���

					//�@�O���񂾂甽�Ό���
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
