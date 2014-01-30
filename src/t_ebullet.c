#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "export.h"
#include "global.h"

/******************************************************************/
/*                         Enemy Bullet                          */
/******************************************************************/
static s32 CalcEBullet( struct TaskData* pTask , u32 Flag ) {

  pTask->Data.ebullet.count++;

	pTask->y += pTask->Data.ebullet.dy;
	pTask->x += pTask->Data.ebullet.dx;
  if( pTask->Data.ebullet.count> 80){
    pTask->Data.ebullet.dy += 1;
  }
	if( pTask->Data.ebullet.count > 100 ) {
		pTask->visible = 0;
		pTask->flag = TASK_FLAG_DESTROY;
	};

	if ( (pTask->x - g_PlayerX) * (pTask->x - g_PlayerX) + (pTask->y - g_PlayerY - 32 ) * (pTask->y - g_PlayerY - 32 ) < 40*40) {
		//if ( g_pPlayerRect != NULL && HitFrog(pTask, g_pPlayerRect) ) {
    KillPlayer( g_pPlayerTask );
  }

	return( 0 );
}

static s32 DrawEBullet( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
	int w, h;

	if( (pTask->x + 50) > g_OffsetX && (pTask->x - 50) < (g_OffsetX + 1024) ) {
		agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
		//ageTransferAAC( pDBuf, pTask->Data.ebullet.image, 0, &w, &h );
    ageTransferAAC_RM3( pDBuf, pTask->Data.ebullet.image , 0, &w, &h , (pTask->Data.ebullet.count>>1) % (ageRM3[pTask->Data.ebullet.image].Frames) );

		agDrawSPRITE( pDBuf, 1,
				(pTask->x - g_OffsetX - w/2)<<2 , (pTask->y - g_OffsetY - h)<<2 ,
				(pTask->x - g_OffsetX + w/2)<<2 , (pTask->y - g_OffsetY)<<2 );
	};

	return( 0 );
}

void InitTaskEBullet( struct TaskData* pTask , s32 x , s32 y , u16 Image , s16 dx , s16 dy , u16 Count , u16 Pattern ) {
	memset( pTask , 0 , sizeof( *pTask ) );

	pTask->type = TASK_EBULLET;
	pTask->visible = 1;
	pTask->x = x;
	pTask->y = y;
	pTask->Calc = CalcEBullet;
	pTask->Draw = DrawEBullet;
	pTask->Data.ebullet.image = Image;
	pTask->Data.ebullet.dx = dx;
	pTask->Data.ebullet.dy = dy;
	pTask->Data.ebullet.count = Count;
	pTask->Data.ebullet.pattern = Pattern;
}
