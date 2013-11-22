#ifndef __TASK_H__
#define __TASK_H__

#include "rect.h"
#include "t_player.h"
#include "t_bg.h"
#include "t_static.h"
#include "t_food.h"
#include "t_senario1.h"
#include "t_opening.h"
#include "t_score.h"
#include "t_frog.h"
#include "t_object.h"
#include "t_attack.h"
#include "t_snake.h"

#define TASK_MAX			(512)
#define DISP_LEVEL_MAX		(16)

#define DISP_LEVEL_BG			(0)			//�@�ŉ��w
#define DISP_LEVEL_OBJECT		(5)			//�@�I�u�W�F�N�g
#define DISP_LEVEL_FOOD			(6)			//�@�I�u�W�F�N�g
#define DISP_LEVEL_ENEMY		(7)			//�@�I�u�W�F�N�g
#define DISP_LEVEL_PLAYER		(8)			//�@���@
#define DISP_LEVEL_BG_FRONT		(9)			//�@���@�̑O�̔w�i
#define DISP_LEVEL_FRAME		(10)		//�@�g
#define DISP_LEVEL_SCORE		(11)		//�@�X�R�A
#define DISP_LEVEL_TOP			(15)		//�@�X�R�A

#define TASK_FLAG_DESTROY	(1)

enum TaskType {
	TASK_NONE = 0,
	TASK_PLAYER,
	TASK_BG,
	TASK_SCORE,
	TASK_STATIC,

	TASK_FOOD,
	TASK_ENEMY,
	TASK_EFFECT,

	TASK_SENARIO,
	TASK_OPENING,
};


struct TaskData;

typedef s32 (* TaskCalc)( struct TaskData* pTask , u32 Flag );
typedef s32 (* TaskDraw)( struct TaskData* pTask , AGDrawBuffer* pDBuf );
typedef s32 (* TaskHit)( struct TaskData* pTask , const struct RECT* pRect );

struct TaskData {
	u8 type;
	u8 visible;
	u8 stop;
	u8 flag;
	s32 x,y;

	struct TaskData* Next;
	struct TaskData* Child;

	TaskCalc Calc;
	TaskDraw Draw;
	TaskHit Hit;

	union {
		struct PlayerData player;
		struct BgData bg;
		struct StaticData st;
		struct FoodData food;
		struct SenarioData senario;
		struct TitleData title;
		struct ScoreData score;
		struct FrogData frog;
		struct ObjectData object;
		struct AttackData attack;
		struct SnakeData snake;
	} Data;
};

void ClearAllTask( void );
struct TaskData* AllocTask( void );
void AddlLink( struct TaskData* pTask , int DispLevel );
int CalcTask( u32 Flag );
int DrawTask( AGDrawBuffer* pDBuf , int DispLevel );
int DrawTaskAll( AGDrawBuffer* pDBuf );
struct TaskData* GetDispLink( int DispLevel );

#endif // __TASK_H__
