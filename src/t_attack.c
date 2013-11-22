#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "export.h"
#include "global.h"

/******************************************************************/
/*                            Attack                              */
/******************************************************************/
static s32 CalcAttack( struct TaskData* pTask , u32 Flag ) {
	pTask->Data.attack.count++;

	if( pTask->Data.attack.count >= 20 ) {
		pTask->visible = 0;
		pTask->flag = TASK_FLAG_DESTROY;
	};

	return( 0 );
}

static s32 DrawAttack( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
	int w, h;
	int x , y;

	x = (pTask->x - g_OffsetX)<<2;
	y = (pTask->y - g_OffsetY)<<2;

	agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
	if( pTask->Data.attack.count < 10 ) {
		ageTransferAAC( pDBuf, AG_CG_EFFECT_DMG1, 0, &w, &h );
	}
	else {
		ageTransferAAC( pDBuf, AG_CG_EFFECT_DMG2, 0, &w, &h );
	};
	agDrawSPRITE( pDBuf, 1 , x - (w<<1) , y - (h<<2) , x + (w<<1), y );

	return( 0 );
}

void InitTaskAttack( struct TaskData* pTask , s32 x , s32 y ) {
	memset( pTask , 0 , sizeof( *pTask ) );

	pTask->type = TASK_EFFECT;
	pTask->visible = 1;
	pTask->x = x;
	pTask->y = y;
	pTask->Calc = CalcAttack;
	pTask->Draw = DrawAttack;
	pTask->Data.attack.count = 0;
}
