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

static struct SStory {
  int n;
  int pages[5];
  int snds[5];
};

static struct SStory stories[] = {
  {2, {0, 1},     {AS_SND_B01, AS_SND_B02} },
  {2, {2, 1},     {AS_SND_B08, AS_SND_B02} },
  {2, {3, 1},     {AS_SND_B09, AS_SND_B02} },
  {3, {4, 5, 6},  {AS_SND_B10, AS_SND_A04, AS_SND_B11} },
};

static s32 CalcStory( struct TaskData* pTask , u32 Flag ) {

  //　ソフトリセット
  if( PadTrg()&PAD_UP && PadTrg()&PAD_DOWN ) {
    ageSndMgrRelease( pTask->Data.senario.bgm_handle );
    GotoMode( MODE_TITLE );
  };

  if ( pTask->Data.story.mode < stories[g_Stage].n ) {
    pTask->Data.story.count++;

    if (pTask->Data.story.count == 10) {
      // 前の台詞の再生を止める
      if ( pTask->Data.story.mode > 0 ) {
        ageSndMgrRelease( pTask->Data.story.voice_handle );
      }

      // 台詞を再生する
      if ( pTask->Data.story.mode < stories[g_Stage].n - 1) {
        pTask->Data.story.voice_handle = ageSndMgrAlloc( stories[g_Stage].snds[pTask->Data.story.mode] , 0 , 0 , AGE_SNDMGR_PANMODE_LR12 , 0 );

        ageSndMgrPlay( pTask->Data.story.voice_handle );
        ageSndMgrSetVolume( pTask->Data.story.voice_handle , 0xa0 );
        ageSndMgrSetPanMode( pTask->Data.story.voice_handle , 0 );
      } else {
        // 最後の台詞だけ、ageSndMgrPlayOneshot() で再生する。
        ageSndMgrPlayOneshot( stories[g_Stage].snds[pTask->Data.story.mode] , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
#ifdef DEBUG
        _dprintf( "最後のせりふ\n" );
#endif
      }
    }

    if ( pTask->Data.story.count == 50 ) {
      pTask->Data.story.pButtonTask->visible = TRUE;
    }

    if( PadTrg()&PAD_A || PadTrg()&PAD_B ) {
      pTask->Data.story.mode++;
      pTask->Data.story.count = 0;
      pTask->Data.story.pButtonTask->visible = FALSE;

      ageSndMgrPlayOneshot( AS_SND_DECIDE008 , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
    };
  } else {
    // スタートボタン後
    pTask->Data.story.count += 64;

    ageSndMgrSetVolume( pTask->Data.story.bgm_handle , 0xa0 - pTask->Data.story.count/32 );
    if( pTask->Data.story.count/32 >= 0xa0 ) {
      ageSndMgrRelease( pTask->Data.story.bgm_handle );
      ageSndMgrRelease( pTask->Data.story.voice_handle );

      if ( g_Stage == STAGE_N) {
        GotoMode( MODE_TITLE );
      } else {
        GotoMode( MODE_GAME );
      }
    };
  };

  return( 0 );
}

static void DrawMessage( struct TaskData* pTask , AGDrawBuffer* pDBuf, int frame, float t ) {
  int w,h;
  int x,y;

  agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
  ageTransferAAC_RM3( pDBuf, AG_RP_SIN_MESSAGE, 0, &w, &h, frame );

  w *= 0.8;
  h *= 0.8;

  x = (1024-w)/2;
  y = (768/2-h)/2 + 768 - 768/2 * ease_out(t);
  //y = (768/2-h)/2 + 768/2 * ease_out(t);

  agDrawSPRITE( pDBuf, 1, x<<2 , y<<2 , (x+w)<<2 , (y+h)<<2 );
}

static s32 DrawStory( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
  int w, h;
  int a;
  int x,y;
  float t;
  int daigorou_dx = 0;

  if( pTask->Data.story.mode == 0 ) {
    a = abs( (pTask->Data.story.count%256) - 128 ) + 127;
  }
  else {
    a = abs( (pTask->Data.story.count%510) - 255 );
  };

  if (g_Stage > 0) {
    // 集中線
    int a = abs( ((pTask->Data.story.count * 8)%256) - 128 ) + 127;
    int b = (pTask->Data.story.count / 10) % 2;
    agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
    ageTransferAAC( pDBuf, AG_CG_STORY_SHUCHU + b, 0, &w, &h );
    x = 280;
    y = 200;
    agPictureRotTex(pDBuf, AG_CG_STORY_SHUCHU + b, 
        x<<2, 
        y<<2, 
        (pTask->Data.story.count % 360)<<2, 
        0x100);
    //agDrawSPRITE( pDBuf, 1, x<<2 , y<<2 , (x+w)<<2 , (y+h)<<2 );
  }

  switch( g_Stage ) {
    case 0:
      // なし
      daigorou_dx = 0;
      break;

    case 1:
      // めろんぱん
      agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
      ageTransferAAC( pDBuf, AG_CG_ITEM_MERONPAN256, 0, &w, &h );
      x = 150;
      y = 100;
      agDrawSPRITE( pDBuf, 1, x<<2 , y<<2 , (x+w)<<2 , (y+h)<<2 );
      daigorou_dx = 150;
      break;

    case 2:
      // UNIXスーパーテキスト
      agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
      ageTransferAAC( pDBuf, AG_CG_ITEM_UNIXSP256, 0, &w, &h );
      x = 150 + 50;
      y = 100;
      agDrawSPRITE( pDBuf, 1, x<<2 , y<<2 , (x+w)<<2 , (y+h)<<2 );
      daigorou_dx = 150;
      break;

    case STAGE_N:
      // えりたん
      agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
      ageTransferAAC( pDBuf, AG_CG_STORY_ERITAN, 0, &w, &h );
      x = (1024-w)/2 - 330;
      y = (768-h)/2 + 20;
      agDrawSPRITE( pDBuf, 1, x<<2 , y<<2 , (x+w)<<2 , (y+h)<<2 );
      daigorou_dx = 220;
      break;
  }

  // 大五郎
  agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
  ageTransferAAC( pDBuf, AG_CG_STORY_DAIGOROU, 0, &w, &h );
  x = (1024-w)/2 + daigorou_dx;
  y = (768-h)/2 + 50;
  agDrawSPRITE( pDBuf, 1, x<<2 , y<<2 , (x+w)<<2 , (y+h)<<2 );

  if ( g_Stage < STAGE_N) {
    // えりたんを思い浮かべる雲
    agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
    ageTransferAAC( pDBuf, AG_CG_STORY_CLOUD_ERITAN, 0, &w, &h );
    x = x + 200;
    y = y - 100;
    agDrawSPRITE( pDBuf, 1, x<<2 , y<<2 , (x+w)<<2 , (y+h)<<2 );
  }

  if ( pTask->Data.story.mode < stories[g_Stage].n ) {
    // message
    t = pTask->Data.story.count / 50.0;
    DrawMessage( pTask, pDBuf, stories[g_Stage].pages[pTask->Data.story.mode], t );
  } else {
    // start
    DrawMessage( pTask, pDBuf, stories[g_Stage].pages[pTask->Data.story.mode - 1], 1.0 );
    {
      int at = pTask->Data.story.count / 64 * 255 / 80;

      agPictureSetBlendMode( pDBuf , 0 , at , 0 , 0 , 0 , 1 );
      agDrawSETFCOLOR( pDBuf , ARGB( 0xff , 0xff , 0xff , 0xff ) );
      agDrawSPRITE( pDBuf, 0, 0<<2 , 0<<2 , (1024)<<2 , (768)<<2 );
    };
  };

  g_OffsetX++;

  return( 0 );
}

void InitTaskStory( struct TaskData* pTask ) {
  struct TaskData* pBTask;
  memset( pTask , 0 , sizeof( *pTask ) );

  pTask->type = TASK_STORY;
  pTask->visible = 1;
  pTask->Calc = CalcStory;
  pTask->Draw = DrawStory;

  pTask->Data.story.mode = 0;
  pTask->Data.story.count = 0;

  pTask->Data.story.bgm_handle = ageSndMgrAlloc( AS_SND_TITLE_1 , 0 , 1 , AGE_SNDMGR_PANMODE_LR12 , 0 );
  pTask->Data.story.voice_handle = 0;

  pBTask = AllocTask();
  pTask->Data.story.pButtonTask = pBTask;
  pBTask->visible = FALSE;
  InitTaskStatic2( pBTask, 800, 650, AG_CG_STORY_A_BUTTON, Static2Type_Blink, 0 );
  AddlLink( pBTask , DISP_LEVEL_TOP );


  ageSndMgrPlay( pTask->Data.story.bgm_handle );
  ageSndMgrSetVolume( pTask->Data.story.bgm_handle , 0xa0 );
  ageSndMgrSetPanMode( pTask->Data.story.bgm_handle , 0 );
  ageSndMgrSetPan( pTask->Data.story.bgm_handle , 0x8080 );
}
