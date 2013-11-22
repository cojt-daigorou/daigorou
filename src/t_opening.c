#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "randMT.h"
#include "export.h"
#include "global.h"

/******************************************************************/
/*                          ƒ^ƒCƒgƒ‹‰æ–Ê                          */
/******************************************************************/
static s32 CalcOpening( struct TaskData* pTask , u32 Flag ) {
	if( pTask->Data.title.mode == 0 ) {
		pTask->Data.title.count++;

		if( PadTrg()&PAD_A || PadTrg()&PAD_B || (PadTrg()&PAD_LEFT && PadTrg()&PAD_RIGHT) ) {
			pTask->Data.title.mode = 1;
			pTask->Data.title.count = 0;

			ageSndMgrPlayOneshot( AS_SND_DECIDE008 , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
		};
	}
	else {
		pTask->Data.title.count += 64;

		ageSndMgrSetVolume( pTask->Data.title.bgm_handle , 0xa0 - pTask->Data.title.count/32 );
		if( pTask->Data.title.count/32 >= 0xa0 ) {
			ageSndMgrRelease( pTask->Data.title.bgm_handle );

			GotoMode( MODE_GAME );
		};
	};

	return( 0 );
}

static s32 DrawOpening( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
	int w, h;
	int a;
	int x,y;

	if( pTask->Data.title.mode == 0 ) {
		a = abs( (pTask->Data.title.count%256) - 128 ) + 127;
	}
	else {
		a = abs( (pTask->Data.title.count%510) - 255 );
	};

	agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
	ageTransferAAC( pDBuf, AG_CG_TITLE, 0, &w, &h );

	x = (1024-w)/2;
	y = (768*3/4-h)/2;

	agDrawSPRITE( pDBuf, 1, x<<2 , y<<2 , (x+w)<<2 , (y+h)<<2 );

	agPictureSetBlendMode( pDBuf , 0 , a , 0 , 0 , 2 , 1 );
	ageTransferAAC( pDBuf, AG_CG_GAMESTART, 0, &w, &h );

	x = (1024-w)/2;
	y = (768/2-h)/2 + 768/2;

	agDrawSPRITE( pDBuf, 1, x<<2 , y<<2 , (x+w)<<2 , (y+h)<<2 );

	if( pTask->Data.title.mode == 1 ) {
		int at = pTask->Data.title.count / 64 * 255 / 80;

		agPictureSetBlendMode( pDBuf , 0 , at , 0 , 0 , 0 , 1 );
		agDrawSETFCOLOR( pDBuf , ARGB( 0xff , 0xff , 0xff , 0xff ) );
		agDrawSPRITE( pDBuf, 0, 0<<2 , 0<<2 , (1024)<<2 , (768)<<2 );
	};

	g_OffsetX++;

	return( 0 );
}

void InitTaskOpening( struct TaskData* pTask ) {
	memset( pTask , 0 , sizeof( *pTask ) );

	pTask->type = TASK_OPENING;
	pTask->visible = 1;
	pTask->Calc = CalcOpening;
	pTask->Draw = DrawOpening;
	pTask->Data.title.count = 0;
	pTask->Data.title.mode = 0;

	pTask->Data.title.bgm_handle = ageSndMgrAlloc( AS_SND_TITLE , 0 , 1 , AGE_SNDMGR_PANMODE_LR12 , 0 );

	ageSndMgrPlay( pTask->Data.title.bgm_handle );
	ageSndMgrSetVolume( pTask->Data.title.bgm_handle , 0xa0 );
	ageSndMgrSetPanMode( pTask->Data.title.bgm_handle , 0 );
	ageSndMgrSetPan( pTask->Data.title.bgm_handle , 0x8080 );
}
