#ifndef __TASK_OBJECT_H__
#define __TASK_OBJECT_H__

#include <agtypes.h>

enum ObjectMotion {
  ObjectMotion_None,
  ObjectMotion_Horizon,
  ObjectMotion_Vertical
};

struct ObjectData {
  u32 count;
	u16 image;
	u16 is_hit;
  enum ObjectMotion motion;
  s32 center_x;
  s32 pre_x;
  float phase;
};

void InitTaskObject( struct TaskData* pTask , s32 x , s32 y , u16 image , u16 is_hit, enum ObjectMotion motion, float phase );

#endif // __TASK_OBJECT_H__
