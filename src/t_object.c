#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "randMT.h"
#include "export.h"
#include "global.h"
#include "rect.h"
#include "t_object.h"

/******************************************************************/
/*                         固定オブジェクト                       */
/******************************************************************/

static s32 CalcObject( struct TaskData* pTask , u32 Flag ) {

  switch( pTask->Data.object.motion ) {
    case ObjectMotion_None:
      break;
    case ObjectMotion_Horizon:
      pTask->Data.object.pre_x = pTask->x;
      pTask->x = pTask->Data.object.center_x + pTask->Data.object.amplitude * sinf(pTask->Data.object.phase + pTask->Data.object.frequency * (pTask->Data.object.count++));
      break;
    case ObjectMotion_Vertical:
      pTask->Data.object.pre_y = pTask->y;
      pTask->y = pTask->Data.object.center_y + pTask->Data.object.amplitude * sinf(pTask->Data.object.phase + pTask->Data.object.frequency * (pTask->Data.object.count++));
      break;
  }

  // 自機の弾の判定
  if (pTask->Data.object.is_hit) {
    struct TaskData* pBTask;
    pBTask = GetDispLink( DISP_LEVEL_PBULLET );
    while ( pBTask != NULL ) {
      if (pBTask->type == TASK_PBULLET) {
        struct RECT rect;

        rect.x0 = pBTask->x - 45;
        rect.y0 = pBTask->y - 109;
        rect.x1 = pBTask->x + 45;
        rect.y1 = pBTask->y - 19;
        if ( HitObject(pTask, &rect) ) {
          struct TaskData* pATask;

          pATask = AllocTask();
          InitTaskAttack( pATask , pBTask->x , pBTask->y);
          AddlLink( pATask , DISP_LEVEL_ATTACK );

          if (pTask->Data.object.is_breakable) {
            pTask->visible = 0;
            pTask->flag = TASK_FLAG_DESTROY;
          }

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

static s32 DrawObject( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
  int w,h;

  if( (pTask->x + 100) > g_OffsetX && (pTask->x - 100) < (g_OffsetX + 1024) ) {
    agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
    ageTransferAAC( pDBuf, pTask->Data.object.image, 0, &w, &h );

    agDrawSPRITE( pDBuf, 1,
        (pTask->x - w/2 - g_OffsetX)<<2 , (pTask->y - g_OffsetY)<<2 ,
        (pTask->x + w/2 - g_OffsetX)<<2, (pTask->y - g_OffsetY + h)<<2 );
  };
#if 0
  agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 0 , 1 );
  agDrawSETFCOLOR( pDBuf , 0xff000000);
  agDrawSPRITE( pDBuf, 0, (pTask->x-4- g_OffsetX)<<2 , (pTask->y-4- g_OffsetY)<<2 ,(pTask->x+4- g_OffsetX)<<2 , (pTask->y+4- g_OffsetY)<<2 );

  agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
  agDrawSETFCOLOR( pDBuf , 0xffffffff);
# endif
}

static s32 HitObject( struct TaskData* pTask , const struct RECT* pRect ) {
  int w,h;
  struct RECT rect;

  w = ageRM[ pTask->Data.object.image ].Width;
  h = ageRM[ pTask->Data.object.image ].Height;

  rect.x0 = pTask->x - w/2;
  rect.y0 = pTask->y;
  rect.x1 = pTask->x + w/2;
  rect.y1 = pTask->y + h;

  return( IsHitRect( pRect , &rect ) );
}

void InitTaskObject( struct TaskData* pTask, s32 x, s32 y, u16 image,
    u16 is_hit, u16 is_harmful, u16 is_breakable, 
    enum ObjectMotion motion, float phase, float frequency, float amplitude ) {

  memset( pTask , 0 , sizeof( *pTask ) );

  pTask->type = TASK_STATIC;
  pTask->visible = 1;
  pTask->x = x;
  pTask->y = y;
  pTask->Calc = CalcObject;
  pTask->Draw = DrawObject;
  if( is_hit != 0 ) {
    pTask->Hit = HitObject;
  };
  pTask->Data.object.image = image;
  pTask->Data.object.is_hit = is_hit;
  pTask->Data.object.is_harmful = is_harmful;
  pTask->Data.object.is_breakable = is_breakable;
  pTask->Data.object.motion = motion;
  pTask->Data.object.count = 0;
  pTask->Data.object.center_x = x;
  pTask->Data.object.pre_x = x;
  pTask->Data.object.center_y = y;
  pTask->Data.object.pre_y = y;
  pTask->Data.object.phase = phase;
  pTask->Data.object.frequency = frequency;
  pTask->Data.object.amplitude = amplitude;
}
