#ifndef __AG_EXPORT__
#define __AG_EXPORT__

#include <agexport.h>
#include <ag3d.h>

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************/
/*                       FrameBuffer                           */
/***************************************************************/
#define AGE_FB_WIDTH	(1024)
#define AGE_FB_HEIGHT	(768)
#define AGE_DISP_WIDTH	(1024)
#define AGE_DISP_HEIGHT	(768)
#define AGE_FB_ADDR0	(7602176)
#define AGE_FB_ADDR1	(6815744)
#define AGE_ZB_ADDR	(6815744)
#define AGE_ZB_DEPTH	(4)
#define AGE_ZMD	(1)
#define AGE_AAC_ADDR	(13631488)
#define AGE_AAC_SIZE	(13631488)
#define AGE_SOUND_ROM_OFFSET	(0x80000)

/***************************************************************/
/*                    Rom Member Symbol                        */
/***************************************************************/
#define AG_CG_ICON_FOOD_ODANGO	(0)
#define AG_CG_ICON_FOOD_ONIGIRI	(1)
#define AG_CG_ICON_FOOD_SUIKA	(2)
#define AG_CG_INFO_FOOD	(3)
#define AG_CG_INFO_TIME	(4)
#define AG_CG_WORKSTAND	(5)
#define AG_CG_GAMECLEAR	(6)
#define AG_CG_GAMEOVER	(7)
#define AG_CG_GAMESTART	(8)
#define AG_CG_SCOREFONT	(9)
#define AG_CG_TITLE	(10)
#define AG_CG_EFFECT_DMG1	(11)
#define AG_CG_EFFECT_DMG2	(12)
#define AG_CG_EFFECT_RECOVERY1	(13)
#define AG_CG_EFFECT_RECOVERY2	(14)
#define AG_CG_EFFECT_RECOVERY3	(15)
#define AG_CG_ENEMY_FROGA1	(16)
#define AG_CG_ENEMY_FROGA2	(17)
#define AG_CG_ENEMY_FROGA3	(18)
#define AG_CG_ICON_LIFE1	(19)
#define AG_CG_ICON_LIFE2	(20)
#define AG_CG_ICON_LIFE3	(21)
#define AG_CG_ENEMY_IGAGURI	(22)
#define AG_CG_OBJ_BLOCK1	(23)
#define AG_CG_OBJ_BLOCK2	(24)
#define AG_CG_OBJ_BLOCK3	(25)
#define AG_CG_OBJ_BLOCK4	(26)
#define AG_CG_OBJ_BOX1	(27)
#define AG_CG_OBJ_BOX2	(28)
#define AG_CG_OBJ_CANNONBALL	(29)
#define AG_CG_OBJ_CROW_BODY1	(30)
#define AG_CG_OBJ_CROW_BODY2	(31)
#define AG_CG_OBJ_CROW_BODY3	(32)
#define AG_CG_OBJ_CROW_WING_L1	(33)
#define AG_CG_OBJ_CROW_WING_L2	(34)
#define AG_CG_OBJ_CROW_WING_L3	(35)
#define AG_CG_OBJ_CROW_WING_R1	(36)
#define AG_CG_OBJ_CROW_WING_R2	(37)
#define AG_CG_OBJ_CROW_WING_R3	(38)
#define AG_CG_OBJ_GRASS	(39)
#define AG_CG_OBJ_JUMP1	(40)
#define AG_CG_OBJ_JUMP2	(41)
#define AG_CG_OBJ_JUMP3	(42)
#define AG_CG_OBJ_KEY	(43)
#define AG_CG_OBJ_KEYHOLE	(44)
#define AG_CG_OBJ_MORTAR1	(45)
#define AG_CG_OBJ_MORTAR2	(46)
#define AG_CG_OBJ_NEEDLE	(47)
#define AG_CG_OBJ_PULLEY1	(48)
#define AG_CG_OBJ_PULLEY2	(49)
#define AG_CG_OBJ_PULLEY3	(50)
#define AG_CG_OBJ_PULLEY4	(51)
#define AG_CG_OBJ_PULLEY5	(52)
#define AG_CG_OBJ_SLOPE_0GRASS1	(53)
#define AG_CG_OBJ_SLOPE_0GRASS2	(54)
#define AG_CG_OBJ_SLOPE_0GRASS3	(55)
#define AG_CG_OBJ_SLOPE_0GRASS4	(56)
#define AG_CG_OBJ_SLOPE_0GRASS5	(57)
#define AG_CG_OBJ_SLOPE_30GRASS1	(58)
#define AG_CG_OBJ_SLOPE_30GRASS2	(59)
#define AG_CG_OBJ_SLOPE_30GRASS3	(60)
#define AG_CG_OBJ_SLOPE_30GRASS4	(61)
#define AG_CG_OBJ_SLOPE_30GRASS5	(62)
#define AG_CG_OBJ_SLOPE_30GRASS6	(63)
#define AG_CG_OBJ_SLOPE_30GRASS7	(64)
#define AG_CG_OBJ_SLOPE_30GRASS8	(65)
#define AG_CG_OBJ_SLOPE_45GRASS1	(66)
#define AG_CG_OBJ_SLOPE_45GRASS2	(67)
#define AG_CG_OBJ_SLOPE_45GRASS3	(68)
#define AG_CG_OBJ_SLOPE_45GRASS4	(69)
#define AG_CG_OBJ_SLOPE_45GRASS5	(70)
#define AG_CG_OBJ_SLOPE_45GRASS6	(71)
#define AG_CG_OBJ_SLOPE_GROUND1	(72)
#define AG_CG_OBJ_SLOPE_GROUND2	(73)
#define AG_CG_OBJ_SLOPE_GROUND3	(74)
#define AG_CG_OBJ_SNAKE1	(75)
#define AG_CG_OBJ_SNAKE2	(76)
#define AG_CG_OBJ_SNAKE3	(77)
#define AG_CG_OBJ_SNAKE4	(78)
#define AG_CG_OBJ_SWITCH1	(79)
#define AG_CG_OBJ_SWITCH2	(80)
#define AG_CG_OBJ_TAKE1	(81)
#define AG_CG_OBJ_TAKE2	(82)
#define AG_CG_OBJ_TAKE3	(83)
#define AG_CG_OBJ_TAKE4	(84)
#define AG_CG_OBJ_TAKE5	(85)
#define AG_CG_OBJ_WHEEL	(86)
#define AG_CG_OBJ_WORKSTAND1	(87)
#define AG_CG_OBJ_WORKSTAND2	(88)
#define AG_CG_OBJ_WORKSTAND3	(89)
#define AG_CG_OBJ_WORKSTAND4	(90)
#define AG_CG_UI_ITEMFLAME	(91)
#define AG_CG_BG_0_0	(92)
#define AG_CG_BG_0_1	(93)
#define AG_CG_BG_0_2	(94)
#define AG_CG_BG_0_3	(95)
#define AG_CG_BG_0_4	(96)
#define AG_CG_BG_1_0	(97)
#define AG_CG_BG_1_1	(98)
#define AG_CG_BG_1_2	(99)
#define AG_CG_BG_1_3	(100)
#define AG_CG_BG_1_4	(101)
#define AG_CG_BG_2_0	(102)
#define AG_CG_BG_2_1	(103)
#define AG_CG_BG_2_2	(104)
#define AG_CG_BG_2_3	(105)
#define AG_CG_BG_2_4	(106)
#define AG_CG_BG_3_0	(107)
#define AG_CG_BG_3_1	(108)
#define AG_CG_BG_3_2	(109)
#define AG_CG_BG_3_3	(110)
#define AG_CG_BG_3_4	(111)
#define AG_CG_BG_4_0	(112)
#define AG_CG_BG_4_1	(113)
#define AG_CG_BG_4_2	(114)
#define AG_CG_BG_4_3	(115)
#define AG_CG_BG_4_4	(116)
#define AG_CG_OBJ_TOGE	(117)
#define AG_CG_OBJ_TOGE4	(118)

