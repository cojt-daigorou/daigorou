#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "randMT.h"
#include "export.h"
#include "global.h"
#include "t_item.h"

/******************************************************************/
/*                              H‚×•¨                            */
/******************************************************************/
static s32 CalcItem( struct TaskData* pTask , u32 Flag ) {
	return( 0 );
}

static s32 DrawItem( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
	int w, h;

	if( (pTask->x + 50) > g_OffsetX && (pTask->x - 50) < (g_OffsetX + 1024) ) {
		agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
		ageTransferAAC( pDBuf, pTask->Data.item.image, 0, &w, &h );

		agDrawSPRITE( pDBuf, 1,
				(pTask->x - g_OffsetX - w/2)<<2 , (pTask->y - g_OffsetY - h)<<2 ,
				(pTask->x - g_OffsetX + w/2)<<2 , (pTask->y - g_OffsetY)<<2 );
	};
}

void InitTaskItem( struct TaskData* pTask, s32 x, s32 y, u16 Image, u16 score, u16 star, u16 time, u16 is_keyitem) {
	memset( pTask , 0 , sizeof( *pTask ) );

	pTask->type = TASK_ITEM;
	pTask->visible = 1;
	pTask->x = x;
	pTask->y = y;
	pTask->Calc = CalcItem;
	pTask->Draw = DrawItem;

	pTask->Data.item.image = Image;
	pTask->Data.item.count = 0;

  pTask->Data.item.score = score;
  pTask->Data.item.star = star;
  pTask->Data.item.time = time;
  pTask->Data.item.is_keyitem = is_keyitem;
}
