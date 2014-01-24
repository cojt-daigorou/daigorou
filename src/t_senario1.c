#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "randMT.h"
#include "export.h"
#include "global.h"
#include "t_senario1.h"

/******************************************************************/
/*                          シナリオ１                            */
/******************************************************************/
static struct SPos {
  int x, y;
  int type;
  int image;
};

enum {
  OBJECT_TYPE_HIT = 0 ,
  OBJECT_TYPE_NOHIT   ,
  OBJECT_TYPE_FRONT	  ,
  OBJECT_TYPE_HIT_H1  ,
  OBJECT_TYPE_HIT_V1  ,
  OBJECT_TYPE_HIT_H2  ,
  OBJECT_TYPE_HIT_V2  ,
  OBJECT_TYPE_TOGE	  ,
  OBJECT_TYPE_TOGE_H1 ,
  OBJECT_TYPE_TOGE_V1 ,
  OBJECT_TYPE_TOGE_H2 ,
  OBJECT_TYPE_TOGE_V2 ,
};

enum {
  ENEMY_TYPE_FROG = 0 ,
  ENEMY_TYPE_SNAKE    ,
};

enum {
  ITEM_TYPE_A = 0 ,
  ITEM_TYPE_B     ,
  ITEM_TYPE_C     ,
  ITEM_TYPE_KEY
};


//----------------------------------------------------------
// stage 1
//----------------------------------------------------------

static struct SPos wpos_1[] = {
  { 150 , 419 , OBJECT_TYPE_FRONT , AG_CG_OBJ_GRASS },

  //{ 1000 , 605      , OBJECT_TYPE_HIT , AG_CG_OBJ_TAKE4 },
  //{ 1000 , 605-64   , OBJECT_TYPE_HIT , AG_CG_OBJ_TAKE3 },
  //{ 1000 , 605-64*2 , OBJECT_TYPE_HIT , AG_CG_OBJ_TAKE2 },
  //{ 1000 , 605-64*3 , OBJECT_TYPE_HIT , AG_CG_OBJ_TAKE1 },

  //{ 1800 , 605      , OBJECT_TYPE_HIT , AG_CG_OBJ_TAKE4 },
  //{ 1800 , 605-64   , OBJECT_TYPE_HIT , AG_CG_OBJ_TAKE3 },
  //{ 1800 , 605-64*2 , OBJECT_TYPE_HIT , AG_CG_OBJ_TAKE2 },
  //{ 1800 , 605-64*3 , OBJECT_TYPE_HIT , AG_CG_OBJ_TAKE1 },
  
  { 800 , 500 , OBJECT_TYPE_HIT_H1 , AG_CG_OBJ_LIFT },

  { 1024, 541, OBJECT_TYPE_HIT , AG_CG_OBJ_BLOCK },
  { 1024+128, GROUND_LINE - 32, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE },

  { 2800+400*0 , 500 , OBJECT_TYPE_HIT_H1 , AG_CG_OBJ_LIFT },
  { 2800+400*1 , 400 , OBJECT_TYPE_HIT_H2 , AG_CG_OBJ_LIFT },
  { 2800+400*2 , 300 , OBJECT_TYPE_HIT_H1 , AG_CG_OBJ_LIFT },
  { 2800+400*3 , 200 , OBJECT_TYPE_HIT_H2 , AG_CG_OBJ_LIFT },
  { 2800+400*4 , 100 , OBJECT_TYPE_HIT_H1 , AG_CG_OBJ_LIFT },
  { 2800+400*5 , 000 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_LIFT },

};

static struct SPos ipos_1[] = {
  { 1400 , GROUND_LINE , ITEM_TYPE_A , 0 },
  { 2400 , GROUND_LINE , ITEM_TYPE_B , 0 },
  { 2800 , 500 , ITEM_TYPE_C , 0 },
  { 3600 , 100 , ITEM_TYPE_A , 0 },
  { 6200 , GROUND_LINE , ITEM_TYPE_B , 0 },
  { 6500 , GROUND_LINE , ITEM_TYPE_C , 0 },
  { 2800+400*5, 0, ITEM_TYPE_KEY, AG_CG_ITEM_MERONPAN64 },
  { 400, GROUND_LINE, ITEM_TYPE_KEY, AG_CG_ITEM_MERONPAN64 },
};

static struct SPos epos_1[] = {
  //{ 420  , 674 , ENEMY_TYPE_FROG  , 300 },
  //{ 820+300*2  , 674 , ENEMY_TYPE_FROG  , 300 },
  //{ 820+600*2  , 674 , ENEMY_TYPE_FROG  , 300 },
  { 1800 , 416 , ENEMY_TYPE_SNAKE , 300 },
};


