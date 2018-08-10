#ifndef _LIBS_VRAM_H_
#define _LIBS_VRAM_H_


void         vram_init    ( unsigned int base );
void         vram_destroy ( );
unsigned int vram_new     ( unsigned int tiles );
void         vram_delete  ( unsigned int pos );
unsigned int vram_count   ( );

void         vram_sample  ( );
void         vram_info    ( );


#endif // _LIBS_VRAM_H_
