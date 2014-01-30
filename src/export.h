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
#define AGE_SOUND_ROM_OFFSET	(0x40000)

/***************************************************************/
/*                    Rom Member Symbol                        */
/***************************************************************/
#define AG_CG_INFO_TIME	(0)
#define AG_CG_GAMECLEAR	(1)
#define AG_CG_GAMEOVER	(2)
#define AG_CG_TIMEOVER	(3)
#define AG_CG_GAMESTART	(4)
#define AG_CG_SCOREFONT	(5)
#define AG_CG_TITLE	(6)
#define AG_CG_EFFECT_DMG1	(7)
#define AG_CG_EFFECT_DMG2	(8)
#define AG_CG_EFFECT_RECOVERY1	(9)
#define AG_CG_EFFECT_RECOVERY2	(10)
#define AG_CG_EFFECT_RECOVERY3	(11)
#define AG_CG_ENEMY_FROGA1	(12)
#define AG_CG_ENEMY_FROGA2	(13)
#define AG_CG_ENEMY_FROGA3	(14)
#define AG_CG_OBJ_CROW_BODY1	(15)
#define AG_CG_OBJ_CROW_BODY2	(16)
#define AG_CG_OBJ_CROW_BODY3	(17)
#define AG_CG_OBJ_CROW_WING_L1	(18)
#define AG_CG_OBJ_CROW_WING_L2	(19)
#define AG_CG_OBJ_CROW_WING_L3	(20)
#define AG_CG_OBJ_CROW_WING_R1	(21)
#define AG_CG_OBJ_CROW_WING_R2	(22)
#define AG_CG_OBJ_CROW_WING_R3	(23)
#define AG_CG_OBJ_GRASS	(24)
#define AG_CG_OBJ_SNAKE1	(25)
#define AG_CG_OBJ_SNAKE2	(26)
#define AG_CG_OBJ_SNAKE3	(27)
#define AG_CG_OBJ_SNAKE4	(28)
#define AG_CG_BG_0_0_0	(29)
#define AG_CG_BG_0_1_0	(30)
#define AG_CG_BG_0_0_1	(31)
#define AG_CG_BG_0_0_2	(32)
#define AG_CG_BG_0_0_3	(33)
#define AG_CG_BG_0_1_1	(34)
#define AG_CG_BG_0_1_2	(35)
#define AG_CG_BG_0_1_3	(36)
#define AG_CG_BG_0_2_0	(37)
#define AG_CG_BG_0_2_1	(38)
#define AG_CG_BG_0_2_2	(39)
#define AG_CG_BG_0_2_3	(40)
#define AG_CG_BG_0_3_0	(41)
#define AG_CG_BG_0_3_1	(42)
#define AG_CG_BG_0_3_2	(43)
#define AG_CG_BG_0_3_3	(44)
#define AG_CG_OBJ_TOGE	(45)
#define AG_CG_OBJ_TOGE_D	(46)
#define AG_CG_OBJ_TOGE_L	(47)
#define AG_CG_OBJ_TOGE_R	(48)
#define AG_CG_OBJ_TOGE4	(49)
#define AG_CG_OBJ_TOGE4_D	(50)
#define AG_CG_OBJ_TOGE4_L	(51)
#define AG_CG_OBJ_TOGE4_R	(52)
#define AG_CG_OBJ_CANNON	(53)
#define AG_CG_OBJ_BLOCK	(54)
#define AG_CG_OBJ_BLOCK_H	(55)
#define AG_CG_OBJ_BLOCK4_0	(56)
#define AG_CG_OBJ_BLOCK_H4	(57)
#define AG_CG_OBJ_LIFT	(58)
#define AG_CG_STORY_DAIGOROU	(59)
#define AG_CG_STORY_ERITAN	(60)
#define AG_CG_STORY_CLOUD_ERITAN	(61)
#define AG_CG_ITEM_MERONPAN256	(62)
#define AG_CG_ITEM_UNIXSP256	(63)
#define AG_CG_STORY_SHUCHU	(64)
#define AG_CG_STORY_SHUCHU_SUB	(65)
#define AG_CG_STORY_A_BUTTON	(66)
#define AG_CG_ITEM_MERONPAN64	(67)
#define AG_CG_ITEM_UNIXSP64	(68)
#define AG_CG_ITEM_ERITAN	(69)
#define AG_CG_ITEM_BONE_AG	(70)
#define AG_CG_ITEM_BONE_AU	(71)
#define AG_CG_ICON_DAIGORO	(72)
#define AG_CG_ICON_CROSS	(73)
#define AG_CG_ICON_STAR	(74)
#define AG_CG_TEXT_HIGHSCORE	(75)
#define AG_CG_TEXT_NEWRECORD	(76)
#define AG_CG_TEXT_SCORE	(77)

/***************************************************************/
/*                     RM3 Member Symbol                       */
/***************************************************************/
#define AG_RP_DAIGOROU_GAMEOVER	(0)
#define AG_RP_DAIGOROU_JUMP	(1)
#define AG_RP_DAIGOROU_JUMPEND	(2)
#define AG_RP_DAIGOROU_RT	(3)
#define AG_RP_DAIGOROU_RUN	(4)
#define AG_RP_DAIGOROU_RUNEND	(5)
#define AG_RP_DAIGOROU_RUNSTART	(6)
#define AG_RP_DAIGOROU_WAIT	(7)
#define AG_RP_DAIGOROU_WALK	(8)
#define AG_RP_DAIGOROU_JUMPSTART	(9)
#define AG_RP_DAIGOROU_WALKEND	(10)
#define AG_RP_DAIGOROU_WALKSTART	(11)
#define AG_RP_EFF_RT	(12)
#define AG_RP_OBJ_EBULLET	(13)
#define AG_RP_OBJ_PBULLET	(14)
#define AG_RP_SIN_MESSAGE	(15)

/***************************************************************/
/*                       Vram Group Symbol                     */
/***************************************************************/

/***************************************************************/
/*                       Sound Member Symbol                   */
/***************************************************************/
#define AS_SND_BGM_2_441	(0)
#define AS_SND_BGM_2_441_HU	(1)
#define AS_SND_TITLE_1	(2)
#define AS_SND_GAMEOVER	(3)
#define AS_SND_GAMECLEAR	(4)
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
#define AS_SND_CANNON	(18)
#define AS_SND_CROW	(19)
#define AS_SND_FROG	(20)
#define AS_SND_A01	(21)
#define AS_SND_A02	(22)
#define AS_SND_A03	(23)
#define AS_SND_A04	(24)
#define AS_SND_B01	(25)
#define AS_SND_B02	(26)
#define AS_SND_B03	(27)
#define AS_SND_B04	(28)
#define AS_SND_B05	(29)
#define AS_SND_B06	(30)
#define AS_SND_B07	(31)
#define AS_SND_B08	(32)
#define AS_SND_B09	(33)
#define AS_SND_B10	(34)
#define AS_SND_B11	(35)

/***************************************************************/
/*                          Data Member                        */
/***************************************************************/
extern const AGERomMember ageRM[78];
extern const AGERM3Member ageRM3[16];
extern const u32 ageReserve[1];
extern const u32 ageUser[1];
extern const s16 ageVGCnt;
extern const AGESoundRomMember ageSRM[36];

#ifdef __cplusplus
}
#endif

#endif /* __AG_EXPORT__ */
