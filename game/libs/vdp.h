#ifndef _LIB_VDP_H_
#define _LIB_VDP_H_

u16 VDP_setMapRect   ( VDPPlan plan, const Map *map, u16 basetile, u16 x, u16 y, u16 region_x, u16 region_y, u16 width, u16 height );
u16 VDP_setMapColumn ( VDPPlan plan, const Map *map, u16 basetile, u16 x, u16 y, u16 region_x, u16 region_y, u16 height );
u16 VDP_setMapRow    ( VDPPlan plan, const Map *map, u16 basetile, u16 x, u16 y, u16 region_x, u16 region_y, u16 width );
u16 VDP_getTile      ( VDPPlan plan, u16 x, u16 y );

#endif // _LIB_VDP_H_
