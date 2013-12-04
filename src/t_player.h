#ifndef __TASK_PLAYER_H__
#define __TASK_PLAYER_H__

#define PLAYER_MODE_WAIT		(0)
#define PLAYER_MODE_RUNSTART	(1)
#define PLAYER_MODE_RUN			(2)
#define PLAYER_MODE_RUNEND		(3)
#define PLAYER_MODE_JUMPSTART	(4)
#define PLAYER_MODE_JUMP		(5)
#define PLAYER_MODE_JUMPEND		(6)
#define PLAYER_MODE_FALL		(7)
#define PLAYER_MODE_ATTACK		(8)

#define PLAYER_WALK_SPEED		(8)
#define PLAYER_RUN_SPEED		(16)

#define GROUND_LINE				(548)

struct PlayerData {
	u8 direction;
	u8 count;
	u8 mode;
	u8 jump_count;
};

void InitTaskPlayer( struct TaskData* pTask );

#endif // __TASK_PLAYER_H__
