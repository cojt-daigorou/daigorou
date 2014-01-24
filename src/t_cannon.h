#ifndef __TASK_CANNON_H__
#define __TASK_CANNON_H__

#include <agtypes.h>

struct CannonData {
	u16 count;
	u16 sub_count;
	u16 score;
	u8 direction;
	u8 mode;
};

void InitTaskCannon( struct TaskData* pTask , s32 x , s32 y , u16 Score , u8 Direction );
static s32 HitCannon( struct TaskData* pTask , const struct RECT* pRect );

#endif // __TASK_FOOD_H__
