#include <amlib.h>
#include <agdraw.h>
#include <agpicture.h>
#include "work.h"

#define MAX_WORKMETER_COUNT		(10)

static volatile int g_VWidth = 1;
static volatile int VCount = 0;
static volatile int WorkMeterCount = 0;
static volatile u32 WorkMeterColor[ MAX_WORKMETER_COUNT ];
static volatile u32 WorkMeterPos[ MAX_WORKMETER_COUNT ];
static int g_FBWidth = 800;
static int g_FBHeight = 600;

static s32 VSyncCallback( int type ) {
	VCount++;

	return( 1 );
}

void InitWorkMeter( int fb_width , int fb_height , int VWidth ) {
	if( VWidth > 0 ) {
		g_VWidth = VWidth;
	};

			//　コールバック登録
	if( aglGetMainDisplay() == 0 ) {		//　表示Ａ
		aglRemoveInterruptCallback( AG_INT_TYPE_VBLA , VSyncCallback );
		aglAddInterruptCallback( AG_INT_TYPE_VBLA , VSyncCallback );
	}
	else {
		aglRemoveInterruptCallback( AG_INT_TYPE_VBLB , VSyncCallback );
		aglAddInterruptCallback( AG_INT_TYPE_VBLB , VSyncCallback );
	};

	g_FBWidth = fb_width;
	g_FBHeight = fb_height;

	ClearWorkMeter();
}

void ClearWorkMeter( void ) {
	VCount = 0;
	WorkMeterCount = 0;
}

int GetWorkMeterPos( void ) {
	int line;
	int vc = VCount;
	int vb_line;
	int vsc;

	if( aglGetMainDisplay() == 0 ) {		//　表示Ａ
		line = AG4REG.DSPALMNTR.OUTPUT;
		vb_line = AG4REG.DSPAVPRM0.VBL+1 + AG4REG.DSPASIZE0.VDO;
		vsc = AG4REG.DSPAVPRM0.VSC;
	}
	else {
		line = AG4REG.DSPBLMNTR.OUTPUT;
		vb_line = AG4REG.DSPBVPRM0.VBL+1 + AG4REG.DSPBSIZE0.VDO;
		vsc = AG4REG.DSPBVPRM0.VSC;
	};

	if( line >= vb_line ) {
		return( vsc * vc + (line - vb_line) );
	}
	else {
		return( vsc * vc + (vsc - vb_line) + line );
	};
}

void SetWorkMeter( u32 Color ) {
	if( WorkMeterCount >= MAX_WORKMETER_COUNT ) {
		return;
	};

	WorkMeterPos[WorkMeterCount] = GetWorkMeterPos();
	WorkMeterColor[WorkMeterCount] = Color;

	WorkMeterCount++;
}

void DrawWorkMeter( AGDrawBuffer* DBuf ) {
	u32 Start = 32;
	u32 DrawWidth = g_FBWidth - 32*2;
	u32 Height = g_FBHeight;
	u32 Width;
	int i;
	int j;
	int dw;

	if( aglGetMainDisplay() == 0 ) {		//　表示Ａ
		Width = AG4REG.DSPAVPRM0.VSC * g_VWidth;
		dw = AG4REG.DSPAVPRM0.VSC*DrawWidth;
	}
	else {
		Width = AG4REG.DSPBVPRM0.VSC * g_VWidth;
		dw = AG4REG.DSPBVPRM0.VSC*DrawWidth;
	};

	AG_DRAW_SETATEST( *DBuf , 0 , 7 , 0 );
	AG_DRAW_SETDTEST( *DBuf , 7 , 0 );

	for( i=0 ; i<WorkMeterCount ; i++ ) {
		u32 Pos = WorkMeterPos[i] * DrawWidth / Width + 32;

		AG_DRAW_SETFCOLOR_ARGB( *DBuf , WorkMeterColor[i] );
		AG_DRAW_RECTANGLE( *DBuf , Start<<2 , (Height-32)<<2 , Pos<<2 , (Height-32+5)<<2 );

		Start = Pos;
	};

	for( i=0 ; i<=g_VWidth ; i++ ) {
		AG_DRAW_SETFCOLOR_ARGB( *DBuf , ARGB( 255 , 255 , 255 , 255 ) );
		AG_DRAW_RECTANGLE( *DBuf , (i*dw/Width+32)<<2 , (Height-32-2)<<2 , (i*dw/Width+32+1)<<2 , (Height-32+5+2)<<2 );

		if( i < g_VWidth ) {
			AG_DRAW_SETFCOLOR_ARGB( *DBuf , ARGB( 255 , 128 , 128 , 128 ) );

			for( j=1 ; j<10 ; j++ ) {
				int dh = 0;

				if( j == 5 ) {
					dh = 1;
				};

				AG_DRAW_RECTANGLE( *DBuf , ((i*dw + (dw*j/10))/Width+32)<<2 , (Height-32-dh)<<2 ,
								((i*dw + (dw*j/10))/Width+32+1)<<2 , (Height-32+5+dh)<<2 );
			};
		};
	};
}
