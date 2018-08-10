#include <genesis.h>

#include "../inc/entity.h"
#include "../../res/resources.h"

const Entity entityPlayer1 = {  1, "Player 1",              0, (SpriteDefinition*) &nave1, PAL2, ENTITY_PLAYER, FIX32(1.50), FIX32(1.50), 0, 0, 0, 0, /*NULL, mcb_player, 0,*/ {  3,  3,  3,  3 } };
const Entity entityPlayer2 = {  1, "Player 2",              0, (SpriteDefinition*) &nave1, PAL2, ENTITY_PLAYER, FIX32(1.50), FIX32(1.50), 0, 0, 0, 0, /*NULL, mcb_player, 0,*/ {  3,  3,  3,  3 } };
