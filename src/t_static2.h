#ifndef __TASK_STATIC2_H__
#define __TASK_STATIC2_H__

#include <agtypes.h>

enum Static2Type {
  Static2Type_Blink,
  Static2Type_MoveHorizon,
  Static2Type_MoveVertical,
};

struct Static2Data {
	u16 image;
  u16 type;
  u32 count;
  u32 delay;
};

void InitTaskStatic2( struct TaskData* pTask, s32 x, s32 y, u16 Image, u16 Type, u32 Delay );

#endif // __TASK_STATIC2_H__
