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

// スコア関連

void AddScore( u32 n ) {
  g_Score += n;
  if ( g_Score > SCORE_MAX ) {
    g_Score = SCORE_MAX;
  }
}

void AddStar( u32 n ) {
  g_Star += n;
  if ( g_Star > STAR_MAX ) {
    g_Star = STAR_MAX;
  }
}

void AddTime( u32 n ) {
  g_Time += n;
  if ( g_Time > TIME_MAX ) {
    g_Time = TIME_MAX;
  }
}

// 数学

s32 max(int a, int b) {
  return a > b ? a : b;
}
s32 min(int a, int b) {
  return a < b ? a : b;
}
float ease_out(float t) {
  return 1 - expf( -6.0 * t );
}
