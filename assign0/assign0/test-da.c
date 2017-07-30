#include <stdio.h>
#include <stdlib.h>
#include "da.h"
#include "integer.h"

static void showItems(DA *items)
{
	printf("The items are ");
	displayDA(stdout, items);
	printf(".\n");
}

int main(int argc, char **argv)
{
	DA *items = newDA(displayInteger);
	showItems(items);
	insertDA(items, 0, newInteger(3));                   //insert at front
	insertDA(items, sizeDA(items), newInteger(2));      //insert at back
	insertDA(items, 1, newInteger(1));                   //insert at middle
	showItems(items);
	printf("The value ");
	displayInteger(stdout, removeDA(items, 0));          //remove from front
	printf(" was removed.\n");
	showItems(items);
	int x = getInteger((INTEGER *)getDA(items, 0));    //get the first item
	printf("The first item is %d.\n", x);
	return 0;
}