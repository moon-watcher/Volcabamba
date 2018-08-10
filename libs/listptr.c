#include <genesis.h>      // for SGDK compatibility
#define malloc  MEM_alloc // for SGDK compatibility
#define free    MEM_free  // for SGDK compatibility


#include "listptr.h"


void listptr_new ( listptr *list, listptrFunction freeFn )
{
	list->length = 0;
	list->head   = ((void*)0);
	list->freeFn = freeFn;
}


void listptr_destroy ( listptr *list )
{
	listptrNode *node;

	while ( list->head )
	{
		node = list->head;
		list->head = node->next;

		listptr_remove ( list, node );
	}
}


listptrNode *listptr_append ( listptr *list, void *element )
{
	listptrNode *node = (listptrNode *) malloc ( sizeof ( listptrNode ) );

	node->pointer    = element;
	node->prev       = ((void*) 0);
	node->next       = list->head;

	list->head       = node;
	list->head->prev = node;

	++list->length;

	return node;
}


void listptr_foreach ( listptr *list, listptrFunction iterator )
{
	listptrNode *node = list->head;

	while ( node )
	{
		iterator ( node->pointer );
		node = node->next;
	}
}


int listptr_size ( listptr *list )
{
	return list->length;
}


void listptr_remove ( listptr *list, listptrNode *node )
{
	if ( list->freeFn )
	{
		list->freeFn ( node->pointer );
	}

	if ( node->prev )
	{
		node->prev->next = node->next;
	}
	else
	{
		list->head = node->next;
	}

	if ( node->next )
	{
		node->next->prev = node->prev;
	}

	list->length--;

	free ( node );
}
