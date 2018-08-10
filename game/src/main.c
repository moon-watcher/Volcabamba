#include <genesis.h>

#include "game.h"
#include "../libs/display.h"
#include "../libs/joyreader.h"


void init ( )
{
	displayOff(0);

	MEM_init();
	VDP_setScreenWidth256 ( );
	VDP_setPlanSize ( 64, 32 );

	JoyReader_init(2);
}


int main()
{
    displayOff(0);
//	screen_sega();

	init();

	while ( 1 )
	{
//		while ( 1 )
//		{
//			if ( screen_intro() ) break;
//			if ( screen_title() ) break;
//		}

		int ok;
		ok = game();


//		if ( ok )
//		{
//			screen_ending();
//		}
//		else
//		{
//			screen_gameover();
//		}
	}

	return 0;
}



//int main ()
//{
//	VDP_setScreenWidth256 ( );
//    VDP_setPlanSize ( 64, 32 );
//
//    const Image *imglist[5] = { &stage1, &stage2, &stage3, &stage4, &stage5 };
//
//    while (1)
//	{
//		const Image *img = imglist [ i++ % 5 ];
//
//		//scrollInit ( &scroll, -10*8, 05*8, PLAN_B, (Image*) img, TILE_ATTR_FULL ( PAL1, 0, 0, 0, 16 ) );
//		scrollInit ( &scroll, 0*8, 0*8, PLAN_B, (Image*) img, TILE_ATTR_FULL ( PAL1, 0, 0, 0, 16 ) );
//
//		SYS_setVIntCallback ( (_voidCallback*) vint_callback );
//
//		// TODO:
//		//  - Añadir paddings
//		//  - Poder hacer loops
//		//  - Mover más de 8 de una vez
//
//		VDP_setMapRect ( scroll.plan, scroll.image->map, scroll.attributes, 0, 0, 0, 0, 42, 22	 );
//
//
//		#define VEL 8
//
//		SYS_disableInts();
//		VDP_loadTileData ( (u32*)img->tileset->tiles, 16, img->tileset->numTile,  0 );
//		VDP_setPalette( PAL1, img->palette->data );
//	    VDP_setTextPalette(PAL2);
//		SYS_enableInts();
//
//	//	scrollDrawScreen ( &scroll );
//
//
//
//		u16 nivel_x = 0;
//
//
//		SPR_init(40, 0, 0);
//
//		s16 pos_x = VDP_getScreenWidth  ( ) / 2 - 8;
//		s16 pos_y = VDP_getScreenHeight ( ) / 2 - 8;
//
//		Sprite *sprites[45];
//		sprites[0] = SPR_addSprite(&nave1, pos_x, pos_y, TILE_ATTR(PAL2, TRUE, FALSE, FALSE));
//		//SPR_setAnim(sprites[0], 5);
//		SPR_update();
//
//		VDP_setPalette ( PAL2, nave1.palette->data );
//
//		/*
//		u16 inc_scroll = 0;
//		*/
//
//
//		u8 vel_nave = 2;
//
//		s16 tile_x, tile_y;
//
//
//		u16 array_pos=0;
//
//		while ( 1 )
//		{
//			VDP_waitVSync();
//			JoyReader_update();
//
//			EnemyPosition *e = &stage1_e[array_pos];
//
//			while ( nivel_x == e->time )
//			{
//				++array_pos;
//
//				int x = e->x/2-50;
//				int y = e->y/2;
//				sprites[array_pos] = SPR_addSprite(e->resource, x, y, TILE_ATTR(PAL2, TRUE, FALSE, FALSE));
//				SPR_setAnim ( &sprites[array_pos], e->animation );
//
//				drawUInt ( x, 0, 2, 3 );
//				drawUInt ( y, 5, 2, 3 );
//
//				e = &stage1_e[array_pos];
//				waitMs(1000);
//
//			}
//
//
//
//
//	//        if ( joy1_active_right ) { SPR_setAnim(sprites[0], 7); vel_x = -VEL; }
//	//        if ( joy1_active_left  )
//	//        {
//	//            //scrollCanMove ( )
//	//            SPR_setAnim(sprites[0], 6); vel_x = +VEL;
//	//        }
//	//
//	//        if ( joy1_active_up    ) { SPR_setAnim(sprites[0], 4); vel_y = -VEL; }
//	//        if ( joy1_active_down  ) { SPR_setAnim(sprites[0], 5); vel_y = +VEL; }
//
//			if ( joy1_active_right ) { pos_x+=vel_nave; }
//			if ( joy1_active_left  ) { pos_x-=vel_nave; }
//			if ( joy1_active_up    ) { pos_y-=vel_nave; }
//			if ( joy1_active_down  ) { pos_y+=vel_nave; }
//
//			if ( joy1_pressed_abc ) break;
//
//			SPR_setPosition(sprites[0], pos_x, pos_y);
//
//
//
//			s16 vel_x = 0;
//			s16 vel_y = 0;
//
//			u16 wait = 1;
//			//if ( inc_scroll++ % 18 == 0 ) wait = 1;
////			if ( inc_scroll %  18 == 0 ) wait = 1;
////			if ( inc_scroll %  5 == 0 ) wait = 1;
//			if ( vtimer % wait == 0 ) { vel_x = -1;  }
//
////			if ( joy1_active_abc )
////			{
////				vel_x  = 0;
////			}
//
//
//
////			drawInt ( scroll.x, 0, 1, 5 );
////			drawInt ( scroll.y, 0, 2, 5 );
////
////			drawInt ( pos_x, 0, 4, 5 );
////			drawInt ( pos_y, 0, 5, 5 );
//
//
//
//
//
//			tile_x = ( ( pos_x + 8 ) - scroll.x ) >> 3 ;
//			tile_x %= planWidth;
//
//			tile_y = ( ( pos_y + 8 ) - scroll.y ) >> 3 ;
//			tile_y %= planHeight;
//
//			u16 tile = VDP_getTile ( PLAN_B, tile_x, tile_y );
//
//			tile = ( tile << 5 );
//			tile = ( tile >> 5 );
//			tile -= 16;
//
//			u8  solid = getMastk1(tile);
//
//			if ( solid )
//			{
//				vel_x = 0;
//			}
//
//
//
//			drawUInt ( nivel_x, 0, 0, 6 );
//
////			drawUInt ( tile, 0, 7, 3 );
////			drawUInt ( solid, 0, 8, 1 );
////
////			drawUInt ( tile_x, 0, 10, 4 );
////			drawUInt ( tile_y, 0, 11, 4 );
//
//
//
//
//
//
//			scrollUpdate ( &scroll, vel_x, vel_y );
//			SPR_update();
//
//			if ( vtimer % 4 == 0 )
//			{
//				++nivel_x;
//			}
//		}
//		waitMs(400);
//
//
//	}
//
//    return 0;
//}








