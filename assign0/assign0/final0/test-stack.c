#include <stdio.h>
#include <stdlib.h>
#include "da.h"
#include "stack.h"
#include "integer.h"

static void showItems(STACK *items)
{
	printf("The items are ");
	displaySTACK(stdout, items);
	printf(".\n");
	printf("The items with visualize are ");
	visualizeSTACK(stdout, items);
	printf(".\n");
}

//int argc, char **argv
int main()
{
	STACK *items = newSTACK(displayInteger);
	showItems(items);
	push(items, newInteger(5));
	push(items, newInteger(4));
	push(items, newInteger(3));                   //insert at front
	push(items, newInteger(2));      //insert at back
	push(items, newInteger(1));                   //insert at middle
	showItems(items);
	printf("The value ");
	displayInteger(stdout, pop(items));          //remove from front
	printf(" was removed.\n");
	showItems(items);
	int x = getInteger((INTEGER *)peekSTACK(items));    //get the first item
	printf("The first item is %d.\n", x);
	int size = sizeSTACK(items);
	printf("The stack is %d long. \n", size);
	return 0;
}
