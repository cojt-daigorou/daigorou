#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "randMT.h"
#include "export.h"
#include "global.h"
#include "t_static2.h"

/******************************************************************/
/*                              static2                           */
/******************************************************************/
static s32 CalcStatic2( struct TaskData* pTask , u32 Flag ) {
	return( 0 );
}

static s32 DrawStatic2( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
	int w, h;
  int alpha = 0xff;
  int dx = 0, dy = 0;
  float t;
  int yy = 400 << 2;
  int xx = 600 << 2;

  pTask->Data.st2.count++;

  switch ( pTask->Data.st2.type ) {
    case Static2Type_Blink:
      alpha = 0xff * 0.5 * ( 1.0 + sinf( 0.2 * pTask->Data.st2.count ) );
      break;

    case Static2Type_MoveHorizon:
      t = max( pTask->Data.st2.count - pTask->Data.st2.delay, 0 ) / 50.0;
      dx = xx - xx * ease_out( t );
      break;

    case Static2Type_MoveVertical:
      t = max( pTask->Data.st2.count - pTask->Data.st2.delay, 0 ) / 50.0;
      dy = yy - yy * ease_out( t );
      break;
  }

	agPictureSetBlendMode( pDBuf , 0 , alpha , 0 , 0 , 2 , 1 );
	ageTransferAAC( pDBuf, pTask->Data.st2.image, 0, &w, &h );
	agDrawSPRITE( pDBuf, 1, pTask->x - dx, pTask->y - dy, pTask->x + (w<<2) - dx, pTask->y + (h<<2) - dy );

	return( 0 );
}

void InitTaskStatic2( struct TaskData* pTask, s32 x, s32 y, u16 Image, u16 Type, u32 Delay ) {
	memset( pTask , 0 , sizeof( *pTask ) );

	pTask->type = TASK_STATIC;
	pTask->visible = 1;
	pTask->x = x<<2;
	pTask->y = y<<2;
	pTask->Calc = CalcStatic2;
	pTask->Draw = DrawStatic2;
	pTask->Data.st2.image = Image;
	pTask->Data.st2.type = Type;
	pTask->Data.st2.count = 0;
	pTask->Data.st2.delay = Delay;
}
