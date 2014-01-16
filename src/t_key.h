#ifndef __TASK_KEY_H__
#define __TASK_KEY_H__

#include <agtypes.h>

struct KeyData {
	u16 image;
	u16 erase_time;
	u16 count;
	u16 score;
};

void InitTaskKey( struct TaskData* pTask , s32 x , s32 y , u16 Image , u16 erase_time , u16 Score );

#endif // __TASK_KEY_H__
