#include <genesis.h>

#include "player.h"
#include "game.h"
#include "GameObject.h"

#include "../libs/display.h"
#include "../libs/joyreader.h"

#include "data/entities.h"



void player_init( )
{
    Object  o1;
    Sprite *s1;

    o1.entity = (Entity*) &entity01;

    goPlayer1 = goManagerAdd ( &waObjects, &o1 );
    s1 = &waSprites [ wvSpriteCounter ];
    goSetSprite ( goPlayer1, s1 );
    ++wvSpriteCounter;

    preparePal ( o1.entity->palette, o1.entity->sd->palette->data );
}


void player_update ( )
{
    if ( joy1_changed_horizontal ) goPlayer1->vel_x = zero;
    if ( joy1_changed_vertical   ) goPlayer1->vel_y = zero;

    if ( joy1_pressed_right ) goPlayer1->vel_x = +goPlayer1->object->entity->vel_x;
    if ( joy1_pressed_left  ) goPlayer1->vel_x = -goPlayer1->object->entity->vel_x;
    if ( joy1_pressed_down  ) goPlayer1->vel_y = +goPlayer1->object->entity->vel_y;
    if ( joy1_pressed_up    ) goPlayer1->vel_y = -goPlayer1->object->entity->vel_y;


    if ( joy2_changed_horizontal ) goPlayer2->vel_x = zero;
    if ( joy2_changed_vertical   ) goPlayer2->vel_y = zero;

    if ( joy2_pressed_right ) goPlayer2->vel_x = +goPlayer2->object->entity->vel_x;
    if ( joy2_pressed_left  ) goPlayer2->vel_x = -goPlayer2->object->entity->vel_x;
    if ( joy2_pressed_down  ) goPlayer2->vel_y = +goPlayer2->object->entity->vel_y;
    if ( joy2_pressed_up    ) goPlayer2->vel_y = -goPlayer2->object->entity->vel_y;

}
