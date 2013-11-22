#ifndef __TASK_BG_H__
#define __TASK_BG_H__

#include <agtypes.h>

struct BgData {
	u16 image;
	u16 alpha_flag;
};

void InitTaskBg( struct TaskData* pTask , u16 Image , u8 AlphaFlag );

#endif // __TASK_BG_H__