/***************************************************************/
/*                     RM3 Member Symbol                       */
/***************************************************************/
#define AG_RP_DAIGOROU_CLEAR	(0)
#define AG_RP_DAIGOROU_LOSE	(1)
#define AG_RP_DAIGOROU_ONIGIRI	(2)
#define AG_RP_DAIGOROU_JUMP	(3)
#define AG_RP_DAIGOROU_JUMPEND	(4)
#define AG_RP_DAIGOROU_JUMPSTART	(5)
#define AG_RP_DAIGOROU_RUN	(6)
#define AG_RP_DAIGOROU_RUNEND	(7)
#define AG_RP_DAIGOROU_RUNSTART	(8)
#define AG_RP_DAIGOROU_WAIT	(9)
#define AG_RP_DAIGOROU_WALK	(10)
#define AG_RP_DAIGOROU_WALKEND	(11)
#define AG_RP_DAIGOROU_WALKSTART	(12)
#define AG_RP_DAIGOROU_RT	(13)
#define AG_RP_EFF_RT	(14)
#define AG_RP_DAIGOROU_GAMEOVER	(15)

/***************************************************************/
/*                       Vram Group Symbol                     */
/***************************************************************/

/***************************************************************/
/*                       Sound Member Symbol                   */
/***************************************************************/
#define AS_SND_BGM	(0)
#define AS_SND_BGM_FAST	(1)
#define AS_SND_GAMEOVER	(2)
#define AS_SND_GAMECLEAR	(3)
#define AS_SND_TITLE	(4)
#define AS_SND_JUMP	(5)
#define AS_SND_TIMECOUNT	(6)
#define AS_SND_ATTACK1	(7)
#define AS_SND_ATTACK2	(8)
#define AS_SND_ATTACK3	(9)
#define AS_SND_GET1	(10)
#define AS_SND_GET2	(11)
#define AS_SND_GET3	(12)
#define AS_SND_CUT	(13)
#define AS_SND_LANDING	(14)
#define AS_SND_WALK_RIGHT	(15)
#define AS_SND_WALK_LEFT	(16)
#define AS_SND_DECIDE008	(17)

/***************************************************************/
/*                          Data Member                        */
/***************************************************************/
extern const AGERomMember ageRM[119];
extern const AGERM3Member ageRM3[16];
extern const u32 ageReserve[1];
extern const u32 ageUser[1];
extern const s16 ageVGCnt;
extern const AGESoundRomMember ageSRM[18];

#ifdef __cplusplus
}
#endif

#endif /* __AG_EXPORT__ */
