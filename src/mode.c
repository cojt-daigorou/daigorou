#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "mode.h"
#include "task.h"
#include "export.h"
#include "global.h"

static enum GameMode NowMode;

void InitMode( void ) {
	NowMode = MODE_NONE;
}

void GotoMode( enum GameMode mode ) {
	struct TaskData* pTask;

	ClearAllTask();

	switch( mode ) {
		case MODE_TITLE :
			g_OffsetX = 0;
			g_OffsetY = 0;
			g_PlayerX = 0;
			g_PlayerY = 0;

			g_isGameOver = 0;
      g_isStageClear = FALSE;
      g_isGetKeyItem = FALSE;

			g_Score = 0;
			g_Time = 100;
			g_Life = 1;
      g_Stage = 0;

			pTask = AllocTask();
			InitTaskBg( pTask , AG_CG_BG_0_0 , 0 );
			AddlLink( pTask , DISP_LEVEL_BG );

			pTask = AllocTask();
			InitTaskOpening( pTask );
			AddlLink( pTask , DISP_LEVEL_OBJECT );
			break;

		case MODE_GAME :
			g_Life = 1;
			g_OffsetX = 0;
			g_OffsetY = 0;
			g_PlayerX = 0;
			g_PlayerY = 0;

			g_isGameOver = 0;
      g_isStageClear = FALSE;
      g_isGetKeyItem = FALSE;

      switch (g_Stage) {
        case 0: 
          g_Score = 0;
          g_Time = 100;
          break;
        case 1:
          g_Time = 200;
          break;
        default:
          break;
      }

			pTask = AllocTask();
			InitTaskBg( pTask , AG_CG_BG_0_0 , 0 );
			AddlLink( pTask , DISP_LEVEL_BG );

			pTask = AllocTask();
			InitTaskPlayer( pTask );
			AddlLink( pTask , DISP_LEVEL_PLAYER );

			pTask = AllocTask();
      InitTaskSenario1( pTask );
			AddlLink( pTask , DISP_LEVEL_BG );

			pTask = AllocTask();
			InitTaskScore( pTask , 750 , 30 , &(g_Score) );
			AddlLink( pTask , DISP_LEVEL_SCORE );

			pTask = AllocTask();
			InitTaskScore( pTask , 30 , 30 , &(g_Time) );
			AddlLink( pTask , DISP_LEVEL_SCORE );

			pTask = AllocTask();
			InitTaskStatic( pTask , 0 , 10 , AG_CG_INFO_TIME , 1 );
			AddlLink( pTask , DISP_LEVEL_SCORE );

			break;

		default :
			break;
	};
}
