#include <amlib.h>
#include <agdraw.h>
#include <agesndmgr.h>
#include "task.h"
#include "pad.h"
#include "mode.h"
#include "randMT.h"
#include "export.h"
#include "global.h"

/******************************************************************/
/*                             ƒXƒRƒA                             */
/******************************************************************/
static s32 DrawScore( struct TaskData* pTask , AGDrawBuffer* pDBuf ) {
	int i;
	int x,y;
	int w,h;
	u32 score;

	agPictureSetBlendMode( pDBuf , 0 , 0xff , 0 , 0 , 2 , 1 );
	ageTransferAAC( pDBuf, AG_CG_SCOREFONT, 0, &w, &h );

	score = *(pTask->Data.score.pScore);

	for( i=0 ; i<pTask->Data.score.digit ; i++ ) {
		u32 n = score%10;

		x = pTask->x + ((pTask->Data.score.digit-i) * 50);
		y = pTask->y;

		agDrawSPRITE_UV( pDBuf, x<<2 , y<<2 , (n*58*0x1000)/w , 0 , (x+58)<<2 , (y+70)<<2 , ((n+1)*58*0x1000)/w , 0x1000 );

		score /= 10;
	};

	return( 0 );
}

void InitTaskScore( struct TaskData* pTask , s32 x , s32 y , u32* pScore, u8 digit ) {
	pTask->type = TASK_SCORE;
	pTask->visible = 1;
	pTask->x = x;
	pTask->y = y;
	pTask->Calc = NULL;
	pTask->Draw = DrawScore;
	pTask->Data.score.pScore = pScore;
	pTask->Data.score.digit = digit;
}
