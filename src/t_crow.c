#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "randMT.h"
#include "export.h"
#include "global.h"
#include "t_crow.h"
#include "rect.h"

/******************************************************************/
/*                              ‚©‚ç‚·                            */
/******************************************************************/
static s32 CalcCrow( struct TaskData* pTask , u32 Flag ) {
	int dx = pTask->x - g_PlayerX;
	int dy = pTask->y - g_PlayerY -g_OffsetY + 275;


	pTask->Data.crow.count += 1;
	if(pTask->Data.crow.count>=60){
        // ’e”­ŽË
          struct TaskData* pBTask;
          pBTask = AllocTask();
          if (pBTask != NULL) {
			  InitTaskEBullet( pBTask , pTask->x, pTask->y, AG_RP_OBJ_EBULLET,0, 5, 0,0 );
            AddlLink( pBTask , DISP_LEVEL_EBULLET );
        };
		pTask->Data.crow.count = 0;

	};
	if(pTask->Data.crow.count % 20 == 0){
		pTask->Data.crow.mode += 1;
		pTask->Data.crow.mode %= 3;
	};

	if(dx*dx>512*512) return 0;	//‰“‚·‚¬‚éê‡‚Í‚·‚®I—¹

	//ˆÚ“®
	{
		int ax = (int)(-dx*0.01 - pTask->Data.crow.vx*0.04);
		int ay = (int)(-dy*0.01 - pTask->Data.crow.vy*0.04);
		if(ax==0){
			if(dx>0)ax = -1;
			else if(dx<0)ax = 1;
		}
		pTask->Data.crow.vx += ax;
		pTask->Data.crow.vy += ay;
	
	if(pTask->Data.crow.vx==0){
		if(dx>0)pTask->Data.crow.vx = -1;
		else if(dx<0)pTask->Data.crow.vx = 1;
	}
	pTask->x += pTask->Data.crow.vx;
	pTask->y += pTask->Data.crow.vy;
	}

  // Ž©‹@‚Ì’e‚Ì”»’è
  {
    struct TaskData* pBTask;
    pBTask = GetDispLink( DISP_LEVEL_PBULLET );
    while ( pBTask != NULL ) {
      if (pBTask->type == TASK_PBULLET) {
        if ( (pTask->x - pBTask->x) * (pTask->x - pBTask->x) + (pTask->y - pBTask->y) * (pTask->y - pBTask->y) < 50*50) {
          struct TaskData* pATask;

          pATask = AllocTask();
          InitTaskAttack( pATask , pTask->x , pTask->y );
          AddlLink( pATask , DISP_LEVEL_ATTACK );

          pTask->visible = 0;
          pTask->flag = TASK_FLAG_DESTROY;

          AddScore( pTask->Data.crow.score );

          pBTask->visible = 0;
          pBTask->flag = TASK_FLAG_DESTROY;
          break;
        }
      }

      pBTask = pBTask->Next;
    }
  }

  // Ž©‹@‚Æ‚Ì”»’è
  if ( (pTask->x - g_PlayerX) * (pTask->x - g_PlayerX) + (pTask->y - 28 - g_PlayerY ) * (pTask->y - 28 - g_PlayerY ) < 60*60) {
  //if ( g_pPlayerRect != NULL && HitCrow(pTask, g_pPlayerRect) ) {
    KillPlayer( g_pPlayerTask );
  }

	return( 0 );
}

