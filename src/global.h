#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <agtypes.h>

#define PI (3.14159265359)

extern int g_PlayerX;
extern int g_PlayerY;
extern int g_OffsetX;
extern int g_OffsetY;

extern int g_isGameOver;
extern int g_isStageClear;
extern int g_isGetKeyItem;

extern u32 g_Score;
extern u32 g_Time;
extern u32 g_Life;
extern u32 g_Stage;

extern struct RECT* g_pPlayerRect;

#endif // __GLOBAL_H__
