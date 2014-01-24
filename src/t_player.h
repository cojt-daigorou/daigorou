#ifndef __TASK_PLAYER_H__
#define __TASK_PLAYER_H__

enum {
  PLAYER_MODE_WAIT      = 0,
  PLAYER_MODE_WALKSTART    ,
  PLAYER_MODE_WALK         ,
  PLAYER_MODE_WALKEND      ,
  PLAYER_MODE_JUMPSTART    ,
  PLAYER_MODE_JUMP         ,
  PLAYER_MODE_JUMPEND      ,
  PLAYER_MODE_FALL         ,
  PLAYER_MODE_ATTACK       ,
  PLAYER_MODE_RUNSTART     ,
  PLAYER_MODE_RUN          ,
  PLAYER_MODE_RUNEND       ,
  PLAYER_MODE_GAMEOVER     ,
  PLAYER_MODE_RETWEET		   ,
};

struct PlayerData {
  u8 direction;
  u8 count;
  u8 mode;
  s32 jump_power;
};

void AddScore( u32 n );
void KillPlayer( struct TaskData* pTask );
void InitTaskPlayer( struct TaskData* pTask );

#endif // __TASK_PLAYER_H__
