#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "randMT.h"
#include "export.h"
#include "global.h"
#include "t_senario1.h"

/******************************************************************/
/*                          シナリオ１                            */
/******************************************************************/
static struct SPos {
  int x, y;
  int type;
  int image;
};

enum {
  OBJECT_TYPE_HIT = 0 ,
  OBJECT_TYPE_BREAKABLE ,
  OBJECT_TYPE_NOHIT   ,
  OBJECT_TYPE_FRONT   ,
  OBJECT_TYPE_HIT_H1  ,
  OBJECT_TYPE_HIT_V1  ,
  OBJECT_TYPE_HIT_H2  ,
  OBJECT_TYPE_HIT_V2  ,
  OBJECT_TYPE_TOGE    ,
  OBJECT_TYPE_TOGE_H1 ,
  OBJECT_TYPE_TOGE_V1 ,
  OBJECT_TYPE_TOGE_H2 ,
  OBJECT_TYPE_TOGE_V2 ,
};

enum {
  ENEMY_TYPE_FROG = 0 ,
  ENEMY_TYPE_SNAKE    ,
  ENEMY_TYPE_CANNON   ,
  ENEMY_TYPE_CROW,
};

enum {
  ITEM_TYPE_STAR = 0  ,
  ITEM_TYPE_SCORE_A   ,
  ITEM_TYPE_SCORE_B   ,
  ITEM_TYPE_KEY       ,
};


//----------------------------------------------------------
// stage 1
//----------------------------------------------------------

static struct SPos wpos_1[] = {
  { 150, GROUND_LINE-32,  OBJECT_TYPE_TOGE, AG_CG_OBJ_TOGE4 },
  { 200, GROUND_LINE-128, OBJECT_TYPE_FRONT, AG_CG_OBJ_GRASS },

  //{ 800, 500, OBJECT_TYPE_HIT_V1, AG_CG_OBJ_LIFT },

  { 1024,     GROUND_LINE-128,  OBJECT_TYPE_BREAKABLE,  AG_CG_OBJ_BLOCK },
  { 1024-128*1,     GROUND_LINE-128, OBJECT_TYPE_HIT,  AG_CG_OBJ_BLOCK_H },
  { 1024-128*2,     GROUND_LINE-128,  OBJECT_TYPE_BREAKABLE,  AG_CG_OBJ_BLOCK },

  { 1024,     GROUND_LINE-128*2,  OBJECT_TYPE_BREAKABLE,  AG_CG_OBJ_BLOCK },
  { 1024-128*1,     GROUND_LINE-128*2,  OBJECT_TYPE_BREAKABLE,  AG_CG_OBJ_BLOCK },
  { 1024-128*2,     GROUND_LINE-128*2,  OBJECT_TYPE_BREAKABLE,  AG_CG_OBJ_BLOCK },

  { 1024,     GROUND_LINE-128*3,  OBJECT_TYPE_HIT,  AG_CG_OBJ_BLOCK_H },
  { 1024-128*1,     GROUND_LINE-128*3,  OBJECT_TYPE_HIT,  AG_CG_OBJ_BLOCK_H },
  { 1024-128*2,     GROUND_LINE-128*3,  OBJECT_TYPE_HIT,  AG_CG_OBJ_BLOCK_H },
  { 3500+400*5, GROUND_LINE-32,   OBJECT_TYPE_TOGE,       AG_CG_OBJ_TOGE },
  { 2000, GROUND_LINE-128, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },

  { 2372+128*0, GROUND_LINE-128*1, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 2372+128*1, GROUND_LINE-128*1, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 2372+128*2, GROUND_LINE-128*1, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 2372+128*0, GROUND_LINE-128*2, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 2372+128*1, GROUND_LINE-128*2, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 2372+128*2, GROUND_LINE-128*2, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 2372+128*0, GROUND_LINE-128*3, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 2372+128*1, GROUND_LINE-128*3, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 2372+128*2, GROUND_LINE-128*3, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },

  { 3000, GROUND_LINE-128, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },

  { 3500+400*0, GROUND_LINE-90*1 , OBJECT_TYPE_HIT_H1, AG_CG_OBJ_LIFT },
  { 3500+400*1, GROUND_LINE-90*2 , OBJECT_TYPE_HIT_H2, AG_CG_OBJ_LIFT },
  { 3500+400*2, GROUND_LINE-90*3 , OBJECT_TYPE_HIT_H1, AG_CG_OBJ_LIFT },
  { 3500+400*3, GROUND_LINE-90*4 , OBJECT_TYPE_HIT_H2, AG_CG_OBJ_LIFT },
  { 3500+400*4, GROUND_LINE-90*5 , OBJECT_TYPE_HIT_H1, AG_CG_OBJ_LIFT },
  { 3500+400*5, GROUND_LINE-90*6 , OBJECT_TYPE_HIT,    AG_CG_OBJ_LIFT },

