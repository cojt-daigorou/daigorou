#ifndef __TASK_STORY_H__
#define __TASK_STORY_H__

#include <agtypes.h>

struct StoryData {
	s32 bgm_handle;
	s32 voice_handle;
  u16 mode;
  u16 count;
  struct TaskData *pButtonTask;
};

void InitTaskStory( struct TaskData* pTask );

#endif // __TASK_STORY_H__
