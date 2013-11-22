#ifndef __TASK_FOOD_H__
#define __TASK_FOOD_H__

#include <agtypes.h>

struct FoodData {
	u16 image;
	u16 erase_time;
	u16 count;
	u16 score;
};

void InitTaskFood( struct TaskData* pTask , s32 x , s32 y , u16 Image , u16 erase_time , u16 Score );

#endif // __TASK_FOOD_H__
