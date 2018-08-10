#include <genesis.h>

#define PLAN_ADDR(p)  ( ( (p).value == PLAN_A.value ) ? VDP_PLAN_A : VDP_PLAN_B )



void VDP_setMapRect ( VDPPlan plan, const Map *map, u16 basetile, u16 x, u16 y, u16 region_x, u16 region_y, u16 width, u16 height )
{
    x %= planWidth;
    y %= planHeight;

    VDP_setAutoInc(2);

    const u16 plan_addr = PLAN_ADDR(plan);
    const u16 baseindex = basetile & TILE_INDEX_MASK;
    const u16 baseflags = basetile & TILE_ATTR_MASK;
    const u16 src_inc   = map->w - width;

    u16  *src    = map->tilemap + ( region_y * map->w ) + region_x;

    vu32 *plctrl = (u32 *) GFX_CTRL_PORT;
    vu16 *pwdata = (u16 *) GFX_DATA_PORT;

    *plctrl = GFX_WRITE_VRAM_ADDR ( plan_addr + ((x + (y << planWidthSft)) <<  1) );


    while ( height-- )
    {
        u16 e = x;
        u16 w = width;

        while ( w-- )
        {
            *pwdata = baseflags | (*src++ + baseindex);

            if ( ++e == planWidth )
            {
                e = 0;
                *plctrl = GFX_WRITE_VRAM_ADDR ( plan_addr + ((e + (y << planWidthSft)) <<  1) );
            }
        }

        if ( ++y == planHeight )
        {
            y = 0;
        }

        *plctrl = GFX_WRITE_VRAM_ADDR ( plan_addr + ((x + (y << planWidthSft)) <<  1) );

        src  += src_inc;
    }
}



void VDP_setMapColumn ( VDPPlan plan, const Map *map, u16 basetile, u16 x, u16 y, u16 region_x, u16 region_y, u16 height )
{
    x %= planWidth;
    y %= planHeight;

    VDP_setAutoInc(2);

    const u16 mapWidth  = map->w;
    const u16 plan_addr = PLAN_ADDR(plan);
    const u16 baseindex = basetile & TILE_INDEX_MASK;
    const u16 baseflags = basetile & TILE_ATTR_MASK;
    const u16 addr_inc  = ( planWidth << 1 );

    u16  *src    = map->tilemap + (region_y * mapWidth) + region_x;
    u32   addr   = plan_addr + ((x + (y << planWidthSft)) <<  1);

    vu32 *plctrl = (u32 *) GFX_CTRL_PORT;
    vu16 *pwdata = (u16 *) GFX_DATA_PORT;

    while ( height-- )
    {
        *plctrl = GFX_WRITE_VRAM_ADDR(addr);
        *pwdata = baseflags | (*src++ + baseindex);

        src  += mapWidth - 1;
        addr += addr_inc;

        if ( ++y == planHeight )
        {
            y = 0;
            addr = plan_addr + ((x + (y << planWidthSft)) <<  1);
        }
    }
}



void VDP_setMapRow ( VDPPlan plan, const Map *map, u16 basetile, u16 x, u16 y, u16 region_x, u16 region_y, u16 width )
{
    x %= planWidth;
    y %= planHeight;

    VDP_setAutoInc(2);

    const u16 mapWidth  = map->w;
    const u16 plan_addr = PLAN_ADDR(plan);
    const u16 baseindex = basetile & TILE_INDEX_MASK;
    const u16 baseflags = basetile & TILE_ATTR_MASK;


    u16  *src    = map->tilemap + (region_y * mapWidth) + region_x;
    u32   addr   = plan_addr + ((x + (y << planWidthSft)) <<  1);

    vu32 *plctrl = (u32 *) GFX_CTRL_PORT;
    vu16 *pwdata = (u16 *) GFX_DATA_PORT;

    *plctrl = GFX_WRITE_VRAM_ADDR(addr);

    while ( width-- )
    {
        *pwdata = baseflags | (*src++ + baseindex);

        if ( ++x == planWidth )
        {
            x = 0;
            addr = plan_addr + ((x + (y << planWidthSft)) <<  1);
            *plctrl = GFX_WRITE_VRAM_ADDR(addr);
        }
    }
}



u16 VDP_getTile ( VDPPlan plan, u16 x, u16 y )
{
    vu32 *plctrl;
    vu16 *pwdata;

    const u16 plan_addr = PLAN_ADDR(plan);

    /* point to vdp port */
    plctrl = (u32 *) GFX_CTRL_PORT;
    pwdata = (u16 *) GFX_DATA_PORT;

    *plctrl = GFX_READ_VRAM_ADDR( plan_addr + ((x + (planWidth * y)) * 2) );

    return *pwdata;
}