  { 5800 , GROUND_LINE-128*1 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800 , GROUND_LINE-128*2 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800 , GROUND_LINE-128*3 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800 , GROUND_LINE-128*4 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800 , GROUND_LINE-128*5 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800 , GROUND_LINE-128*6 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800 , GROUND_LINE-128*7 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800-80  ,GROUND_LINE-128*1, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},
  { 5800-80  ,GROUND_LINE-128*2, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},
  { 5800-80  ,GROUND_LINE-128*3, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},
  { 5800-80  ,GROUND_LINE-128*4, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},
  { 5800-80  ,GROUND_LINE-128*5, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},
  { 5800-80  ,GROUND_LINE-128*6, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},
  { 5800-80  ,GROUND_LINE-128*7, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},

};

static struct SPos ipos_1[] = {
  { 200 , GROUND_LINE , ITEM_TYPE_SCORE_B , 0 },

  { 2372+128*0, GROUND_LINE-128*0, ITEM_TYPE_SCORE_A, 0 },
  { 2372+128*1, GROUND_LINE-128*0, ITEM_TYPE_SCORE_B, 0 },
  { 2372+128*2, GROUND_LINE-128*0, ITEM_TYPE_STAR, 0 },
  { 2372+128*0, GROUND_LINE-128*1, ITEM_TYPE_SCORE_B, 0 },
  { 2372+128*1, GROUND_LINE-128*1, ITEM_TYPE_STAR, 0 },
  { 2372+128*2, GROUND_LINE-128*1, ITEM_TYPE_SCORE_A, 0 },
//  { 2372+128*0, GROUND_LINE-128*2, ITEM_TYPE_STAR, 0 },
//  { 2372+128*1, GROUND_LINE-128*2, ITEM_TYPE_SCORE_A, 0 },
//  { 2372+128*2, GROUND_LINE-128*2, ITEM_TYPE_SCORE_B, 0 },

  { 3500+400*0, GROUND_LINE-90*1, ITEM_TYPE_SCORE_B, 0 },
  { 3500+400*1, GROUND_LINE-90*2, ITEM_TYPE_SCORE_A, 0 },
  { 3500+400*2, GROUND_LINE-90*4, ITEM_TYPE_STAR,    0 },
  { 3500+400*3, GROUND_LINE-90*5, ITEM_TYPE_SCORE_A, 0 },
  { 3500+400*4, GROUND_LINE-90*7, ITEM_TYPE_SCORE_A, 0 },

  { 3500+400*5, GROUND_LINE-90*6, ITEM_TYPE_KEY,     AG_CG_ITEM_MERONPAN64 },

#ifdef IS_DEBUG
  { 300, GROUND_LINE, ITEM_TYPE_KEY, AG_CG_ITEM_MERONPAN64 },
#endif

};

static struct SPos epos_1[] = {
  { 1024-128*1,     GROUND_LINE-128*3,  ENEMY_TYPE_CANNON, 0 },
  { 1500, GROUND_LINE,      ENEMY_TYPE_FROG  , 0 },
  { 2000, GROUND_LINE-32*4, ENEMY_TYPE_SNAKE , 0 },
  { 4000, GROUND_LINE,      ENEMY_TYPE_FROG  , 0 },
  { 5500, GROUND_LINE,      ENEMY_TYPE_FROG  , 0 },
  { 7500, GROUND_LINE,      ENEMY_TYPE_FROG  , 0 },

};


//----------------------------------------------------------
// stage 2
//----------------------------------------------------------

