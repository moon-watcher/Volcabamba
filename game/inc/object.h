#ifndef _INC_OBJECT_H_
#define _INC_OBJECT_H_


#include "entity.h"


typedef struct
{
	Entity *entity;

	s16     x;
	s16     y;

	s8      dir_x;
	s8      dir_y;

	fix32   vel_x;
	fix32   vel_y;

	u8      flipH;
	u8      flipV;
}
Object;



Object *objectCreate           ( );
void    objectDelete           ( Object *object );

//u16     objectIsItem           ( Object *object );
//u16     objectIsDoor           ( Object *object );
//u16     objectIsItemRemovable  ( Object *object );
//
//s8      objectGetPaddingTop    ( Object *object );
//s8      objectGetPaddingLeft   ( Object *object );
//s8      objectGetPaddingRight  ( Object *object );
//s8      objectGetPaddingBottom ( Object *object );
//
//u8      objectGetWidth         ( Object *object );
//u8      objectGetHeight        ( Object *object );



#define objectGetPaddingTop(x)    (x)->entity->padding.top
#define objectGetPaddingLeft(x)   (x)->entity->padding.left
#define objectGetPaddingRight(x)  (x)->entity->padding.right
#define objectGetPaddingBottom(x) (x)->entity->padding.bottom
#define objectGetWidth(x)         (x)->entity->sd->animations[0]->frames[0]->w
#define objectGetHeight(x)        (x)->entity->sd->animations[0]->frames[0]->h


#endif // _INC_OBJECT_H_
