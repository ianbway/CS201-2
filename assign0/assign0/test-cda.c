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

int main()
{
	printf("WE IN MAIN\n");
	CDA *items = newCDA(displayInteger);
	printf("DECLARED ITEMS\n");
	showItems(items);
	printf("WE DID SHOW\n");
	insertCDAFront(items, newInteger(3));                   //insert at front
	printf("WE INSERTED\n");
	printf("DOES THIS EVEN WORK RIGHT\n");
	showItems(items);
	insertCDABack(items, newInteger(1));                   //insert at middle
	printf("INSERT BACK ONE\n");
	insertCDABack(items, newInteger(2));      //insert at back
	showItems(items);
	printf("The value ");
	displayInteger(stdout, removeCDAFront(items));          //remove from front
	printf(" was removed.\n");
	showItems(items);
	int x = getInteger((INTEGER *)getCDA(items, 0));    //get the first item
	printf("The first item is %d.\n", x);
	return 0;
}