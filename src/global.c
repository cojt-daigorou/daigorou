#include <amlib.h>
#include "global.h"

int g_PlayerX = 0;
int g_PlayerY = 0;
int g_OffsetX = 0;
int g_OffsetY = 0;

int g_isGameOver = 0;
int g_isStageClear = 0;
int g_isGetKeyItem = FALSE;

u32 g_Score = 0;
u32 g_Time = 0;
u32 g_Life = 10;
u32 g_Star = 30;
u32 g_Stage = 0;

struct RECT *g_pPlayerRect = NULL;
struct TaskData* g_pPlayerTask = NULL;
