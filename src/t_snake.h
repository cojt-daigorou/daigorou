#ifndef __TASK_SNAKE_H__
#define __TASK_SNAKE_H__

#include <agtypes.h>

struct SnakeData {
	u16 count;
	u16 sub_count;
	u16 score;
	u8 mode;
};

void InitTaskSnake( struct TaskData* pTask , s32 x , s32 y , u16 Score );

#endif // __TASK_SNAKE_H__
