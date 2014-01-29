#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <agtypes.h>

#define PI (3.14159265359)
#define GROUND_LINE (668)

#define STAGE_N (3)

// TODO: �����[�X�̎��ɂ͊O��( dprintf()�p )
//#define DEBUG debug

extern int g_PlayerX;
extern int g_PlayerY;
extern int g_OffsetX;
extern int g_OffsetY;

extern int g_isGameOver;
extern int g_isStageClear;
extern int g_isGetKeyItem;

extern int g_Score;
extern int g_ScoreInitial;// �X�e�[�W�J�n���̃X�R�A
extern int g_HighScoreS[STAGE_N];// �e�X�e�[�W�̃N���A���̃n�C�X�R�A
extern int g_isHighScore;

extern int g_Time;
extern int g_Life;
extern int g_Star;
extern int g_Stage;

extern struct RECT* g_pPlayerRect;
extern struct TaskData* g_pPlayerTask;
extern struct TaskData* g_pSenarioTask;

// �X�R�A�֘A

// �{�[�i�X�X�R�A�v�Z���̏d��
#define BSCORE_TIME (1)
#define BSCORE_LIFE (50)
#define BSCORE_STAR (1)

// �J���X�g�p
#define SCORE_MAX (9999)
#define STAR_MAX  (99)
#define TIME_MAX  (999)

extern void AddScore( u32 n );
extern void AddStar( u32 n );
extern void AddTime( u32 n );


// ���w

extern s32 max(int a, int b);
extern s32 min(int a, int b);
extern float ease_out(float t);

#endif // __GLOBAL_H__
