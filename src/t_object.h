#ifndef __TASK_OBJECT_H__
#define __TASK_OBJECT_H__

#include <agtypes.h>

struct ObjectData {
	u16 image;
	u16 is_hit;
};

void InitTaskObject( struct TaskData* pTask , s32 x , s32 y , u16 image , u16 is_hit );

#endif // __TASK_OBJECT_H__