//----------------------------------------------------------
// stage 2
//----------------------------------------------------------

static struct SPos wpos_2[] = {
  { 2800+400*0 , 500 , OBJECT_TYPE_HIT_H1 , AG_CG_OBJ_LIFT },
};

static struct SPos ipos_2[] = {
  { 800+100*0 , GROUND_LINE , ITEM_TYPE_A , 0 },
  { 800+100*1 , GROUND_LINE , ITEM_TYPE_B , 0 },
  { 800+100*2 , GROUND_LINE , ITEM_TYPE_C , 0 },
  { 800+100*3 , GROUND_LINE , ITEM_TYPE_KEY , AG_CG_ITEM_UNIXSP64 },
};

static struct SPos epos_2[] = {
  { 820  , 674 , ENEMY_TYPE_FROG  , 300 },
};


//----------------------------------------------------------
// stage 3
//----------------------------------------------------------

static struct SPos wpos_3[] = {
  { 2800+400*0 , 500 , OBJECT_TYPE_HIT_H1 , AG_CG_OBJ_LIFT },

  // えりたん
  { 800+100*3 , GROUND_LINE-128 , OBJECT_TYPE_FRONT , AG_CG_ITEM_ERITAN },
};

static struct SPos ipos_3[] = {
  { 800+100*0 , GROUND_LINE , ITEM_TYPE_A , 0 },
  { 800+100*1 , GROUND_LINE , ITEM_TYPE_B , 0 },
  { 800+100*2 , GROUND_LINE , ITEM_TYPE_C , 0 },
  { 800+100*3 , GROUND_LINE , ITEM_TYPE_KEY , AG_CG_ITEM_ERITAN },
};

static struct SPos epos_3[] = {
  { 820  , 674 , ENEMY_TYPE_FROG  , 300 },
};



