#include <amlib.h>
#include "global.h"

int g_PlayerX = 0;
int g_PlayerY = 0;
int g_OffsetX = 0;
int g_OffsetY = 0;

int g_isGameOver = 0;
int g_isStageClear = 0;
int g_isGetKeyItem = FALSE;

int g_Score = 0;
int g_HighScoreS[STAGE_N] = {0};
int g_isHighScore = FALSE;

int g_Time = 0;
int g_Life = 0;
int g_Star = 0;
int g_Stage = 0;

struct RECT *g_pPlayerRect = NULL;
struct TaskData* g_pPlayerTask = NULL;
struct TaskData* g_pSenarioTask = NULL;
