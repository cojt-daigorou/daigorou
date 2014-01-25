#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <agtypes.h>

#define PI (3.14159265359)
#define GROUND_LINE (668)

#define STAGE_N (3)

// TODO: リリースの時には外す( dprintf()用 )
//#define DEBUG debug

extern int g_PlayerX;
extern int g_PlayerY;
extern int g_OffsetX;
extern int g_OffsetY;

extern int g_isGameOver;
extern int g_isStageClear;
extern int g_isGetKeyItem;

extern int g_Score;
// 各ステージのクリア時のハイスコア
extern int g_HighScoreS[STAGE_N];
extern int g_isHighScore;

extern int g_Time;
extern int g_Life;
extern int g_Star;
extern int g_Stage;

extern struct RECT* g_pPlayerRect;
extern struct TaskData* g_pPlayerTask;
extern struct TaskData* g_pSenarioTask;

#endif // __GLOBAL_H__
