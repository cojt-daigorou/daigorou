#include <amlib.h>
#include "global.h"

int g_PlayerX = 0;
int g_PlayerY = 0;
int g_OffsetX = 0;
int g_OffsetY = 0;
int g_GameOver = 0;

u32 g_Score = 0;
u32 g_Time = 0;
u32 g_Life = 1;

struct RECT *g_pPlayerRect = NULL;
