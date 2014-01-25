#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "export.h"
#include "global.h"

/******************************************************************/
/*                            Retweet                              */
/******************************************************************/
static s32 CalcRetweet( struct TaskData* pTask , u32 Flag ) {
  pTask->Data.retweet.count++;

  // “G‚Ì’e‚Ì”»’è
  {
    struct TaskData* pBTask;
    pBTask = GetDispLink( DISP_LEVEL_EBULLET );
    while ( pBTask != NULL ) {
      if (pBTask->type == TASK_EBULLET) {
        // “G‚Ì’e‚ªÚ‹ß‚µ‚½‚Æ‚«AƒŠƒcƒC[ƒg‚ª”­“®‚·‚éB
        if ( (pTask->x - pBTask->x) * (pTask->x - pBTask->x)/(2*2) + (pTask->y - pBTask->y) * (pTask->y - pBTask->y) < 100*100 ) {
			struct TaskData* pATask;

          pATask = AllocTask();
          InitTaskAttack( pATask , pBTask->x , pBTask->y );
          AddlLink( pATask , DISP_LEVEL_ATTACK );

          pTask->Data.retweet.flag = 1;
          pBTask->visible = 0;
          pBTask->flag = TASK_FLAG_DESTROY;
          break;
        }
      }

      pBTask = pBTask->Next;
    }
  }

	if(pTask->Data.retweet.flag==1){
		if( pTask->Data.retweet.count%5 == 0 ) {
			int i;
			int x = g_PlayerX;
			int y = g_PlayerY + 64;
			for(i=0;i<8;i++){
				int dx = (int)(20*cosf(pTask->Data.retweet.count + PI*i/4));
				int dy = (int)(20*sinf(pTask->Data.retweet.count + PI*i/4));
				struct TaskData* pBTask;
				pBTask = AllocTask();
				if (pBTask != NULL) {
					InitTaskPBullet( pBTask ,x , y, AG_RP_OBJ_PBULLET, dx,dy, 0,0 );
					AddlLink( pBTask , DISP_LEVEL_PBULLET );
					AddScore( 10 );

				};
			};
		};
	};
	if( pTask->Data.retweet.count > ageRM3[AG_RP_EFF_RT].Frames ) {
		pTask->visible = 0;
		pTask->flag = TASK_FLAG_DESTROY;
	};

	return( 0 );
}

static s32 DrawRetweet( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
	int w, h;
	int x , y;
	u8 flip;

	x = (g_PlayerX - g_OffsetX)<<2;
	y = (g_PlayerY - g_OffsetY+128)<<2;
	if( pTask->Data.retweet.direction == 0 ) {
		flip = 0;
	}
	else {
		flip = 1;
	};

	ageTransferAAC_RM3( pDBuf, pTask->Data.retweet.image , 0, &w, &h , (pTask->Data.retweet.count>>1) % (ageRM3[pTask->Data.retweet.image].Frames) );

	if(flip==0){
		agDrawSPRITE( pDBuf, 1 , x - (w<<1) , y - (h<<2) , x + (w<<1), y );
	}
	else {
		agDrawSPRITE_UV( pDBuf , x - (w<<1) , y - (h<<2) , 0x1000 , 0, x + (w<<1), y , 0 , 0x1000);
	};

	return( 0 );
}

void InitTaskRetweet( struct TaskData* pTask , s32 x , s32 y ,s8 dir) {
	memset( pTask , 0 , sizeof( *pTask ) );

	pTask->type = TASK_EFFECT;
	pTask->visible = 1;
	pTask->x = x;
	pTask->y = y;
	pTask->Calc = CalcRetweet;
	pTask->Draw = DrawRetweet;
	pTask->Data.retweet.count = 0;
	pTask->Data.retweet.image = AG_RP_EFF_RT;
	pTask->Data.retweet.direction = dir;
	pTask->Data.retweet.flag = 0;
}
