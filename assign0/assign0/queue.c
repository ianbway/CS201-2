#include queue.h
#include cda.h

QUEUE *
newQUEUE(void(*d)(FILE *, void *))	//d is the display function
{
	QUEUE *items = malloc(sizeof(QUEUE));

	assert(items > 0);

	items->size = 0;
	items->display = d;
	return items;

}

void
enqueue(QUEUE *items, void *value)
{


}

void *
dequeue(QUEUE *items)
{
	assert(items->size > 0);

}

int 
peekQUEUE(QUEUE *items)
{
	assert(items->size > 0);

}

int 
sizeQUEUE(QUEUE *items)
{


}

void
displayQUEUE(FILE *, QUEUE *items)
{


}

void
displayQUEUEds(FILE *, QUEUE *items)
{


}