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
	    160922,    161478,    162078,    162682,    163262,    163806,
};

const u32 ageRM3Offsets0005[] = {		/* AG_RP_DAIGOROU_JUMPSTART */
	    164323,    164835,    165355,    165871,    166355,    166823,    167327,
};

const u32 ageRM3Offsets0006[] = {		/* AG_RP_DAIGOROU_RUN */
	    167832,    168428,    169020,    169584,    170164,    170668,    171196,    171768,
	    172324,    172872,    173476,    174076,
};

const u32 ageRM3Offsets0007[] = {		/* AG_RP_DAIGOROU_RUNEND */
	    174693,    175289,
};

const u32 ageRM3Offsets0008[] = {		/* AG_RP_DAIGOROU_RUNSTART */
	    175822,    176334,
};

const u32 ageRM3Offsets0009[] = {		/* AG_RP_DAIGOROU_WAIT */
	    176947,    177451,    177955,    178467,    178975,    179487,    179999,    180519,
	    181043,    181571,    182087,    182607,    183123,    183647,    184175,    184691,
	    185207,    185723,    186243,    186755,    187271,    187783,    188299,    188823,
	    189347,    189863,    190375,    190887,    191391,    191903,
};

const u32 ageRM3Offsets0010[] = {		/* AG_RP_DAIGOROU_WALK */
	    192428,    193056,    193672,    194264,    194796,    195328,    195908,    196516,
	    197136,    197748,    198364,    198976,    199584,    200164,    200728,    201244,
	    201764,    202352,    202956,    203568,    204192,
};

const u32 ageRM3Offsets0011[] = {		/* AG_RP_DAIGOROU_WALKEND */
	    204841,    205449,    206037,    206561,    207073,
};

const u32 ageRM3Offsets0012[] = {		/* AG_RP_DAIGOROU_WALKSTART */
	    207602,    208114,    208690,    209310,    209946,
};

const u32 ageRM3Offsets0013[] = {		/* AG_RP_DAIGOROU_RT */
	    210599,    211103,    211667,    212267,    212871,    213479,    214079,    214683,
	    215271,    215863,    216455,    217043,    217635,    218219,    218803,    219395,
	    219987,    220583,    221179,    221775,    222367,    222967,    223571,    224171,
	    224783,    225383,    225987,    226591,    227187,    227735,    228270,    228778,
	    229286,    229794,    230302,    230810,    231318,    231826,    232334,    232842,
	    233350,
};

const u32 ageRM3Offsets0014[] = {		/* AG_RP_EFF_RT */
	    233879,    234003,    234151,    234311,    234563,    234963,    235551,    236363,
	    237291,    238283,    239427,    240691,    241991,    243267,    244503,    245767,
	    247047,    248287,    249559,    250867,    252147,    253391,    254635,    255947,
	    257235,    258447,    259683,    260991,    262255,    263527,    264722,    265986,
	    267218,    268442,    269622,    270750,    271806,    272782,    273618,    274310,
	    274890,
};

const u32 ageRM3Offsets0015[] = {		/* AG_RP_DAIGOROU_GAMEOVER */
	    275299,    275811,    276319,    276851,    277411,    277979,    278543,    279103,
	    279667,    280227,    280787,    281343,    281891,    282427,    282967,    283507,
	    284047,    284595,    285147,    285707,    286259,    286807,    287359,    287879,
	    288399,    288931,    289471,    290019,    290551,    291115,    291658,    292202,
	    292762,    293294,    293830,    294362,    294894,    295450,    296010,    296574,
	    297122,    297674,    298210,    298738,    299238,    299706,    300146,    300554,
	    300966,    301386,    301806,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{        804,  256,  256,   7680,      9, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_DAIGOROU_CLEAR */
	{       6533,  256,  256,   7680,     10, 2, 0, ageRM3Offsets0001, NULL        },		/* AG_RP_DAIGOROU_LOSE */
	{      12721,  256,  256,   7680,     10, 2, 0, ageRM3Offsets0002, NULL        },		/* AG_RP_DAIGOROU_ONIGIRI */
	{     160317,  256,  256,   7680,      1, 2, 0, ageRM3Offsets0003, NULL        },		/* AG_RP_DAIGOROU_JUMP */
	{     160902,  256,  256,   7680,      6, 2, 0, ageRM3Offsets0004, NULL        },		/* AG_RP_DAIGOROU_JUMPEND */
	{     164303,  256,  256,   7680,      7, 2, 0, ageRM3Offsets0005, NULL        },		/* AG_RP_DAIGOROU_JUMPSTART */
	{     167812,  256,  256,   7680,     12, 2, 0, ageRM3Offsets0006, NULL        },		/* AG_RP_DAIGOROU_RUN */
	{     174673,  256,  256,   7680,      2, 2, 0, ageRM3Offsets0007, NULL        },		/* AG_RP_DAIGOROU_RUNEND */
	{     175802,  256,  256,   7680,      2, 2, 0, ageRM3Offsets0008, NULL        },		/* AG_RP_DAIGOROU_RUNSTART */
	{     176927,  256,  256,   7680,     30, 2, 0, ageRM3Offsets0009, NULL        },		/* AG_RP_DAIGOROU_WAIT */
	{     192408,  256,  256,   7680,     21, 2, 0, ageRM3Offsets0010, NULL        },		/* AG_RP_DAIGOROU_WALK */
	{     204821,  256,  256,   7680,      5, 2, 0, ageRM3Offsets0011, NULL        },		/* AG_RP_DAIGOROU_WALKEND */
	{     207582,  256,  256,   7680,      5, 2, 0, ageRM3Offsets0012, NULL        },		/* AG_RP_DAIGOROU_WALKSTART */
	{     210579,  256,  256,   7680,     41, 2, 0, ageRM3Offsets0013, NULL        },		/* AG_RP_DAIGOROU_RT */
	{     233859,  512,  512,   7680,     41, 2, 0, ageRM3Offsets0014, NULL        },		/* AG_RP_EFF_RT */
	{     275279,  256,  256,   7680,     51, 2, 0, ageRM3Offsets0015, NULL        },		/* AG_RP_DAIGOROU_GAMEOVER */
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
