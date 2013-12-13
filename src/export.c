#include "export.h"

/***************************************************************/
/*                       Rom Member Lists                      */
/***************************************************************/
const AGERomMember ageRM[] = {
	/*    Offset,  PalOffset,    W,    H,VramW,Type,      Size, Container */
	{      34732,          0,  107,  109,   56,  8,       3136, NULL },		/* AG_CG_ICON_FOOD_ODANGO */
	{      35124,          0,  107,  109,   56,  8,       3296, NULL },		/* AG_CG_ICON_FOOD_ONIGIRI */
	{      35536,          0,  107,  109,   56,  8,       2720, NULL },		/* AG_CG_ICON_FOOD_SUIKA */
	{      35876,          0,   87,   97,   48,  8,        160, NULL },		/* AG_CG_INFO_FOOD */
	{      35896,          0,   87,   97,   48,  8,       4064, NULL },		/* AG_CG_INFO_TIME */
	{      36404,          0,  235,   55,  120,  8,       2752, NULL },		/* AG_CG_WORKSTAND */
	{      36748,          0,  966,  647,  488,  8,      61120, NULL },		/* AG_CG_GAMECLEAR */
	{      44388,          0,  935,  493,  472,  8,      68608, NULL },		/* AG_CG_GAMEOVER */
	{      52964,          0,  516,  198,  264,  8,      15200, NULL },		/* AG_CG_GAMESTART */
	{      54864,          0,  638,   70,  320,  8,      19808, NULL },		/* AG_CG_SCOREFONT */
	{      57340,          0,  592,  357,  296,  8,      54112, NULL },		/* AG_CG_TITLE */
	{      64104,          0,  137,  133,   72,  8,       2336, NULL },		/* AG_CG_EFFECT_DMG1 */
	{      64396,          0,  137,  133,   72,  8,       2688, NULL },		/* AG_CG_EFFECT_DMG2 */
	{      64732,          0,  127,  127,   64,  8,       2016, NULL },		/* AG_CG_EFFECT_RECOVERY1 */
	{      64984,          0,  127,  127,   64,  8,       2112, NULL },		/* AG_CG_EFFECT_RECOVERY2 */
	{      65248,          0,  127,  127,   64,  8,       1952, NULL },		/* AG_CG_EFFECT_RECOVERY3 */
	{      65492,          0,  112,  112,   56,  8,       2688, NULL },		/* AG_CG_ENEMY_FROGA1 */
	{      65828,          0,  147,  126,   80,  8,       3456, NULL },		/* AG_CG_ENEMY_FROGA2 */
	{      66260,          0,  125,   75,   64,  8,       2336, NULL },		/* AG_CG_ENEMY_FROGA3 */
	{      66552,          0,   86,   82,   48,  8,       2688, NULL },		/* AG_CG_ICON_LIFE1 */
	{      66888,          0,   86,   82,   48,  8,       2784, NULL },		/* AG_CG_ICON_LIFE2 */
	{      67236,          0,   86,   82,   48,  8,       2656, NULL },		/* AG_CG_ICON_LIFE3 */
	{      67568,          0,  144,  135,   72,  8,       6848, NULL },		/* AG_CG_ENEMY_IGAGURI */
	{      68424,          0,   72,   72,   40,  8,       1504, NULL },		/* AG_CG_OBJ_BLOCK1 */
	{      68612,          0,   72,   72,   40,  8,       1664, NULL },		/* AG_CG_OBJ_BLOCK2 */
	{      68820,          0,   77,   80,   40,  8,       2272, NULL },		/* AG_CG_OBJ_BLOCK3 */
	{      69104,          0,   72,   72,   40,  8,       1248, NULL },		/* AG_CG_OBJ_BLOCK4 */
	{      69260,          0,  158,  126,   80,  8,       2592, NULL },		/* AG_CG_OBJ_BOX1 */
	{      69584,          0,  158,  126,   80,  8,       4416, NULL },		/* AG_CG_OBJ_BOX2 */
	{      70136,          0,   74,   74,   40,  8,       1152, NULL },		/* AG_CG_OBJ_CANNONBALL */
	{      70280,          0,  134,  134,   72,  8,       4384, NULL },		/* AG_CG_OBJ_CROW_BODY1 */
	{      70828,          0,  134,  134,   72,  8,       4448, NULL },		/* AG_CG_OBJ_CROW_BODY2 */
	{      71384,          0,  134,  134,   72,  8,       4608, NULL },		/* AG_CG_OBJ_CROW_BODY3 */
	{      71960,          0,  124,  148,   64,  8,       2592, NULL },		/* AG_CG_OBJ_CROW_WING_L1 */
	{      72284,          0,  124,  148,   64,  8,       2720, NULL },		/* AG_CG_OBJ_CROW_WING_L2 */
	{      72624,          0,  124,  148,   64,  8,       2400, NULL },		/* AG_CG_OBJ_CROW_WING_L3 */
	{      72924,          0,  124,  148,   64,  8,       2656, NULL },		/* AG_CG_OBJ_CROW_WING_R1 */
	{      73256,          0,  124,  148,   64,  8,       2816, NULL },		/* AG_CG_OBJ_CROW_WING_R2 */
	{      73608,          0,  124,  148,   64,  8,       2496, NULL },		/* AG_CG_OBJ_CROW_WING_R3 */
	{      73920,          0,  319,  256,  160,  8,      12480, NULL },		/* AG_CG_OBJ_GRASS */
	{      75480,          0,   72,   72,   40,  8,       1856, NULL },		/* AG_CG_OBJ_JUMP1 */
	{      75712,          0,   72,   72,   40,  8,       1696, NULL },		/* AG_CG_OBJ_JUMP2 */
	{      75924,          0,   72,   72,   40,  8,       1440, NULL },		/* AG_CG_OBJ_JUMP3 */
	{      76104,          0,   75,   76,   40,  8,       1728, NULL },		/* AG_CG_OBJ_KEY */
	{      76320,          0,   76,   75,   40,  8,       1632, NULL },		/* AG_CG_OBJ_KEYHOLE */
	{      76524,          0,  138,  159,   72,  8,       5280, NULL },		/* AG_CG_OBJ_MORTAR1 */
	{      77184,          0,  138,  159,   72,  8,       5152, NULL },		/* AG_CG_OBJ_MORTAR2 */
	{      77828,          0,   65,   73,   40,  8,       1568, NULL },		/* AG_CG_OBJ_NEEDLE */
	{      78024,          0,   69,   69,   40,  8,       1728, NULL },		/* AG_CG_OBJ_PULLEY1 */
	{      78240,          0,   69,   69,   40,  8,       1600, NULL },		/* AG_CG_OBJ_PULLEY2 */
	{      78440,          0,   14,    8,   14,  3,        240, NULL },		/* AG_CG_OBJ_PULLEY3 */
	{      78470,          0,    8,   14,    8,  3,        392, NULL },		/* AG_CG_OBJ_PULLEY4 */
	{      78519,          0,   14,    8,   14,  3,        312, NULL },		/* AG_CG_OBJ_PULLEY5 */
	{      78558,          0,  100,  100,   56,  6,       3576, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS1 */
	{      79005,          0,  100,  100,   56,  8,       3968, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS2 */
	{      79501,          0,  100,  100,   56,  8,       3872, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS3 */
	{      79985,          0,  100,  100,   56,  8,       4096, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS4 */
	{      80497,          0,  100,  100,   56,  8,       4064, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS5 */
	{      81005,          0,  100,  100,   56,  8,       1664, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS1 */
	{      81213,          0,  100,  100,   56,  8,       3104, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS2 */
	{      81601,          0,  100,  100,   56,  8,       3808, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS3 */
	{      82077,          0,  100,  100,   56,  8,       3968, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS4 */
	{      82573,          0,  100,  100,   56,  8,       1536, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS5 */
	{      82765,          0,  100,  100,   56,  8,       2912, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS6 */
	{      83129,          0,  100,  100,   56,  8,       3712, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS7 */
	{      83593,          0,  100,  100,   56,  8,       3968, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS8 */
	{      84089,          0,  100,  100,   56,  8,       2240, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS1 */
	{      84369,          0,  100,  100,   56,  8,       3808, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS2 */
	{      84845,          0,  100,  100,   56,  8,       4160, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS3 */
	{      85365,          0,  100,  100,   56,  8,       2080, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS4 */
	{      85625,          0,  100,  100,   56,  8,       3744, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS5 */
	{      86093,          0,  100,  100,   56,  8,       4032, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS6 */
	{      86597,          0,  100,  100,   56,  8,       4032, NULL },		/* AG_CG_OBJ_SLOPE_GROUND1 */
	{      87101,          0,  100,  100,   56,  8,       4384, NULL },		/* AG_CG_OBJ_SLOPE_GROUND2 */
	{      87649,          0,  100,  100,   56,  8,       4128, NULL },		/* AG_CG_OBJ_SLOPE_GROUND3 */
	{      88165,          0,  100,  100,   56,  8,       1984, NULL },		/* AG_CG_OBJ_SNAKE1 */
	{      88413,          0,  100,  100,   56,  8,       2400, NULL },		/* AG_CG_OBJ_SNAKE2 */
	{      88713,          0,  100,  100,   56,  8,       1632, NULL },		/* AG_CG_OBJ_SNAKE3 */
	{      88917,          0,  100,  100,   56,  8,       3072, NULL },		/* AG_CG_OBJ_SNAKE4 */
	{      89301,          0,  100,  130,   56,  8,       3072, NULL },		/* AG_CG_OBJ_SWITCH1 */
	{      89685,          0,  100,  130,   56,  8,       2976, NULL },		/* AG_CG_OBJ_SWITCH2 */
	{      90057,          0,  220,   64,  112,  8,       1472, NULL },		/* AG_CG_OBJ_TAKE1 */
	{      90241,          0,  220,   64,  112,  8,        832, NULL },		/* AG_CG_OBJ_TAKE2 */
	{      90345,          0,  220,   64,  112,  8,       1536, NULL },		/* AG_CG_OBJ_TAKE3 */
	{      90537,          0,  220,   64,  112,  8,       3520, NULL },		/* AG_CG_OBJ_TAKE4 */
	{      90977,          0,  220,   64,  112,  8,       1440, NULL },		/* AG_CG_OBJ_TAKE5 */
	{      91157,          0,  302,  302,  152,  8,      20832, NULL },		/* AG_CG_OBJ_WHEEL */
	{      93761,          0,  236,   41,  120,  8,       2272, NULL },		/* AG_CG_OBJ_WORKSTAND1 */
	{      94045,          0,  236,   41,  120,  8,       3232, NULL },		/* AG_CG_OBJ_WORKSTAND2 */
	{      94449,          0,   41,  236,   24,  8,       2048, NULL },		/* AG_CG_OBJ_WORKSTAND3 */
	{      94705,          0,   41,  236,   24,  8,       3168, NULL },		/* AG_CG_OBJ_WORKSTAND4 */
	{      95101,          0,   77,   78,   40,  8,       2080, NULL },		/* AG_CG_UI_ITEMFLAME */
	{      95361,          0,  512,  512,  256,  6,      10392, NULL },		/* AG_CG_BG_0_0 */
	{      96660,          0,  512,  512,  256,  6,       6904, NULL },		/* AG_CG_BG_0_1 */
	{      97523,          0,  512,  512,  256,  6,       6520, NULL },		/* AG_CG_BG_0_2 */
	{      98338,          0,  512,  512,  256,  6,       2104, NULL },		/* AG_CG_BG_0_3 */
	{      98601,          0,  452,  512,  232,  6,       1176, NULL },		/* AG_CG_BG_0_4 */
	{      98748,          0,  512,  512,  256,  6,      25400, NULL },		/* AG_CG_BG_1_0 */
	{     101923,          0,  512,  512,  256,  6,      28312, NULL },		/* AG_CG_BG_1_1 */
	{     105462,          0,  512,  512,  256,  6,      28440, NULL },		/* AG_CG_BG_1_2 */
	{     109017,          0,  512,  512,  256,  6,      30552, NULL },		/* AG_CG_BG_1_3 */
	{     112836,          0,  452,  512,  232,  6,      26488, NULL },		/* AG_CG_BG_1_4 */
	{     116147,          0,  512,  512,  256,  6,      34616, NULL },		/* AG_CG_BG_2_0 */
	{     120474,          0,  512,  512,  256,  6,      23128, NULL },		/* AG_CG_BG_2_1 */
	{     123365,          0,  512,  512,  256,  6,      25880, NULL },		/* AG_CG_BG_2_2 */
	{     126600,          0,  512,  512,  256,  6,      31352, NULL },		/* AG_CG_BG_2_3 */
	{     130519,          0,  452,  512,  232,  6,      30328, NULL },		/* AG_CG_BG_2_4 */
	{     134310,          0,  512,  512,  256,  6,      34008, NULL },		/* AG_CG_BG_3_0 */
	{     138561,          0,  512,  512,  256,  6,      30680, NULL },		/* AG_CG_BG_3_1 */
	{     142396,          0,  512,  512,  256,  6,      35256, NULL },		/* AG_CG_BG_3_2 */
	{     146803,          0,  512,  512,  256,  6,      39416, NULL },		/* AG_CG_BG_3_3 */
	{     151730,          0,  452,  512,  232,  6,      35320, NULL },		/* AG_CG_BG_3_4 */
	{     156145,          0,  512,  252,  256,  6,      37240, NULL },		/* AG_CG_BG_4_0 */
	{     160800,          0,  512,  252,  256,  6,      29048, NULL },		/* AG_CG_BG_4_1 */
	{     164431,          0,  512,  252,  256,  6,      32056, NULL },		/* AG_CG_BG_4_2 */
	{     168438,          0,  512,  252,  256,  6,      29848, NULL },		/* AG_CG_BG_4_3 */
	{     172169,          0,  452,  252,  232,  6,      32728, NULL },		/* AG_CG_BG_4_4 */
};

/***************************************************************/
/*                       RM3 Member Lists                      */
/***************************************************************/
const u32 ageRM3Offsets0000[] = {		/* AG_RP_KOMACHI_CLEAR */
	        20,       631,      1198,      1833,      2484,      3139,      3794,      4445,
	      5092,
};

const u32 ageRM3Offsets0001[] = {		/* AG_RP_KOMACHI_JUMP */
	      5749,
};

const u32 ageRM3Offsets0002[] = {		/* AG_RP_KOMACHI_JUMPEND */
	      6290,      6834,      7410,      8002,      8586,      9130,
};

const u32 ageRM3Offsets0003[] = {		/* AG_RP_KOMACHI_JUMPSTART */
	      9635,     10111,     10587,     11035,     11431,     11787,     12187,
};

const u32 ageRM3Offsets0004[] = {		/* AG_RP_KOMACHI_LOSE */
	     12604,     13295,     13970,     14613,     15228,     15815,     16406,     16989,
	     17580,     18179,
};

const u32 ageRM3Offsets0005[] = {		/* AG_RP_KOMACHI_ONIGIRI */
	     18792,     19375,     19982,     20617,     21196,     21891,     22626,     23393,
	     24224,     24931,
};

const u32 ageRM3Offsets0006[] = {		/* AG_RP_KOMACHI_RUN */
	     25664,     26232,     26792,     27324,     27868,     28340,     28836,     29376,
	     29900,     30416,     30984,     31552,
};

const u32 ageRM3Offsets0007[] = {		/* AG_RP_KOMACHI_RUNEND */
	     32141,     32701,
};

const u32 ageRM3Offsets0008[] = {		/* AG_RP_KOMACHI_RUNSTART */
	     33198,     33674,
};

const u32 ageRM3Offsets0009[] = {		/* AG_RP_KOMACHI_WAIT */
	     34255,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{          0,  256,  256,   7680,      9, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_KOMACHI_CLEAR */
	{       5729,  256,  256,   7680,      1, 2, 1, ageRM3Offsets0001, NULL        },		/* AG_RP_KOMACHI_JUMP */
	{       6270,  256,  256,   7680,      6, 2, 0, ageRM3Offsets0002, NULL        },		/* AG_RP_KOMACHI_JUMPEND */
	{       9615,  256,  256,   7680,      7, 2, 0, ageRM3Offsets0003, NULL        },		/* AG_RP_KOMACHI_JUMPSTART */
	{      12584,  256,  256,   7680,     10, 2, 0, ageRM3Offsets0004, NULL        },		/* AG_RP_KOMACHI_LOSE */
	{      18772,  256,  256,   7680,     10, 2, 0, ageRM3Offsets0005, NULL        },		/* AG_RP_KOMACHI_ONIGIRI */
	{      25644,  256,  256,   7680,     12, 2, 0, ageRM3Offsets0006, NULL        },		/* AG_RP_KOMACHI_RUN */
	{      32121,  256,  256,   7680,      2, 2, 0, ageRM3Offsets0007, NULL        },		/* AG_RP_KOMACHI_RUNEND */
	{      33178,  256,  256,   7680,      2, 2, 0, ageRM3Offsets0008, NULL        },		/* AG_RP_KOMACHI_RUNSTART */
	{      34235,  256,  256,   7680,      1, 2, 1, ageRM3Offsets0009, NULL        },		/* AG_RP_KOMACHI_WAIT */
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
