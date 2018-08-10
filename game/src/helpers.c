#include <genesis.h>

#include "helpers.h"
#include "../libs/vram.h"
#include "../libs/display.h"


void drawText ( const char *str, u16 x, u16 y )
{
    SYS_disableInts();
    VDP_drawText ( str, x, y );
    SYS_enableInts();
}


void drawInt ( s32 nb, u8 x, u8 y, u8 zeros )
{
    char str [ zeros+1 ];
    intToStr ( nb, str, zeros );
    drawText ( str, x, y );
}


void drawUInt ( u32 nb, u8 x, u8 y, u8 zeros )
{
    char str [ zeros+1 ];
    uintToStr ( nb, str, zeros );
    drawText ( str, x, y );
}


void drawFix32 ( fix32 nb, u8 x, u8 y, u8 zeros )
{
    char str [ zeros+1 ];
    fix32ToStr ( nb, str, zeros );

    SYS_disableInts();
    VDP_drawText ( str, x, y );
    SYS_enableInts();
}


void drawUIntBG ( u32 nb, u8 x, u8 y, u8 zeros, VDPPlan plan, u16 flags )
{
    char str [ zeros+1 ];
    uintToStr ( nb, str, zeros );

    SYS_disableInts();
    VDP_drawTextBG ( PLAN_B, str, x, y );
    SYS_enableInts();
}


u16 drawImage ( Image *image, VDPPlan plan )
{
    if ( image == NULL )
    {
        return 0;
    }

    s16 x = ( screenWidth  >> 4 ) - ( image->map->w >> 1 );
    s16 y = ( screenHeight >> 4 ) - ( image->map->h >> 1 );

    return drawImageXY ( image, plan, x, y );
}


u16 drawImageXY ( Image *image, VDPPlan plan, u16 x, u16 y )
{
    if ( image == NULL )
    {
        return 0;
    }

    u16 pos = vram_new ( image->tileset->numTile );
    u16 pal = ( plan.value == PLAN_A.value ) ? PAL1 : PAL0;

    SYS_disableInts();
    VDP_drawImageEx ( plan, image, TILE_ATTR_FULL ( pal, 0, 0, 0, pos ), x, y, 0, 0 );
    SYS_enableInts();

    preparePal ( pal, image->palette->data );

    return pos;
}


void drawMem ( u8 x, u8 y )
{
    drawUInt ( MEM_getFree ( ), x, y, 5 );
}



void SPR_setVRAMDirect ( Sprite *sprite, u16 vrampos )
{
	sprite->attribut = ( sprite->attribut & TILE_ATTR_MASK ) | vrampos;
	sprite->status |= 0x0001; // NEED_ST_ATTR_UPDATE;
	sprite->timer = 0;
}


u16 SPR_nbTiles ( Sprite *sprite )
{
    // see SPRITE_SIZE macro
    return ( sprite->frame[0].h >> 3 ) * ( sprite->frame[0].w >> 3 );
}

