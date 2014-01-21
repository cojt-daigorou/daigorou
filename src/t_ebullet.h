#ifndef __TASK_EBULLET_H__
#define __TASK_EBULLET_H__

#include <agtypes.h>

struct EBulletData {
	u16 image;
	s16 dx;
	s16 dy;
	u16 count;
	u16 pattern;
};

void InitTaskEBullet( struct TaskData* pTask , s32 x , s32 y , u16 Image , s16 dx , s16 dy , u16 Count , u16 Pattern );

#endif // __TASK_EBULLET_H__
