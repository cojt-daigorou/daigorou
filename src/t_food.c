#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "randMT.h"
#include "export.h"
#include "global.h"
#include "t_food.h"

/******************************************************************/
/*                              H‚×•¨                            */
/******************************************************************/
static s32 CalcFood( struct TaskData* pTask , u32 Flag ) {
	return( 0 );
}

static s32 DrawFood( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
	int w, h;

	if( (pTask->x + 50) > g_OffsetX && (pTask->x - 50) < (g_OffsetX + 1024) ) {
		agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
		ageTransferAAC( pDBuf, pTask->Data.food.image, 0, &w, &h );

		agDrawSPRITE( pDBuf, 1,
				(pTask->x - g_OffsetX - w/2)<<2 , (pTask->y - g_OffsetY - h)<<2 ,
				(pTask->x - g_OffsetX + w/2)<<2 , (pTask->y - g_OffsetY)<<2 );
	};
}

void InitTaskFood( struct TaskData* pTask , s32 x , s32 y , u16 Image , u16 erase_time , u16 Score ) {
	memset( pTask , 0 , sizeof( *pTask ) );

	pTask->type = TASK_FOOD;
	pTask->visible = 1;
	pTask->x = x;
	pTask->y = y;
	pTask->Calc = CalcFood;
	pTask->Draw = DrawFood;
	pTask->Data.food.count = 0;
	pTask->Data.food.image = Image;
	pTask->Data.food.erase_time = erase_time;
	pTask->Data.food.score = Score;
}
