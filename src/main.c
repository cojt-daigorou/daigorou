#include <amlib.h>
#include <agdraw.h>
#include <agetool.h>
#include <agtransfer.h>
#include <agesndmgr.h>
#include <vdpreg.h>
#include "pad.h"
#include "task.h"
#include "mode.h"
#include "work.h"
#include "export.h"

u32 DrawBuffer[ 4096 ];

AGESoundManagerData SndMgrData;

void  main( void ) {
	int cnt = 0;
	AGDrawBuffer DBuf;
	struct TaskData* pTask;
	int i;

	agpDisableCpuInterrupts();
	aglInitialize();
	agpEnableCpuInterrupts();

	ageSndMgrInit( &SndMgrData , AGE_SOUND_ROM_OFFSET );

	//	マスターボリューム設定
	for( i=0 ; i<AG_SND_MAX_MASTERVOLUME ; i++ ) {
		ageSndMgrSetMasterVolume( i , 0x94 );
	};

	//	チャンネルボリューム設定
	for( i=0 ; i<AG_SND_MAX_CHANNEL ; i++ ) {
		ageSndMgrSetChannelVolume( i , 0xc0 );
	};

	InitWorkMeter( FB_WIDTH , FB_HEIGHT , 1 );

	PadInit();
	ClearAllTask();

	GotoMode( MODE_TITLE );

	while( 1 ) {
		int w, h;

		ageSndMgrRun();
		PadRun();

		CalcTask( 0 );

		ClearWorkMeter();

		// ディスプレイリストの作成
		agDrawBufferInit( &DBuf , DrawBuffer );

		// VRAM設定
		agDrawSETDAVR( &DBuf , 0 , 0 , aglGetDrawFrame() , 0 , 0 );
		agDrawSETDAVF( &DBuf, 0, 0, FB_WIDTH<<2, FB_HEIGHT<<2 );

			//　タスク描画
		DrawTaskAll( &DBuf );

		// ディスプレイリスト生成終了
		agDrawEODL( &DBuf );

		SetWorkMeter( ARGB( 255 , 255 , 0 , 0 ) );

		// ディスプレイリストを転送して描画終了を待つ
		agTransferDrawDMA( &DBuf );

		SetWorkMeter( ARGB( 255 , 0 , 255 , 0 ) );

					//　ワークメーター描画
		agDrawBufferInit( &DBuf , DrawBuffer );

		agDrawSETDAVR( &DBuf , 0 , 0 , aglGetDrawFrame() , 0 , 0 );
		agDrawSETDAVF( &DBuf , 0 , 0 , FB_WIDTH<<2 , FB_HEIGHT<<2 );

		DrawWorkMeter( &DBuf );
		agDrawEODL( &DBuf );

		agTransferDrawDMA( &DBuf );

		cnt++;

		aglWaitVSync();
		aglSwap();
	};
}
