#ifndef _INC_GAME_H_
#define _INC_GAME_H_

#include <genesis.h>

#include "../../libs/listptr.h"



#define MAX_SPRITE 79


Sprite   waSprites [ MAX_SPRITE ] ;
u8       wvSpriteCounter;

listptr  waObjects;
listptr  waItems;


int game();


#endif // _INC_GAME_H_
