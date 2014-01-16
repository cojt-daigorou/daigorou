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
  u16 is_harmful;
  u16 is_breakable;
  enum ObjectMotion motion;
  s32 center_x;
  s32 pre_x;
  s32 center_y;
  s32 pre_y;
  float phase;
  float frequency;
  float amplitude;
};

void InitTaskObject( struct TaskData* pTask, s32 x, s32 y, u16 image,
    u16 is_hit, u16 is_harmful, u16 is_breakable, 
    enum ObjectMotion motion, float phase, float frequency, float amplitude );

#endif // __TASK_OBJECT_H__
