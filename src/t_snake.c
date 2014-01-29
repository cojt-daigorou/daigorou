#include <amlib.h>
#include <agdraw.h>
#include <agpicture.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "randMT.h"
#include "export.h"
#include "global.h"
#include "t_snake.h"

/******************************************************************/
/*                               へび                             */
/******************************************************************/
static s32 CalcSnake( struct TaskData* pTask , u32 Flag ) {
  switch( pTask->Data.snake.mode ) {
    default :
    case 0 :    //　通常待機状態
      pTask->Data.snake.count++;
      if( pTask->Data.snake.count > 60 ) {
        pTask->Data.snake.count = 0;
        pTask->Data.snake.mode = 1;   //　伸び状態
      };
      break;

    case 1 :    //　伸び状態
      pTask->Data.snake.count++;
      if( pTask->Data.snake.count >= 120 ) {
        pTask->Data.snake.count = 0;
        pTask->Data.snake.mode = 2;
      };
      break;

    case 2 :    //　パクパク状態
      pTask->Data.snake.count++;
      if( pTask->Data.snake.count >= 120 ) {
        pTask->Data.snake.count = 120;
        pTask->Data.snake.mode = 3;
      };

      // 自機との判定
      if ( (pTask->x - g_PlayerX) * (pTask->x - g_PlayerX) + (pTask->y - g_PlayerY - 100) * (pTask->y - g_PlayerY - 100 ) < 60*60) {
        KillPlayer( g_pPlayerTask );
      }
      break;

    case 3 :    //　縮み状態
      pTask->Data.snake.count--;
      if( pTask->Data.snake.count <= 0 ) {
        pTask->Data.snake.count = 0;
        pTask->Data.snake.mode = 0;
      };
      break;
  };

  // 自機の弾の判定
  {
    struct TaskData* pBTask;
    pBTask = GetDispLink( DISP_LEVEL_PBULLET );
    while ( pBTask != NULL ) {
      if (pBTask->type == TASK_PBULLET) {
        if ( (pTask->x - pBTask->x) * (pTask->x - pBTask->x) + (pTask->y - pBTask->y) * (pTask->y - pBTask->y) < 40*40) {
          struct TaskData* pATask;

          pATask = AllocTask();
          InitTaskAttack( pATask , pTask->x , pTask->y );
          AddlLink( pATask , DISP_LEVEL_ATTACK );

          pTask->visible = 0;
          pTask->flag = TASK_FLAG_DESTROY;

          AddScore( pTask->Data.frog.score );

          pBTask->visible = 0;
          pBTask->flag = TASK_FLAG_DESTROY;
          break;
        }
      }

      pBTask = pBTask->Next;
    }
  }

  return( 0 );
}

static s32 DrawSnake( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
  int w, h;
  int x, y;
  int a = 255;
  int len;

  if( (pTask->x + 50) < g_OffsetX || (pTask->x - 50) > (g_OffsetX + 1024) ) {
    return( 0 );    //　範囲外なので描画しない
  };

  x = (pTask->x - g_OffsetX)<<2;
  y = (pTask->y - g_OffsetY)<<2;
#if 1
  switch( pTask->Data.snake.mode ) {
    default :
    case 0 :    //　通常待機状態
      agPictureSetBlendMode( pDBuf , 0 , a , 0 , 0 , 2 , 1 );
      ageTransferAAC( pDBuf, AG_CG_OBJ_SNAKE1 , 0, &w, &h );
      agDrawSPRITE( pDBuf, 1, x - (w<<1) , y - (h<<2) , x + (w<<1), y );
      break;

    case 1 :    //　伸び状態
    case 3 :    //　縮み状態
      agPictureSetBlendMode( pDBuf , 0 , a , 0 , 0 , 2 , 1 );
      ageTransferAAC( pDBuf, AG_CG_OBJ_SNAKE3 , 0, &w, &h );
      len = h * pTask->Data.snake.count / 120;

      {
        AGPolyT* p = agDrawTRIANGLE_T( pDBuf, (4-1), 0 , 0, 0, 0 );

        p->x = x - (w<<1);
        p->y = y - (len<<2);
        p->u = 0;
        p->v = 0;
        p++;
        p->x = x + (w<<1);
        p->y = y - (len<<2);
        p->u = 0x1000;
        p->v = 0;
        p++;
        p->x = x - (w<<1);
        p->y = y;
        p->u = 0;
        p->v = 0x1000 * len / h;
        p++;
        p->x = x + (w<<1);
        p->y = y;
        p->u = 0x1000;
        p->v = 0x1000 * len / h;
        p++;
      };

      ageTransferAAC( pDBuf, AG_CG_OBJ_SNAKE1 , 0, &w, &h );
      agDrawSPRITE( pDBuf, 1 , x - (w<<1) , y - (h<<2) - (len<<2) , x + (w<<1), y - (len<<2) );
      break;

    case 2 :    //　パクパク状態
      agPictureSetBlendMode( pDBuf , 0 , a , 0 , 0 , 2 , 1 );
      ageTransferAAC( pDBuf, AG_CG_OBJ_SNAKE3 , 0, &w, &h );
      len = h;
      agDrawSPRITE( pDBuf , 1 , x - (w<<1) , y - (h<<2) , x + (w<<1), y );

      ageTransferAAC( pDBuf, ( (pTask->Data.snake.count % 40) > 20 ) ? AG_CG_OBJ_SNAKE1 : AG_CG_OBJ_SNAKE2, 0, &w, &h );
      agDrawSPRITE( pDBuf , 1 , x - (w<<1) , y - (h<<2) - (len<<2) , x + (w<<1), y - (len<<2) );
      break;
  };
#endif
}

void InitTaskSnake( struct TaskData* pTask , s32 x , s32 y , u16 Score ) {
  memset( pTask , 0 , sizeof( *pTask ) );

  pTask->type = TASK_ENEMY;
  pTask->visible = 1;
  pTask->x = x;
  pTask->y = y;
  pTask->Calc = CalcSnake;
  pTask->Draw = DrawSnake;
  pTask->Data.snake.count = 0;
  pTask->Data.snake.sub_count = 0;
  pTask->Data.snake.score = Score;
  pTask->Data.snake.mode = 0;
}
