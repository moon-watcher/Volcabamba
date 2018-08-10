#include <genesis.h>      // for SGDK compatibility
#define malloc  MEM_alloc // for SGDK compatibility
#define free    MEM_free  // for SGDK compatibility


void *realloc ( void *ptr, unsigned int size )
{
	if ( !ptr )
	{
		return malloc ( size );
	}

	void *newptr = malloc ( size );

	if ( !newptr )
	{
		return NULL;
	}

	memcpy ( newptr, ptr, size );
	free ( ptr );

	return newptr;
}
