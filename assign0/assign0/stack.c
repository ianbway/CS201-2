#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include"stack.h"
#include"da.h"

typedef struct stack
{
	DA *stackItems;
	void(*display) (FILE *, void *);

} STACK;

/****** public methods ******/

STACK *
newSTACK(void(*d)(FILE *, void *))	//d is the display function
{
	//The constructor is passed a function that knows how to display the generic value stored in a linked list node. 
	//That function is stored in a display field of the STACK object: 

	STACK *items = malloc(sizeof(STACK));

	assert(items != 0);
	items->stackItems = newDA(d);
	items->display = d;
	
	return items;
}

void
push(STACK *items, void *value)
{
	//The push method runs in constant or amortized constant time. 

	insertDA(items->stackItems, value);

}

void *
pop(STACK *items)
{
	//The pop method runs in constant or amortized constant time. 

	assert(sizeDA(items->stackItems) > 0);

	return removeDA(items->stackItems);

}

void *
peekSTACK(STACK *items)
{
	//The peek method returns the value ready to come off the stack, but leaves the stack unchanged.
	//It runs in constant time.
	assert(sizeDA(items->stackItems) > 0);

	return getDA(items->stackItems, sizeDA(items->stackItems) - 1);

}

int 
sizeSTACK(STACK *items)
{
	//The size method returns the number of items stored in the list. 
	//It runs in amortized constant time. 

	return sizeDA(items->stackItems);

}

void
displaySTACK(FILE *fp, STACK *items)
{
	//The display method prints the items stored in the stack. If the integers 5, 6, 2, 9, and 1 are pushed in the order given, the method would generate this output:
	// | 5, 6, 2, 9, 1 |
	// with no preceding or following whitespace.An empty stack displays as || .

	int i;
	int size = sizeDA(items->stackItems);

	fprintf(fp, "|");
	for (i = 0; i < size; i = i + 1)
	{
		items->display(fp, getDA(items->stackItems,i));
		if (size > 1 && i != size-1)
		{
			fprintf(fp, ",");
		}

	}

	fprintf(fp, "|");

}

void
visualizeSTACK(FILE *fp, STACK *items)
{
	//The visualize method simply calls the display method of the data structure upon which the stack is based.

	displayDA(fp, items->stackItems);

}
