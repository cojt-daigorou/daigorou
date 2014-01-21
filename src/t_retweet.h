#ifndef __TASK_RETWEET_H__
#define __TASK_RETWEET_H__

#include <agtypes.h>

struct RetweetData {
	u16 image;
	u16 count;
	u8 flag;
	u8 direction;
};

void InitTaskRetweet( struct TaskData* pTask , s32 x , s32 y ,s8 dir);

#endif // __TASK_RETWEET_H__
