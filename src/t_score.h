#ifndef __TASK_SCORE_H__
#define __TASK_SCORE_H__

struct ScoreData {
	u32* pScore;
  u8 digit;
};

void InitTaskScore( struct TaskData* pTask , s32 x , s32 y , u32* pScore, u8 digit );

#endif // __TASK_SCORE_H__
