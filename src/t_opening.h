#ifndef __TASK_OPENING_H__
#define __TASK_OPENING_H__

#include <agtypes.h>

struct TitleData {
	s32 bgm_handle;
	u16 mode;
	u16 count;
};

void InitTaskOpening( struct TaskData* pTask );

#endif // __TASK_OPENING_H__
