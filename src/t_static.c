#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "randMT.h"
#include "export.h"
#include "global.h"
#include "t_static.h"

/******************************************************************/
/*                              static                            */
/******************************************************************/
static s32 CalcStatic( struct TaskData* pTask , u32 Flag ) {
	return( 0 );
}

static s32 DrawStatic( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
	int w, h;

	agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
	ageTransferAAC( pDBuf, pTask->Data.st.image, 0, &w, &h );
	agDrawSPRITE( pDBuf, 1, pTask->x , pTask->y , pTask->x + (w<<2), pTask->y + (h<<2) );

	return( 0 );
}

void InitTaskStatic( struct TaskData* pTask , s32 x , s32 y , u16 Image , u8 AlphaFlag ) {
	memset( pTask , 0 , sizeof( *pTask ) );

	pTask->type = TASK_STATIC;
	pTask->visible = 1;
	pTask->x = x<<2;
	pTask->y = y<<2;
	pTask->Calc = CalcStatic;
	pTask->Draw = DrawStatic;
	pTask->Data.st.image = Image;
	pTask->Data.st.alpha_flag = AlphaFlag;
}
