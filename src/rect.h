#ifndef __RECT_H__
#define __RECT_H__

struct RECT {
	s32 x0;
	s32 y0;
	s32 x1;
	s32 y1;
};

void AddRect( struct RECT *pRect , s16 dx , s16 dy );
int IsHitRect( const struct RECT* pRect0 , const struct RECT* pRect1 );

#endif // __RECT_H__