static struct SPos wpos_2[] = {
  { 2800+400*0 , 500 , OBJECT_TYPE_HIT_H1 , AG_CG_OBJ_LIFT },
  { 800,500, OBJECT_TYPE_TOGE_V2,AG_CG_OBJ_TOGE4_D},
  { 800,500-128, OBJECT_TYPE_HIT_V2,AG_CG_OBJ_BLOCK_H},
  { 1200,GROUND_LINE-128, OBJECT_TYPE_BREAKABLE,AG_CG_OBJ_BLOCK},
  { 1600,500, OBJECT_TYPE_TOGE_V2,AG_CG_OBJ_TOGE4_D},
  { 1600,500-128, OBJECT_TYPE_HIT_V2,AG_CG_OBJ_BLOCK_H},
  { 2400,GROUND_LINE-200, OBJECT_TYPE_BREAKABLE,AG_CG_OBJ_BLOCK},
  { 2400+128,GROUND_LINE-200, OBJECT_TYPE_BREAKABLE,AG_CG_OBJ_BLOCK},
  { 3100+400*0 , 500 , OBJECT_TYPE_HIT_H1 , AG_CG_OBJ_LIFT },
  { 3100+400*1 , 400 , OBJECT_TYPE_HIT_H2 , AG_CG_OBJ_LIFT },
  { 3100+400*2 , 300 , OBJECT_TYPE_HIT_H1 , AG_CG_OBJ_LIFT },
  { 3100+400*2 , 500 , OBJECT_TYPE_HIT_H1 , AG_CG_OBJ_LIFT },
  { 3100+400*3 , 200 , OBJECT_TYPE_HIT_H2 , AG_CG_OBJ_LIFT },
  { 3100+400*4 , 100 , OBJECT_TYPE_HIT_H1 , AG_CG_OBJ_LIFT },
  { 3100+400*5 , 000 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_LIFT },
  { 3100+400*3+200 , 350 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 3100+400*3+200+80  ,350, OBJECT_TYPE_TOGE_V2,AG_CG_OBJ_TOGE4_R},
  { 3100+400*3+200-80  ,350, OBJECT_TYPE_TOGE_V2,AG_CG_OBJ_TOGE4_L},
  { 3100+400*4+200 , 350 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 3100+400*4+200+80  ,350, OBJECT_TYPE_TOGE_V2,AG_CG_OBJ_TOGE4_R},
  { 3100+400*4+200-80  ,350, OBJECT_TYPE_TOGE_V2,AG_CG_OBJ_TOGE4_L},

  { 5800 , GROUND_LINE-128*1 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800 , GROUND_LINE-128*2 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800 , GROUND_LINE-128*3 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800 , GROUND_LINE-128*4 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800 , GROUND_LINE-128*5 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800 , GROUND_LINE-128*6 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800 , GROUND_LINE-128*7 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800-80  ,GROUND_LINE-128*1, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},
  { 5800-80  ,GROUND_LINE-128*2, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},
  { 5800-80  ,GROUND_LINE-128*3, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},
  { 5800-80  ,GROUND_LINE-128*4, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},
  { 5800-80  ,GROUND_LINE-128*5, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},
  { 5800-80  ,GROUND_LINE-128*6, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},
  { 5800-80  ,GROUND_LINE-128*7, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},

};

static struct SPos ipos_2[] = {
  //{ 800+100*0 , GROUND_LINE , ITEM_TYPE_SCORE_A , 0 },
  //{ 800+100*1 , GROUND_LINE , ITEM_TYPE_STAR , 0 },
  //{ 800+100*2 , GROUND_LINE , ITEM_TYPE_SCORE_B , 0 },
  { 3100+400*4-200 , 350 , ITEM_TYPE_SCORE_B ,   0 },
  { 3100+400*4+200 , 350 , ITEM_TYPE_SCORE_B ,   0 },

#ifdef IS_DEBUG
  { 200 , GROUND_LINE-30 , ITEM_TYPE_KEY , AG_CG_ITEM_UNIXSP64 },
#endif

  { 3100+400*5 , 000 , ITEM_TYPE_KEY , AG_CG_ITEM_UNIXSP64 },
};

static struct SPos epos_2[] = {
  //{ 820  , 674 , ENEMY_TYPE_FROG  , 30 },
  { 3000, GROUND_LINE , ENEMY_TYPE_CANNON  , 0 },
  { 4200 , 0 , ENEMY_TYPE_CROW , 0 },
};


//----------------------------------------------------------
// stage 3
//----------------------------------------------------------

static struct SPos wpos_3[] = {

  // 1
  { 800+128*0, GROUND_LINE-128, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },
  { 800+128*1, GROUND_LINE-32, OBJECT_TYPE_TOGE, AG_CG_OBJ_TOGE4 },
  { 800+128*2, GROUND_LINE-32, OBJECT_TYPE_TOGE, AG_CG_OBJ_TOGE4 },
  { 800+128*3, GROUND_LINE-32, OBJECT_TYPE_TOGE, AG_CG_OBJ_TOGE4 },
  { 800+128*4, GROUND_LINE-32, OBJECT_TYPE_TOGE, AG_CG_OBJ_TOGE4 },
  { 800+128*5, GROUND_LINE-32, OBJECT_TYPE_TOGE, AG_CG_OBJ_TOGE4 },
  { 800+128*6, GROUND_LINE-128, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },

  { 800+128*3, GROUND_LINE-250 , OBJECT_TYPE_HIT_H1 , AG_CG_OBJ_LIFT },

  // 2
  { 3000, GROUND_LINE-128*1, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },
  { 3000, GROUND_LINE-128*2, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },
  { 3000, GROUND_LINE-128*3, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },
  { 3000, GROUND_LINE-128*4, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },

  //{ 3000-64-16, GROUND_LINE-128*1, OBJECT_TYPE_TOGE, AG_CG_OBJ_TOGE4_L },
  { 3000-64-16, GROUND_LINE-128*2+32, OBJECT_TYPE_TOGE, AG_CG_OBJ_TOGE4_L },
  //{ 3000-64-16, GROUND_LINE-128*3, OBJECT_TYPE_TOGE, AG_CG_OBJ_TOGE4_L },
  { 3000-64-16, GROUND_LINE-128*4+32, OBJECT_TYPE_TOGE, AG_CG_OBJ_TOGE4_L },

  //{3000+64+16, GROUND_LINE-128*4, OBJECT_TYPE_TOGE, AG_CG_OBJ_TOGE4_R },
  { 3000+64+16, GROUND_LINE-128*3, OBJECT_TYPE_TOGE, AG_CG_OBJ_TOGE4_R },
  //{ 3000+64+16, GROUND_LINE-128*2, OBJECT_TYPE_TOGE, AG_CG_OBJ_TOGE4_R },
  { 3000+64+16, GROUND_LINE-128*1, OBJECT_TYPE_TOGE, AG_CG_OBJ_TOGE4_R },

  { 2800, GROUND_LINE-128*2.4, OBJECT_TYPE_HIT_V2 , AG_CG_OBJ_LIFT },


  // 3
  { 4000,       GROUND_LINE-128*4-128*1, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },
  { 4000+128*2, GROUND_LINE-128*4-128*1, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },

  { 4000+128*0, GROUND_LINE-128*4-128*3, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },
  { 4000+128*1, GROUND_LINE-128*4-128*3, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },
  { 4000+128*2, GROUND_LINE-128*4-128*3, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },
  { 4000+128*3, GROUND_LINE-128*4-128*3, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },
  { 4000+128*4, GROUND_LINE-128*4-128*3, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },
  { 4000+128*5, GROUND_LINE-128*4-128*3, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },

  { 4000+128*0, GROUND_LINE-128*4-128*0, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },
  { 4000+128*1, GROUND_LINE-128*4-128*0, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },
  { 4000+128*2, GROUND_LINE-128*4-128*0, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },
  { 4000+128*3, GROUND_LINE-128*4-128*0, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },
  { 4000+128*4, GROUND_LINE-128*4-128*0, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },
  { 4000+128*5, GROUND_LINE-128*4-128*0, OBJECT_TYPE_HIT, AG_CG_OBJ_BLOCK_H },

  { 4000+128,   GROUND_LINE-128*4-32, OBJECT_TYPE_TOGE, AG_CG_OBJ_TOGE4 },

  { 4000+128*0, GROUND_LINE-128*4-128*2, OBJECT_TYPE_TOGE, AG_CG_OBJ_TOGE4_D },
  { 4000+128*1, GROUND_LINE-128*4-128*2, OBJECT_TYPE_TOGE, AG_CG_OBJ_TOGE4_D },
  { 4000+128*2, GROUND_LINE-128*4-128*2, OBJECT_TYPE_TOGE, AG_CG_OBJ_TOGE4_D },

  { 2900+128*5, GROUND_LINE-128*1, OBJECT_TYPE_HIT , AG_CG_OBJ_LIFT },
  { 2900+128*3, GROUND_LINE-128*2, OBJECT_TYPE_HIT , AG_CG_OBJ_LIFT },
  { 2900+128*5, GROUND_LINE-128*3, OBJECT_TYPE_HIT , AG_CG_OBJ_LIFT },
  { 2900+128*7, GROUND_LINE-128*4, OBJECT_TYPE_HIT , AG_CG_OBJ_LIFT },

  { 4000+128*0, GROUND_LINE-128*1, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 4000+128*1, GROUND_LINE-128*1, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 4000+128*2, GROUND_LINE-128*1, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 4000+128*3, GROUND_LINE-128*1, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 4000+128*4, GROUND_LINE-128*1, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 4000+128*5, GROUND_LINE-128*1, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 4000+128*0, GROUND_LINE-128*2, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 4000+128*1, GROUND_LINE-128*2, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 4000+128*2, GROUND_LINE-128*2, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 4000+128*3, GROUND_LINE-128*2, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 4000+128*4, GROUND_LINE-128*2, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 4000+128*5, GROUND_LINE-128*2, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 4000+128*0, GROUND_LINE-128*3, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 4000+128*1, GROUND_LINE-128*3, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 4000+128*2, GROUND_LINE-128*3, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 4000+128*3, GROUND_LINE-128*3, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 4000+128*4, GROUND_LINE-128*3, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },
  { 4000+128*5, GROUND_LINE-128*3, OBJECT_TYPE_BREAKABLE, AG_CG_OBJ_BLOCK },

