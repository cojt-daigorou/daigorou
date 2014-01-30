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
#include "global.h"

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

  //	�}�X�^�[�{�����[���ݒ�
  for( i=0 ; i<AG_SND_MAX_MASTERVOLUME ; i++ ) {
    ageSndMgrSetMasterVolume( i , 0x94 );
  };

  //	�`�����l���{�����[���ݒ�
  for( i=0 ; i<AG_SND_MAX_CHANNEL ; i++ ) {
    ageSndMgrSetChannelVolume( i , 0xc0 );
  };

#ifdef IS_DEBUG
  InitWorkMeter( FB_WIDTH , FB_HEIGHT , 1 );
#endif

  PadInit();
  ClearAllTask();

  GotoMode( MODE_TITLE );

  while( 1 ) {
    int w, h;

    ageSndMgrRun();
    PadRun();

    CalcTask( 0 );

#ifdef IS_DEBUG
    ClearWorkMeter();
#endif

    // �f�B�X�v���C���X�g�̍쐬
    agDrawBufferInit( &DBuf , DrawBuffer );

    // VRAM�ݒ�
    agDrawSETDAVR( &DBuf , 0 , 0 , aglGetDrawFrame() , 0 , 0 );
    agDrawSETDAVF( &DBuf, 0, 0, FB_WIDTH<<2, FB_HEIGHT<<2 );

    //�@�^�X�N�`��
    DrawTaskAll( &DBuf );

    // �f�B�X�v���C���X�g�����I��
    agDrawEODL( &DBuf );

#ifdef IS_DEBUG
    SetWorkMeter( ARGB( 255 , 255 , 0 , 0 ) );
#endif

    // �f�B�X�v���C���X�g��]�����ĕ`��I����҂�
    agTransferDrawDMA( &DBuf );

#ifdef IS_DEBUG
    SetWorkMeter( ARGB( 255 , 0 , 255 , 0 ) );
#endif

    //�@���[�N���[�^�[�`��
    agDrawBufferInit( &DBuf , DrawBuffer );

    agDrawSETDAVR( &DBuf , 0 , 0 , aglGetDrawFrame() , 0 , 0 );
    agDrawSETDAVF( &DBuf , 0 , 0 , FB_WIDTH<<2 , FB_HEIGHT<<2 );

#ifdef IS_DEBUG
    DrawWorkMeter( &DBuf );
#endif
    agDrawEODL( &DBuf );

    agTransferDrawDMA( &DBuf );

    cnt++;

    aglWaitVSync();
    aglSwap();
  };
}
