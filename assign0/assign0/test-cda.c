#include <stdio.h>
#include <stdlib.h>
#include "cda.h"
#include "integer.h"

static void showItems(CDA *items)
{
	printf("The items are ");
	displayCDA(stdout, items);
	printf(".\n");
}

int main(int argc, char **argv)
{
	CDA *items = newCDA(displayInteger);
	showItems(items);
	insertCDA(items, 0, newInteger(3));                   //insert at front
	insertCDA(items, sizeCDA(items), newInteger(2));      //insert at back
	insertCDA(items, 1, newInteger(1));                   //insert at middle
	showItems(items);
	printf("The value ");
	displayInteger(stdout, removeCDA(items, 0));          //remove from front
	printf(" was removed.\n");
	showItems(items);
	int x = getInteger((INTEGER *)getCDA(items, 0));    //get the first item
	printf("The first item is %d.\n", x);
	return 0;
}