  { 5800 , GROUND_LINE-128*1 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800 , GROUND_LINE-128*2 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800 , GROUND_LINE-128*3 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800 , GROUND_LINE-128*4 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800 , GROUND_LINE-128*5 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800 , GROUND_LINE-128*6 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800 , GROUND_LINE-128*7 , OBJECT_TYPE_HIT ,   AG_CG_OBJ_BLOCK_H },
  { 5800-80  ,GROUND_LINE-128*1, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},
  { 5800-80  ,GROUND_LINE-128*2, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},
  { 5800-80  ,GROUND_LINE-128*3, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},
  { 5800-80  ,GROUND_LINE-128*4, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},
  { 5800-80  ,GROUND_LINE-128*5, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},
  { 5800-80  ,GROUND_LINE-128*6, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},
  { 5800-80  ,GROUND_LINE-128*7, OBJECT_TYPE_TOGE , AG_CG_OBJ_TOGE4_L},

  // えりたん
#ifdef IS_DEBUG
  { 200 , GROUND_LINE-128 , OBJECT_TYPE_FRONT , AG_CG_ITEM_ERITAN },
#endif

  { 5200 , GROUND_LINE-128 , OBJECT_TYPE_FRONT , AG_CG_ITEM_ERITAN },
};

static struct SPos ipos_3[] = {
  { 800+128*1 ,GROUND_LINE-350 , ITEM_TYPE_SCORE_A , 0 },
  { 800+128*3 ,GROUND_LINE-350 , ITEM_TYPE_STAR , 0 },
  { 800+128*5 ,GROUND_LINE-350 , ITEM_TYPE_SCORE_B , 0 },

  { 4000+128*3, GROUND_LINE-128*4-128*1, ITEM_TYPE_SCORE_B, 0 },
  { 4000+128*4, GROUND_LINE-128*4-128*1, ITEM_TYPE_SCORE_B, 0 },
  { 4000+128*5, GROUND_LINE-128*4-128*1, ITEM_TYPE_SCORE_B, 0 },

  { 4000+128*3, GROUND_LINE-128*4-128*0, ITEM_TYPE_SCORE_B, 0 },
  { 4000+128*4, GROUND_LINE-128*4-128*0, ITEM_TYPE_SCORE_B, 0 },
  { 4000+128*5, GROUND_LINE-128*4-128*0, ITEM_TYPE_SCORE_B, 0 },

  // えりたん
#ifdef IS_DEBUG
  { 200 ,GROUND_LINE , ITEM_TYPE_KEY , AG_CG_ITEM_ERITAN },
#endif

  { 5200 ,GROUND_LINE , ITEM_TYPE_KEY , AG_CG_ITEM_ERITAN },
};

static struct SPos epos_3[] = {
  { 700  , 674 , ENEMY_TYPE_FROG  , 0 },
  { 1501  , 674 , ENEMY_TYPE_CANNON  , 0 },
  { 2000  , 0 , ENEMY_TYPE_CROW  , 0 },
  { 2150+20*1  , 0 , ENEMY_TYPE_CROW  , 0 },
  { 2150+20*2  , -30 , ENEMY_TYPE_CROW  , 0 },
  { 2150+20*3  , -60 , ENEMY_TYPE_CROW  , 0 },
  { 2150+20*4  , -90 , ENEMY_TYPE_CROW  , 0 },
  { 2150+20*5  , -120 , ENEMY_TYPE_CROW  , 0 },
  { 2150+20*6  , -150 , ENEMY_TYPE_CROW  , 0 },
  { 2150  , 0 , ENEMY_TYPE_CROW  , 0 },
  { 2150+20*1  , 0 , ENEMY_TYPE_CROW  , 0 },
  { 2150+20*2  , GROUND_LINE+20 , ENEMY_TYPE_CROW  , 0 },
  { 2150+20*3  , GROUND_LINE+40 , ENEMY_TYPE_CROW  , 0 },
  { 2150+20*4  , GROUND_LINE+60 , ENEMY_TYPE_CROW  , 0 },
  { 2150+20*5  , GROUND_LINE+80 , ENEMY_TYPE_CROW  , 0 },
  { 2150+20*6  , GROUND_LINE+100 , ENEMY_TYPE_CROW  , 0 },
};



//
// ボーナススコア関連
//

// Time や Life を考慮した BonusScore を計算
static int CalcBonusScore() {
  if ( g_Stage < STAGE_N - 1 ) {
    return min( g_Score + BSCORE_TIME * g_Time, SCORE_MAX );
  } else {
    return min( g_Score + BSCORE_TIME * g_Time + BSCORE_LIFE * g_Life + BSCORE_STAR * g_Star, SCORE_MAX );
  }
}

// Bonus の加算が完了したら、TRUE を返す。
static int AddBonusScore() {
  if ( g_Stage < STAGE_N - 1 ) {
    if ( g_Time > 0) {
      g_Score += BSCORE_TIME;
      g_Time -= 1;
    }
    return g_Time == 0;
  } else {
    if ( g_Time > 0) {
      g_Score += BSCORE_TIME;
      g_Time--;
    }
    if ( g_Life > 0) {
      g_Score += BSCORE_LIFE;
      g_Life--;
    }
    if ( g_Star > 0 ) {
      g_Score += BSCORE_STAR;
      g_Star--;
    }

    g_Score = min( g_Score, SCORE_MAX );
    return g_Time == 0 && g_Life == 0 && g_Star == 0;
  }
}



