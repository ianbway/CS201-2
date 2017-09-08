// Ian Braudaway
// Tester file for queue class
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "integer.h"

static void showItems(QUEUE *items)
{
	printf("The items are ");
	displayQUEUE(stdout, items);
	printf(".\n");
	printf("The items with visualize are ");
	visualizeQUEUE(stdout, items);
	printf(".\n");
}

int main()
{
	QUEUE *items = newQUEUE(displayInteger);
	showItems(items);
	enqueue(items, newInteger(3));                   //insert at front
	enqueue(items, newInteger(2));      //insert at back
	enqueue(items, newInteger(1));                   //insert at middle
	showItems(items);
	printf("The value ");
	displayInteger(stdout, dequeue(items));          //remove from front
	printf(" was removed.\n");
	showItems(items);
	int x = getInteger((INTEGER *)peekQUEUE(items));    //get the first item
	printf("The first item is %d.\n", x);
	int size = sizeQUEUE(items);
	printf("The queue is %d long. \n", size);
	return 0;
}