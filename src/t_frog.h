#ifndef __TASK_FROG_H__
#define __TASK_FROG_H__

#include <agtypes.h>

struct FrogData {
	u16 count;
	u16 sub_count;
	u16 score;
	u8 direction;
	u8 mode;
};

void InitTaskFrog( struct TaskData* pTask , s32 x , s32 y , u16 Score , u8 Direction );

#endif // __TASK_FOOD_H__
