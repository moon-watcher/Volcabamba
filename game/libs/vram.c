#include <genesis.h>      // for SGDK compatibility
#define malloc  MEM_alloc // for SGDK compatibility
#define free    MEM_free  // for SGDK compatibility


struct vram
{
	unsigned int  pos;
	unsigned int  tiles;
	struct vram  *next;
};


static struct vram  *_list  = NULL;
static unsigned int  _base  = 0;
static unsigned int  _count = 0;


//////////////////////////////////////////////////////////////////////////////////////////////////////


void vram_init ( unsigned int base )
{
	_list  = NULL;
	_base  = base ? base : 16;
	_count = 0;
}


void vram_destroy ( )
{
	while ( _list )
	{
		struct vram *aux = _list->next;

		free ( _list );
		_list = aux;
	}

	_list  = NULL;
	_base  = 0;
	_count = 0;
}


unsigned int vram_new ( unsigned int tiles )
{
	unsigned int  pos  = _base;
	struct vram  *node = _list;
	struct vram  *new  = malloc ( sizeof ( struct vram ) );
	struct vram  *next = NULL;

	if ( node )
	{
		while ( node )
		{
			pos  = node->pos + node->tiles;
			next = node->next;

			if ( next == NULL || next->pos >= pos + tiles )
			{
				break;
			}

			node = next;
		}

		node->next = new;
	}
	else
	{
		_list = new;
	}

	new->pos   = pos;
	new->tiles = tiles;
	new->next  = next;

	++_count;

	return pos;
}


void vram_delete ( unsigned int pos )
{
	struct vram *node = _list;
	struct vram *prev = NULL;

	while ( node )
	{
		if ( node->pos == pos )
		{
			prev->next = node->next;
			free ( node );

			if ( --_count == 0 )
			{
				_list = NULL;
			}

			return;
		}

		prev = node;
		node = node->next;
	}
}


unsigned int vram_count ( )
{
	return _count;
}


void vram_info ()
{
	struct vram *aux = _list;

	char i = 3;
	char str[10];

	VDP_drawText ( " Nb   Pos   Tiles ", 1, 0 );
	VDP_drawText ( "---- ----- -------", 1, 1 );

	while ( aux )
	{
		uintToStr(i-2, str, 1);
		VDP_drawText(str, 2, i);

		uintToStr(aux->pos, str, 1);
		VDP_drawText(str, 7, i);

		uintToStr(aux->tiles, str, 1);
		VDP_drawText(str, 13, i);

		aux = aux->next;
		i++;
	}
}


void vram_sample ( void )
{
	vram_init(0);

	vram_new(9);
	s16 x = vram_new(3);
	vram_new(927);
	vram_delete ( x );
	vram_new(2);
	unsigned int y = vram_new(5);
	vram_new(1);
	vram_new(8);
	vram_delete ( y );
	vram_new(3);
	vram_new(2);
	vram_new(1);
	vram_new(3);

	vram_info();
}
