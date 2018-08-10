#ifndef _INC_ROOM_H_
#define _INC_ROOM_H_

#include "../inc/mask.h"
#include "../inc/object.h"

#include "../libs/music.h"


typedef struct _room
{
    Image   *foreground;
    Image   *background;

    Object  *objects;
    Mask    *mask;
    Image   *text;
    Music   *track;

    void (*function) ( struct _room *, u8 ) ;
}
Room;



enum
{
	ROOM_ACTION_ENTER,
	ROOM_ACTION_STAY,
	ROOM_ACTION_LEAVE
};



Room *room_get           ( );
void  room_draw          ( Room *room );
u8    room_objects_count ( Room *room );
void  room_null          ( Room *room, u8 action );
void  room_function      ( Room *room, u8 action );



//void room_funct_10_all    ( Room *room, u8 action );
//void room_funct_20_all    ( Room *room, u8 action );
//void room_funct_30_all    ( Room *room, u8 action );
//void room_funct_40_all    ( Room *room, u8 action );
//
//void room_funct_01_all    ( Room *room, u8 action );
//void room_funct_11_all    ( Room *room, u8 action );
//void room_funct_21_all    ( Room *room, u8 action );
//void room_funct_31_all    ( Room *room, u8 action );
//void room_funct_41_all    ( Room *room, u8 action );
//
//void room_funct_02_all    ( Room *room, u8 action );
//void room_funct_12_all    ( Room *room, u8 action );
//void room_funct_22_all    ( Room *room, u8 action );
//void room_funct_32_all    ( Room *room, u8 action );
//void room_funct_42_all    ( Room *room, u8 action );
//
//void room_funct_03_all    ( Room *room, u8 action );
//void room_funct_13_all    ( Room *room, u8 action );
//void room_funct_23_all    ( Room *room, u8 action );
//void room_funct_33_all    ( Room *room, u8 action );
//void room_funct_43_all    ( Room *room, u8 action );
//
//void room_funct_04_all    ( Room *room, u8 action );
//void room_funct_14_all    ( Room *room, u8 action );
//void room_funct_24_all    ( Room *room, u8 action );
//void room_funct_34_all    ( Room *room, u8 action );
//void room_funct_44_all    ( Room *room, u8 action );
//
//// �apa
//s8   room_44_get_sequence ( );


#endif // _INC_ROOM_H_
