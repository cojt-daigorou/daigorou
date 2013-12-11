#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "randMT.h"
#include "export.h"
#include "global.h"
#include "rect.h"
#include "t_object.h"

/******************************************************************/
/*                         固定オブジェクト                       */
/******************************************************************/
static s32 CalcObject( struct TaskData* pTask , u32 Flag ) {

  switch( pTask->Data.object.motion ) {
    case ObjectMotion_None:
      break;
    case ObjectMotion_Horizon:
      pTask->Data.object.pre_x = pTask->x;
      pTask->x = pTask->Data.object.center_x + 100 * sinf(0.1 * (pTask->Data.object.count++));
      break;
    case ObjectMotion_Vertical:
      break;
  }

	return( 0 );
}

static s32 DrawObject( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
	int w,h;

	if( (pTask->x + 100) > g_OffsetX && (pTask->x - 100) < (g_OffsetX + 1024) ) {
		agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
		ageTransferAAC( pDBuf, pTask->Data.object.image, 0, &w, &h );

		agDrawSPRITE( pDBuf, 1,
				(pTask->x - w/2 - g_OffsetX)<<2 , (pTask->y - g_OffsetY)<<2 ,
				(pTask->x + w/2 - g_OffsetX)<<2, (pTask->y - g_OffsetY + h)<<2 );
	};
}

static s32 HitObject( struct TaskData* pTask , const struct RECT* pRect ) {
	int w,h;
	struct RECT rect;

	w = ageRM[ pTask->Data.object.image ].Width;
	h = ageRM[ pTask->Data.object.image ].Height;

	rect.x0 = pTask->x - w/2;
	rect.y0 = pTask->y;
	rect.x1 = pTask->x + w/2;
	rect.y1 = pTask->y + h;

	return( IsHitRect( pRect , &rect ) );
}

void InitTaskObject( struct TaskData* pTask , s32 x , s32 y , u16 image , u16 is_hit, enum ObjectMotion motion ) {
	memset( pTask , 0 , sizeof( *pTask ) );

	pTask->type = TASK_STATIC;
	pTask->visible = 1;
	pTask->x = x;
	pTask->y = y;
	pTask->Calc = CalcObject;
	pTask->Draw = DrawObject;
	if( is_hit != 0 ) {
		pTask->Hit = HitObject;
	};
	pTask->Data.object.image = image;
	pTask->Data.object.is_hit = is_hit;
  pTask->Data.object.motion = motion;
  pTask->Data.object.count = 0;
  pTask->Data.object.center_x = x;
  pTask->Data.object.pre_x = x;
}
