// Ian Braudaway
// Tester file for stack class
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

int main()
{
	STACK *items = newSTACK(displayINTEGER);
	showItems(items);
	push(items, newINTEGER(5));
	push(items, newINTEGER(4));
	push(items, newINTEGER(3));                   //insert at front
	push(items, newINTEGER(2));      //insert at back
	push(items, newINTEGER(1));                   //insert at middle
	showItems(items);
	printf("The value ");
	displayINTEGER(stdout, pop(items));          //remove from front
	printf(" was removed.\n");
	showItems(items);
	int x = getINTEGER((INTEGER *)peekSTACK(items));    //get the first item
	printf("The first item is %d.\n", x);
	int size = sizeSTACK(items);
	printf("The stack is %d long. \n", size);
	return 0;
}
