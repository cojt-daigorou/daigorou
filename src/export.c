#include "export.h"

/***************************************************************/
/*                       Rom Member Lists                      */
/***************************************************************/
const AGERomMember ageRM[] = {
	/*    Offset,  PalOffset,    W,    H,VramW,Type,      Size, Container */
	{          0,          0,  107,  109,   56,  8,       3136, NULL },		/* AG_CG_ICON_FOOD_ODANGO */
	{        392,          0,  107,  109,   56,  8,       3296, NULL },		/* AG_CG_ICON_FOOD_ONIGIRI */
	{      19593,          0,  107,  109,   56,  8,       2720, NULL },		/* AG_CG_ICON_FOOD_SUIKA */
	{      19933,          0,   87,   97,   48,  8,        160, NULL },		/* AG_CG_INFO_FOOD */
	{      19953,          0,   87,   97,   48,  8,       4064, NULL },		/* AG_CG_INFO_TIME */
	{      20461,          0,  235,   55,  120,  8,       2752, NULL },		/* AG_CG_WORKSTAND */
	{      20805,          0,  966,  647,  488,  8,      61120, NULL },		/* AG_CG_GAMECLEAR */
	{      28445,          0,  935,  493,  472,  8,      68608, NULL },		/* AG_CG_GAMEOVER */
	{      37021,          0,  516,  198,  264,  8,      15200, NULL },		/* AG_CG_GAMESTART */
	{      38921,          0,  638,   70,  320,  8,      19808, NULL },		/* AG_CG_SCOREFONT */
	{      41397,          0,  592,  357,  296,  8,      54112, NULL },		/* AG_CG_TITLE */
	{      48161,          0,  137,  133,   72,  8,       2336, NULL },		/* AG_CG_EFFECT_DMG1 */
	{      48453,          0,  137,  133,   72,  8,       2688, NULL },		/* AG_CG_EFFECT_DMG2 */
	{      48789,          0,  127,  127,   64,  8,       2016, NULL },		/* AG_CG_EFFECT_RECOVERY1 */
	{      49041,          0,  127,  127,   64,  8,       2112, NULL },		/* AG_CG_EFFECT_RECOVERY2 */
	{      49305,          0,  127,  127,   64,  8,       1952, NULL },		/* AG_CG_EFFECT_RECOVERY3 */
	{      49549,          0,  112,  112,   56,  8,       2688, NULL },		/* AG_CG_ENEMY_FROGA1 */
	{      49885,          0,  147,  126,   80,  8,       3456, NULL },		/* AG_CG_ENEMY_FROGA2 */
	{      50317,          0,  125,   75,   64,  8,       2336, NULL },		/* AG_CG_ENEMY_FROGA3 */
	{      50609,          0,   86,   82,   48,  8,       2688, NULL },		/* AG_CG_ICON_LIFE1 */
	{      50945,          0,   86,   82,   48,  8,       2784, NULL },		/* AG_CG_ICON_LIFE2 */
	{      51293,          0,   86,   82,   48,  8,       2656, NULL },		/* AG_CG_ICON_LIFE3 */
	{      51625,          0,  144,  135,   72,  8,       6848, NULL },		/* AG_CG_ENEMY_IGAGURI */
	{      52481,          0,   72,   72,   40,  8,       1504, NULL },		/* AG_CG_OBJ_BLOCK1 */
	{      52669,          0,   72,   72,   40,  8,       1664, NULL },		/* AG_CG_OBJ_BLOCK2 */
	{      52877,          0,   77,   80,   40,  8,       2272, NULL },		/* AG_CG_OBJ_BLOCK3 */
	{      53161,          0,   72,   72,   40,  8,       1248, NULL },		/* AG_CG_OBJ_BLOCK4 */
	{      53317,          0,  158,  126,   80,  8,       2592, NULL },		/* AG_CG_OBJ_BOX1 */
	{      53641,          0,  158,  126,   80,  8,       4416, NULL },		/* AG_CG_OBJ_BOX2 */
	{      54193,          0,   74,   74,   40,  8,       1152, NULL },		/* AG_CG_OBJ_CANNONBALL */
	{      54337,          0,  134,  134,   72,  8,       4384, NULL },		/* AG_CG_OBJ_CROW_BODY1 */
	{      54885,          0,  134,  134,   72,  8,       4448, NULL },		/* AG_CG_OBJ_CROW_BODY2 */
	{      55441,          0,  134,  134,   72,  8,       4608, NULL },		/* AG_CG_OBJ_CROW_BODY3 */
	{      56017,          0,  124,  148,   64,  8,       2592, NULL },		/* AG_CG_OBJ_CROW_WING_L1 */
	{      56341,          0,  124,  148,   64,  8,       2720, NULL },		/* AG_CG_OBJ_CROW_WING_L2 */
	{      56681,          0,  124,  148,   64,  8,       2400, NULL },		/* AG_CG_OBJ_CROW_WING_L3 */
	{      56981,          0,  124,  148,   64,  8,       2656, NULL },		/* AG_CG_OBJ_CROW_WING_R1 */
	{      57313,          0,  124,  148,   64,  8,       2816, NULL },		/* AG_CG_OBJ_CROW_WING_R2 */
	{      57665,          0,  124,  148,   64,  8,       2496, NULL },		/* AG_CG_OBJ_CROW_WING_R3 */
	{      57977,          0,  319,  256,  160,  8,      12480, NULL },		/* AG_CG_OBJ_GRASS */
	{      59537,          0,   72,   72,   40,  8,       1856, NULL },		/* AG_CG_OBJ_JUMP1 */
	{      59769,          0,   72,   72,   40,  8,       1696, NULL },		/* AG_CG_OBJ_JUMP2 */
	{      59981,          0,   72,   72,   40,  8,       1440, NULL },		/* AG_CG_OBJ_JUMP3 */
	{      60161,          0,   75,   76,   40,  8,       1728, NULL },		/* AG_CG_OBJ_KEY */
	{      60377,          0,   76,   75,   40,  8,       1632, NULL },		/* AG_CG_OBJ_KEYHOLE */
	{      60581,          0,  138,  159,   72,  8,       5280, NULL },		/* AG_CG_OBJ_MORTAR1 */
	{      61241,          0,  138,  159,   72,  8,       5152, NULL },		/* AG_CG_OBJ_MORTAR2 */
	{      61885,          0,   65,   73,   40,  8,       1568, NULL },		/* AG_CG_OBJ_NEEDLE */
	{      62081,          0,   69,   69,   40,  8,       1728, NULL },		/* AG_CG_OBJ_PULLEY1 */
	{      62297,          0,   69,   69,   40,  8,       1600, NULL },		/* AG_CG_OBJ_PULLEY2 */
	{      62497,          0,   14,    8,   14,  3,        240, NULL },		/* AG_CG_OBJ_PULLEY3 */
	{      62527,          0,    8,   14,    8,  3,        392, NULL },		/* AG_CG_OBJ_PULLEY4 */
	{      62576,          0,   14,    8,   14,  3,        312, NULL },		/* AG_CG_OBJ_PULLEY5 */
	{      62615,          0,  100,  100,   56,  6,       3576, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS1 */
	{      63062,          0,  100,  100,   56,  8,       3968, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS2 */
	{      63558,          0,  100,  100,   56,  8,       3872, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS3 */
	{      64042,          0,  100,  100,   56,  8,       4096, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS4 */
	{      64554,          0,  100,  100,   56,  8,       4064, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS5 */
	{      65062,          0,  100,  100,   56,  8,       1664, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS1 */
	{      65270,          0,  100,  100,   56,  8,       3104, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS2 */
	{      65658,          0,  100,  100,   56,  8,       3808, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS3 */
	{      66134,          0,  100,  100,   56,  8,       3968, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS4 */
	{      66630,          0,  100,  100,   56,  8,       1536, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS5 */
	{      66822,          0,  100,  100,   56,  8,       2912, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS6 */
	{      67186,          0,  100,  100,   56,  8,       3712, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS7 */
	{      67650,          0,  100,  100,   56,  8,       3968, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS8 */
	{      68146,          0,  100,  100,   56,  8,       2240, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS1 */
	{      68426,          0,  100,  100,   56,  8,       3808, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS2 */
	{      68902,          0,  100,  100,   56,  8,       4160, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS3 */
	{      69422,          0,  100,  100,   56,  8,       2080, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS4 */
	{      69682,          0,  100,  100,   56,  8,       3744, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS5 */
	{      70150,          0,  100,  100,   56,  8,       4032, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS6 */
	{      70654,          0,  100,  100,   56,  8,       4032, NULL },		/* AG_CG_OBJ_SLOPE_GROUND1 */
	{      71158,          0,  100,  100,   56,  8,       4384, NULL },		/* AG_CG_OBJ_SLOPE_GROUND2 */
	{      71706,          0,  100,  100,   56,  8,       4128, NULL },		/* AG_CG_OBJ_SLOPE_GROUND3 */
	{      72222,          0,  100,  100,   56,  8,       1984, NULL },		/* AG_CG_OBJ_SNAKE1 */
	{      72470,          0,  100,  100,   56,  8,       2400, NULL },		/* AG_CG_OBJ_SNAKE2 */
	{      72770,          0,  100,  100,   56,  8,       1632, NULL },		/* AG_CG_OBJ_SNAKE3 */
	{      72974,          0,  100,  100,   56,  8,       3072, NULL },		/* AG_CG_OBJ_SNAKE4 */
	{      73358,          0,  100,  130,   56,  8,       3072, NULL },		/* AG_CG_OBJ_SWITCH1 */
	{      73742,          0,  100,  130,   56,  8,       2976, NULL },		/* AG_CG_OBJ_SWITCH2 */
	{      74114,          0,  220,   64,  112,  8,       1472, NULL },		/* AG_CG_OBJ_TAKE1 */
	{      74298,          0,  220,   64,  112,  8,        832, NULL },		/* AG_CG_OBJ_TAKE2 */
	{      74402,          0,  220,   64,  112,  8,       1536, NULL },		/* AG_CG_OBJ_TAKE3 */
	{      74594,          0,  220,   64,  112,  8,       3520, NULL },		/* AG_CG_OBJ_TAKE4 */
	{      75034,          0,  220,   64,  112,  8,       1440, NULL },		/* AG_CG_OBJ_TAKE5 */
	{      75214,          0,  302,  302,  152,  8,      20832, NULL },		/* AG_CG_OBJ_WHEEL */
	{      77818,          0,  236,   41,  120,  8,       2272, NULL },		/* AG_CG_OBJ_WORKSTAND1 */
	{      78102,          0,  236,   41,  120,  8,       3232, NULL },		/* AG_CG_OBJ_WORKSTAND2 */
	{      78506,          0,   41,  236,   24,  8,       2048, NULL },		/* AG_CG_OBJ_WORKSTAND3 */
	{      78762,          0,   41,  236,   24,  8,       3168, NULL },		/* AG_CG_OBJ_WORKSTAND4 */
	{      79158,          0,   77,   78,   40,  8,       2080, NULL },		/* AG_CG_UI_ITEMFLAME */
	{      79418,          0,  512,  512,  256,  6,      10392, NULL },		/* AG_CG_BG_0_0 */
	{      80717,          0,  512,  512,  256,  6,       6904, NULL },		/* AG_CG_BG_0_1 */
	{      81580,          0,  512,  512,  256,  6,       6520, NULL },		/* AG_CG_BG_0_2 */
	{      82395,          0,  512,  512,  256,  6,       2104, NULL },		/* AG_CG_BG_0_3 */
	{      82658,          0,  452,  512,  232,  6,       1176, NULL },		/* AG_CG_BG_0_4 */
	{      82805,          0,  512,  512,  256,  6,      25400, NULL },		/* AG_CG_BG_1_0 */
	{      85980,          0,  512,  512,  256,  6,      28312, NULL },		/* AG_CG_BG_1_1 */
	{      89519,          0,  512,  512,  256,  6,      28440, NULL },		/* AG_CG_BG_1_2 */
	{      93074,          0,  512,  512,  256,  6,      30552, NULL },		/* AG_CG_BG_1_3 */
	{      96893,          0,  452,  512,  232,  6,      26488, NULL },		/* AG_CG_BG_1_4 */
	{     100204,          0,  512,  512,  256,  6,      34616, NULL },		/* AG_CG_BG_2_0 */
	{     104531,          0,  512,  512,  256,  6,      23128, NULL },		/* AG_CG_BG_2_1 */
	{     107422,          0,  512,  512,  256,  6,      25880, NULL },		/* AG_CG_BG_2_2 */
	{     110657,          0,  512,  512,  256,  6,      31352, NULL },		/* AG_CG_BG_2_3 */
	{     114576,          0,  452,  512,  232,  6,      30328, NULL },		/* AG_CG_BG_2_4 */
	{     118367,          0,  512,  512,  256,  6,      34008, NULL },		/* AG_CG_BG_3_0 */
	{     122618,          0,  512,  512,  256,  6,      30680, NULL },		/* AG_CG_BG_3_1 */
	{     126453,          0,  512,  512,  256,  6,      35256, NULL },		/* AG_CG_BG_3_2 */
	{     130860,          0,  512,  512,  256,  6,      39416, NULL },		/* AG_CG_BG_3_3 */
	{     135787,          0,  452,  512,  232,  6,      35320, NULL },		/* AG_CG_BG_3_4 */
	{     140202,          0,  512,  252,  256,  6,      37240, NULL },		/* AG_CG_BG_4_0 */
	{     144857,          0,  512,  252,  256,  6,      29048, NULL },		/* AG_CG_BG_4_1 */
	{     148488,          0,  512,  252,  256,  6,      32056, NULL },		/* AG_CG_BG_4_2 */
	{     152495,          0,  512,  252,  256,  6,      29848, NULL },		/* AG_CG_BG_4_3 */
	{     156226,          0,  452,  252,  232,  6,      32728, NULL },		/* AG_CG_BG_4_4 */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_DAIGOROU_CLEAR */
	       824,      1435,      2002,      2637,      3288,      3943,      4598,      5249,
	      5896,
};

const u32 ageRM3Offsets0001[] = {		/* AG_RP_DAIGOROU_LOSE */
	      6553,      7244,      7919,      8562,      9177,      9764,     10355,     10938,
	     11529,     12128,
};

const u32 ageRM3Offsets0002[] = {		/* AG_RP_DAIGOROU_ONIGIRI */
	     12741,     13324,     13931,     14566,     15145,     15840,     16575,     17342,
	     18173,     18880,
};

const u32 ageRM3Offsets0003[] = {		/* AG_RP_DAIGOROU_JUMP */
	    160337,
};

const u32 ageRM3Offsets0004[] = {		/* AG_RP_DAIGOROU_JUMPEND */
	    160878,    161422,    161998,    162590,    163174,    163718,
};

const u32 ageRM3Offsets0005[] = {		/* AG_RP_DAIGOROU_JUMPSTART */
	    164223,    164699,    165175,    165623,    166019,    166375,    166775,
};

const u32 ageRM3Offsets0006[] = {		/* AG_RP_DAIGOROU_RUN */
	    167192,    167760,    168320,    168852,    169396,    169868,    170364,    170904,
	    171428,    171944,    172512,    173080,
};

const u32 ageRM3Offsets0007[] = {		/* AG_RP_DAIGOROU_RUNEND */
	    173669,    174229,
};

const u32 ageRM3Offsets0008[] = {		/* AG_RP_DAIGOROU_RUNSTART */
	    174726,    175202,
};

const u32 ageRM3Offsets0009[] = {		/* AG_RP_DAIGOROU_WAIT */
	    175783,
};

const u32 ageRM3Offsets0010[] = {		/* AG_RP_DAIGOROU_WALK */
	    176280,    176872,    177460,    178024,    178528,    179028,    179576,    180152,
	    180736,    181316,    181896,    182476,    183048,    183596,    184132,    184620,
	    185112,    185664,    186236,    186812,    187400,
};

const u32 ageRM3Offsets0011[] = {		/* AG_RP_DAIGOROU_WALKEND */
	    188013,    188589,    189017,    189405,    189757,
};

const u32 ageRM3Offsets0012[] = {		/* AG_RP_DAIGOROU_WALKSTART */
	    190118,    190594,    191054,    191554,    192046,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{        804,  256,  256,   7680,      9, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_DAIGOROU_CLEAR */
	{       6533,  256,  256,   7680,     10, 2, 0, ageRM3Offsets0001, NULL        },		/* AG_RP_DAIGOROU_LOSE */
	{      12721,  256,  256,   7680,     10, 2, 0, ageRM3Offsets0002, NULL        },		/* AG_RP_DAIGOROU_ONIGIRI */
	{     160317,  256,  256,   7680,      1, 2, 1, ageRM3Offsets0003, NULL        },		/* AG_RP_DAIGOROU_JUMP */
	{     160858,  256,  256,   7680,      6, 2, 0, ageRM3Offsets0004, NULL        },		/* AG_RP_DAIGOROU_JUMPEND */
	{     164203,  256,  256,   7680,      7, 2, 0, ageRM3Offsets0005, NULL        },		/* AG_RP_DAIGOROU_JUMPSTART */
	{     167172,  256,  256,   7680,     12, 2, 0, ageRM3Offsets0006, NULL        },		/* AG_RP_DAIGOROU_RUN */
	{     173649,  256,  256,   7680,      2, 2, 0, ageRM3Offsets0007, NULL        },		/* AG_RP_DAIGOROU_RUNEND */
	{     174706,  256,  256,   7680,      2, 2, 0, ageRM3Offsets0008, NULL        },		/* AG_RP_DAIGOROU_RUNSTART */
	{     175763,  256,  256,   7680,      1, 2, 1, ageRM3Offsets0009, NULL        },		/* AG_RP_DAIGOROU_WAIT */
	{     176260,  256,  256,   7680,     21, 2, 0, ageRM3Offsets0010, NULL        },		/* AG_RP_DAIGOROU_WALK */
	{     187993,  256,  256,   7680,      5, 2, 1, ageRM3Offsets0011, NULL        },		/* AG_RP_DAIGOROU_WALKEND */
	{     190098,  256,  256,   7680,      5, 2, 1, ageRM3Offsets0012, NULL        },		/* AG_RP_DAIGOROU_WALKSTART */
};

/***************************************************************/
/*                     Reserve Member Lists                    */
/***************************************************************/
const u32 ageReserve[1] = { 0 }; /* No Reserve Member */

/***************************************************************/
/*                      User Member Lists                      */
/***************************************************************/
const u32 ageUser[1] = { 0 }; /* No User Member */

/***************************************************************/
/*                      Vram Group Lists                       */
/***************************************************************/
const AGEVramGroup ageVG[] = { { 0, NULL } };
const s16 ageVGCnt = 0;

const u8* ageMotCommon[] = { NULL };
const AGEMotion ageMot[] = {
	{ 0, 0, 0, NULL, },
};
/***************************************************************/
/*                   Sound Rom Member Lists                    */
/***************************************************************/
const AGESoundRomMember ageSRM[] = {
	/* Ch, Length */
	{ 2,    49535 },		/* AS_SND_BGM */
	{ 2,     7616 },		/* AS_SND_BGM_FAST */
	{ 2,     8363 },		/* AS_SND_GAMEOVER */
	{ 2,     8767 },		/* AS_SND_GAMECLEAR */
	{ 2,     6716 },		/* AS_SND_TITLE */
	{ 1,      555 },		/* AS_SND_JUMP */
	{ 1,      446 },		/* AS_SND_TIMECOUNT */
	{ 1,      359 },		/* AS_SND_ATTACK1 */
	{ 1,      364 },		/* AS_SND_ATTACK2 */
	{ 1,      281 },		/* AS_SND_ATTACK3 */
	{ 1,      927 },		/* AS_SND_GET1 */
	{ 1,      993 },		/* AS_SND_GET2 */
	{ 1,      952 },		/* AS_SND_GET3 */
	{ 1,      362 },		/* AS_SND_CUT */
	{ 1,      541 },		/* AS_SND_LANDING */
	{ 1,      184 },		/* AS_SND_WALK_RIGHT */
	{ 1,      193 },		/* AS_SND_WALK_LEFT */
	{ 1,     1256 },		/* AS_SND_DECIDE008 */
};

/***************************************************************/
/*                      Sound Score Lists                      */
/***************************************************************/
const AGESoundScore ageSS[] = { { 0, 0, 0, -1, NULL } };
