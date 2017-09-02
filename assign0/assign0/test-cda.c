#include <stdio.h>
#include <stdlib.h>
#include "cda.h"
#include "integer.h"

static void showItems(CDA *items)
{
	printf("The items are ");
	displayCDA(stdout, items);
	printf(".\n");
	printf("Items with space left are ");
	visualizeCDA(stdout, items);
	printf(".\n");
}

int main()
{
	CDA *items = newCDA(displayInteger);
	showItems(items);
	insertCDABack(items, newInteger(2));                   //insert at back
	showItems(items);
	insertCDAFront(items, newInteger(1));                   //insert at front
	showItems(items);
	insertCDABack(items, newInteger(3));      //insert at back
	showItems(items);
	printf("The value ");
	displayInteger(stdout, removeCDAFront(items));          //remove from front
	printf(" was removed.\n");
	showItems(items);
	int x = getInteger((INTEGER *)getCDA(items, 0));    //get the first item
	printf("The first item is %d.\n", x);
	return 0;
}