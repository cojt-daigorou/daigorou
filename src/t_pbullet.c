#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "export.h"
#include "global.h"

/******************************************************************/
/*                         Player Bullet                          */
/******************************************************************/
static s32 CalcPBullet( struct TaskData* pTask , u32 Flag ) {
	pTask->y += pTask->Data.pbullet.dy;
	pTask->x += pTask->Data.pbullet.dx;

	if( pTask->y < -32 ) {
		pTask->visible = 0;
		pTask->flag = TASK_FLAG_DESTROY;
	};

	return( 0 );
}

static s32 DrawPBullet( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
	int w, h;

	agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
	ageTransferAAC( pDBuf, pTask->Data.pbullet.image, 0, &w, &h );
	agDrawSPRITE( pDBuf, 1, pTask->x - (w<<1) , pTask->y - (h<<1) , pTask->x + (w<<1), pTask->y + (h<<1) );

	return( 0 );
}

void InitTaskPBullet( struct TaskData* pTask , s32 x , s32 y , u16 Image , s16 dx , s16 dy , u16 Count , u16 Pattern ) {
	memset( pTask , 0 , sizeof( *pTask ) );

	pTask->type = TASK_PBULLET;
	pTask->visible = 1;
	pTask->x = x;
	pTask->y = y;
	pTask->Calc = CalcPBullet;
	pTask->Draw = DrawPBullet;
	pTask->Data.pbullet.image = Image;
	pTask->Data.pbullet.dx = dx;
	pTask->Data.pbullet.dy = dy;
	pTask->Data.pbullet.count = Count;
	pTask->Data.pbullet.pattern = Pattern;
}
