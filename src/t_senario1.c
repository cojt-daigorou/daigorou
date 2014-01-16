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
/*                          シナリオ１                            */
/******************************************************************/
struct SPos {
  int x, y;
  int type;
  int image;
};


#define OBJECT_TYPE_HIT		  (0)
#define OBJECT_TYPE_NOHIT   (1)
#define OBJECT_TYPE_FRONT	  (2)
#define OBJECT_TYPE_HITH1   (3)
#define OBJECT_TYPE_HITV1   (4)
#define OBJECT_TYPE_HITH2   (5)
#define OBJECT_TYPE_HITV2   (6)
#define OBJECT_TYPE_TOGE4	  (7)
#define OBJECT_TYPE_TOGE4H1	(8)
#define OBJECT_TYPE_TOGE4V1	(9)
#define OBJECT_TYPE_TOGE4H2	(10)
#define OBJECT_TYPE_TOGE4V2	(11)

#define ENEMY_TYPE_FROG		    (0)
#define ENEMY_TYPE_SNAKE	    (1)

struct SPos wpos[] = {
  { 150 , 419 , OBJECT_TYPE_FRONT , AG_CG_OBJ_GRASS },

  { 1000 , 605      , OBJECT_TYPE_HIT , AG_CG_OBJ_TAKE4 },
  { 1000 , 605-64   , OBJECT_TYPE_HIT , AG_CG_OBJ_TAKE3 },
  { 1000 , 605-64*2 , OBJECT_TYPE_HIT , AG_CG_OBJ_TAKE2 },
  { 1000 , 605-64*3 , OBJECT_TYPE_HIT , AG_CG_OBJ_TAKE1 },

  { 1800 , 605      , OBJECT_TYPE_HIT , AG_CG_OBJ_TAKE4 },
  { 1800 , 605-64   , OBJECT_TYPE_HIT , AG_CG_OBJ_TAKE3 },
  { 1800 , 605-64*2 , OBJECT_TYPE_HIT , AG_CG_OBJ_TAKE2 },
  { 1800 , 605-64*3 , OBJECT_TYPE_HIT , AG_CG_OBJ_TAKE1 },

  { 2800+700*0 , 500 , OBJECT_TYPE_HITH1 , AG_CG_OBJ_WORKSTAND1 },
  { 2800+700*1 , 300 , OBJECT_TYPE_HITH2 , AG_CG_OBJ_WORKSTAND1 },
  { 2800+700*2 , 100 , OBJECT_TYPE_HITH1 , AG_CG_OBJ_WORKSTAND1 },
  { 2800+700*3 ,-100 , OBJECT_TYPE_HITH2 , AG_CG_OBJ_WORKSTAND1 },
  { 2800+700*4 ,-300 , OBJECT_TYPE_HITH1 , AG_CG_OBJ_WORKSTAND1 },
  { 2800+700*5 ,-500 , OBJECT_TYPE_HITV1 , AG_CG_OBJ_WORKSTAND1 },

  { 1300 ,605 , OBJECT_TYPE_TOGE4 , AG_CG_OBJ_TOGE4 },
};

struct SPos fpos[] = {
  { 1400 , 680 , 1 , 0 },
  { 2400 , 680 , 1 , 0 },
  { 2800 , 500 , 0 , 0 },
  { 3600 , 100 , 2 , 0 },
  { 6200 , 680 , 0 , 0 },
  { 6500 , 680 , 1 , 0 },
};

struct SPos epos[] = {
  { 820  , 674 , ENEMY_TYPE_FROG  , 300 },
  //{ 820+100*2  , 674 , ENEMY_TYPE_FROG  , 300 },
  //{ 820+200*2  , 674 , ENEMY_TYPE_FROG  , 300 },
  //{ 820+300*2  , 674 , ENEMY_TYPE_FROG  , 300 },
  //{ 820+400*2  , 674 , ENEMY_TYPE_FROG  , 300 },
  //{ 820+500*2  , 674 , ENEMY_TYPE_FROG  , 300 },
  //{ 820+600*2  , 674 , ENEMY_TYPE_FROG  , 300 },
  //{ 820+700*2  , 674 , ENEMY_TYPE_FROG  , 300 },
  //{ 820+800*2  , 674 , ENEMY_TYPE_FROG  , 300 },
  //{ 820+900*2  , 674 , ENEMY_TYPE_FROG  , 300 },
  { 1800 , 416 , ENEMY_TYPE_SNAKE , 300 },
};


