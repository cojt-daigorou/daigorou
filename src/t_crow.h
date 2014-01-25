#ifndef __TASK_CROW_H__
#define __TASK_CROW_H__

#include <agtypes.h>

struct CrowData {
	u16 count;
	u16 sub_count;
	u16 score;
	u8 direction;
	u8 mode;
	int vx;
	int vy;
};

void InitTaskCrow( struct TaskData* pTask , s32 x , s32 y , u16 Score , u8 Direction );
static s32 HitCROW( struct TaskData* pTask , const struct RECT* pRect );

#endif // __TASK_CROW_H__
