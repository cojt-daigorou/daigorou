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
	{      20805,          0,  935,  493,  472,  8,      27200, NULL },		/* AG_CG_GAMECLEAR */
	{      24205,          0,  935,  493,  472,  8,      97024, NULL },		/* AG_CG_GAMEOVER */
	{      36333,          0,  516,  198,  264,  8,      15200, NULL },		/* AG_CG_GAMESTART */
	{      38233,          0,  638,   70,  320,  8,      19808, NULL },		/* AG_CG_SCOREFONT */
	{      40709,          0,  592,  357,  296,  8,      21632, NULL },		/* AG_CG_TITLE */
	{      43413,          0,   68,   66,   40,  8,       1696, NULL },		/* AG_CG_EFFECT_DMG1 */
	{      43625,          0,   68,   66,   40,  8,       2912, NULL },		/* AG_CG_EFFECT_DMG2 */
	{      43989,          0,   64,   64,   32,  8,       1248, NULL },		/* AG_CG_EFFECT_RECOVERY1 */
	{      44145,          0,   64,   64,   32,  8,       1280, NULL },		/* AG_CG_EFFECT_RECOVERY2 */
	{      44305,          0,   64,   64,   32,  8,       1120, NULL },		/* AG_CG_EFFECT_RECOVERY3 */
	{      44445,          0,   56,   56,   32,  8,       1472, NULL },		/* AG_CG_ENEMY_FROGA1 */
	{      44629,          0,   74,   63,   40,  8,       1664, NULL },		/* AG_CG_ENEMY_FROGA2 */
	{      44837,          0,   62,   38,   32,  8,       1216, NULL },		/* AG_CG_ENEMY_FROGA3 */
	{      44989,          0,   43,   41,   24,  8,       1152, NULL },		/* AG_CG_ICON_LIFE1 */
	{      45133,          0,   43,   41,   24,  8,       1184, NULL },		/* AG_CG_ICON_LIFE2 */
	{      45281,          0,   43,   41,   24,  8,       1120, NULL },		/* AG_CG_ICON_LIFE3 */
	{      45421,          0,   72,   68,   40,  8,       2624, NULL },		/* AG_CG_ENEMY_IGAGURI */
	{      45749,          0,   36,   36,   24,  8,        704, NULL },		/* AG_CG_OBJ_BLOCK1 */
	{      45837,          0,   36,   36,   24,  8,        928, NULL },		/* AG_CG_OBJ_BLOCK2 */
	{      45953,          0,   38,   40,   24,  8,       1408, NULL },		/* AG_CG_OBJ_BLOCK3 */
	{      46129,          0,   36,   36,   24,  8,        672, NULL },		/* AG_CG_OBJ_BLOCK4 */
	{      46213,          0,   79,   63,   40,  8,       1024, NULL },		/* AG_CG_OBJ_BOX1 */
	{      46341,          0,   79,   63,   40,  8,       1504, NULL },		/* AG_CG_OBJ_BOX2 */
	{      46529,          0,   37,   37,   24,  8,        608, NULL },		/* AG_CG_OBJ_CANNONBALL */
	{      46605,          0,   67,   67,   40,  8,       1696, NULL },		/* AG_CG_OBJ_CROW_BODY1 */
	{      46817,          0,   67,   67,   40,  8,       1632, NULL },		/* AG_CG_OBJ_CROW_BODY2 */
	{      47021,          0,   67,   67,   40,  8,       1632, NULL },		/* AG_CG_OBJ_CROW_BODY3 */
	{      47225,          0,   62,   74,   32,  8,       1056, NULL },		/* AG_CG_OBJ_CROW_WING_L1 */
	{      47357,          0,   62,   74,   32,  8,        960, NULL },		/* AG_CG_OBJ_CROW_WING_L2 */
	{      47477,          0,   62,   74,   32,  8,       1024, NULL },		/* AG_CG_OBJ_CROW_WING_L3 */
	{      47605,          0,   62,   74,   32,  8,       1088, NULL },		/* AG_CG_OBJ_CROW_WING_R1 */
	{      47741,          0,   62,   74,   32,  8,       1024, NULL },		/* AG_CG_OBJ_CROW_WING_R2 */
	{      47869,          0,   62,   74,   32,  8,        992, NULL },		/* AG_CG_OBJ_CROW_WING_R3 */
	{      47993,          0,  160,  128,   80,  8,       5024, NULL },		/* AG_CG_OBJ_GRASS */
	{      48621,          0,   36,   36,   24,  8,        896, NULL },		/* AG_CG_OBJ_JUMP1 */
	{      48733,          0,   36,   36,   24,  8,        864, NULL },		/* AG_CG_OBJ_JUMP2 */
	{      48841,          0,   36,   36,   24,  8,        800, NULL },		/* AG_CG_OBJ_JUMP3 */
	{      48941,          0,   38,   38,   24,  8,       1024, NULL },		/* AG_CG_OBJ_KEY */
	{      49069,          0,   38,   38,   24,  8,        928, NULL },		/* AG_CG_OBJ_KEYHOLE */
	{      49185,          0,   69,   80,   40,  8,       2272, NULL },		/* AG_CG_OBJ_MORTAR1 */
	{      49469,          0,   69,   80,   40,  8,       2208, NULL },		/* AG_CG_OBJ_MORTAR2 */
	{      49745,          0,   32,   36,   16,  8,        768, NULL },		/* AG_CG_OBJ_NEEDLE */
	{      49841,          0,   34,   34,   24,  8,        864, NULL },		/* AG_CG_OBJ_PULLEY1 */
	{      49949,          0,   34,   34,   24,  8,        896, NULL },		/* AG_CG_OBJ_PULLEY2 */
	{      50061,          0,    7,    4,    7,  3,        136, NULL },		/* AG_CG_OBJ_PULLEY3 */
	{      50078,          0,    4,    7,    4,  3,        176, NULL },		/* AG_CG_OBJ_PULLEY4 */
	{      50100,          0,    7,    4,    7,  3,        160, NULL },		/* AG_CG_OBJ_PULLEY5 */
	{      50120,          0,   50,   50,   32,  8,       1408, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS1 */
	{      50296,          0,   50,   50,   32,  8,       1600, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS2 */
	{      50496,          0,   50,   50,   32,  8,       1536, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS3 */
	{      50688,          0,   50,   50,   32,  8,       1248, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS4 */
	{      50844,          0,   50,   50,   32,  8,       1280, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS5 */
	{      51004,          0,   50,   50,   32,  8,        896, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS1 */
	{      51116,          0,   50,   50,   32,  8,       1472, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS2 */
	{      51300,          0,   50,   50,   32,  8,       1440, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS3 */
	{      51480,          0,   50,   50,   32,  8,       1248, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS4 */
	{      51636,          0,   50,   50,   32,  8,        832, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS5 */
	{      51740,          0,   50,   50,   32,  8,       1408, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS6 */
	{      51916,          0,   50,   50,   32,  8,       1408, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS7 */
	{      52092,          0,   50,   50,   32,  8,       1248, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS8 */
	{      52248,          0,   50,   50,   32,  8,       1280, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS1 */
	{      52408,          0,   50,   50,   32,  8,       1376, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS2 */
	{      52580,          0,   50,   50,   32,  8,       1568, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS3 */
	{      52776,          0,   50,   50,   32,  8,       1088, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS4 */
	{      52912,          0,   50,   50,   32,  8,       1376, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS5 */
	{      53084,          0,   50,   50,   32,  8,       1568, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS6 */
	{      53280,          0,   50,   50,   32,  8,       1184, NULL },		/* AG_CG_OBJ_SLOPE_GROUND1 */
	{      53428,          0,   50,   50,   32,  8,       1344, NULL },		/* AG_CG_OBJ_SLOPE_GROUND2 */
	{      53596,          0,   50,   50,   32,  8,       1184, NULL },		/* AG_CG_OBJ_SLOPE_GROUND3 */
	{      53744,          0,   50,   50,   32,  8,        992, NULL },		/* AG_CG_OBJ_SNAKE1 */
	{      53868,          0,   50,   50,   32,  8,       1120, NULL },		/* AG_CG_OBJ_SNAKE2 */
	{      54008,          0,   50,   50,   32,  8,        832, NULL },		/* AG_CG_OBJ_SNAKE3 */
	{      54112,          0,   50,   50,   32,  8,       1376, NULL },		/* AG_CG_OBJ_SNAKE4 */
	{      54284,          0,   50,   65,   32,  8,       1344, NULL },		/* AG_CG_OBJ_SWITCH1 */
	{      54452,          0,   50,   65,   32,  8,       1344, NULL },		/* AG_CG_OBJ_SWITCH2 */
	{      54620,          0,  110,   32,   56,  8,        896, NULL },		/* AG_CG_OBJ_TAKE1 */
	{      54732,          0,  110,   32,   56,  8,        576, NULL },		/* AG_CG_OBJ_TAKE2 */
	{      54804,          0,  110,   32,   56,  8,        992, NULL },		/* AG_CG_OBJ_TAKE3 */
	{      54928,          0,  110,   32,   56,  8,       1568, NULL },		/* AG_CG_OBJ_TAKE4 */
	{      55124,          0,  110,   32,   56,  8,        864, NULL },		/* AG_CG_OBJ_TAKE5 */
	{      55232,          0,  151,  151,   80,  8,       7104, NULL },		/* AG_CG_OBJ_WHEEL */
	{      56120,          0,  118,   20,   64,  8,       1152, NULL },		/* AG_CG_OBJ_WORKSTAND1 */
	{      56264,          0,  118,   20,   64,  8,       1088, NULL },		/* AG_CG_OBJ_WORKSTAND2 */
	{      56400,          0,   20,  118,   16,  8,       1152, NULL },		/* AG_CG_OBJ_WORKSTAND3 */
	{      56544,          0,   20,  118,   16,  8,       1120, NULL },		/* AG_CG_OBJ_WORKSTAND4 */
	{      56684,          0,   38,   39,   24,  8,       1120, NULL },		/* AG_CG_UI_ITEMFLAME */
	{      56824,          0,  512,  512,  256,  6,      10392, NULL },		/* AG_CG_BG_0_0 */
	{      58123,          0,  512,  512,  256,  6,       6904, NULL },		/* AG_CG_BG_0_1 */
	{      58986,          0,  512,  512,  256,  6,       6520, NULL },		/* AG_CG_BG_0_2 */
	{      59801,          0,  512,  512,  256,  6,       2104, NULL },		/* AG_CG_BG_0_3 */
	{      60064,          0,  452,  512,  232,  6,       1176, NULL },		/* AG_CG_BG_0_4 */
	{      60211,          0,  512,  512,  256,  6,      25400, NULL },		/* AG_CG_BG_1_0 */
	{      63386,          0,  512,  512,  256,  6,      28312, NULL },		/* AG_CG_BG_1_1 */
	{      66925,          0,  512,  512,  256,  6,      28440, NULL },		/* AG_CG_BG_1_2 */
	{      70480,          0,  512,  512,  256,  6,      30552, NULL },		/* AG_CG_BG_1_3 */
	{      74299,          0,  452,  512,  232,  6,      26488, NULL },		/* AG_CG_BG_1_4 */
	{      77610,          0,  512,  512,  256,  6,      34616, NULL },		/* AG_CG_BG_2_0 */
	{      81937,          0,  512,  512,  256,  6,      23128, NULL },		/* AG_CG_BG_2_1 */
	{      84828,          0,  512,  512,  256,  6,      25880, NULL },		/* AG_CG_BG_2_2 */
	{      88063,          0,  512,  512,  256,  6,      31352, NULL },		/* AG_CG_BG_2_3 */
	{      91982,          0,  452,  512,  232,  6,      30328, NULL },		/* AG_CG_BG_2_4 */
	{      95773,          0,  512,  512,  256,  6,      34008, NULL },		/* AG_CG_BG_3_0 */
	{     100024,          0,  512,  512,  256,  6,      30680, NULL },		/* AG_CG_BG_3_1 */
	{     103859,          0,  512,  512,  256,  6,      35256, NULL },		/* AG_CG_BG_3_2 */
	{     108266,          0,  512,  512,  256,  6,      39416, NULL },		/* AG_CG_BG_3_3 */
	{     113193,          0,  452,  512,  232,  6,      35320, NULL },		/* AG_CG_BG_3_4 */
	{     117608,          0,  512,  252,  256,  6,      37240, NULL },		/* AG_CG_BG_4_0 */
	{     122263,          0,  512,  252,  256,  6,      29048, NULL },		/* AG_CG_BG_4_1 */
	{     125894,          0,  512,  252,  256,  6,      32056, NULL },		/* AG_CG_BG_4_2 */
	{     129901,          0,  512,  252,  256,  6,      29848, NULL },		/* AG_CG_BG_4_3 */
	{     133632,          0,  452,  252,  232,  6,      32728, NULL },		/* AG_CG_BG_4_4 */
	{     218203,          0,   32,   32,   16,  8,        512, NULL },		/* AG_CG_OBJ_TOGE */
	{     218267,          0,   32,   32,   16,  8,        512, NULL },		/* AG_CG_OBJ_TOGE_D */
	{     218331,          0,   32,   32,   16,  8,        512, NULL },		/* AG_CG_OBJ_TOGE_L */
	{     218395,          0,   32,   32,   16,  8,        512, NULL },		/* AG_CG_OBJ_TOGE_R */
	{     218459,          0,  128,   32,   64,  8,       1344, NULL },		/* AG_CG_OBJ_TOGE4 */
	{     218627,          0,  128,   32,   64,  8,       1344, NULL },		/* AG_CG_OBJ_TOGE4_D */
	{     218795,          0,   34,  129,   24,  8,       1664, NULL },		/* AG_CG_OBJ_TOGE4_L */
	{     219003,          0,   34,  129,   24,  8,       1696, NULL },		/* AG_CG_OBJ_TOGE4_R */
	{     219215,          0,  128,  128,   64,  8,       5952, NULL },		/* AG_CG_OBJ_BLOCK */
	{     219959,          0,  128,  128,   64,  8,       6848, NULL },		/* AG_CG_OBJ_BLOCK_H */
	{     220815,          0,  512,  128,  256,  8,      23328, NULL },		/* AG_CG_OBJ_BLOCK4_0 */
	{     223731,          0,  512,  128,  256,  8,      26944, NULL },		/* AG_CG_OBJ_BLOCK_H4 */
	{     227099,          0,  128,   32,   64,  8,        800, NULL },		/* AG_CG_OBJ_LIFT */
	{     261640,          0,  344,  600,  176,  8,      21952, NULL },		/* AG_CG_STORY_DAIGOROU */
	{     264384,          0,  603,  600,  304,  8,      21344, NULL },		/* AG_CG_STORY_ERITAN */
	{     267052,          0,  233,  200,  120,  8,      10112, NULL },		/* AG_CG_STORY_CLOUD_ERITAN */
	{     268316,          0,  256,  210,  128,  8,      10464, NULL },		/* AG_CG_ITEM_MERONPAN256 */
	{     269624,          0,  178,  256,   96,  8,       9632, NULL },		/* AG_CG_ITEM_UNIXSP256 */
	{     270828,          0,  512,  512,  256,  8,      87360, NULL },		/* AG_CG_STORY_SHUCHU */
	{     281748,          0,  512,  512,  256,  8,      42784, NULL },		/* AG_CG_STORY_SHUCHU_SUB */
	{     287096,          0,   64,   53,   32,  8,       1696, NULL },		/* AG_CG_ITEM_MERONPAN64 */
	{     287308,          0,   45,   64,   24,  8,       1600, NULL },		/* AG_CG_ITEM_UNIXSP64 */
	{     287508,          0,   33,  128,   24,  8,       2688, NULL },		/* AG_CG_ITEM_ERITAN */
	{     287844,          0,  100,  100,   56,  8,       1888, NULL },		/* AG_CG_ICON_DAIGORO */
	{     288080,          0,   45,   64,   45,  0,      11520, NULL },		/* AG_CG_ICON_CROSS */
	{     289520,          0,   84,   80,   84,  0,      26880, NULL },		/* AG_CG_ICON_STAR */
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

const u32 ageRM3Offsets0003[] = {		/* AG_RP_DAIGOROU_GAMEOVER */
	    137743,    137991,    138243,    138499,    138771,    139039,    139307,    139579,
	    139851,    140123,    140387,    140659,    140927,    141187,    141451,    141711,
	    141971,    142231,    142503,    142775,    143035,    143303,    143571,    143819,
	    144071,    144339,    144595,    144859,    145119,    145395,    145658,    145922,
	    146190,    146462,    146726,    146986,    147246,    147522,    147794,    148070,
	    148338,    148598,    148854,    149102,    149338,    149558,    149770,    149962,
	    150154,    150350,    150546,
};

const u32 ageRM3Offsets0004[] = {		/* AG_RP_DAIGOROU_JUMP */
	    150763,
};

const u32 ageRM3Offsets0005[] = {		/* AG_RP_DAIGOROU_JUMPEND */
	    151052,    151320,    151608,    151904,    152184,    152448,
};

const u32 ageRM3Offsets0006[] = {		/* AG_RP_DAIGOROU_JUMPSTART */
	    152709,    152957,    153213,    153465,    153705,    153933,    154185,
};

const u32 ageRM3Offsets0007[] = {		/* AG_RP_DAIGOROU_RT */
	    154442,    154686,    154966,    155270,    155566,    155858,    156150,    156450,
	    156746,    157042,    157334,    157630,    157922,    158210,    158498,    158790,
	    159078,    159362,    159658,    159950,    160242,    160542,    160838,    161138,
	    161438,    161734,    162038,    162302,    162566,    162822,    163081,    163325,
	    163569,    163813,    164057,    164301,    164545,    164789,    165033,    165277,
	    165521,
};

const u32 ageRM3Offsets0008[] = {		/* AG_RP_DAIGOROU_RUN */
	    165786,    166082,    166370,    166638,    166914,    167154,    167406,    167682,
	    167950,    168210,    168502,    168802,
};

const u32 ageRM3Offsets0009[] = {		/* AG_RP_DAIGOROU_RUNEND */
	    169119,    169403,
};

const u32 ageRM3Offsets0010[] = {		/* AG_RP_DAIGOROU_RUNSTART */
	    169672,    169920,
};

const u32 ageRM3Offsets0011[] = {		/* AG_RP_DAIGOROU_WAIT */
	    170229,    170477,    170725,    170973,    171221,    171469,    171717,    171965,
	    172213,    172461,    172709,    172961,    173209,    173457,    173709,    173961,
	    174217,    174469,    174721,    174969,    175217,    175465,    175713,    175961,
	    176209,    176457,    176705,    176957,    177205,    177453,
};

const u32 ageRM3Offsets0012[] = {		/* AG_RP_DAIGOROU_WALK */
	    177722,    178030,    178330,    178618,    178878,    179138,    179422,    179718,
	    180018,    180314,    180618,    180926,    181226,    181514,    181786,    182042,
	    182298,    182586,    182882,    183182,    183490,
};

const u32 ageRM3Offsets0013[] = {		/* AG_RP_DAIGOROU_WALKEND */
	    183819,    184107,    184395,    184667,    184923,
};

const u32 ageRM3Offsets0014[] = {		/* AG_RP_DAIGOROU_WALKSTART */
	    185192,    185440,    185708,    186008,    186316,
};

const u32 ageRM3Offsets0015[] = {		/* AG_RP_EFF_RT */
	    186645,    186713,    186797,    186885,    187029,    187253,    187569,    188005,
	    188501,    189049,    189669,    190353,    191041,    191713,    192373,    193045,
	    193725,    194401,    195069,    195777,    196453,    197125,    197793,    198501,
	    199161,    199833,    200505,    201181,    201833,    202497,    203124,    203800,
	    204452,    205088,    205736,    206372,    206972,    207516,    208028,    208464,
	    208840,
};

const u32 ageRM3Offsets0016[] = {		/* AG_RP_OBJ_EBULLET */
	    209137,    209249,    209357,    209473,    209585,    209705,    209825,    209945,
	    210057,    210169,    210285,    210401,    210521,    210645,    210765,    210877,
	    210993,    211109,    211229,    211345,    211465,    211581,    211701,    211813,
	    211933,    212049,    212169,    212285,    212397,
};

const u32 ageRM3Offsets0017[] = {		/* AG_RP_OBJ_PBULLET */
	    212538,    212734,    212926,    213122,    213322,    213514,    213702,    213890,
	    214078,    214270,    214458,    214646,    214834,    215018,    215202,    215390,
	    215574,    215758,    215942,    216122,    216306,    216494,    216686,    216870,
	    217058,    217246,    217434,    217626,    217814,    218006,
};

const u32 ageRM3Offsets0018[] = {		/* AG_RP_SIN_MESSAGE */
	    227219,    232699,    237027,    241859,    247319,    251983,    257439,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{        804,  256,  256,   7680,      9, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_DAIGOROU_CLEAR */
	{       6533,  256,  256,   7680,     10, 2, 0, ageRM3Offsets0001, NULL        },		/* AG_RP_DAIGOROU_LOSE */
	{      12721,  256,  256,   7680,     10, 2, 0, ageRM3Offsets0002, NULL        },		/* AG_RP_DAIGOROU_ONIGIRI */
	{     137723,  128,  128,   7680,     51, 2, 0, ageRM3Offsets0003, NULL        },		/* AG_RP_DAIGOROU_GAMEOVER */
	{     150743,  128,  128,   7680,      1, 2, 0, ageRM3Offsets0004, NULL        },		/* AG_RP_DAIGOROU_JUMP */
	{     151032,  128,  128,   7680,      6, 2, 0, ageRM3Offsets0005, NULL        },		/* AG_RP_DAIGOROU_JUMPEND */
	{     152689,  128,  128,   7680,      7, 2, 0, ageRM3Offsets0006, NULL        },		/* AG_RP_DAIGOROU_JUMPSTART */
	{     154422,  128,  128,   7680,     41, 2, 0, ageRM3Offsets0007, NULL        },		/* AG_RP_DAIGOROU_RT */
	{     165766,  128,  128,   7680,     12, 2, 0, ageRM3Offsets0008, NULL        },		/* AG_RP_DAIGOROU_RUN */
	{     169099,  128,  128,   7680,      2, 2, 0, ageRM3Offsets0009, NULL        },		/* AG_RP_DAIGOROU_RUNEND */
	{     169652,  128,  128,   7680,      2, 2, 0, ageRM3Offsets0010, NULL        },		/* AG_RP_DAIGOROU_RUNSTART */
	{     170209,  128,  128,   7680,     30, 2, 0, ageRM3Offsets0011, NULL        },		/* AG_RP_DAIGOROU_WAIT */
	{     177702,  128,  128,   7680,     21, 2, 0, ageRM3Offsets0012, NULL        },		/* AG_RP_DAIGOROU_WALK */
	{     183799,  128,  128,   7680,      5, 2, 0, ageRM3Offsets0013, NULL        },		/* AG_RP_DAIGOROU_WALKEND */
	{     185172,  128,  128,   7680,      5, 2, 0, ageRM3Offsets0014, NULL        },		/* AG_RP_DAIGOROU_WALKSTART */
	{     186625,  256,  256,   7680,     41, 2, 0, ageRM3Offsets0015, NULL        },		/* AG_RP_EFF_RT */
	{     209117,   64,   64,   7680,     29, 2, 0, ageRM3Offsets0016, NULL        },		/* AG_RP_OBJ_EBULLET */
	{     212518,   64,   64,   7680,     30, 2, 0, ageRM3Offsets0017, NULL        },		/* AG_RP_OBJ_PBULLET */
	{     227199,  944,  408,   7680,      7, 2, 0, ageRM3Offsets0018, NULL        },		/* AG_RP_SIN_MESSAGE */
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
	{ 1,      229 },		/* AS_SND_LANDING */
	{ 1,       98 },		/* AS_SND_WALK_RIGHT */
	{ 1,      162 },		/* AS_SND_WALK_LEFT */
	{ 1,     1256 },		/* AS_SND_DECIDE008 */
	{ 1,     1433 },		/* AS_SND_A01 */
	{ 1,     3393 },		/* AS_SND_A02 */
	{ 1,     2573 },		/* AS_SND_A03 */
	{ 1,     8165 },		/* AS_SND_A04 */
	{ 1,     4918 },		/* AS_SND_B01 */
	{ 1,     2668 },		/* AS_SND_B02 */
	{ 1,      342 },		/* AS_SND_B03 */
	{ 1,     2654 },		/* AS_SND_B04 */
	{ 1,     1284 },		/* AS_SND_B05 */
	{ 1,      258 },		/* AS_SND_B06 */
	{ 1,      564 },		/* AS_SND_B07 */
	{ 1,     4166 },		/* AS_SND_B08 */
	{ 1,     7177 },		/* AS_SND_B09 */
	{ 1,     3182 },		/* AS_SND_B10 */
	{ 1,     2480 },		/* AS_SND_B11 */
};

/***************************************************************/
/*                      Sound Score Lists                      */
/***************************************************************/
const AGESoundScore ageSS[] = { { 0, 0, 0, -1, NULL } };
