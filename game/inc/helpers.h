#ifndef _INC_HELPERS_H_
#define _INC_HELPERS_H_


#define SPR_getWidth(s)  (s)->frame[0].w
#define SPR_getHeight(s) (s)->frame[0].h

#define SPR_getVFlip(s)  (((s)->attribut >> 12) & 1)
#define SPR_getHFlip(s)  (((s)->attribut >> 11) & 1)



void drawText    ( const char *str, u16 x, u16 y );
void drawInt     ( s32 nb, u8 x, u8 y, u8 zeros );
void drawUInt    ( u32 nb, u8 x, u8 y, u8 zeros );
void drawUIntBG  ( u32 number, u8 x, u8 y, u8 leading_zeros, VDPPlan plan, u16 flags );
u16  drawImage   ( Image *image, VDPPlan plan );
u16  drawImageXY ( Image *image, VDPPlan plan, u16 x, u16 y );


void SPR_setVRAMDirect ( Sprite *sprite, u16 vrampos );
u16  SPR_nbTiles       ( Sprite *sprite );

#endif // _INC_HELPERS_H_
