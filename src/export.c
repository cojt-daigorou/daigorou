#include "export.h"

/***************************************************************/
/*                       Rom Member Lists                      */
/***************************************************************/
const AGERomMember ageRM[] = {
	/*    Offset,  PalOffset,    W,    H,VramW,Type,      Size, Container */
	{      43900,          0,  107,  109,   56,  8,       3136, NULL },		/* AG_CG_ICON_FOOD_ODANGO */
	{      44292,          0,  107,  109,   56,  8,       3296, NULL },		/* AG_CG_ICON_FOOD_ONIGIRI */
	{      44704,          0,  107,  109,   56,  8,       2720, NULL },		/* AG_CG_ICON_FOOD_SUIKA */
	{      45044,          0,   87,   97,   48,  8,        160, NULL },		/* AG_CG_INFO_FOOD */
	{      45064,          0,   87,   97,   48,  8,       4064, NULL },		/* AG_CG_INFO_TIME */
	{      45572,          0,  235,   55,  120,  8,       2752, NULL },		/* AG_CG_WORKSTAND */
	{      45916,          0,  966,  647,  488,  8,      61120, NULL },		/* AG_CG_GAMECLEAR */
	{      53556,          0,  935,  493,  472,  8,      68608, NULL },		/* AG_CG_GAMEOVER */
	{      62132,          0,  516,  198,  264,  8,      15200, NULL },		/* AG_CG_GAMESTART */
	{      64032,          0,  638,   70,  320,  8,      19808, NULL },		/* AG_CG_SCOREFONT */
	{      66508,          0,  592,  357,  296,  8,      54112, NULL },		/* AG_CG_TITLE */
	{      73272,          0,  137,  133,   72,  8,       2336, NULL },		/* AG_CG_EFFECT_DMG1 */
	{      73564,          0,  137,  133,   72,  8,       2688, NULL },		/* AG_CG_EFFECT_DMG2 */
	{      73900,          0,  127,  127,   64,  8,       2016, NULL },		/* AG_CG_EFFECT_RECOVERY1 */
	{      74152,          0,  127,  127,   64,  8,       2112, NULL },		/* AG_CG_EFFECT_RECOVERY2 */
	{      74416,          0,  127,  127,   64,  8,       1952, NULL },		/* AG_CG_EFFECT_RECOVERY3 */
	{      74660,          0,  112,  112,   56,  8,       2688, NULL },		/* AG_CG_ENEMY_FROGA1 */
	{      74996,          0,  147,  126,   80,  8,       3456, NULL },		/* AG_CG_ENEMY_FROGA2 */
	{      75428,          0,  125,   75,   64,  8,       2336, NULL },		/* AG_CG_ENEMY_FROGA3 */
	{      75720,          0,   86,   82,   48,  8,       2688, NULL },		/* AG_CG_ICON_LIFE1 */
	{      76056,          0,   86,   82,   48,  8,       2784, NULL },		/* AG_CG_ICON_LIFE2 */
	{      76404,          0,   86,   82,   48,  8,       2656, NULL },		/* AG_CG_ICON_LIFE3 */
	{      76736,          0,  144,  135,   72,  8,       6848, NULL },		/* AG_CG_ENEMY_IGAGURI */
	{      77592,          0,   72,   72,   40,  8,       1504, NULL },		/* AG_CG_OBJ_BLOCK1 */
	{      77780,          0,   72,   72,   40,  8,       1664, NULL },		/* AG_CG_OBJ_BLOCK2 */
	{      77988,          0,   77,   80,   40,  8,       2272, NULL },		/* AG_CG_OBJ_BLOCK3 */
	{      78272,          0,   72,   72,   40,  8,       1248, NULL },		/* AG_CG_OBJ_BLOCK4 */
	{      78428,          0,  158,  126,   80,  8,       2592, NULL },		/* AG_CG_OBJ_BOX1 */
	{      78752,          0,  158,  126,   80,  8,       4416, NULL },		/* AG_CG_OBJ_BOX2 */
	{      79304,          0,   74,   74,   40,  8,       1152, NULL },		/* AG_CG_OBJ_CANNONBALL */
	{      79448,          0,  134,  134,   72,  8,       4384, NULL },		/* AG_CG_OBJ_CROW_BODY1 */
	{      79996,          0,  134,  134,   72,  8,       4448, NULL },		/* AG_CG_OBJ_CROW_BODY2 */
	{      80552,          0,  134,  134,   72,  8,       4608, NULL },		/* AG_CG_OBJ_CROW_BODY3 */
	{      81128,          0,  124,  148,   64,  8,       2592, NULL },		/* AG_CG_OBJ_CROW_WING_L1 */
	{      81452,          0,  124,  148,   64,  8,       2720, NULL },		/* AG_CG_OBJ_CROW_WING_L2 */
	{      81792,          0,  124,  148,   64,  8,       2400, NULL },		/* AG_CG_OBJ_CROW_WING_L3 */
	{      82092,          0,  124,  148,   64,  8,       2656, NULL },		/* AG_CG_OBJ_CROW_WING_R1 */
	{      82424,          0,  124,  148,   64,  8,       2816, NULL },		/* AG_CG_OBJ_CROW_WING_R2 */
	{      82776,          0,  124,  148,   64,  8,       2496, NULL },		/* AG_CG_OBJ_CROW_WING_R3 */
	{      83088,          0,  319,  256,  160,  8,      12480, NULL },		/* AG_CG_OBJ_GRASS */
	{      84648,          0,   72,   72,   40,  8,       1856, NULL },		/* AG_CG_OBJ_JUMP1 */
	{      84880,          0,   72,   72,   40,  8,       1696, NULL },		/* AG_CG_OBJ_JUMP2 */
	{      85092,          0,   72,   72,   40,  8,       1440, NULL },		/* AG_CG_OBJ_JUMP3 */
	{      85272,          0,   75,   76,   40,  8,       1728, NULL },		/* AG_CG_OBJ_KEY */
	{      85488,          0,   76,   75,   40,  8,       1632, NULL },		/* AG_CG_OBJ_KEYHOLE */
	{      85692,          0,  138,  159,   72,  8,       5280, NULL },		/* AG_CG_OBJ_MORTAR1 */
	{      86352,          0,  138,  159,   72,  8,       5152, NULL },		/* AG_CG_OBJ_MORTAR2 */
	{      86996,          0,   65,   73,   40,  8,       1568, NULL },		/* AG_CG_OBJ_NEEDLE */
	{      87192,          0,   69,   69,   40,  8,       1728, NULL },		/* AG_CG_OBJ_PULLEY1 */
	{      87408,          0,   69,   69,   40,  8,       1600, NULL },		/* AG_CG_OBJ_PULLEY2 */
	{      87608,          0,   14,    8,   14,  3,        240, NULL },		/* AG_CG_OBJ_PULLEY3 */
	{      87638,          0,    8,   14,    8,  3,        392, NULL },		/* AG_CG_OBJ_PULLEY4 */
	{      87687,          0,   14,    8,   14,  3,        312, NULL },		/* AG_CG_OBJ_PULLEY5 */
	{      87726,          0,  100,  100,   56,  6,       3576, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS1 */
	{      88173,          0,  100,  100,   56,  8,       3968, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS2 */
	{      88669,          0,  100,  100,   56,  8,       3872, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS3 */
	{      89153,          0,  100,  100,   56,  8,       4096, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS4 */
	{      89665,          0,  100,  100,   56,  8,       4064, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS5 */
	{      90173,          0,  100,  100,   56,  8,       1664, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS1 */
	{      90381,          0,  100,  100,   56,  8,       3104, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS2 */
	{      90769,          0,  100,  100,   56,  8,       3808, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS3 */
	{      91245,          0,  100,  100,   56,  8,       3968, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS4 */
	{      91741,          0,  100,  100,   56,  8,       1536, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS5 */
	{      91933,          0,  100,  100,   56,  8,       2912, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS6 */
	{      92297,          0,  100,  100,   56,  8,       3712, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS7 */
	{      92761,          0,  100,  100,   56,  8,       3968, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS8 */
	{      93257,          0,  100,  100,   56,  8,       2240, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS1 */
	{      93537,          0,  100,  100,   56,  8,       3808, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS2 */
	{      94013,          0,  100,  100,   56,  8,       4160, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS3 */
	{      94533,          0,  100,  100,   56,  8,       2080, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS4 */
	{      94793,          0,  100,  100,   56,  8,       3744, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS5 */
	{      95261,          0,  100,  100,   56,  8,       4032, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS6 */
	{      95765,          0,  100,  100,   56,  8,       4032, NULL },		/* AG_CG_OBJ_SLOPE_GROUND1 */
	{      96269,          0,  100,  100,   56,  8,       4384, NULL },		/* AG_CG_OBJ_SLOPE_GROUND2 */
	{      96817,          0,  100,  100,   56,  8,       4128, NULL },		/* AG_CG_OBJ_SLOPE_GROUND3 */
	{      97333,          0,  100,  100,   56,  8,       1984, NULL },		/* AG_CG_OBJ_SNAKE1 */
	{      97581,          0,  100,  100,   56,  8,       2400, NULL },		/* AG_CG_OBJ_SNAKE2 */
	{      97881,          0,  100,  100,   56,  8,       1632, NULL },		/* AG_CG_OBJ_SNAKE3 */
	{      98085,          0,  100,  100,   56,  8,       3072, NULL },		/* AG_CG_OBJ_SNAKE4 */
	{      98469,          0,  100,  130,   56,  8,       3072, NULL },		/* AG_CG_OBJ_SWITCH1 */
	{      98853,          0,  100,  130,   56,  8,       2976, NULL },		/* AG_CG_OBJ_SWITCH2 */
	{      99225,          0,  220,   64,  112,  8,       1472, NULL },		/* AG_CG_OBJ_TAKE1 */
	{      99409,          0,  220,   64,  112,  8,        832, NULL },		/* AG_CG_OBJ_TAKE2 */
	{      99513,          0,  220,   64,  112,  8,       1536, NULL },		/* AG_CG_OBJ_TAKE3 */
	{      99705,          0,  220,   64,  112,  8,       3520, NULL },		/* AG_CG_OBJ_TAKE4 */
	{     100145,          0,  220,   64,  112,  8,       1440, NULL },		/* AG_CG_OBJ_TAKE5 */
	{     100325,          0,  302,  302,  152,  8,      20832, NULL },		/* AG_CG_OBJ_WHEEL */
	{     102929,          0,  236,   41,  120,  8,       2272, NULL },		/* AG_CG_OBJ_WORKSTAND1 */
	{     103213,          0,  236,   41,  120,  8,       3232, NULL },		/* AG_CG_OBJ_WORKSTAND2 */
	{     103617,          0,   41,  236,   24,  8,       2048, NULL },		/* AG_CG_OBJ_WORKSTAND3 */
	{     103873,          0,   41,  236,   24,  8,       3168, NULL },		/* AG_CG_OBJ_WORKSTAND4 */
	{     104269,          0,   77,   78,   40,  8,       2080, NULL },		/* AG_CG_UI_ITEMFLAME */
	{     104529,          0,  512,  512,  256,  6,      10392, NULL },		/* AG_CG_BG_0_0 */
	{     105828,          0,  512,  512,  256,  6,       6904, NULL },		/* AG_CG_BG_0_1 */
	{     106691,          0,  512,  512,  256,  6,       6520, NULL },		/* AG_CG_BG_0_2 */
	{     107506,          0,  512,  512,  256,  6,       2104, NULL },		/* AG_CG_BG_0_3 */
	{     107769,          0,  452,  512,  232,  6,       1176, NULL },		/* AG_CG_BG_0_4 */
	{     107916,          0,  512,  512,  256,  6,      25400, NULL },		/* AG_CG_BG_1_0 */
	{     111091,          0,  512,  512,  256,  6,      28312, NULL },		/* AG_CG_BG_1_1 */
	{     114630,          0,  512,  512,  256,  6,      28440, NULL },		/* AG_CG_BG_1_2 */
	{     118185,          0,  512,  512,  256,  6,      30552, NULL },		/* AG_CG_BG_1_3 */
	{     122004,          0,  452,  512,  232,  6,      26488, NULL },		/* AG_CG_BG_1_4 */
	{     125315,          0,  512,  512,  256,  6,      34616, NULL },		/* AG_CG_BG_2_0 */
	{     129642,          0,  512,  512,  256,  6,      23128, NULL },		/* AG_CG_BG_2_1 */
	{     132533,          0,  512,  512,  256,  6,      25880, NULL },		/* AG_CG_BG_2_2 */
	{     135768,          0,  512,  512,  256,  6,      31352, NULL },		/* AG_CG_BG_2_3 */
	{     139687,          0,  452,  512,  232,  6,      30328, NULL },		/* AG_CG_BG_2_4 */
	{     143478,          0,  512,  512,  256,  6,      34008, NULL },		/* AG_CG_BG_3_0 */
	{     147729,          0,  512,  512,  256,  6,      30680, NULL },		/* AG_CG_BG_3_1 */
	{     151564,          0,  512,  512,  256,  6,      35256, NULL },		/* AG_CG_BG_3_2 */
	{     155971,          0,  512,  512,  256,  6,      39416, NULL },		/* AG_CG_BG_3_3 */
	{     160898,          0,  452,  512,  232,  6,      35320, NULL },		/* AG_CG_BG_3_4 */
	{     165313,          0,  512,  252,  256,  6,      37240, NULL },		/* AG_CG_BG_4_0 */
	{     169968,          0,  512,  252,  256,  6,      29048, NULL },		/* AG_CG_BG_4_1 */
	{     173599,          0,  512,  252,  256,  6,      32056, NULL },		/* AG_CG_BG_4_2 */
	{     177606,          0,  512,  252,  256,  6,      29848, NULL },		/* AG_CG_BG_4_3 */
	{     181337,          0,  452,  252,  232,  6,      32728, NULL },		/* AG_CG_BG_4_4 */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_KOMACHI_CLEAR */
	        20,       631,      1198,      1833,      2484,      3139,      3794,      4445,
	      5092,
};

const u32 ageRM3Offsets0001[] = {		/* AG_RP_KOMACHI_JUMP */
	      5749,      6300,      6863,      7446,
};

const u32 ageRM3Offsets0002[] = {		/* AG_RP_KOMACHI_JUMPEND */
	      8027,      8658,      9185,      9752,
};

const u32 ageRM3Offsets0003[] = {		/* AG_RP_KOMACHI_JUMPSTART */
	     10401,     10988,     11539,     12074,     12669,
};

const u32 ageRM3Offsets0004[] = {		/* AG_RP_KOMACHI_LOSE */
	     13290,     13981,     14656,     15299,     15914,     16501,     17092,     17675,
	     18266,     18865,
};

const u32 ageRM3Offsets0005[] = {		/* AG_RP_KOMACHI_ONIGIRI */
	     19478,     20061,     20668,     21303,     21882,     22577,     23312,     24079,
	     24910,     25617,
};

const u32 ageRM3Offsets0006[] = {		/* AG_RP_KOMACHI_RUN */
	     26350,     26981,     27588,     28171,     28874,     29609,     30312,     30991,
	     31634,     32257,
};

const u32 ageRM3Offsets0007[] = {		/* AG_RP_KOMACHI_RUNEND */
	     32862,     33517,     34132,
};

const u32 ageRM3Offsets0008[] = {		/* AG_RP_KOMACHI_RUNSTART */
	     34861,     35492,     36223,
};

const u32 ageRM3Offsets0009[] = {		/* AG_RP_KOMACHI_WAIT */
	     36904,     37619,     38334,     39033,     39728,     40419,     41106,     41797,
	     42492,     43195,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{          0,  256,  256,   7680,      9, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_KOMACHI_CLEAR */
	{       5729,  256,  256,   7680,      4, 2, 0, ageRM3Offsets0001, NULL        },		/* AG_RP_KOMACHI_JUMP */
	{       8007,  256,  256,   7680,      4, 2, 0, ageRM3Offsets0002, NULL        },		/* AG_RP_KOMACHI_JUMPEND */
	{      10381,  256,  256,   7680,      5, 2, 0, ageRM3Offsets0003, NULL        },		/* AG_RP_KOMACHI_JUMPSTART */
	{      13270,  256,  256,   7680,     10, 2, 0, ageRM3Offsets0004, NULL        },		/* AG_RP_KOMACHI_LOSE */
	{      19458,  256,  256,   7680,     10, 2, 0, ageRM3Offsets0005, NULL        },		/* AG_RP_KOMACHI_ONIGIRI */
	{      26330,  256,  256,   7680,     10, 2, 0, ageRM3Offsets0006, NULL        },		/* AG_RP_KOMACHI_RUN */
	{      32842,  256,  256,   7680,      3, 2, 0, ageRM3Offsets0007, NULL        },		/* AG_RP_KOMACHI_RUNEND */
	{      34841,  256,  256,   7680,      3, 2, 0, ageRM3Offsets0008, NULL        },		/* AG_RP_KOMACHI_RUNSTART */
	{      36884,  256,  256,   7680,     10, 2, 0, ageRM3Offsets0009, NULL        },		/* AG_RP_KOMACHI_WAIT */
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
