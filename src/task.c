#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "randMT.h"
#include "export.h"
#include "global.h"

#define ENEMY_A_SCORE		(123)

static struct TaskData TaskBuffer[ TASK_MAX ];
static struct TaskData* DispLink[ DISP_LEVEL_MAX ];

void ClearAllTask( void ) {
	int i;

	for( i=0; i<TASK_MAX ; i++ ) {
		TaskBuffer[i].type = TASK_NONE;		//　タスクなし
	};

	for( i=0 ; i<DISP_LEVEL_MAX ; i++ ) {
		DispLink[i] = NULL;
	};
}

struct TaskData* AllocTask( void ) {
	int i;

	for( i=0 ; i<TASK_MAX ; i++ ) {
		if( TaskBuffer[i].type == TASK_NONE ) {
			return( &(TaskBuffer[i]) );
		};
	};

#ifdef DEBUG
  _dprintf( "AllocTask() NoTaskNoneError : %d\n" , 0 );
#endif

  return( NULL );
}

void AddlLink( struct TaskData* pTask , int DispLevel ) {
	if( DispLevel < 0 || DispLevel >= DISP_LEVEL_MAX ) {
#ifdef DEBUG
		_dprintf( "AddlDrawLink() DispLevelError : %d\n" , DispLevel );
#endif
		return;
	};

	if( DispLink[DispLevel] != NULL ) {
		pTask->Next = DispLink[DispLevel];
	}
	else {
		pTask->Next = NULL;
	};

	DispLink[DispLevel] = pTask;
}

int CalcTask( u32 Flag ) {
	struct TaskData* pTask;
	struct TaskData* pPrevTask;
	int i;

	for( i=0 ; i<DISP_LEVEL_MAX ; i++ ) {
		pTask = DispLink[i];
		pPrevTask = NULL;

		while( pTask != NULL ) {
			if( pTask->flag == TASK_FLAG_DESTROY ) {
				if( pTask == DispLink[i] ) {
					DispLink[i] = pTask->Next;
				};

				if( pPrevTask != NULL ) {
					pPrevTask->Next = pTask->Next;
				};

				pTask->type = TASK_NONE;
			}
			else if( pTask->Calc != NULL && pTask->stop == 0 ) {
				pTask->Calc( pTask , Flag );
				pPrevTask = pTask;
			};

			pTask = pTask->Next;
		};
	};

	return( 0 );
}

int DrawTask( AGDrawBuffer* pDBuf , int DispLevel ) {
	struct TaskData* pTask;

	if( DispLevel < 0 || DispLevel >= DISP_LEVEL_MAX ) {
		_dprintf( "DrawTask() DispLevelError : %d\n" , DispLevel );
		return( -1 );
	};

	pTask = DispLink[DispLevel];

	while( pTask != NULL ) {
		if( pTask->Draw != NULL && pTask->visible != 0 ) {
			pTask->Draw( pTask , pDBuf );
		};

		pTask = pTask->Next;
	};

	return( 0 );
}

int DrawTaskAll( AGDrawBuffer* pDBuf ) {
	int i;

	for( i=0 ; i<DISP_LEVEL_MAX ; i++ ) {
		DrawTask( pDBuf , i );
	};

	return( 0 );
}

struct TaskData* GetDispLink( int DispLevel ) {
	if( DispLevel < 0 || DispLevel >= DISP_LEVEL_MAX ) {
		return( NULL );
	};

	return( DispLink[ DispLevel ] );
}
