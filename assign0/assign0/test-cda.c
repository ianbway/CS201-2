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
	//CDA *items = newCDA(displayInteger);
	//showItems(items);
	//insertCDABack(items, newInteger(2));                   //insert at back
	//showItems(items);
	//insertCDAFront(items, newInteger(1));                   //insert at front
	//showItems(items);
	//insertCDABack(items, newInteger(3));      //insert at back
	//showItems(items);
	//insertCDABack(items, newInteger(4));
	//insertCDABack(items, newInteger(5));
	//showItems(items);
	//insertCDAFront(items, newInteger(0));                   //insert at front
	//showItems(items);
	//printf("The value ");
	//displayInteger(stdout, removeCDAFront(items));          //remove from front
	//printf(" was removed.\n");
	//showItems(items);
	//int x = getInteger((INTEGER *)getCDA(items, 0));    //get the first item
	//printf("The first item is %d.\n", x);
	//setCDA(items, 0, newInteger(25));
	//showItems(items);

	//int size = sizeCDA(items);
	//printf("The array is %d long.\n", size);

	//extractCDA(items);
	//showItems(items);

	CDA *donor = newCDA(displayInteger);
	showItems(donor);
	insertCDAFront(donor, newInteger(1));                   //insert at front
	insertCDAFront(donor, newInteger(2));                   //insert at front
	insertCDABack(donor, newInteger(3));                   //insert at back
	insertCDAFront(donor, newInteger(4));                   //insert at front
	removeCDAFront(donor);
	removeCDAFront(donor);
	removeCDABack(donor);
	removeCDABack(donor);
	showItems(donor);
	insertCDAFront(donor, newInteger(5));                   //insert at front
	insertCDAFront(donor, newInteger(6));                   //insert at front
	insertCDABack(donor, newInteger(3));                   //insert at back
	insertCDAFront(donor, newInteger(6));                   //insert at front
	showItems(donor);
	removeCDAFront(donor);
	showItems(donor);

	CDA *recipient = newCDA(displayInteger);
	showItems(recipient);
	insertCDABack(recipient, newInteger(80));                   //insert at back
	insertCDABack(recipient, newInteger(90));                   //insert at back
	insertCDABack(recipient, newInteger(100));                   //insert at back
	showItems(recipient);
	unionCDA(recipient, donor);
	showItems(recipient);
	extractCDA(recipient);
	showItems(recipient);

	return 0;
}
