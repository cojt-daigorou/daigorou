#include <amlib.h>
#include "rect.h"

void AddRect( struct RECT *pRect , s16 dx , s16 dy ) {
	pRect->x0 += dx;
	pRect->x1 += dx;
	pRect->y0 += dy;
	pRect->y1 += dy;
}

int IsHitRect( const struct RECT* pRect0 , const struct RECT* pRect1 ) {
	if( pRect0->x0 < pRect1->x0 && pRect0->x1 < pRect1->x0 ) {
		return( 0 );
	};
	if( pRect0->y0 < pRect1->y0 && pRect0->y1 < pRect1->y0 ) {
		return( 0 );
	};
	if( pRect0->x0 >= pRect1->x1 && pRect0->x1 >= pRect1->x1 ) {
		return( 0 );
	};
	if( pRect0->y0 >= pRect1->y1 && pRect0->y1 >= pRect1->y1 ) {
		return( 0 );
	};

	return( 1 );
}
