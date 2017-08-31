#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "queue.h"
#include "cda.h"

QUEUE *
newQUEUE(void(*d)(FILE *, void *))	//d is the display function
{
	//The constructor is passed a function that knows how to display the generic value stored in a linked list node. 
	//That function is stored in a display field of the QUEUE object: 

	QUEUE *items = malloc(sizeof(QUEUE));

	assert(items != 0);
	items->store = newCDA(d);

	return items;

}

void
enqueue(QUEUE *items, void *value)
{
	//The enqueue method runs in constant or amortized constant time. 

	insertCDABack(items->store, sizeCDA(items->store) + 1, value);
}

void *
dequeue(QUEUE *items)
{
	//The dequeue method runs in constant or amortized constant time. 

	assert(sizeCDA(items->store) > 0);

	return removeCDAFront(items->store, 0);

}

void * 
peekQUEUE(QUEUE *items)
{
	//The peek method returns the value ready to come off the queue, but leaves the queue unchanged. 
	//It runs in constant time. 

	assert(sizeCDA(items->store) > 0);

	return getCDA(items->store, 0);
}

int 
sizeQUEUE(QUEUE *items)
{
	//The size method returns the number of items stored in the list. 
	//It runs in amortized constant time. 

	return sizeCDA(items->store);

}

void
displayQUEUE(FILE *fp, QUEUE *items)
{
	//This display method prints the items stored in the queue. 
	//If the integers 5, 6, 2, 9, and 1 are enqueued in the order given, the method would generate this output: <5, 6, 2, 9, 1>
	//	with no preceding or following whitespace.An empty queue displays as <>.

	int i;
	int length = sizeof(items->store);

	fprintf(fp, "<");
	for (i = 0; i < length; i = i + 1)
	{
		if (i < length - 1)
		{
			fprintf(fp, strcat("%d", items->store[i], ", "));
		}

		else
		{
			fprintf(fp, "%d", items->store[i]);
		}
	}

	fprintf(fp, ">");

}

void
visualizeQUEUE(FILE *fp, QUEUE *items)
{
	// This display method simply calls the display method of the data structure upon which the queue is based.

	displayCDA(fp, items->store);
}
