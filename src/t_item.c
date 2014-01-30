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
/*                              食べ物                            */
/******************************************************************/
static s32 CalcItem( struct TaskData* pTask , u32 Flag ) {
	return( 0 );
}

static s32 DrawItem( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
	int w, h;

  pTask->Data.item.count++;

	if( (pTask->x + 50) > g_OffsetX && (pTask->x - 50) < (g_OffsetX + 1024) ) {

    // キーアイテムなら、集中線を表示する。
    if ( pTask->Data.item.is_keyitem ) {
      // 集中線
      int a = abs( ((pTask->Data.item.count * 8)%256) - 128 ) + 127;
      int b = (pTask->Data.item.count / 10) % 2;
      int ih = ageRM[ pTask->Data.object.image ].Height;
      agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
      ageTransferAAC( pDBuf, AG_CG_STORY_SHUCHU + b, 0, &w, &h );
      agPictureRotTex(pDBuf, AG_CG_STORY_SHUCHU + b, 
          (pTask->x - g_OffsetX)<<2, 
          (pTask->y - g_OffsetY - ih/2 )<<2, 
          (pTask->Data.item.count % 360)<<2, 
          0x100/2);
    }

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
