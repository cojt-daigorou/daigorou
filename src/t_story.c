#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "randMT.h"
#include "export.h"
#include "global.h"
#include "t_story.h"

/******************************************************************/
/*                              story                             */
/******************************************************************/
static s32 CalcStory( struct TaskData* pTask , u32 Flag ) {
	if( pTask->Data.story.mode == 0 ) {
		pTask->Data.story.count++;

		if( PadTrg()&PAD_A || PadTrg()&PAD_B || (PadTrg()&PAD_LEFT && PadTrg()&PAD_RIGHT) ) {
			pTask->Data.story.mode = 1;
			pTask->Data.story.count = 0;

			ageSndMgrPlayOneshot( AS_SND_DECIDE008 , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
		};
	}
	else {
		pTask->Data.story.count += 64;

		ageSndMgrSetVolume( pTask->Data.story.bgm_handle , 0xa0 - pTask->Data.story.count/32 );
		if( pTask->Data.story.count/32 >= 0xa0 ) {
			ageSndMgrRelease( pTask->Data.story.bgm_handle );

			GotoMode( MODE_GAME );
		};
	};

	return( 0 );
}

static s32 DrawStory( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
	int w, h;
	int a;
	int x,y;

	if( pTask->Data.story.mode == 0 ) {
		a = abs( (pTask->Data.story.count%256) - 128 ) + 127;
	}
	else {
		a = abs( (pTask->Data.story.count%510) - 255 );
	};

	agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
	ageTransferAAC( pDBuf, AG_CG_GAMECLEAR, 0, &w, &h );

	x = (1024-w)/2;
	y = (768*3/4-h)/2;

	agDrawSPRITE( pDBuf, 1, x<<2 , y<<2 , (x+w)<<2 , (y+h)<<2 );

	agPictureSetBlendMode( pDBuf , 0 , a , 0 , 0 , 2 , 1 );
	ageTransferAAC( pDBuf, AG_CG_GAMESTART, 0, &w, &h );

	x = (1024-w)/2;
	y = (768/2-h)/2 + 768/2;

	agDrawSPRITE( pDBuf, 1, x<<2 , y<<2 , (x+w)<<2 , (y+h)<<2 );

	if( pTask->Data.story.mode == 1 ) {
		int at = pTask->Data.story.count / 64 * 255 / 80;

		agPictureSetBlendMode( pDBuf , 0 , at , 0 , 0 , 0 , 1 );
		agDrawSETFCOLOR( pDBuf , ARGB( 0xff , 0xff , 0xff , 0xff ) );
		agDrawSPRITE( pDBuf, 0, 0<<2 , 0<<2 , (1024)<<2 , (768)<<2 );
	};

	g_OffsetX++;


	return( 0 );
}

void InitTaskStory( struct TaskData* pTask ) {
	memset( pTask , 0 , sizeof( *pTask ) );

	pTask->type = TASK_STORY;
	pTask->visible = 1;
	pTask->Calc = CalcStory;
	pTask->Draw = DrawStory;

	pTask->Data.story.mode = 0;
	pTask->Data.story.count = 0;

	pTask->Data.story.bgm_handle = ageSndMgrAlloc( AS_SND_TITLE , 0 , 1 , AGE_SNDMGR_PANMODE_LR12 , 0 );

	ageSndMgrPlay( pTask->Data.story.bgm_handle );
	ageSndMgrSetVolume( pTask->Data.story.bgm_handle , 0xa0 );
	ageSndMgrSetPanMode( pTask->Data.story.bgm_handle , 0 );
	ageSndMgrSetPan( pTask->Data.story.bgm_handle , 0x8080 );
}
