#ifndef _INC_PLAYER_H_
#define _INC_PLAYER_H_

#include <genesis.h>

#include "player.h"
#include "GameObject.h"

#include "../inc/data/entities.h"


//Object      obPlayer1,  obPlayer2;
//Sprite     *spPlayer1, *spPlayer2;

GameObject *goPlayer1;
GameObject *goPlayer2;


void player_init   ( );
void player_update ( );


#endif // _INC_PLAYER_H_
