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


#define OBJECT_TYPE_HIT		(0)
#define OBJECT_TYPE_NOHIT	(1)
#define OBJECT_TYPE_FRONT	(2)

#define ENEMY_TYPE_FROG		(0)
#define ENEMY_TYPE_SNAKE	(1)

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

  { 2800 , 500 , OBJECT_TYPE_HIT , AG_CG_OBJ_WORKSTAND1 },
  { 3200 , 300 , OBJECT_TYPE_HIT , AG_CG_OBJ_WORKSTAND1 },
  { 3600 , 100 , OBJECT_TYPE_HIT , AG_CG_OBJ_WORKSTAND1 },
  { 4000 ,-100 , OBJECT_TYPE_HIT , AG_CG_OBJ_WORKSTAND1 },
  { 4400 ,-300 , OBJECT_TYPE_HIT , AG_CG_OBJ_WORKSTAND1 },
  { 4800 ,-500 , OBJECT_TYPE_HIT , AG_CG_OBJ_WORKSTAND1 },
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
  { 820+100*2  , 674 , ENEMY_TYPE_FROG  , 300 },
  { 820+200*2  , 674 , ENEMY_TYPE_FROG  , 300 },
  { 820+300*2  , 674 , ENEMY_TYPE_FROG  , 300 },
  { 820+400*2  , 674 , ENEMY_TYPE_FROG  , 300 },
  { 820+500*2  , 674 , ENEMY_TYPE_FROG  , 300 },
  { 820+600*2  , 674 , ENEMY_TYPE_FROG  , 300 },
  { 820+700*2  , 674 , ENEMY_TYPE_FROG  , 300 },
  { 820+800*2  , 674 , ENEMY_TYPE_FROG  , 300 },
  { 820+900*2  , 674 , ENEMY_TYPE_FROG  , 300 },
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
    int is_hit = FALSE;
    int disp_level = DISP_LEVEL_OBJECT;

    if( wpos[i].type == OBJECT_TYPE_HIT ) {
      is_hit = TRUE;
    }
    else if( wpos[i].type == OBJECT_TYPE_FRONT ) {
      disp_level = DISP_LEVEL_BG_FRONT;
    };
    pWTask = AllocTask();
    if (i > 8) {
      if (i % 2) {
        InitTaskObject( pWTask , wpos[i].x , wpos[i].y , wpos[i].image , is_hit, FALSE, FALSE, ObjectMotion_Horizon, 3.141592 * (i%2), 0.05, 100 );
      } else {
        InitTaskObject( pWTask , wpos[i].x , wpos[i].y , wpos[i].image , is_hit, FALSE, FALSE, ObjectMotion_Vertical, 3.141592 * (i%2), 0.03, 100 );
      }
    } else {
      InitTaskObject( pWTask , wpos[i].x , wpos[i].y , wpos[i].image , is_hit, FALSE, FALSE, ObjectMotion_None, 0, 0, 0 );
    }

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
