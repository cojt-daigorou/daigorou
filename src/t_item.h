#ifndef __TASK_ITEM_H__
#define __TASK_ITEM_H__

#include <agtypes.h>

struct ItemData {
	u16 image;
	u16 erase_time;
	u16 count;
	u16 score;
  u16 is_keyitem;
};

void InitTaskItem( struct TaskData* pTask , s32 x , s32 y , u16 Image , u16 erase_time , u16 Score , u16 is_keyitem);

#endif // __TASK_ITEM_H__
