#include <genesis.h>
#include "scroll.h"
#include "vdp.h"


// TODO:
//  - Añadir paddings
//  - Poder hacer loops
//  - Mover más de 8 de una vez


void scrollInit ( Scroll *scroll, VDPPlan plan, Image *image, u16 attributes )
{
    scroll->x            = 0;
    scroll->y            = 0;

    scroll->width        = ( image->map->w << 3 ) - screenWidth;
    scroll->height       = ( image->map->h << 3 ) - screenHeight;

    scroll->column       = 0;
    scroll->row          = 0;

    scroll->column_prev  = 0;
    scroll->row_prev     = 0;

    scroll->plan         = plan;
    scroll->image        = (Image*) image;
    scroll->attributes   = attributes;

    scroll->tiles_height = min ( image->map->h, ( screenHeight >> 3 ) + 4 );
    scroll->tiles_width  = min ( image->map->w, ( screenWidth  >> 3 ) + 4 );
}


void scrollMove ( Scroll *scroll )
{
    SYS_disableInts();
    VDP_setHorizontalScroll ( scroll->plan, scroll->x );
    VDP_setVerticalScroll   ( scroll->plan, scroll->y );
    SYS_enableInts();

    if ( scroll->column != scroll->column_prev )
    {
        s16 y = ( +scroll->y >> 3 ) - 2;

        if ( y < 0 ) y = 0;

        SYS_disableInts();
        VDP_setMapColumn ( scroll->plan, scroll->image->map, scroll->attributes, scroll->column, y, scroll->column, y, scroll->tiles_height );
        SYS_enableInts();

        scroll->column_prev = scroll->column;
    }

    if ( scroll->row != scroll->row_prev )
    {
        s16 x = ( -scroll->x >> 3 ) - 2;

        if ( x < 0 ) x = 0;

        SYS_disableInts();
        VDP_setMapRow ( scroll->plan, scroll->image->map, scroll->attributes, x, scroll->row, x, scroll->row, scroll->tiles_width );
        SYS_enableInts();

        scroll->row_prev = scroll->row;
    }
}


void scrollUpdate ( Scroll *scroll, s16 inc_x, s16 inc_y )
{
    if ( inc_x )
    {
        scroll->x += inc_x;

             if ( scroll->x < -scroll->width ) scroll->x = -scroll->width;
        else if ( scroll->x > 0              ) scroll->x = 0;

        s16 aux = - ( scroll->x >> 3 ) - 2;

        if ( inc_x < 0 ) aux = ( ( -scroll->x + screenWidth ) >> 3 ) + 1;
        if ( aux   < 0 ) aux = 0;

        scroll->column = aux;
    }

    if ( inc_y )
    {
        scroll->y += inc_y;

             if ( scroll->y > +scroll->height ) scroll->y = +scroll->height;
        else if ( scroll->y < 0               ) scroll->y = 0;

        s16 aux = + ( scroll->y >> 3 ) - 1;

        if ( inc_y > 0 ) aux = ( ( +scroll->y + screenHeight ) >> 3 ) + 1;
        if ( aux   < 0 ) aux = 0;

        scroll->row = aux;
    }
}


//void scrollDrawScreen ( Scroll *scroll )
//{
//    s16 x = - ( scroll->x >> 3 ) - 2;
//    s16 y = + ( scroll->y >> 3 ) - 2;
//
//    SYS_disableInts();
//    VDP_setMapRect ( scroll->plan, scroll->image->map, scroll->attributes, x, y, x, y, scroll->tiles_width, scroll->tiles_height );
//    SYS_enableInts();
//}