static s32 CalcSenario1( struct TaskData* pTask , u32 Flag ) {
  pTask->x++;

  //　ソフトリセット
  if( PadTrg()&PAD_UP && PadTrg()&PAD_DOWN ) {
    ageSndMgrRelease( pTask->Data.senario.bgm_handle );
    GotoMode( MODE_TITLE );
  };

  if( g_isGameOver ) {
    pTask->x++;
    if( pTask->x > 800 ) {
      ageSndMgrRelease( pTask->Data.senario.bgm_handle );
      GotoMode( MODE_TITLE );
    };
    return(0);
  };

  if ( g_isStageClear ) {
    pTask->x++;
    if( AddBonusScore() && pTask->x > 800 ) {
      if ( g_isHighScore ) {
        g_HighScoreS[ g_Stage ] = g_Score;
      }
      ageSndMgrRelease( pTask->Data.senario.bgm_handle );
      g_Stage++;
      GotoMode( MODE_STORY );
    }; 
    return(0);
  };

  if( g_Time > 0 && (pTask->x % 60) == 0 ) {
    g_Time--;
#ifdef IS_DEBUG
    g_Time-=19;
# endif

    if( g_Time == 30 ) {
      ageSndMgrRelease( pTask->Data.senario.bgm_handle );

      pTask->Data.senario.bgm_handle = ageSndMgrAlloc( AS_SND_BGM_2_441_HU , 0 , 1 , AGE_SNDMGR_PANMODE_LR12 , 0 );

      ageSndMgrPlay( pTask->Data.senario.bgm_handle );
      ageSndMgrSetVolume( pTask->Data.senario.bgm_handle , 0xa0 );
      ageSndMgrSetPanMode( pTask->Data.senario.bgm_handle , 0 );
      ageSndMgrSetPan( pTask->Data.senario.bgm_handle , 0x8080 );
    };

    if( g_Time == 0) {
      struct TaskData* pETask;
      int w,h;

      w = ageRM[ AG_CG_TIMEOVER ].Width;
      h = ageRM[ AG_CG_TIMEOVER ].Height;

      pETask = AllocTask();
      InitTaskStatic( pETask , (1024-w)/2 , (768-h)/2 , AG_CG_TIMEOVER , 1 );
      AddlLink( pETask , DISP_LEVEL_TOP );

      ageSndMgrRelease( pTask->Data.senario.bgm_handle );

      pTask->Data.senario.bgm_handle = ageSndMgrAlloc( AS_SND_GAMEOVER , 0 , 1 , AGE_SNDMGR_PANMODE_LR12 , 0 );

      ageSndMgrPlay( pTask->Data.senario.bgm_handle );
      ageSndMgrSetVolume( pTask->Data.senario.bgm_handle , 0xa0 );
      ageSndMgrSetPanMode( pTask->Data.senario.bgm_handle , 0 );
      ageSndMgrSetPan( pTask->Data.senario.bgm_handle , 0x8080 );

      --g_Life;
      KillPlayer( g_pPlayerTask );
    };
  };

  if( g_Life == 0 ) {
    struct TaskData* pETask;
    int w,h;

    w = ageRM[ AG_CG_GAMEOVER ].Width;
    h = ageRM[ AG_CG_GAMEOVER ].Height;

    pETask = AllocTask();
    InitTaskStatic( pETask , (1024-w)/2 , (768-h)/2 , AG_CG_GAMEOVER , 1 );
    AddlLink( pETask , DISP_LEVEL_TOP );

    ageSndMgrRelease( pTask->Data.senario.bgm_handle );

    pTask->Data.senario.bgm_handle = ageSndMgrAlloc( AS_SND_GAMEOVER , 0 , 1 , AGE_SNDMGR_PANMODE_LR12 , 0 );

    ageSndMgrPlay( pTask->Data.senario.bgm_handle );
    ageSndMgrSetVolume( pTask->Data.senario.bgm_handle , 0xa0 );
    ageSndMgrSetPanMode( pTask->Data.senario.bgm_handle , 0 );
    ageSndMgrSetPan( pTask->Data.senario.bgm_handle , 0x8080 );

    g_isGameOver = TRUE;
    pTask->x = 0;

    ageSndMgrPlayOneshot( (g_OffsetX % 2) ? AS_SND_A02 : AS_SND_A03 , 0 , 0x80 , AGE_SNDMGR_PANMODE_LR12 , 0x80 , 0 );
  };

  if ( g_isGetKeyItem ){
    struct TaskData* pETask;
    int w,h,y;

    w = ageRM[ AG_CG_GAMEOVER ].Width;
    h = ageRM[ AG_CG_GAMEOVER ].Height;

    // ステージクリア
    pETask = AllocTask();
    InitTaskStatic2( pETask, (1024-w)/2, (768*3/4-h)/2, AG_CG_GAMECLEAR, Static2Type_MoveVertical, 0 );
    AddlLink( pETask , DISP_LEVEL_TOP );

    y = 400;

    // NEW RECORD
    if ( CalcBonusScore() > g_HighScoreS[ g_Stage ] ) {
      g_isHighScore = TRUE;

      pETask = AllocTask();
      w = ageRM[ AG_CG_TEXT_NEWRECORD ].Width;
      InitTaskStatic2( pETask , (1024-w)/2 , y , AG_CG_TEXT_NEWRECORD , Static2Type_Blink, 0 );
      AddlLink( pETask , DISP_LEVEL_TOP );

      y += 100;
    }

    // SCORE
    pETask = AllocTask();
    InitTaskStatic2( pETask, 100, y, AG_CG_TEXT_SCORE, Static2Type_MoveHorizon, 40 );
    AddlLink( pETask , DISP_LEVEL_TOP );

    pETask = AllocTask();
    InitTaskScore( pETask , 600 , y , &(g_Score), 4 );
    AddlLink( pETask , DISP_LEVEL_TOP );

    y += 100;

    // HIGH SCORE
    pETask = AllocTask();
    InitTaskStatic2( pETask, 100, y, AG_CG_TEXT_HIGHSCORE, Static2Type_MoveHorizon, 80 );
    AddlLink( pETask , DISP_LEVEL_TOP );

    pETask = AllocTask();
    InitTaskScore( pETask , 600 , y , &(g_HighScoreS[ g_Stage ]), 4 );
    AddlLink( pETask , DISP_LEVEL_TOP );


    // BGM
    ageSndMgrRelease( pTask->Data.senario.bgm_handle );

    pTask->Data.senario.bgm_handle = ageSndMgrAlloc( AS_SND_GAMECLEAR , 0 , 1 , AGE_SNDMGR_PANMODE_LR12 , 0 );

    ageSndMgrPlay( pTask->Data.senario.bgm_handle );
    ageSndMgrSetVolume( pTask->Data.senario.bgm_handle , 0xa0 );
    ageSndMgrSetPanMode( pTask->Data.senario.bgm_handle , 0 );
    ageSndMgrSetPan( pTask->Data.senario.bgm_handle , 0x8080 );

    g_isStageClear = TRUE;
    pTask->x = 0;
  };

  return( 0 );
}

