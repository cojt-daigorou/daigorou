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
#define AG_CG_INFO_TIME	(0)
#define AG_CG_GAMECLEAR	(1)
#define AG_CG_GAMEOVER	(2)
#define AG_CG_GAMESTART	(3)
#define AG_CG_SCOREFONT	(4)
#define AG_CG_TITLE	(5)
#define AG_CG_EFFECT_DMG1	(6)
#define AG_CG_EFFECT_DMG2	(7)
#define AG_CG_EFFECT_RECOVERY1	(8)
#define AG_CG_EFFECT_RECOVERY2	(9)
#define AG_CG_EFFECT_RECOVERY3	(10)
#define AG_CG_ENEMY_FROGA1	(11)
#define AG_CG_ENEMY_FROGA2	(12)
#define AG_CG_ENEMY_FROGA3	(13)
#define AG_CG_OBJ_CROW_BODY1	(14)
#define AG_CG_OBJ_CROW_BODY2	(15)
#define AG_CG_OBJ_CROW_BODY3	(16)
#define AG_CG_OBJ_CROW_WING_L1	(17)
#define AG_CG_OBJ_CROW_WING_L2	(18)
#define AG_CG_OBJ_CROW_WING_L3	(19)
#define AG_CG_OBJ_CROW_WING_R1	(20)
#define AG_CG_OBJ_CROW_WING_R2	(21)
#define AG_CG_OBJ_CROW_WING_R3	(22)
#define AG_CG_OBJ_GRASS	(23)
#define AG_CG_OBJ_SNAKE1	(24)
#define AG_CG_OBJ_SNAKE2	(25)
#define AG_CG_OBJ_SNAKE3	(26)
#define AG_CG_OBJ_SNAKE4	(27)
#define AG_CG_BG_0_0_0	(28)
#define AG_CG_BG_0_1_0	(29)
#define AG_CG_BG_0_0_1	(30)
#define AG_CG_BG_0_0_2	(31)
#define AG_CG_BG_0_0_3	(32)
#define AG_CG_BG_0_1_1	(33)
#define AG_CG_BG_0_1_2	(34)
#define AG_CG_BG_0_1_3	(35)
#define AG_CG_BG_0_2_0	(36)
#define AG_CG_BG_0_2_1	(37)
#define AG_CG_BG_0_2_2	(38)
#define AG_CG_BG_0_2_3	(39)
#define AG_CG_BG_0_3_0	(40)
#define AG_CG_BG_0_3_1	(41)
#define AG_CG_BG_0_3_2	(42)
#define AG_CG_BG_0_3_3	(43)
#define AG_CG_OBJ_TOGE	(44)
#define AG_CG_OBJ_TOGE_D	(45)
#define AG_CG_OBJ_TOGE_L	(46)
#define AG_CG_OBJ_TOGE_R	(47)
#define AG_CG_OBJ_TOGE4	(48)
#define AG_CG_OBJ_TOGE4_D	(49)
#define AG_CG_OBJ_TOGE4_L	(50)
#define AG_CG_OBJ_TOGE4_R	(51)
#define AG_CG_OBJ_CANNON	(52)
#define AG_CG_OBJ_BLOCK	(53)
#define AG_CG_OBJ_BLOCK_H	(54)
#define AG_CG_OBJ_BLOCK4_0	(55)
#define AG_CG_OBJ_BLOCK_H4	(56)
#define AG_CG_OBJ_LIFT	(57)
#define AG_CG_STORY_DAIGOROU	(58)
#define AG_CG_STORY_ERITAN	(59)
#define AG_CG_STORY_CLOUD_ERITAN	(60)
#define AG_CG_ITEM_MERONPAN256	(61)
#define AG_CG_ITEM_UNIXSP256	(62)
#define AG_CG_STORY_SHUCHU	(63)
#define AG_CG_STORY_SHUCHU_SUB	(64)
#define AG_CG_ITEM_MERONPAN64	(65)
#define AG_CG_ITEM_UNIXSP64	(66)
#define AG_CG_ITEM_ERITAN	(67)
#define AG_CG_ITEM_BONE_AG	(68)
#define AG_CG_ITEM_BONE_AU	(69)
#define AG_CG_ICON_DAIGORO	(70)
#define AG_CG_ICON_CROSS	(71)
#define AG_CG_ICON_STAR	(72)
#define AG_CG_TEXT_HIGHSCORE	(73)
#define AG_CG_TEXT_NEWRECORD	(74)
#define AG_CG_TEXT_SCORE	(75)

/***************************************************************/
/*                     RM3 Member Symbol                       */
/***************************************************************/
#define AG_RP_DAIGOROU_GAMEOVER	(0)
#define AG_RP_DAIGOROU_JUMP	(1)
#define AG_RP_DAIGOROU_JUMPEND	(2)
#define AG_RP_DAIGOROU_JUMPSTART	(3)
#define AG_RP_DAIGOROU_RT	(4)
#define AG_RP_DAIGOROU_RUN	(5)
#define AG_RP_DAIGOROU_RUNEND	(6)
#define AG_RP_DAIGOROU_RUNSTART	(7)
#define AG_RP_DAIGOROU_WAIT	(8)
#define AG_RP_DAIGOROU_WALK	(9)
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
extern const AGERomMember ageRM[76];
extern const AGERM3Member ageRM3[16];
extern const u32 ageReserve[1];
extern const u32 ageUser[1];
extern const s16 ageVGCnt;
extern const AGESoundRomMember ageSRM[36];

#ifdef __cplusplus
}
#endif

#endif /* __AG_EXPORT__ */
