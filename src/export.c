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
	{      28445,          0,  935,  493,  472,  8,      97024, NULL },		/* AG_CG_GAMEOVER */
	{      40573,          0,  516,  198,  264,  8,      15200, NULL },		/* AG_CG_GAMESTART */
	{      42473,          0,  638,   70,  320,  8,      19808, NULL },		/* AG_CG_SCOREFONT */
	{      44949,          0,  592,  357,  296,  8,      21632, NULL },		/* AG_CG_TITLE */
	{      47653,          0,   68,   66,   40,  8,       1696, NULL },		/* AG_CG_EFFECT_DMG1 */
	{      47865,          0,   68,   66,   40,  8,       2912, NULL },		/* AG_CG_EFFECT_DMG2 */
	{      48229,          0,   64,   64,   32,  8,       1248, NULL },		/* AG_CG_EFFECT_RECOVERY1 */
	{      48385,          0,   64,   64,   32,  8,       1280, NULL },		/* AG_CG_EFFECT_RECOVERY2 */
	{      48545,          0,   64,   64,   32,  8,       1120, NULL },		/* AG_CG_EFFECT_RECOVERY3 */
	{      48685,          0,   56,   56,   32,  8,       1472, NULL },		/* AG_CG_ENEMY_FROGA1 */
	{      48869,          0,   74,   63,   40,  8,       1664, NULL },		/* AG_CG_ENEMY_FROGA2 */
	{      49077,          0,   62,   38,   32,  8,       1216, NULL },		/* AG_CG_ENEMY_FROGA3 */
	{      49229,          0,   43,   41,   24,  8,       1152, NULL },		/* AG_CG_ICON_LIFE1 */
	{      49373,          0,   43,   41,   24,  8,       1184, NULL },		/* AG_CG_ICON_LIFE2 */
	{      49521,          0,   43,   41,   24,  8,       1120, NULL },		/* AG_CG_ICON_LIFE3 */
	{      49661,          0,   72,   68,   40,  8,       2624, NULL },		/* AG_CG_ENEMY_IGAGURI */
	{      49989,          0,   36,   36,   24,  8,        704, NULL },		/* AG_CG_OBJ_BLOCK1 */
	{      50077,          0,   36,   36,   24,  8,        928, NULL },		/* AG_CG_OBJ_BLOCK2 */
	{      50193,          0,   38,   40,   24,  8,       1408, NULL },		/* AG_CG_OBJ_BLOCK3 */
	{      50369,          0,   36,   36,   24,  8,        672, NULL },		/* AG_CG_OBJ_BLOCK4 */
	{      50453,          0,   79,   63,   40,  8,       1024, NULL },		/* AG_CG_OBJ_BOX1 */
	{      50581,          0,   79,   63,   40,  8,       1504, NULL },		/* AG_CG_OBJ_BOX2 */
	{      50769,          0,   37,   37,   24,  8,        608, NULL },		/* AG_CG_OBJ_CANNONBALL */
	{      50845,          0,   67,   67,   40,  8,       1696, NULL },		/* AG_CG_OBJ_CROW_BODY1 */
	{      51057,          0,   67,   67,   40,  8,       1632, NULL },		/* AG_CG_OBJ_CROW_BODY2 */
	{      51261,          0,   67,   67,   40,  8,       1632, NULL },		/* AG_CG_OBJ_CROW_BODY3 */
	{      51465,          0,   62,   74,   32,  8,       1056, NULL },		/* AG_CG_OBJ_CROW_WING_L1 */
	{      51597,          0,   62,   74,   32,  8,        960, NULL },		/* AG_CG_OBJ_CROW_WING_L2 */
	{      51717,          0,   62,   74,   32,  8,       1024, NULL },		/* AG_CG_OBJ_CROW_WING_L3 */
	{      51845,          0,   62,   74,   32,  8,       1088, NULL },		/* AG_CG_OBJ_CROW_WING_R1 */
	{      51981,          0,   62,   74,   32,  8,       1024, NULL },		/* AG_CG_OBJ_CROW_WING_R2 */
	{      52109,          0,   62,   74,   32,  8,        992, NULL },		/* AG_CG_OBJ_CROW_WING_R3 */
	{      52233,          0,  160,  128,   80,  8,       5024, NULL },		/* AG_CG_OBJ_GRASS */
	{      52861,          0,   36,   36,   24,  8,        896, NULL },		/* AG_CG_OBJ_JUMP1 */
	{      52973,          0,   36,   36,   24,  8,        864, NULL },		/* AG_CG_OBJ_JUMP2 */
	{      53081,          0,   36,   36,   24,  8,        800, NULL },		/* AG_CG_OBJ_JUMP3 */
	{      53181,          0,   38,   38,   24,  8,       1024, NULL },		/* AG_CG_OBJ_KEY */
	{      53309,          0,   38,   38,   24,  8,        928, NULL },		/* AG_CG_OBJ_KEYHOLE */
	{      53425,          0,   69,   80,   40,  8,       2272, NULL },		/* AG_CG_OBJ_MORTAR1 */
	{      53709,          0,   69,   80,   40,  8,       2208, NULL },		/* AG_CG_OBJ_MORTAR2 */
	{      53985,          0,   32,   36,   16,  8,        768, NULL },		/* AG_CG_OBJ_NEEDLE */
	{      54081,          0,   34,   34,   24,  8,        864, NULL },		/* AG_CG_OBJ_PULLEY1 */
	{      54189,          0,   34,   34,   24,  8,        896, NULL },		/* AG_CG_OBJ_PULLEY2 */
	{      54301,          0,    7,    4,    7,  3,        136, NULL },		/* AG_CG_OBJ_PULLEY3 */
	{      54318,          0,    4,    7,    4,  3,        176, NULL },		/* AG_CG_OBJ_PULLEY4 */
	{      54340,          0,    7,    4,    7,  3,        160, NULL },		/* AG_CG_OBJ_PULLEY5 */
	{      54360,          0,   50,   50,   32,  8,       1408, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS1 */
	{      54536,          0,   50,   50,   32,  8,       1600, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS2 */
	{      54736,          0,   50,   50,   32,  8,       1536, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS3 */
	{      54928,          0,   50,   50,   32,  8,       1248, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS4 */
	{      55084,          0,   50,   50,   32,  8,       1280, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS5 */
	{      55244,          0,   50,   50,   32,  8,        896, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS1 */
	{      55356,          0,   50,   50,   32,  8,       1472, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS2 */
	{      55540,          0,   50,   50,   32,  8,       1440, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS3 */
	{      55720,          0,   50,   50,   32,  8,       1248, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS4 */
	{      55876,          0,   50,   50,   32,  8,        832, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS5 */
	{      55980,          0,   50,   50,   32,  8,       1408, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS6 */
	{      56156,          0,   50,   50,   32,  8,       1408, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS7 */
	{      56332,          0,   50,   50,   32,  8,       1248, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS8 */
	{      56488,          0,   50,   50,   32,  8,       1280, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS1 */
	{      56648,          0,   50,   50,   32,  8,       1376, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS2 */
	{      56820,          0,   50,   50,   32,  8,       1568, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS3 */
	{      57016,          0,   50,   50,   32,  8,       1088, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS4 */
	{      57152,          0,   50,   50,   32,  8,       1376, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS5 */
	{      57324,          0,   50,   50,   32,  8,       1568, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS6 */
	{      57520,          0,   50,   50,   32,  8,       1184, NULL },		/* AG_CG_OBJ_SLOPE_GROUND1 */
	{      57668,          0,   50,   50,   32,  8,       1344, NULL },		/* AG_CG_OBJ_SLOPE_GROUND2 */
	{      57836,          0,   50,   50,   32,  8,       1184, NULL },		/* AG_CG_OBJ_SLOPE_GROUND3 */
	{      57984,          0,   50,   50,   32,  8,        992, NULL },		/* AG_CG_OBJ_SNAKE1 */
	{      58108,          0,   50,   50,   32,  8,       1120, NULL },		/* AG_CG_OBJ_SNAKE2 */
	{      58248,          0,   50,   50,   32,  8,        832, NULL },		/* AG_CG_OBJ_SNAKE3 */
	{      58352,          0,   50,   50,   32,  8,       1376, NULL },		/* AG_CG_OBJ_SNAKE4 */
	{      58524,          0,   50,   65,   32,  8,       1344, NULL },		/* AG_CG_OBJ_SWITCH1 */
	{      58692,          0,   50,   65,   32,  8,       1344, NULL },		/* AG_CG_OBJ_SWITCH2 */
	{      58860,          0,  110,   32,   56,  8,        896, NULL },		/* AG_CG_OBJ_TAKE1 */
	{      58972,          0,  110,   32,   56,  8,        576, NULL },		/* AG_CG_OBJ_TAKE2 */
	{      59044,          0,  110,   32,   56,  8,        992, NULL },		/* AG_CG_OBJ_TAKE3 */
	{      59168,          0,  110,   32,   56,  8,       1568, NULL },		/* AG_CG_OBJ_TAKE4 */
	{      59364,          0,  110,   32,   56,  8,        864, NULL },		/* AG_CG_OBJ_TAKE5 */
	{      59472,          0,  151,  151,   80,  8,       7104, NULL },		/* AG_CG_OBJ_WHEEL */
	{      60360,          0,  118,   20,   64,  8,       1152, NULL },		/* AG_CG_OBJ_WORKSTAND1 */
	{      60504,          0,  118,   20,   64,  8,       1088, NULL },		/* AG_CG_OBJ_WORKSTAND2 */
	{      60640,          0,   20,  118,   16,  8,       1152, NULL },		/* AG_CG_OBJ_WORKSTAND3 */
	{      60784,          0,   20,  118,   16,  8,       1120, NULL },		/* AG_CG_OBJ_WORKSTAND4 */
	{      60924,          0,   38,   39,   24,  8,       1120, NULL },		/* AG_CG_UI_ITEMFLAME */
	{      61064,          0,  512,  512,  256,  6,      10392, NULL },		/* AG_CG_BG_0_0 */
	{      62363,          0,  512,  512,  256,  6,       6904, NULL },		/* AG_CG_BG_0_1 */
	{      63226,          0,  512,  512,  256,  6,       6520, NULL },		/* AG_CG_BG_0_2 */
	{      64041,          0,  512,  512,  256,  6,       2104, NULL },		/* AG_CG_BG_0_3 */
	{      64304,          0,  452,  512,  232,  6,       1176, NULL },		/* AG_CG_BG_0_4 */
	{      64451,          0,  512,  512,  256,  6,      25400, NULL },		/* AG_CG_BG_1_0 */
	{      67626,          0,  512,  512,  256,  6,      28312, NULL },		/* AG_CG_BG_1_1 */
	{      71165,          0,  512,  512,  256,  6,      28440, NULL },		/* AG_CG_BG_1_2 */
	{      74720,          0,  512,  512,  256,  6,      30552, NULL },		/* AG_CG_BG_1_3 */
	{      78539,          0,  452,  512,  232,  6,      26488, NULL },		/* AG_CG_BG_1_4 */
	{      81850,          0,  512,  512,  256,  6,      34616, NULL },		/* AG_CG_BG_2_0 */
	{      86177,          0,  512,  512,  256,  6,      23128, NULL },		/* AG_CG_BG_2_1 */
	{      89068,          0,  512,  512,  256,  6,      25880, NULL },		/* AG_CG_BG_2_2 */
	{      92303,          0,  512,  512,  256,  6,      31352, NULL },		/* AG_CG_BG_2_3 */
	{      96222,          0,  452,  512,  232,  6,      30328, NULL },		/* AG_CG_BG_2_4 */
	{     100013,          0,  512,  512,  256,  6,      34008, NULL },		/* AG_CG_BG_3_0 */
	{     104264,          0,  512,  512,  256,  6,      30680, NULL },		/* AG_CG_BG_3_1 */
	{     108099,          0,  512,  512,  256,  6,      35256, NULL },		/* AG_CG_BG_3_2 */
	{     112506,          0,  512,  512,  256,  6,      39416, NULL },		/* AG_CG_BG_3_3 */
	{     117433,          0,  452,  512,  232,  6,      35320, NULL },		/* AG_CG_BG_3_4 */
	{     121848,          0,  512,  252,  256,  6,      37240, NULL },		/* AG_CG_BG_4_0 */
	{     126503,          0,  512,  252,  256,  6,      29048, NULL },		/* AG_CG_BG_4_1 */
	{     130134,          0,  512,  252,  256,  6,      32056, NULL },		/* AG_CG_BG_4_2 */
	{     134141,          0,  512,  252,  256,  6,      29848, NULL },		/* AG_CG_BG_4_3 */
	{     137872,          0,  452,  252,  232,  6,      32728, NULL },		/* AG_CG_BG_4_4 */
	{     222443,          0,   32,   32,   16,  8,        512, NULL },		/* AG_CG_OBJ_TOGE */
	{     222507,          0,   32,   32,   16,  8,        512, NULL },		/* AG_CG_OBJ_TOGE_D */
	{     222571,          0,   32,   32,   16,  8,        512, NULL },		/* AG_CG_OBJ_TOGE_L */
	{     222635,          0,   32,   32,   16,  8,        512, NULL },		/* AG_CG_OBJ_TOGE_R */
	{     222699,          0,  128,   32,   64,  8,       1344, NULL },		/* AG_CG_OBJ_TOGE4 */
	{     222867,          0,  128,   32,   64,  8,       1344, NULL },		/* AG_CG_OBJ_TOGE4_D */
	{     223035,          0,   34,  129,   24,  8,       1664, NULL },		/* AG_CG_OBJ_TOGE4_L */
	{     223243,          0,   34,  129,   24,  8,       1696, NULL },		/* AG_CG_OBJ_TOGE4_R */
	{     223455,          0,  128,  128,   64,  8,       5952, NULL },		/* AG_CG_OBJ_BLOCK */
	{     224199,          0,  128,  128,   64,  8,       6848, NULL },		/* AG_CG_OBJ_BLOCK_H */
	{     225055,          0,  512,  128,  256,  8,      23328, NULL },		/* AG_CG_OBJ_BLOCK4_0 */
	{     227971,          0,  512,  128,  256,  8,      26944, NULL },		/* AG_CG_OBJ_BLOCK_H4 */
	{     231339,          0,  128,   32,   64,  8,        800, NULL },		/* AG_CG_OBJ_LIFT */
	{     265880,          0,  344,  600,  176,  8,      21952, NULL },		/* AG_CG_STORY_DAIGOROU */
	{     268624,          0,  603,  600,  304,  8,      21344, NULL },		/* AG_CG_STORY_ERITAN */
	{     271292,          0,  233,  200,  120,  8,      10112, NULL },		/* AG_CG_STORY_CLOUD_ERITAN */
	{     272556,          0,  256,  210,  128,  8,      10464, NULL },		/* AG_CG_ITEM_MERONPAN256 */
	{     273864,          0,  178,  256,   96,  8,       9632, NULL },		/* AG_CG_ITEM_UNIXSP256 */
	{     275068,          0,   64,   53,   32,  8,       1696, NULL },		/* AG_CG_ITEM_MERONPAN64 */
	{     275280,          0,   45,   64,   24,  8,       1600, NULL },		/* AG_CG_ITEM_UNIXSP64 */
	{     275480,          0,   33,  128,   24,  8,       2688, NULL },		/* AG_CG_ITEM_ERITAN */
	{     275816,          0,  100,  100,   56,  8,       1888, NULL },		/* AG_CG_DAIGORO_ICON */
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
	    141983,    142231,    142483,    142739,    143011,    143279,    143547,    143819,
	    144091,    144363,    144627,    144899,    145167,    145427,    145691,    145951,
	    146211,    146471,    146743,    147015,    147275,    147543,    147811,    148059,
	    148311,    148579,    148835,    149099,    149359,    149635,    149898,    150162,
	    150430,    150702,    150966,    151226,    151486,    151762,    152034,    152310,
	    152578,    152838,    153094,    153342,    153578,    153798,    154010,    154202,
	    154394,    154590,    154786,
};

const u32 ageRM3Offsets0004[] = {		/* AG_RP_DAIGOROU_JUMP */
	    155003,
};

const u32 ageRM3Offsets0005[] = {		/* AG_RP_DAIGOROU_JUMPEND */
	    155292,    155560,    155848,    156144,    156424,    156688,
};

const u32 ageRM3Offsets0006[] = {		/* AG_RP_DAIGOROU_JUMPSTART */
	    156949,    157197,    157453,    157705,    157945,    158173,    158425,
};

const u32 ageRM3Offsets0007[] = {		/* AG_RP_DAIGOROU_RT */
	    158682,    158926,    159206,    159510,    159806,    160098,    160390,    160690,
	    160986,    161282,    161574,    161870,    162162,    162450,    162738,    163030,
	    163318,    163602,    163898,    164190,    164482,    164782,    165078,    165378,
	    165678,    165974,    166278,    166542,    166806,    167062,    167321,    167565,
	    167809,    168053,    168297,    168541,    168785,    169029,    169273,    169517,
	    169761,
};

const u32 ageRM3Offsets0008[] = {		/* AG_RP_DAIGOROU_RUN */
	    170026,    170322,    170610,    170878,    171154,    171394,    171646,    171922,
	    172190,    172450,    172742,    173042,
};

const u32 ageRM3Offsets0009[] = {		/* AG_RP_DAIGOROU_RUNEND */
	    173359,    173643,
};

const u32 ageRM3Offsets0010[] = {		/* AG_RP_DAIGOROU_RUNSTART */
	    173912,    174160,
};

const u32 ageRM3Offsets0011[] = {		/* AG_RP_DAIGOROU_WAIT */
	    174469,    174717,    174965,    175213,    175461,    175709,    175957,    176205,
	    176453,    176701,    176949,    177201,    177449,    177697,    177949,    178201,
	    178457,    178709,    178961,    179209,    179457,    179705,    179953,    180201,
	    180449,    180697,    180945,    181197,    181445,    181693,
};

const u32 ageRM3Offsets0012[] = {		/* AG_RP_DAIGOROU_WALK */
	    181962,    182270,    182570,    182858,    183118,    183378,    183662,    183958,
	    184258,    184554,    184858,    185166,    185466,    185754,    186026,    186282,
	    186538,    186826,    187122,    187422,    187730,
};

const u32 ageRM3Offsets0013[] = {		/* AG_RP_DAIGOROU_WALKEND */
	    188059,    188347,    188635,    188907,    189163,
};

const u32 ageRM3Offsets0014[] = {		/* AG_RP_DAIGOROU_WALKSTART */
	    189432,    189680,    189948,    190248,    190556,
};

const u32 ageRM3Offsets0015[] = {		/* AG_RP_EFF_RT */
	    190885,    190953,    191037,    191125,    191269,    191493,    191809,    192245,
	    192741,    193289,    193909,    194593,    195281,    195953,    196613,    197285,
	    197965,    198641,    199309,    200017,    200693,    201365,    202033,    202741,
	    203401,    204073,    204745,    205421,    206073,    206737,    207364,    208040,
	    208692,    209328,    209976,    210612,    211212,    211756,    212268,    212704,
	    213080,
};

const u32 ageRM3Offsets0016[] = {		/* AG_RP_OBJ_EBULLET */
	    213377,    213489,    213597,    213713,    213825,    213945,    214065,    214185,
	    214297,    214409,    214525,    214641,    214761,    214885,    215005,    215117,
	    215233,    215349,    215469,    215585,    215705,    215821,    215941,    216053,
	    216173,    216289,    216409,    216525,    216637,
};

const u32 ageRM3Offsets0017[] = {		/* AG_RP_OBJ_PBULLET */
	    216778,    216974,    217166,    217362,    217562,    217754,    217942,    218130,
	    218318,    218510,    218698,    218886,    219074,    219258,    219442,    219630,
	    219814,    219998,    220182,    220362,    220546,    220734,    220926,    221110,
	    221298,    221486,    221674,    221866,    222054,    222246,
};

const u32 ageRM3Offsets0018[] = {		/* AG_RP_SIN_MESSAGE */
	    231459,    236939,    241267,    246099,    251559,    256223,    261679,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{        804,  256,  256,   7680,      9, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_DAIGOROU_CLEAR */
	{       6533,  256,  256,   7680,     10, 2, 0, ageRM3Offsets0001, NULL        },		/* AG_RP_DAIGOROU_LOSE */
	{      12721,  256,  256,   7680,     10, 2, 0, ageRM3Offsets0002, NULL        },		/* AG_RP_DAIGOROU_ONIGIRI */
	{     141963,  128,  128,   7680,     51, 2, 0, ageRM3Offsets0003, NULL        },		/* AG_RP_DAIGOROU_GAMEOVER */
	{     154983,  128,  128,   7680,      1, 2, 0, ageRM3Offsets0004, NULL        },		/* AG_RP_DAIGOROU_JUMP */
	{     155272,  128,  128,   7680,      6, 2, 0, ageRM3Offsets0005, NULL        },		/* AG_RP_DAIGOROU_JUMPEND */
	{     156929,  128,  128,   7680,      7, 2, 0, ageRM3Offsets0006, NULL        },		/* AG_RP_DAIGOROU_JUMPSTART */
	{     158662,  128,  128,   7680,     41, 2, 0, ageRM3Offsets0007, NULL        },		/* AG_RP_DAIGOROU_RT */
	{     170006,  128,  128,   7680,     12, 2, 0, ageRM3Offsets0008, NULL        },		/* AG_RP_DAIGOROU_RUN */
	{     173339,  128,  128,   7680,      2, 2, 0, ageRM3Offsets0009, NULL        },		/* AG_RP_DAIGOROU_RUNEND */
	{     173892,  128,  128,   7680,      2, 2, 0, ageRM3Offsets0010, NULL        },		/* AG_RP_DAIGOROU_RUNSTART */
	{     174449,  128,  128,   7680,     30, 2, 0, ageRM3Offsets0011, NULL        },		/* AG_RP_DAIGOROU_WAIT */
	{     181942,  128,  128,   7680,     21, 2, 0, ageRM3Offsets0012, NULL        },		/* AG_RP_DAIGOROU_WALK */
	{     188039,  128,  128,   7680,      5, 2, 0, ageRM3Offsets0013, NULL        },		/* AG_RP_DAIGOROU_WALKEND */
	{     189412,  128,  128,   7680,      5, 2, 0, ageRM3Offsets0014, NULL        },		/* AG_RP_DAIGOROU_WALKSTART */
	{     190865,  256,  256,   7680,     41, 2, 0, ageRM3Offsets0015, NULL        },		/* AG_RP_EFF_RT */
	{     213357,   64,   64,   7680,     29, 2, 0, ageRM3Offsets0016, NULL        },		/* AG_RP_OBJ_EBULLET */
	{     216758,   64,   64,   7680,     30, 2, 0, ageRM3Offsets0017, NULL        },		/* AG_RP_OBJ_PBULLET */
	{     231439,  944,  408,   7680,      7, 2, 0, ageRM3Offsets0018, NULL        },		/* AG_RP_SIN_MESSAGE */
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
