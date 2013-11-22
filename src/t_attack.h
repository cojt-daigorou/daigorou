#ifndef __TASK_ATTACK_H__
#define __TASK_ATTACK_H__

#include <agtypes.h>

struct AttackData {
	u16 count;
};

void InitTaskAttack( struct TaskData* pTask , s32 x , s32 y );

#endif // __TASK_ATTACK_H__
