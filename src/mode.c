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
			g_Life = 3;
			g_Star = 30;
      g_Stage = 0;

			pTask = AllocTask();
			InitTaskBg( pTask , AG_CG_BG_0_0 , 0 );
			AddlLink( pTask , DISP_LEVEL_BG );

			pTask = AllocTask();
			InitTaskOpening( pTask );
			AddlLink( pTask , DISP_LEVEL_OBJECT );
			break;

    case MODE_STORY:

			pTask = AllocTask();
			InitTaskBg( pTask , AG_CG_BG_0_0 , 0 );
			AddlLink( pTask , DISP_LEVEL_BG );

			pTask = AllocTask();
			InitTaskStory( pTask );
			AddlLink( pTask , DISP_LEVEL_OBJECT );
      break;

		case MODE_GAME :
			g_OffsetX = 0;
			g_OffsetY = 0;
			g_PlayerX = 0;
			g_PlayerY = 0;

			g_isGameOver = 0;
      g_isStageClear = FALSE;
      g_isGetKeyItem = FALSE;

      switch (g_Stage) {
        case 0: 
          g_Time = 300;
          break;

        case 1:
          g_Time = 300;
          break;

        case 2:
          g_Time = 300;
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

      // スコア表示などのインジケーター

      // SCORE
			pTask = AllocTask();
			InitTaskScore( pTask , -30 , 30 , &(g_Score), 4 );
			AddlLink( pTask , DISP_LEVEL_SCORE );

      // LIFE
			pTask = AllocTask();
			InitTaskStatic( pTask , 250 , 10 , AG_CG_ICON_DAIGORO , 1 );
			AddlLink( pTask , DISP_LEVEL_INFO );

			pTask = AllocTask();
			InitTaskStatic( pTask , 335 , 30 , AG_CG_ICON_CROSS , 1 );
			AddlLink( pTask , DISP_LEVEL_INFO );

			pTask = AllocTask();
			InitTaskScore( pTask , 320 , 30 , &(g_Life), 2 );
			AddlLink( pTask , DISP_LEVEL_SCORE );

      // STAR
			pTask = AllocTask();
			InitTaskStatic( pTask , 500 , 18 , AG_CG_ICON_STAR , 1 );
			AddlLink( pTask , DISP_LEVEL_INFO );

			pTask = AllocTask();
			InitTaskStatic( pTask , 575 , 30 , AG_CG_ICON_CROSS , 1 );
			AddlLink( pTask , DISP_LEVEL_INFO );

			pTask = AllocTask();
			InitTaskScore( pTask , 560 , 30 , &(g_Star), 2 );
			AddlLink( pTask , DISP_LEVEL_SCORE );

      // TIME
			pTask = AllocTask();
			InitTaskStatic( pTask , 760 , 10 , AG_CG_INFO_TIME , 1 );
			AddlLink( pTask , DISP_LEVEL_INFO );

			pTask = AllocTask();
			InitTaskScore( pTask , 790 , 30 , &(g_Time), 3 );
			AddlLink( pTask , DISP_LEVEL_SCORE );

			break;

		default :
			break;
	};
}