void InitTaskSenario1( struct TaskData* pTask ) {
  int i;
  struct SPos *wpos, *ipos, *epos; 
  int wn, fn, en;

  memset( pTask , 0 , sizeof( *pTask ) );
  g_pSenarioTask = pTask;

  srandMT( 3475573 );

  pTask->type = TASK_SENARIO;
  pTask->Calc = CalcSenario1;
  pTask->x = 0;
  pTask->y = 0;

  g_isHighScore = FALSE;

  switch( g_Stage ) {
    case 0:
      wpos = wpos_1;
      ipos = ipos_1;
      epos = epos_1;
      wn = (sizeof( wpos_1 )/sizeof( wpos_1[0] ));
      fn = (sizeof( ipos_1 )/sizeof( ipos_1[0] ));
      en = (sizeof( epos_1 )/sizeof( epos_1[0] ));
      break;

    case 1:
      wpos = wpos_2;
      ipos = ipos_2;
      epos = epos_2;
      wn = (sizeof( wpos_2 )/sizeof( wpos_2[0] ));
      fn = (sizeof( ipos_2 )/sizeof( ipos_2[0] ));
      en = (sizeof( epos_2 )/sizeof( epos_2[0] ));
      break;

    case 2:
      wpos = wpos_3;
      ipos = ipos_3;
      epos = epos_3;
      wn = (sizeof( wpos_3 )/sizeof( wpos_3[0] ));
      fn = (sizeof( ipos_3 )/sizeof( ipos_3[0] ));
      en = (sizeof( epos_3 )/sizeof( epos_3[0] ));
      break;
  }


  //　固定オブジェクトの作成
  for( i=0 ; i<wn ; i++ ) {
    struct TaskData* pWTask;

    u16 is_hit        = TRUE;
    u16 is_harmful    = FALSE;
    u16 is_breakable  = FALSE;

    enum ObjectMotion motion = ObjectMotion_None;
    float phase       = 0.0;
    float frequency   = 0.0;
    float amplitude   = 0.0;

    int disp_level = DISP_LEVEL_OBJECT;

    switch ( wpos[i].type ) {
      case OBJECT_TYPE_HIT:
        break;

      case OBJECT_TYPE_BREAKABLE:
        is_breakable = TRUE;
        break;

      case OBJECT_TYPE_NOHIT:
        is_hit = FALSE;
        break;

      case OBJECT_TYPE_FRONT:
        is_hit = FALSE;
        disp_level = DISP_LEVEL_BG_FRONT;
        break;

      case OBJECT_TYPE_HIT_H1:
        motion = ObjectMotion_Horizon;
        phase = 0.0;
        frequency = 0.025;
        amplitude = 100;
        break;

      case OBJECT_TYPE_HIT_V1:
        motion = ObjectMotion_Vertical;
        phase = 0.0;
        frequency = 0.03;
        amplitude = 100;
        break;

      case OBJECT_TYPE_HIT_H2:
        motion = ObjectMotion_Horizon;
        phase = PI;
        frequency = 0.025;
        amplitude = 100;
        break;

      case OBJECT_TYPE_HIT_V2:
        motion = ObjectMotion_Vertical;
        phase = PI;
        frequency = 0.03;
        amplitude = 100;
        break;

      case OBJECT_TYPE_TOGE:
        is_harmful = TRUE;
        break;

      case OBJECT_TYPE_TOGE_H1:
        is_harmful = TRUE;
        motion = ObjectMotion_Horizon;
        phase = 0.0;
        frequency = 0.05;
        amplitude = 100;
        break;

      case OBJECT_TYPE_TOGE_V1: 
        is_harmful = TRUE;
        motion = ObjectMotion_Vertical;
        phase = 0.0;
        frequency = 0.03;
        amplitude = 100;
        break;

      case OBJECT_TYPE_TOGE_H2: 
        is_harmful = TRUE;
        motion = ObjectMotion_Horizon;
        phase = PI;
        frequency = 0.05;
        amplitude = 100;
        break;

      case OBJECT_TYPE_TOGE_V2: 
        is_harmful = TRUE;
        motion = ObjectMotion_Vertical;
        phase = PI;
        frequency = 0.03;
        amplitude = 100;
        break;
    }

    pWTask = AllocTask();
    InitTaskObject( pWTask , wpos[i].x , wpos[i].y , wpos[i].image , 
        is_hit, is_harmful, is_breakable, 
        motion, phase, frequency, amplitude );
    AddlLink( pWTask , disp_level );
  };

  //　食べ物の作成
  for( i=0 ; i<fn ; i++ ) {
    struct TaskData* pITask;

    int image = 0;
    int score = 0;
    int star = 0;
    int time = 0;
    u16 is_keyitem = FALSE;

    switch ( ipos[i].type ) {
      case ITEM_TYPE_STAR:
        image = AG_CG_ICON_STAR;
        star = 20;
        break;

      case ITEM_TYPE_SCORE_A:
        image = AG_CG_ITEM_BONE_AG;
        score = 10;
        break;

      case ITEM_TYPE_SCORE_B:
        image = AG_CG_ITEM_BONE_AU;
        score = 50;
        break;

      case ITEM_TYPE_KEY:
        image = ipos[i].image;
        is_keyitem = TRUE;
        break;
    }

    pITask = AllocTask();
    InitTaskItem( pITask, ipos[i].x, ipos[i].y, image, score, star, time, is_keyitem);
    AddlLink( pITask , DISP_LEVEL_ITEM );
  };

  //　敵の作成
  for( i=0 ; i<en ; i++ ) {
    struct TaskData* pETask;

    pETask = AllocTask();
    switch( epos[i].type ) {
      case ENEMY_TYPE_FROG :
        InitTaskFrog( pETask, epos[i].x, epos[i].y, 10, 0 );
        break;

      case ENEMY_TYPE_SNAKE :
        InitTaskSnake( pETask, epos[i].x, epos[i].y, 20 );
        break;

      case ENEMY_TYPE_CANNON :
        InitTaskCannon( pETask, epos[i].x, epos[i].y, 30, epos[i].x%2 );
        break;
      case ENEMY_TYPE_CROW :
        InitTaskCrow( pETask, epos[i].x, epos[i].y, 30, 0 );
        break;
      default :
        break;
    };
    AddlLink( pETask , DISP_LEVEL_ENEMY );
  };

  pTask->Data.senario.bgm_handle = ageSndMgrAlloc( AS_SND_BGM_2_441 , 0 , 1 , AGE_SNDMGR_PANMODE_LR12 , 0 );

  ageSndMgrPlay( pTask->Data.senario.bgm_handle );
  ageSndMgrSetVolume( pTask->Data.senario.bgm_handle , 0xa0 );
  ageSndMgrSetPanMode( pTask->Data.senario.bgm_handle , 0 );
  ageSndMgrSetPan( pTask->Data.senario.bgm_handle , 0x8080 );
}