/*
#include <genesis.h>
#include "resources.h"
#include "display.h"



Sprite *coche1;
Sprite *coche2;

static s16 valuesA [ 224 ];
static s16 valuesB [ 224 ];
static u16 vram_pos = 16;



static _voidCallback *vint_callback ( )
{
	VDP_setHorizontalScrollLine ( PLAN_A, 0, valuesA, 224, 0 );
	VDP_setHorizontalScrollLine ( PLAN_B, 0, valuesB, 224, 0 );

	return 0;
}



void drawImageXY ( Image *image, VDPPlan plan, u16 x, u16 y )
{
    u16 pal = ( plan.value == PLAN_A.value ) ? PAL1 : PAL0;

    SYS_disableInts();
    VDP_drawImageEx ( plan, image, TILE_ATTR_FULL ( pal, 0, 0, 0, vram_pos ), x, y, 0, 0 );
    SYS_enableInts();

    preparePal ( pal, image->palette->data );

    vram_pos += image->tileset->numTile;
}



void drawCocheXY ( s16 x, s16 y )
{
	SPR_setPosition ( coche1, x,    y );
	SPR_setPosition ( coche2, x+88, y );
}



int main ( )
{
	VDP_setScrollingMode ( HSCROLL_LINE, VSCROLL_PLANE );


	SPR_init ( 0, 0, 0 );

	s16 coche_x =  75;
	s16 coche_y = 140;

	coche1 = SPR_addSprite ( &coche, coche_x,    coche_y, TILE_ATTR(PAL2, 0, 0,0) );
	coche2 = SPR_addSprite ( &coche, coche_x+88, coche_y, TILE_ATTR(PAL2, 0, 0,0) );

	SPR_setAnim ( coche1, 0 );
	SPR_setAnim ( coche2, 1 );

	drawCocheXY ( coche_x, coche_y );


	preparePal( PAL2, coche.palette->data);


	s16 i;

	fix32 vel_x_a = FIX32(10);
	fix32 vel_x_b = FIX32(.5);

	fix32 fValuesA [ 224 ];
	fix32 fValuesB [ 224 ];

	for ( i=0; i<224; i++)
	{
		valuesA[i] = 0;
		valuesB[i] = 0;

		fValuesA[i] = FIX32(0);
		fValuesB[i] = FIX32(0);
	}

	displayOff(0);

	drawImageXY ( (Image*) &foreground1, PLAN_A, 0, -17 );
	drawImageXY ( (Image*) &background1, PLAN_B, 0, -17 );

	SYS_setVIntCallback ( (_voidCallback*) vint_callback );

	displayOn(0);


	s32 inc_x = 0;
	s32 inc_y = 0;
	const int values_x[20] = { 4, 5, 3, 2, 1, 0, -1, -2, -3, -5, -4, -5, -3, -2, -1, 0, 1, 2, 3, 5 };
	const int values_y[16] = { 3, 2, 1, 0, -1, -2, -3, -4, -3, -2, -1, 0, 1, 2, 3, 4 };

	s16 repeat = 3;
	s16 sumar = 0;

	while(1)
	{
		SPR_update();



		u16 topB = 60;
		s16 j = 0;

		for ( i=0; i<224; i++)
		{
			fValuesA[i] = fix32Add ( fValuesA[i], vel_x_a );
			fValuesB[i] = fix32Add ( fValuesB[i], vel_x_b );

			if ( i > topB )
			{
				fix32 inc_x = fix32Div ( FIX32(j), FIX32(27)) ;
				fValuesB[i] = fix32Add ( fValuesB[i], inc_x );
				j++;
			}

			valuesA[i] = fix32ToRoundedInt ( fValuesA[i] );
			valuesB[i] = fix32ToRoundedInt ( fValuesB[i] );
		}


		if ( repeat )
		{
			--repeat;
		}
		else
		{
			inc_x = values_x [ sumar % 20 ];
			inc_y = values_y [ sumar % 16 ];
			sumar++;

			repeat = 2;
		}


		drawCocheXY ( coche_x+inc_x, coche_y+inc_y );




		VDP_waitVSync();
	}

}
*/
