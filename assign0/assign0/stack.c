#include stack.h
#include da.h

STACK *
newSTACK(void(*d)(FILE *, void *))	//d is the display function
{
	STACK *items = malloc(sizeof(STACK));

	assert(items > 0);

	items->size = 0;
	items->display = d;
	return items;

}

void
push(STACK *items, void *value)
{


}

void *
pop(STACK *items)
{
	assert(items->size > 0);

}

int
peekSTACK(STACK *items)
{
	assert(items->size > 0);

}

int 
sizeSTACK(STACK *items)
{


}

void
displaySTACK(FILE *, STACK *items)
{


}

void
displaySTACKds(FILE *, STACK *items)
{


}