static s32 DrawCrow( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
	const float offsetRatioX = 0.3f;
	const float offsetRatioY = 0.2f;
	int bw, bh, lw, lh, wofx, wofy;
	int a = 255;
	agPictureSetBlendMode( pDBuf , 0 , a , 0 , 0 , 2 , 1 );
	if( pTask->Data.crow.mode == 0 ) {
		//‘Ì
		ageTransferAAC( pDBuf, AG_CG_OBJ_CROW_BODY1, 0, &bw, &bh );
		agDrawSPRITE( pDBuf, 1, (pTask->x - g_OffsetX - bw/2)<<2 , (pTask->y-g_OffsetY - bh/2)<<2 , (pTask->x - g_OffsetX + bw/2)<<2, (pTask->y-g_OffsetY+bh/2)<<2 );
		//¶—ƒ
		ageTransferAAC( pDBuf, AG_CG_OBJ_CROW_WING_L1, 0, &lw, &lh );
		wofx = (int)(bw*offsetRatioX);
		agDrawSPRITE( pDBuf, 1, (pTask->x - g_OffsetX + wofx)<<2 , (pTask->y-g_OffsetY - lh)<<2 , (pTask->x - g_OffsetX + wofx + lw)<<2, (pTask->y-g_OffsetY)<<2 );
		ageTransferAAC( pDBuf, AG_CG_OBJ_CROW_WING_R1, 0, &lw, &lh );
		agDrawSPRITE( pDBuf, 1, (pTask->x - g_OffsetX - wofx - lw)<<2 , (pTask->y-g_OffsetY - lh)<<2 , (pTask->x - g_OffsetX - wofx)<<2, (pTask->y-g_OffsetY)<<2 );
	}
	else if( pTask->Data.crow.mode == 1 ) {
		//‘Ì
		ageTransferAAC( pDBuf, AG_CG_OBJ_CROW_BODY2, 0, &bw, &bh );
		agDrawSPRITE( pDBuf, 1, (pTask->x - g_OffsetX - bw/2)<<2 , (pTask->y-g_OffsetY - bh/2)<<2 , (pTask->x - g_OffsetX + bw/2)<<2, (pTask->y-g_OffsetY+bh/2)<<2 );
		//¶—ƒ
		ageTransferAAC( pDBuf, AG_CG_OBJ_CROW_WING_L2, 0, &lw, &lh );
		wofx = (int)(bw*offsetRatioX);
		wofy = (int)(bh*offsetRatioY);
		agDrawSPRITE( pDBuf, 1, (pTask->x - g_OffsetX + wofx)<<2 , (pTask->y-g_OffsetY +wofy -lh/2)<<2 , (pTask->x - g_OffsetX + wofx + lw)<<2, (pTask->y-g_OffsetY + wofy +lh/2)<<2 );
		ageTransferAAC( pDBuf, AG_CG_OBJ_CROW_WING_R2, 0, &lw, &lh );
		agDrawSPRITE( pDBuf, 1, (pTask->x - g_OffsetX - wofx - lw)<<2 , (pTask->y-g_OffsetY +wofy -lh/2)<<2 , (pTask->x - g_OffsetX - wofx)<<2, (pTask->y-g_OffsetY + wofy +lh/2)<<2 );
	}
	else {
		//‘Ì
		ageTransferAAC( pDBuf, AG_CG_OBJ_CROW_BODY3, 0, &bw, &bh );
		agDrawSPRITE( pDBuf, 1, (pTask->x - g_OffsetX - bw/2)<<2 , (pTask->y-g_OffsetY - bh/2)<<2 , (pTask->x - g_OffsetX + bw/2)<<2, (pTask->y-g_OffsetY+bh/2)<<2 );
		//¶—ƒ
		ageTransferAAC( pDBuf, AG_CG_OBJ_CROW_WING_L3, 0, &lw, &lh );
		wofx = (int)(bw*offsetRatioX);
		agDrawSPRITE( pDBuf, 1, (pTask->x - g_OffsetX + wofx)<<2 , (pTask->y-g_OffsetY-lh/2)<<2 , (pTask->x - g_OffsetX + wofx + lw)<<2, (pTask->y-g_OffsetY+lh/2)<<2 );
		ageTransferAAC( pDBuf, AG_CG_OBJ_CROW_WING_R3, 0, &lw, &lh );
		agDrawSPRITE( pDBuf, 1, (pTask->x - g_OffsetX - wofx - lw)<<2 , (pTask->y-g_OffsetY-lh/2)<<2 , (pTask->x - g_OffsetX - wofx)<<2, (pTask->y-g_OffsetY+lh/2)<<2 );
	};

}

static s32 HitCrow( struct TaskData* pTask , const struct RECT* pRect ) {
  int w,h;
  struct RECT rect;

  w = 60;
  h = 60;

  rect.x0 = pTask->x - w/2;
  rect.y0 = pTask->y;
  rect.x1 = pTask->x + w/2;
  rect.y1 = pTask->y + h;

  return( IsHitRect( pRect , &rect ) );
}

void InitTaskCrow( struct TaskData* pTask , s32 x , s32 y , u16 Score , u8 Direction ) {
	memset( pTask , 0 , sizeof( *pTask ) );

	pTask->type = TASK_ENEMY;
	pTask->visible = 1;
	pTask->x = x;
	pTask->y = y;
	pTask->Calc = CalcCrow;
	pTask->Draw = DrawCrow;
	pTask->Data.crow.count = 0;
	pTask->Data.crow.score = Score;
	pTask->Data.crow.direction = Direction;
	pTask->Data.crow.mode = 0;
	pTask->Data.crow.vx = 0;
	pTask->Data.crow.vy = 0;
}
