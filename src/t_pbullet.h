#ifndef __TASK_PBULLET_H__
#define __TASK_PBULLET_H__

#include <agtypes.h>

struct PBulletData {
	u16 image;
	s16 dx;
	s16 dy;
	u16 count;
	u16 pattern;
};

void InitTaskPBullet( struct TaskData* pTask , s32 x , s32 y , u16 Image , s16 dx , s16 dy , u16 Count , u16 Pattern );

#endif // __TASK_PBULLET_H__