static s32 CalcSenario1( struct TaskData* pTask , u32 Flag ) {
  pTask->x++;

  //　ソフトリセット
  if( PadTrg()&PAD_UP && PadTrg()&PAD_DOWN ) {
    ageSndMgrRelease( pTask->Data.senario.bgm_handle );
    GotoMode( MODE_TITLE );
  };

  if( g_isGameOver ) {
    pTask->x++;
    if( pTask->x > 800 ) {
      ageSndMgrRelease( pTask->Data.senario.bgm_handle );
      GotoMode( MODE_TITLE );
    };
    return(0);
  };

  if ( g_isStageClear ) {
    pTask->x++;
    if( pTask->x > 800 ) {
      ageSndMgrRelease( pTask->Data.senario.bgm_handle );
      g_Stage++;
      GotoMode( MODE_STORY );
    }; 
    return(0);
  };

  if( g_Time > 0 && (pTask->x % 60) == 0 ) {
    g_Time--;

    if( g_Time == 30 ) {
      ageSndMgrRelease( pTask->Data.senario.bgm_handle );

      pTask->Data.senario.bgm_handle = ageSndMgrAlloc( AS_SND_BGM_FAST , 0 , 1 , AGE_SNDMGR_PANMODE_LR12 , 0 );

      ageSndMgrPlay( pTask->Data.senario.bgm_handle );
      ageSndMgrSetVolume( pTask->Data.senario.bgm_handle , 0xa0 );
      ageSndMgrSetPanMode( pTask->Data.senario.bgm_handle , 0 );
      ageSndMgrSetPan( pTask->Data.senario.bgm_handle , 0x8080 );
    };

    if( g_Time == 0) {
      struct TaskData* pETask;
      int w,h;

      w = ageRM[ AG_CG_GAMEOVER ].Width;
      h = ageRM[ AG_CG_GAMEOVER ].Height;

      pETask = AllocTask();
      InitTaskStatic( pETask , (1024-w)/2 , (768-h)/2 , AG_CG_GAMEOVER , 1 );
      AddlLink( pETask , DISP_LEVEL_TOP );

      ageSndMgrRelease( pTask->Data.senario.bgm_handle );

      pTask->Data.senario.bgm_handle = ageSndMgrAlloc( AS_SND_GAMEOVER , 0 , 1 , AGE_SNDMGR_PANMODE_LR12 , 0 );

      ageSndMgrPlay( pTask->Data.senario.bgm_handle );
      ageSndMgrSetVolume( pTask->Data.senario.bgm_handle , 0xa0 );
      ageSndMgrSetPanMode( pTask->Data.senario.bgm_handle , 0 );
      ageSndMgrSetPan( pTask->Data.senario.bgm_handle , 0x8080 );
      
      --g_Life;
      KillPlayer( g_pPlayerTask );
    };
  };

  if( g_Life == 0 ) {
    struct TaskData* pETask;
    int w,h;

    w = ageRM[ AG_CG_GAMEOVER ].Width;
    h = ageRM[ AG_CG_GAMEOVER ].Height;

    pETask = AllocTask();
    InitTaskStatic( pETask , (1024-w)/2 , (768-h)/2 , AG_CG_GAMEOVER , 1 );
    AddlLink( pETask , DISP_LEVEL_TOP );

    ageSndMgrRelease( pTask->Data.senario.bgm_handle );

    pTask->Data.senario.bgm_handle = ageSndMgrAlloc( AS_SND_GAMEOVER , 0 , 1 , AGE_SNDMGR_PANMODE_LR12 , 0 );

    ageSndMgrPlay( pTask->Data.senario.bgm_handle );
    ageSndMgrSetVolume( pTask->Data.senario.bgm_handle , 0xa0 );
    ageSndMgrSetPanMode( pTask->Data.senario.bgm_handle , 0 );
    ageSndMgrSetPan( pTask->Data.senario.bgm_handle , 0x8080 );

    g_isGameOver = TRUE;
    pTask->x = 0;

    ageSndMgrPlayOneshot( (g_OffsetX % 2) ? AS_SND_A02 : AS_SND_A03 , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
  };

  if ( g_isGetKeyItem ){
    struct TaskData* pETask;
    int w,h;

    w = ageRM[ AG_CG_GAMEOVER ].Width;
    h = ageRM[ AG_CG_GAMEOVER ].Height;

    pETask = AllocTask();
    InitTaskStatic( pETask , (1024-w)/2 , (768*3/4-h)/2 , AG_CG_GAMECLEAR , 1 );
    AddlLink( pETask , DISP_LEVEL_TOP );

    ageSndMgrRelease( pTask->Data.senario.bgm_handle );

    pTask->Data.senario.bgm_handle = ageSndMgrAlloc( AS_SND_GAMECLEAR , 0 , 1 , AGE_SNDMGR_PANMODE_LR12 , 0 );

    ageSndMgrPlay( pTask->Data.senario.bgm_handle );
    ageSndMgrSetVolume( pTask->Data.senario.bgm_handle , 0xa0 );
    ageSndMgrSetPanMode( pTask->Data.senario.bgm_handle , 0 );
    ageSndMgrSetPan( pTask->Data.senario.bgm_handle , 0x8080 );

    g_isStageClear = TRUE;
    pTask->x = 0;
  };

  return( 0 );
}

void InitTaskSenario1( struct TaskData* pTask ) {
  int i;
  struct SPos *wpos, *ipos, *epos; 
  int wn, fn, en;

  memset( pTask , 0 , sizeof( *pTask ) );
  g_pSenarioTask = pTask;

  srandMT( 3475573 );

  pTask->type = TASK_SENARIO;
  pTask->Calc = CalcSenario1;
  pTask->x = 0;
  pTask->y = 0;

  switch( g_Stage ) {
    case 0:
      wpos = wpos_1;
      ipos = ipos_1;
      epos = epos_1;
      wn = (sizeof( wpos_1 )/sizeof( wpos_1[0] ));
      fn = (sizeof( ipos_1 )/sizeof( ipos_1[0] ));
      en = (sizeof( epos_1 )/sizeof( epos_1[0] ));
      break;

    case 1:
      wpos = wpos_2;
      ipos = ipos_2;
      epos = epos_2;
      wn = (sizeof( wpos_2 )/sizeof( wpos_2[0] ));
      fn = (sizeof( ipos_2 )/sizeof( ipos_2[0] ));
      en = (sizeof( epos_2 )/sizeof( epos_2[0] ));
      break;

    case 2:
      wpos = wpos_3;
      ipos = ipos_3;
      epos = epos_3;
      wn = (sizeof( wpos_3 )/sizeof( wpos_3[0] ));
      fn = (sizeof( ipos_3 )/sizeof( ipos_3[0] ));
      en = (sizeof( epos_3 )/sizeof( epos_3[0] ));
      break;
  }


  //　固定オブジェクトの作成
  for( i=0 ; i<wn ; i++ ) {
    struct TaskData* pWTask;

    u16 is_hit        = TRUE;
    u16 is_harmful    = FALSE;
    u16 is_breakable  = FALSE;

    enum ObjectMotion motion = ObjectMotion_None;
    float phase       = 0.0;
    float frequency   = 0.0;
    float amplitude   = 0.0;

    int disp_level = DISP_LEVEL_OBJECT;

    switch ( wpos[i].type ) {
      case OBJECT_TYPE_HIT:
        break;

      case OBJECT_TYPE_NOHIT:
        is_hit = FALSE;
        break;

      case OBJECT_TYPE_FRONT:
        is_hit = FALSE;
        disp_level = DISP_LEVEL_BG_FRONT;
        break;

      case OBJECT_TYPE_HIT_H1:
        motion = ObjectMotion_Horizon;
        phase = 0.0;
        frequency = 0.025;
        amplitude = 100;
        break;

      case OBJECT_TYPE_HIT_V1:
        motion = ObjectMotion_Vertical;
        phase = 0.0;
        frequency = 0.03;
        amplitude = 100;
        break;

      case OBJECT_TYPE_HIT_H2:
        motion = ObjectMotion_Horizon;
        phase = PI;
        frequency = 0.025;
        amplitude = 100;
        break;

      case OBJECT_TYPE_HIT_V2:
        motion = ObjectMotion_Vertical;
        phase = PI;
        frequency = 0.03;
        amplitude = 100;
        break;

      case OBJECT_TYPE_TOGE:
        is_harmful = TRUE;
        break;

      case OBJECT_TYPE_TOGE_H1:
        is_harmful = TRUE;
        motion = ObjectMotion_Horizon;
        phase = 0.0;
        frequency = 0.05;
        amplitude = 100;
        break;

      case OBJECT_TYPE_TOGE_V1:	
        is_harmful = TRUE;
        motion = ObjectMotion_Vertical;
        phase = 0.0;
        frequency = 0.03;
        amplitude = 100;
        break;

      case OBJECT_TYPE_TOGE_H2:	
        is_harmful = TRUE;
        motion = ObjectMotion_Horizon;
        phase = PI;
        frequency = 0.05;
        amplitude = 100;
        break;

      case OBJECT_TYPE_TOGE_V2:	
        is_harmful = TRUE;
        motion = ObjectMotion_Vertical;
        phase = PI;
        frequency = 0.03;
        amplitude = 100;
        break;
    }

    pWTask = AllocTask();
    InitTaskObject( pWTask , wpos[i].x , wpos[i].y , wpos[i].image , 
        is_hit, is_harmful, is_breakable, 
        motion, phase, frequency, amplitude );
    AddlLink( pWTask , disp_level );
  };

  //　食べ物の作成
  for( i=0 ; i<fn ; i++ ) {
    struct TaskData* pITask;

    int image = 0;
    int score = 0;
    int time = 0;
    u16 is_keyitem = FALSE;

    switch ( ipos[i].type ) {
      case ITEM_TYPE_A:
        image = AG_CG_ICON_FOOD_ODANGO;
        score = 100;
        time = 0;
        break;
      case ITEM_TYPE_B:
        image = AG_CG_ICON_FOOD_ONIGIRI;
        score = 0;
        time = 100;
        break;

      case ITEM_TYPE_C:
        image = AG_CG_ICON_FOOD_SUIKA;
        score = 100;
        time = 100;
        break;

      case ITEM_TYPE_KEY:
        image = ipos[i].image;
        is_keyitem = TRUE;
        break;
    }

    pITask = AllocTask();
    InitTaskItem( pITask, ipos[i].x, ipos[i].y, image, time, score, is_keyitem);
    AddlLink( pITask , DISP_LEVEL_ITEM );
  };

  //　敵の作成
  for( i=0 ; i<en ; i++ ) {
    struct TaskData* pETask;

    pETask = AllocTask();
    switch( epos[i].type ) {
      case ENEMY_TYPE_FROG :
        InitTaskFrog( pETask , epos[i].x , epos[i].y  , epos[i].image , 0 );
        break;

      case ENEMY_TYPE_SNAKE :
        InitTaskSnake( pETask , epos[i].x , epos[i].y  , epos[i].image );
        break;

      default :
        break;
    };
    AddlLink( pETask , DISP_LEVEL_ENEMY );
  };

  pTask->Data.senario.bgm_handle = ageSndMgrAlloc( AS_SND_BGM , 0 , 1 , AGE_SNDMGR_PANMODE_LR12 , 0 );

  ageSndMgrPlay( pTask->Data.senario.bgm_handle );
  ageSndMgrSetVolume( pTask->Data.senario.bgm_handle , 0xa0 );
  ageSndMgrSetPanMode( pTask->Data.senario.bgm_handle , 0 );
  ageSndMgrSetPan( pTask->Data.senario.bgm_handle , 0x8080 );
}
