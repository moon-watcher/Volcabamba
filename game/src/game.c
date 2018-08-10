#include <genesis.h>

#include "../libs/vdp.h"
#include "../libs/scroll.h"
#include "../libs/display.h"
#include "../libs/vram.h"
#include "../libs/joyreader.h"
#include "../../libs/listptr.h"

#include "resources.h"
#include "helpers.h"
#include "object.h"
#include "GameObject.h"
#include "game.h"
#include "player.h"


#include "../inc/entities/players.h"

//#include "stage1_e.h"

//#include "enemy_position.h"
//
////#include "../res/mapa.h"


//typedef struct
//{
//	Image *foreground;
//	Image *background;
//	EnemyList *list;
//}
//Room;



Scroll scroll;
u16    currentRoom      = 0;
u16    plan_a_vram_addr = 0;
u16    plan_b_vram_addr = 0;

const Image *stateList[5] = { &stage1, &stage2, &stage3, &stage4, &stage5 };







static _voidCallback *vint_callback ( )
{
	scrollMove ( &scroll );

    return 0;
}



static void screen_init()
{
	const Image *img = stateList [ currentRoom % 5 ];

	scrollInit ( &scroll, PLAN_A, (Image*) img, TILE_ATTR_FULL ( PAL1, 0, 0, 0, 16 ) );

    plan_a_vram_addr = vram_new ( img->tileset->numTile );

	SYS_disableInts();
	VDP_setMapRect ( scroll.plan, scroll.image->map, scroll.attributes, 0, 0, 0, 0, 32+2, 22 );
	VDP_loadTileData ( (u32*)img->tileset->tiles, plan_a_vram_addr, img->tileset->numTile, 0 );
	SYS_enableInts();

	SYS_setVIntCallback ( (_voidCallback*) vint_callback );

    preparePal(PAL1, img->palette->data );
}



//VDP_setPalette ( PAL1, entity01.sd->palette->data );
//VDP_setPalette ( entity01.palette, entity01.sd->palette->data );



//        GameObject *go       =  goManagerAdd ( &waObjects, &currentRoom->objects->array [ i ] );
//		EntityType  entity   =  goGetEntityType ( go );
//		Sprite     *sprite   = &waSprites [ wvSpriteCounter ];
//		u16         itemtype =  goIsItem ( go );
//
//		goSetSprite ( go, sprite );
//		pack_vram_add ( go );
//
//		if ( itemtype )
//		{
//			Item *item = (Item*) itemManagerAdd ( &waItems, i, game.room.x, game.room.y, false, true, 0 );
//
//			goSetItem ( go, item );
//
//			if ( !itemGetVisible ( item ) )
//			{
//				setActive ( go, 0 );
//
//				continue;
//			}
//			else if ( itemGetChecked ( item ) )
//			{
//				Switch *s = (Switch*) switch_find ( game.room.x, game.room.y );
//
//				if ( s != NULL )
//				{
//					goSetObject ( go, &s->on );
//				}
//			}
//
//			if ( itemtype == ENTITY_CHECKPOINT )
//			{
//				checkpoint_draw ( go );
//			}
//
//			else if ( invertedCross  &&  in_array ( itemtype, (u16[]) { ITEM_IS_CROSS, 0 } )  )
//			{
//				invert_cross ( go );
//			}
//		}
//
//		if ( player.in_passage  &&  entity == ENTITY_PASSAGE )
//		{
//			SPR_setHFlip ( player.go->sprite, 1 );
//			goSetXY ( player.go, go->x-10, go->y ) ;//goGetTop(go) + player.go->object->entity->padding.top + 9 );
//			player.in_passage = false;
//		}
//
//		++wvSpriteCounter;






//	VDP_setPalette( PAL1, img->palette->data );
//	VDP_setTextPalette(PAL2);



int game()
{
    int ret = 0;
    currentRoom = 0;

    while(1)
    {
        displayOff(0);

        SPR_init( 80, 0, 0);
        vram_init(0);
        screen_init();
//        JoyReader_reset();

        goManagerInit ( &waObjects );
        player_init();




        displayOn(0);

        s16 vel = -1;

        while(1)
        {
            JoyReader_update();

            s16 vel = -1;

            if (joy1_active_x ) vel = -3;
            if (joy1_active_y ) vel = -5;
            if (joy1_active_z ) vel = -8;

            if (joy1_released_c )
            {
                ++currentRoom;
                break;
            }

            player_update();


            u16 aa;
            aa = 0b10+0b11;
//            drawUInt(aa, 10,3,4);
//            preparePal(PAL0, palette_green );
//            displayOn(0);



            GameObject *go;
			listptrNode *node = waObjects.head;

			while ( node )
			{
				go   = (GameObject *) node->pointer;
                node = node->next;

                //if ( !go->active ) continue;

				goUpdate ( go );
				//go->object->entity->mcbFn ( go );             // map collisions
				//ocb_collisions ( (GameObject*) go, &player ); // objects collisions
				goMoveSprite ( go );
			}


			SPR_update ( );
			scrollUpdate ( &scroll, vel, 0 );
			VDP_waitVSync ( );
        }

        displayOff(10);
        goManagerEnd(&waObjects);
        vram_destroy();
        SPR_clear();
        SPR_end();




        if ( currentRoom == 5 )
        {
            ret = 1;
            break;
        }
    }

	return ret;
}
