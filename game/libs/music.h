#ifndef _LIBS_MUSIC_H_
#define _LIBS_MUSIC_H_

#include <genesis.h>

typedef struct
{
	u8    id;
	char *title;
	u8   *track;
    //u8    driver;
	s8    loop;
}
Music;


void musicInit   ( );
void musicPlay   ( Music *track );
void musicStop   ( );
void musicPause  ( );
void musicResume ( );


#endif // _LIBS_MUSIC_H_
