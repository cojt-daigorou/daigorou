#ifndef __MODE_H__
#define __MODE_H__

enum GameMode {
	MODE_NONE,
	MODE_TITLE,
  MODE_STORY,
	MODE_GAME,
};

void InitMode( void );
void GotoMode( enum GameMode mode );

#endif // __MODE_H__