static s32 CalcSenario1( struct TaskData* pTask , u32 Flag ) {
  pTask->x++;

  if( g_GameOver ) {
    pTask->x++;
    if( pTask->x > 800 ) {
      ageSndMgrRelease( pTask->Data.title.bgm_handle );
      GotoMode( MODE_TITLE );
    };
    return(0);
  };

  if( g_Time > 0 && (pTask->x % 60) == 0 ) {
    g_Time--;

    if( g_Time == 30 ) {
      ageSndMgrRelease( pTask->Data.title.bgm_handle );

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

      ageSndMgrRelease( pTask->Data.title.bgm_handle );

      pTask->Data.senario.bgm_handle = ageSndMgrAlloc( AS_SND_GAMEOVER , 0 , 1 , AGE_SNDMGR_PANMODE_LR12 , 0 );

      ageSndMgrPlay( pTask->Data.senario.bgm_handle );
      ageSndMgrSetVolume( pTask->Data.senario.bgm_handle , 0xa0 );
      ageSndMgrSetPanMode( pTask->Data.senario.bgm_handle , 0 );
      ageSndMgrSetPan( pTask->Data.senario.bgm_handle , 0x8080 );

      g_GameOver = 1;
      pTask->x = 0;
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

    ageSndMgrRelease( pTask->Data.title.bgm_handle );

    pTask->Data.senario.bgm_handle = ageSndMgrAlloc( AS_SND_GAMEOVER , 0 , 1 , AGE_SNDMGR_PANMODE_LR12 , 0 );

    ageSndMgrPlay( pTask->Data.senario.bgm_handle );
    ageSndMgrSetVolume( pTask->Data.senario.bgm_handle , 0xa0 );
    ageSndMgrSetPanMode( pTask->Data.senario.bgm_handle , 0 );
    ageSndMgrSetPan( pTask->Data.senario.bgm_handle , 0x8080 );

    g_GameOver = 1;
    pTask->x = 0;

    ageSndMgrPlayOneshot( (g_OffsetX % 2) ? AS_SND_A02 : AS_SND_A03 , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
  };

  //　ソフトリセット
  if( PadTrg()&PAD_UP && PadTrg()&PAD_DOWN ) {
    ageSndMgrRelease( pTask->Data.title.bgm_handle );
    GotoMode( MODE_TITLE );
  };

  return( 0 );
}

void InitTaskSenario1( struct TaskData* pTask ) {
  int i;

  memset( pTask , 0 , sizeof( *pTask ) );

  srandMT( 3475573 );

  pTask->type = TASK_SENARIO;
  pTask->Calc = CalcSenario1;
  pTask->x = 0;
  pTask->y = 0;

  //　食べ物の作成
  for( i=0 ; i<(sizeof( fpos )/sizeof( fpos[0] )) ; i++ ) {
    struct TaskData* pFTask;

    pFTask = AllocTask();
    InitTaskFood( pFTask , fpos[i].x , fpos[i].y , AG_CG_ICON_FOOD_ODANGO + fpos[i].type , 300 , 100 );
    AddlLink( pFTask , DISP_LEVEL_FOOD );
  };

  //　固定オブジェクトの作成
  for( i=0 ; i<(sizeof( wpos )/sizeof( wpos[0] )) ; i++ ) {
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
        disp_level = DISP_LEVEL_BG_FRONT;
        break;

      case OBJECT_TYPE_HITH1:
        motion = ObjectMotion_Horizon;
        phase = 0.0;
        frequency = 0.05;
        amplitude = 100;
        break;

      case OBJECT_TYPE_HITV1:
        motion = ObjectMotion_Vertical;
        phase = 0.0;
        frequency = 0.03;
        amplitude = 100;
        break;

      case OBJECT_TYPE_HITH2:
        motion = ObjectMotion_Horizon;
        phase = PI;
        frequency = 0.05;
        amplitude = 100;
        break;

      case OBJECT_TYPE_HITV2:
        motion = ObjectMotion_Vertical;
        phase = PI;
        frequency = 0.03;
        amplitude = 100;
        break;

      case OBJECT_TYPE_TOGE4:
        is_harmful = TRUE;
        break;

      case OBJECT_TYPE_TOGE4H1:
        is_harmful = TRUE;
        motion = ObjectMotion_Horizon;
        phase = 0.0;
        frequency = 0.05;
        amplitude = 100;
        break;

      case OBJECT_TYPE_TOGE4V1:	
        is_harmful = TRUE;
        motion = ObjectMotion_Vertical;
        phase = 0.0;
        frequency = 0.03;
        amplitude = 100;
        break;

      case OBJECT_TYPE_TOGE4H2:	
        is_harmful = TRUE;
        motion = ObjectMotion_Horizon;
        phase = PI;
        frequency = 0.05;
        amplitude = 100;
        break;

      case OBJECT_TYPE_TOGE4V2:	
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

  //　敵の作成
  for( i=0 ; i<(sizeof( epos )/sizeof( epos[0] )) ; i++ ) {
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
