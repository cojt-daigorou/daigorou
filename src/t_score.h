#ifndef __TASK_SCORE_H__
#define __TASK_SCORE_H__

struct ScoreData {
	u32* pScore;
};

void InitTaskScore( struct TaskData* pTask , s32 x , s32 y , u32* pScore );

#endif // __TASK_SCORE_H__
