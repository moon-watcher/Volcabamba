#ifndef _SCROLL_H_
#define _SCROLL_H_


typedef struct
{
    s16      x;
    s16      y;

    u16      column;
    u16      column_prev;

    u16      row;
    u16      row_prev;

    u16      width;
    u16      height;

    VDPPlan  plan;
    Image   *image;
    u16      attributes;

    u8       tiles_width;
    u8       tiles_height;
}
Scroll;


void scrollInit       ( Scroll *scroll, VDPPlan plan, Image *image, u16 attributes );
void scrollMove       ( Scroll *scroll );
void scrollUpdate     ( Scroll *scroll, s16 inc_x, s16 inc_y );
void scrollDrawScreen ( Scroll *scroll );

#endif // _SCROLL_H_
