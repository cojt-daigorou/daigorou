#ifndef __TASK_STATIC_H__
#define __TASK_STATIC_H__

#include <agtypes.h>

struct StaticData {
	u16 image;
	u8 alpha_flag;
};

void InitTaskStatic( struct TaskData* pTask , s32 x , s32 y , u16 Image , u8 AlphaFlag );

#endif // __TASK_STATIC_H__
