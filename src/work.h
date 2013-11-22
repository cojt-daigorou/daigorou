#ifndef __WORKMETER_H__
#define __WORKMETER_H__

void InitWorkMeter( int fb_width , int fb_height , int VCount );
void ClearWorkMeter( void );
void SetWorkMeter( u32 Color );
int GetWorkMeterPos( void );
void DrawWorkMeter( AGDrawBuffer* DBuf );

#endif // __WORKMETER_H__
