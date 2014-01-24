#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "randMT.h"
#include "export.h"
#include "global.h"
#include "t_bg.h"

// îwåiÇÃï™äÑêî
#define BG_DX (4)
#define BG_DY (6)

#define BG_WIDTH	(256*BG_DX)
#define BG_HEIGHT	(256*BG_DY)

static const u16 bg_list[BG_DY][BG_DX] = {
	{ AG_CG_BG_0_0_0, AG_CG_BG_0_0_1, AG_CG_BG_0_0_2, AG_CG_BG_0_0_3 },
	{ AG_CG_BG_0_0_0, AG_CG_BG_0_0_1, AG_CG_BG_0_0_2, AG_CG_BG_0_0_3 },
	{ AG_CG_BG_0_0_0, AG_CG_BG_0_0_1, AG_CG_BG_0_0_2, AG_CG_BG_0_0_3 },
	{ AG_CG_BG_0_1_0, AG_CG_BG_0_1_1, AG_CG_BG_0_1_2, AG_CG_BG_0_1_3 },
	{ AG_CG_BG_0_2_0, AG_CG_BG_0_2_1, AG_CG_BG_0_2_2, AG_CG_BG_0_2_3 },
	{ AG_CG_BG_0_3_0, AG_CG_BG_0_3_1, AG_CG_BG_0_3_2, AG_CG_BG_0_3_3 },
};

/******************************************************************/
/*                                bg                              */
/******************************************************************/
static s32 CalcBg( struct TaskData* pTask , u32 Flag ) {
	return( 0 );
}

static s32 DrawBg( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
	int w,h;
	int x,y;
	int pat = 0;
	int xx , yy;
	int ox , oy;

	agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );

	x = g_OffsetX - (g_OffsetX / BG_WIDTH) * BG_WIDTH;
	y = g_OffsetY + BG_HEIGHT - 768;

	oy = 0;

	for( yy=0 ; yy<BG_DY ; yy++ ) {
		h = ageRM[ bg_list[yy][0] ].Height;

		if( (oy + h) < y || (y + 768) < oy ) {
			oy += h;
			continue;
		};

		ox = 0;

		for( pat=0 ; pat<2 ; pat++ ) {
			for( xx=0 ; xx<BG_DX ; xx++ ) {
				w = ageRM[ bg_list[yy][xx] ].Width;

				if( (ox + w) < x || (x + 1024) < ox ) {
					ox += w;
					continue;
				};

				ageTransferAAC( pDBuf, bg_list[yy][xx] , 0, NULL, NULL );

				if( pTask->Data.bg.alpha_flag == 0 ) {
					agDrawSPRITE( pDBuf, 1, (ox - x)<<2 , (oy - y)<<2 , (ox - x + w)<<2, (oy - y + h)<<2 );
				}
				else {
					agDrawSPRITE( pDBuf, 1, (ox - x)<<2 , (oy - y)<<2 , (ox - x + w)<<2, (oy - y + h)<<2 );
				};

				ox += w;
			};
		};

		oy += h;
	};

	return( 0 );
}

void InitTaskBg( struct TaskData* pTask , u16 Image , u8 AlphaFlag ) {
	memset( pTask , 0 , sizeof( *pTask ) );

	pTask->type = TASK_BG;
	pTask->visible = 1;
	pTask->Calc = CalcBg;
	pTask->Draw = DrawBg;
	pTask->Data.bg.image = Image;
	pTask->Data.bg.alpha_flag = AlphaFlag;
}
