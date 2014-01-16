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
	{      28445,          0,  935,  493,  935,  3,     491696, NULL },		/* AG_CG_GAMEOVER */
	{      89907,          0,  516,  198,  264,  8,      15200, NULL },		/* AG_CG_GAMESTART */
	{      91807,          0,  638,   70,  320,  8,      19808, NULL },		/* AG_CG_SCOREFONT */
	{      94283,          0,  592,  357,  592,  3,     184592, NULL },		/* AG_CG_TITLE_0 */
	{     117357,          0,  137,  133,   72,  8,       2336, NULL },		/* AG_CG_EFFECT_DMG1 */
	{     117649,          0,  137,  133,   72,  8,       2688, NULL },		/* AG_CG_EFFECT_DMG2 */
	{     117985,          0,  127,  127,   64,  8,       2016, NULL },		/* AG_CG_EFFECT_RECOVERY1 */
	{     118237,          0,  127,  127,   64,  8,       2112, NULL },		/* AG_CG_EFFECT_RECOVERY2 */
	{     118501,          0,  127,  127,   64,  8,       1952, NULL },		/* AG_CG_EFFECT_RECOVERY3 */
	{     118745,          0,  112,  112,   56,  8,       2688, NULL },		/* AG_CG_ENEMY_FROGA1 */
	{     119081,          0,  147,  126,   80,  8,       3456, NULL },		/* AG_CG_ENEMY_FROGA2 */
	{     119513,          0,  125,   75,   64,  8,       2336, NULL },		/* AG_CG_ENEMY_FROGA3 */
	{     119805,          0,   86,   82,   48,  8,       2688, NULL },		/* AG_CG_ICON_LIFE1 */
	{     120141,          0,   86,   82,   48,  8,       2784, NULL },		/* AG_CG_ICON_LIFE2 */
	{     120489,          0,   86,   82,   48,  8,       2656, NULL },		/* AG_CG_ICON_LIFE3 */
	{     120821,          0,  144,  135,   72,  8,       6848, NULL },		/* AG_CG_ENEMY_IGAGURI */
	{     121677,          0,   72,   72,   40,  8,       1504, NULL },		/* AG_CG_OBJ_BLOCK1 */
	{     121865,          0,   72,   72,   40,  8,       1664, NULL },		/* AG_CG_OBJ_BLOCK2 */
	{     122073,          0,   77,   80,   40,  8,       2272, NULL },		/* AG_CG_OBJ_BLOCK3 */
	{     122357,          0,   72,   72,   40,  8,       1248, NULL },		/* AG_CG_OBJ_BLOCK4 */
	{     122513,          0,  158,  126,   80,  8,       2592, NULL },		/* AG_CG_OBJ_BOX1 */
	{     122837,          0,  158,  126,   80,  8,       4416, NULL },		/* AG_CG_OBJ_BOX2 */
	{     123389,          0,   74,   74,   40,  8,       1152, NULL },		/* AG_CG_OBJ_CANNONBALL */
	{     123533,          0,  134,  134,   72,  8,       4384, NULL },		/* AG_CG_OBJ_CROW_BODY1 */
	{     124081,          0,  134,  134,   72,  8,       4448, NULL },		/* AG_CG_OBJ_CROW_BODY2 */
	{     124637,          0,  134,  134,   72,  8,       4608, NULL },		/* AG_CG_OBJ_CROW_BODY3 */
	{     125213,          0,  124,  148,   64,  8,       2592, NULL },		/* AG_CG_OBJ_CROW_WING_L1 */
	{     125537,          0,  124,  148,   64,  8,       2720, NULL },		/* AG_CG_OBJ_CROW_WING_L2 */
	{     125877,          0,  124,  148,   64,  8,       2400, NULL },		/* AG_CG_OBJ_CROW_WING_L3 */
	{     126177,          0,  124,  148,   64,  8,       2656, NULL },		/* AG_CG_OBJ_CROW_WING_R1 */
	{     126509,          0,  124,  148,   64,  8,       2816, NULL },		/* AG_CG_OBJ_CROW_WING_R2 */
	{     126861,          0,  124,  148,   64,  8,       2496, NULL },		/* AG_CG_OBJ_CROW_WING_R3 */
	{     127173,          0,  319,  256,  160,  8,      12480, NULL },		/* AG_CG_OBJ_GRASS */
	{     128733,          0,   72,   72,   40,  8,       1856, NULL },		/* AG_CG_OBJ_JUMP1 */
	{     128965,          0,   72,   72,   40,  8,       1696, NULL },		/* AG_CG_OBJ_JUMP2 */
	{     129177,          0,   72,   72,   40,  8,       1440, NULL },		/* AG_CG_OBJ_JUMP3 */
	{     129357,          0,   75,   76,   40,  8,       1728, NULL },		/* AG_CG_OBJ_KEY */
	{     129573,          0,   76,   75,   40,  8,       1632, NULL },		/* AG_CG_OBJ_KEYHOLE */
	{     129777,          0,  138,  159,   72,  8,       5280, NULL },		/* AG_CG_OBJ_MORTAR1 */
	{     130437,          0,  138,  159,   72,  8,       5152, NULL },		/* AG_CG_OBJ_MORTAR2 */
	{     131081,          0,   65,   73,   40,  8,       1568, NULL },		/* AG_CG_OBJ_NEEDLE */
	{     131277,          0,   69,   69,   40,  8,       1728, NULL },		/* AG_CG_OBJ_PULLEY1 */
	{     131493,          0,   69,   69,   40,  8,       1600, NULL },		/* AG_CG_OBJ_PULLEY2 */
	{     131693,          0,   14,    8,   14,  3,        240, NULL },		/* AG_CG_OBJ_PULLEY3 */
	{     131723,          0,    8,   14,    8,  3,        392, NULL },		/* AG_CG_OBJ_PULLEY4 */
	{     131772,          0,   14,    8,   14,  3,        312, NULL },		/* AG_CG_OBJ_PULLEY5 */
	{     131811,          0,  100,  100,   56,  6,       3576, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS1 */
	{     132258,          0,  100,  100,   56,  8,       3968, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS2 */
	{     132754,          0,  100,  100,   56,  8,       3872, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS3 */
	{     133238,          0,  100,  100,   56,  8,       4096, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS4 */
	{     133750,          0,  100,  100,   56,  8,       4064, NULL },		/* AG_CG_OBJ_SLOPE_0GRASS5 */
	{     134258,          0,  100,  100,   56,  8,       1664, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS1 */
	{     134466,          0,  100,  100,   56,  8,       3104, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS2 */
	{     134854,          0,  100,  100,   56,  8,       3808, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS3 */
	{     135330,          0,  100,  100,   56,  8,       3968, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS4 */
	{     135826,          0,  100,  100,   56,  8,       1536, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS5 */
	{     136018,          0,  100,  100,   56,  8,       2912, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS6 */
	{     136382,          0,  100,  100,   56,  8,       3712, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS7 */
	{     136846,          0,  100,  100,   56,  8,       3968, NULL },		/* AG_CG_OBJ_SLOPE_30GRASS8 */
	{     137342,          0,  100,  100,   56,  8,       2240, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS1 */
	{     137622,          0,  100,  100,   56,  8,       3808, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS2 */
	{     138098,          0,  100,  100,   56,  8,       4160, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS3 */
	{     138618,          0,  100,  100,   56,  8,       2080, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS4 */
	{     138878,          0,  100,  100,   56,  8,       3744, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS5 */
	{     139346,          0,  100,  100,   56,  8,       4032, NULL },		/* AG_CG_OBJ_SLOPE_45GRASS6 */
	{     139850,          0,  100,  100,   56,  8,       4032, NULL },		/* AG_CG_OBJ_SLOPE_GROUND1 */
	{     140354,          0,  100,  100,   56,  8,       4384, NULL },		/* AG_CG_OBJ_SLOPE_GROUND2 */
	{     140902,          0,  100,  100,   56,  8,       4128, NULL },		/* AG_CG_OBJ_SLOPE_GROUND3 */
	{     141418,          0,  100,  100,   56,  8,       1984, NULL },		/* AG_CG_OBJ_SNAKE1 */
	{     141666,          0,  100,  100,   56,  8,       2400, NULL },		/* AG_CG_OBJ_SNAKE2 */
	{     141966,          0,  100,  100,   56,  8,       1632, NULL },		/* AG_CG_OBJ_SNAKE3 */
	{     142170,          0,  100,  100,   56,  8,       3072, NULL },		/* AG_CG_OBJ_SNAKE4 */
	{     142554,          0,  100,  130,   56,  8,       3072, NULL },		/* AG_CG_OBJ_SWITCH1 */
	{     142938,          0,  100,  130,   56,  8,       2976, NULL },		/* AG_CG_OBJ_SWITCH2 */
	{     143310,          0,  220,   64,  112,  8,       1472, NULL },		/* AG_CG_OBJ_TAKE1 */
	{     143494,          0,  220,   64,  112,  8,        832, NULL },		/* AG_CG_OBJ_TAKE2 */
	{     143598,          0,  220,   64,  112,  8,       1536, NULL },		/* AG_CG_OBJ_TAKE3 */
	{     143790,          0,  220,   64,  112,  8,       3520, NULL },		/* AG_CG_OBJ_TAKE4 */
	{     144230,          0,  220,   64,  112,  8,       1440, NULL },		/* AG_CG_OBJ_TAKE5 */
	{     144410,          0,  302,  302,  152,  8,      20832, NULL },		/* AG_CG_OBJ_WHEEL */
	{     147014,          0,  236,   41,  120,  8,       2272, NULL },		/* AG_CG_OBJ_WORKSTAND1 */
	{     147298,          0,  236,   41,  120,  8,       3232, NULL },		/* AG_CG_OBJ_WORKSTAND2 */
	{     147702,          0,   41,  236,   24,  8,       2048, NULL },		/* AG_CG_OBJ_WORKSTAND3 */
	{     147958,          0,   41,  236,   24,  8,       3168, NULL },		/* AG_CG_OBJ_WORKSTAND4 */
	{     148354,          0,   77,   78,   40,  8,       2080, NULL },		/* AG_CG_UI_ITEMFLAME */
	{     148614,          0,  512,  512,  256,  6,      10392, NULL },		/* AG_CG_BG_0_0 */
	{     149913,          0,  512,  512,  256,  6,       6904, NULL },		/* AG_CG_BG_0_1 */
	{     150776,          0,  512,  512,  256,  6,       6520, NULL },		/* AG_CG_BG_0_2 */
	{     151591,          0,  512,  512,  256,  6,       2104, NULL },		/* AG_CG_BG_0_3 */
	{     151854,          0,  452,  512,  232,  6,       1176, NULL },		/* AG_CG_BG_0_4 */
	{     152001,          0,  512,  512,  256,  6,      25400, NULL },		/* AG_CG_BG_1_0 */
	{     155176,          0,  512,  512,  256,  6,      28312, NULL },		/* AG_CG_BG_1_1 */
	{     158715,          0,  512,  512,  256,  6,      28440, NULL },		/* AG_CG_BG_1_2 */
	{     162270,          0,  512,  512,  256,  6,      30552, NULL },		/* AG_CG_BG_1_3 */
	{     166089,          0,  452,  512,  232,  6,      26488, NULL },		/* AG_CG_BG_1_4 */
	{     169400,          0,  512,  512,  256,  6,      34616, NULL },		/* AG_CG_BG_2_0 */
	{     173727,          0,  512,  512,  256,  6,      23128, NULL },		/* AG_CG_BG_2_1 */
	{     176618,          0,  512,  512,  256,  6,      25880, NULL },		/* AG_CG_BG_2_2 */
	{     179853,          0,  512,  512,  256,  6,      31352, NULL },		/* AG_CG_BG_2_3 */
	{     183772,          0,  452,  512,  232,  6,      30328, NULL },		/* AG_CG_BG_2_4 */
	{     187563,          0,  512,  512,  256,  6,      34008, NULL },		/* AG_CG_BG_3_0 */
	{     191814,          0,  512,  512,  256,  6,      30680, NULL },		/* AG_CG_BG_3_1 */
	{     195649,          0,  512,  512,  256,  6,      35256, NULL },		/* AG_CG_BG_3_2 */
	{     200056,          0,  512,  512,  256,  6,      39416, NULL },		/* AG_CG_BG_3_3 */
	{     204983,          0,  452,  512,  232,  6,      35320, NULL },		/* AG_CG_BG_3_4 */
	{     209398,          0,  512,  252,  256,  6,      37240, NULL },		/* AG_CG_BG_4_0 */
	{     214053,          0,  512,  252,  256,  6,      29048, NULL },		/* AG_CG_BG_4_1 */
	{     217684,          0,  512,  252,  256,  6,      32056, NULL },		/* AG_CG_BG_4_2 */
	{     221691,          0,  512,  252,  256,  6,      29848, NULL },		/* AG_CG_BG_4_3 */
	{     225422,          0,  452,  252,  232,  6,      32728, NULL },		/* AG_CG_BG_4_4 */
	{     371423,          0,   64,   64,   64,  3,       7040, NULL },		/* AG_CG_OBJ_TOGE */
	{     372303,          0,  256,   64,  256,  3,      18216, NULL },		/* AG_CG_OBJ_TOGE4 */
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
	    229533,
};

const u32 ageRM3Offsets0004[] = {		/* AG_RP_DAIGOROU_JUMPEND */
	    230118,    230674,    231274,    231878,    232458,    233002,
};

const u32 ageRM3Offsets0005[] = {		/* AG_RP_DAIGOROU_JUMPSTART */
	    233519,    234031,    234551,    235067,    235551,    236019,    236523,
};

const u32 ageRM3Offsets0006[] = {		/* AG_RP_DAIGOROU_RUN */
	    237028,    237624,    238216,    238780,    239360,    239864,    240392,    240964,
	    241520,    242068,    242672,    243272,
};

const u32 ageRM3Offsets0007[] = {		/* AG_RP_DAIGOROU_RUNEND */
	    243889,    244485,
};

const u32 ageRM3Offsets0008[] = {		/* AG_RP_DAIGOROU_RUNSTART */
	    245018,    245530,
};

const u32 ageRM3Offsets0009[] = {		/* AG_RP_DAIGOROU_WAIT */
	    246143,    246647,    247151,    247663,    248171,    248683,    249195,    249715,
	    250239,    250767,    251283,    251803,    252319,    252843,    253371,    253887,
	    254403,    254919,    255439,    255951,    256467,    256979,    257495,    258019,
	    258543,    259059,    259571,    260083,    260587,    261099,
};

const u32 ageRM3Offsets0010[] = {		/* AG_RP_DAIGOROU_WALK */
	    261624,    262252,    262868,    263460,    263992,    264524,    265104,    265712,
	    266332,    266944,    267560,    268172,    268780,    269360,    269924,    270440,
	    270960,    271548,    272152,    272764,    273388,
};

const u32 ageRM3Offsets0011[] = {		/* AG_RP_DAIGOROU_WALKEND */
	    274037,    274645,    275233,    275757,    276269,
};

const u32 ageRM3Offsets0012[] = {		/* AG_RP_DAIGOROU_WALKSTART */
	    276798,    277310,    277886,    278506,    279142,
};

const u32 ageRM3Offsets0013[] = {		/* AG_RP_DAIGOROU_RT */
	    279795,    280299,    280863,    281463,    282067,    282675,    283275,    283879,
	    284467,    285059,    285651,    286239,    286831,    287415,    287999,    288591,
	    289183,    289779,    290375,    290971,    291563,    292163,    292767,    293367,
	    293979,    294579,    295183,    295787,    296383,    296931,    297466,    297974,
	    298482,    298990,    299498,    300006,    300514,    301022,    301530,    302038,
	    302546,
};

const u32 ageRM3Offsets0014[] = {		/* AG_RP_EFF_RT */
	    303075,    303199,    303347,    303507,    303759,    304159,    304747,    305559,
	    306487,    307479,    308623,    309887,    311187,    312463,    313699,    314963,
	    316243,    317483,    318755,    320063,    321343,    322587,    323831,    325143,
	    326431,    327643,    328879,    330187,    331451,    332723,    333918,    335182,
	    336414,    337638,    338818,    339946,    341002,    341978,    342814,    343506,
	    344086,
};

const u32 ageRM3Offsets0015[] = {		/* AG_RP_DAIGOROU_GAMEOVER */
	    344495,    345007,    345515,    346047,    346607,    347175,    347739,    348299,
	    348863,    349423,    349983,    350539,    351087,    351623,    352163,    352703,
	    353243,    353791,    354343,    354903,    355455,    356003,    356555,    357075,
	    357595,    358127,    358667,    359215,    359747,    360311,    360854,    361398,
	    361958,    362490,    363026,    363558,    364090,    364646,    365206,    365770,
	    366318,    366870,    367406,    367934,    368434,    368902,    369342,    369750,
	    370162,    370582,    371002,
};

const AGERM3Member ageRM3[] = {
	/*    Offset,Width,Height,FrameRate,Frames,Alpha,EncodeType, Offsets */
	{        804,  256,  256,   7680,      9, 2, 0, ageRM3Offsets0000, NULL        },		/* AG_RP_DAIGOROU_CLEAR */
	{       6533,  256,  256,   7680,     10, 2, 0, ageRM3Offsets0001, NULL        },		/* AG_RP_DAIGOROU_LOSE */
	{      12721,  256,  256,   7680,     10, 2, 0, ageRM3Offsets0002, NULL        },		/* AG_RP_DAIGOROU_ONIGIRI */
	{     229513,  256,  256,   7680,      1, 2, 0, ageRM3Offsets0003, NULL        },		/* AG_RP_DAIGOROU_JUMP */
	{     230098,  256,  256,   7680,      6, 2, 0, ageRM3Offsets0004, NULL        },		/* AG_RP_DAIGOROU_JUMPEND */
	{     233499,  256,  256,   7680,      7, 2, 0, ageRM3Offsets0005, NULL        },		/* AG_RP_DAIGOROU_JUMPSTART */
	{     237008,  256,  256,   7680,     12, 2, 0, ageRM3Offsets0006, NULL        },		/* AG_RP_DAIGOROU_RUN */
	{     243869,  256,  256,   7680,      2, 2, 0, ageRM3Offsets0007, NULL        },		/* AG_RP_DAIGOROU_RUNEND */
	{     244998,  256,  256,   7680,      2, 2, 0, ageRM3Offsets0008, NULL        },		/* AG_RP_DAIGOROU_RUNSTART */
	{     246123,  256,  256,   7680,     30, 2, 0, ageRM3Offsets0009, NULL        },		/* AG_RP_DAIGOROU_WAIT */
	{     261604,  256,  256,   7680,     21, 2, 0, ageRM3Offsets0010, NULL        },		/* AG_RP_DAIGOROU_WALK */
	{     274017,  256,  256,   7680,      5, 2, 0, ageRM3Offsets0011, NULL        },		/* AG_RP_DAIGOROU_WALKEND */
	{     276778,  256,  256,   7680,      5, 2, 0, ageRM3Offsets0012, NULL        },		/* AG_RP_DAIGOROU_WALKSTART */
	{     279775,  256,  256,   7680,     41, 2, 0, ageRM3Offsets0013, NULL        },		/* AG_RP_DAIGOROU_RT */
	{     303055,  512,  512,   7680,     41, 2, 0, ageRM3Offsets0014, NULL        },		/* AG_RP_EFF_RT */
	{     344475,  256,  256,   7680,     51, 2, 0, ageRM3Offsets0015, NULL        },		/* AG_RP_DAIGOROU_GAMEOVER */
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
