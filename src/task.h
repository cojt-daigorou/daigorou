#ifndef __TASK_H__
#define __TASK_H__

#include "rect.h"
#include "t_player.h"
#include "t_bg.h"
#include "t_static.h"
#include "t_static2.h"
#include "t_item.h"
#include "t_senario1.h"
#include "t_opening.h"
#include "t_score.h"
#include "t_frog.h"
#include "t_snake.h"
#include "t_crow.h"
#include "t_cannon.h"
#include "t_object.h"
#include "t_attack.h"
#include "t_pbullet.h"
#include "t_ebullet.h"
#include "t_retweet.h"
#include "t_story.h"

#define TASK_MAX			    (256)
#define TASK_FLAG_DESTROY	(1)

enum DISP_LEVEL {
  DISP_LEVEL_BG = 0,			//　最下層
  DISP_LEVEL_OBJECT, 	    //　オブジェクト
  DISP_LEVEL_ITEM,			 	//　オブジェクト
  DISP_LEVEL_ENEMY,		 	  //　オブジェクト
  DISP_LEVEL_PBULLET,     //　自機の弾
  DISP_LEVEL_EBULLET,     //　敵の弾
  DISP_LEVEL_ATTACK,      //　星の爆発
  DISP_LEVEL_PLAYER,		 	//　自機
  DISP_LEVEL_BG_FRONT,	  //　自機の前の背景
  DISP_LEVEL_FRAME,		 	  //　枠
  DISP_LEVEL_INFO,		 	  //　インジケーター
  DISP_LEVEL_SCORE,		 	  //　インジケーター
  DISP_LEVEL_TOP,		      //　トップ
  DISP_LEVEL_MAX,		  
};

enum TaskType {
	TASK_NONE = 0,
	TASK_PLAYER,
	TASK_BG,
	TASK_SCORE,
	TASK_STATIC,
  TASK_STORY,

	TASK_ITEM,
	TASK_ENEMY,
	TASK_EFFECT,

	TASK_SENARIO,
	TASK_OPENING,

	TASK_PBULLET,
	TASK_EBULLET,
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
		struct Static2Data st2;
    struct StoryData story;
		struct ItemData item;
		struct SenarioData senario;
		struct TitleData title;
		struct ScoreData score;
		struct FrogData frog;
		struct SnakeData snake;
		struct CrowData crow;
		struct CannonData cannon;
		struct ObjectData object;
		struct AttackData attack;
		struct PBulletData pbullet;
		struct EBulletData ebullet;
		struct RetweetData retweet;
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
