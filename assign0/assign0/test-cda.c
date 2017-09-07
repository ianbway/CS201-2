// Ian Braudaway
// Tester file for cda class
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
	insertCDAback(items, newInteger(2));                   //insert at back
	insertCDAfront(items, newInteger(1));                   //insert at front
	insertCDAback(items, newInteger(3));      //insert at back
	showItems(items);
	printf("The value ");
	displayInteger(stdout, removeCDAfront(items));          //remove from front
	printf(" was removed.\n");
	showItems(items);
	int x = getInteger((INTEGER *)getCDA(items, 0));    //get the first item
	printf("The first item is %d.\n", x);
	setCDA(items, 0, newInteger(25));
	showItems(items);

	int size = sizeCDA(items);
	printf("The array is %d long.\n", size);

	CDA *donor = newCDA(displayInteger);
	showItems(donor);
	insertCDAfront(donor, newInteger(1));                   //insert at front
	insertCDAfront(donor, newInteger(2));                   //insert at front
	insertCDAback(donor, newInteger(3));                   //insert at back
	insertCDAfront(donor, newInteger(4));                   //insert at front
	removeCDAfront(donor);
	removeCDAfront(donor);
	removeCDAback(donor);
	removeCDAback(donor);
	showItems(donor);
	insertCDAfront(donor, newInteger(5));                   //insert at front
	insertCDAfront(donor, newInteger(6));                   //insert at front
	insertCDAback(donor, newInteger(3));                   //insert at back
	insertCDAfront(donor, newInteger(6));                   //insert at front
	showItems(donor);
	removeCDAfront(donor);
	showItems(donor);

	CDA *recipient = newCDA(displayInteger);
	showItems(recipient);
	insertCDAback(recipient, newInteger(80));                   //insert at back
	insertCDAback(recipient, newInteger(90));                   //insert at back
	insertCDAback(recipient, newInteger(100));                   //insert at back
	showItems(recipient);
	unionCDA(recipient, donor);
	showItems(recipient);
	extractCDA(recipient);
	showItems(recipient);

	return 0;
}
