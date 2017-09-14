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
	CDA *items = newCDA(displayINTEGER);
	showItems(items);
	insertCDAback(items, newINTEGER(2));
	insertCDAfront(items, newINTEGER(1));
	insertCDAback(items, newINTEGER(3));
	insertCDAback(items, newINTEGER(4));
	insertCDAback(items, newINTEGER(5));
	insertCDAback(items, newINTEGER(6));
	insertCDAback(items, newINTEGER(7));
	insertCDAback(items, newINTEGER(8));
	insertCDAback(items, newINTEGER(9));
	visualizeCDA(stdout, items);
	printf("\n");
	removeCDAfront(items);
	visualizeCDA(stdout, items);
	printf("\n");
	removeCDAback(items);
	visualizeCDA(stdout, items);
	printf("\n");
	removeCDAfront(items);
	visualizeCDA(stdout, items);
	printf("\n");
	removeCDAback(items);
	visualizeCDA(stdout, items);
	printf("\n");
	removeCDAback(items);
	visualizeCDA(stdout, items);
	printf("\n");
	removeCDAback(items);
	visualizeCDA(stdout, items);
	printf("\n");
	removeCDAback(items);
	visualizeCDA(stdout, items);
	printf("\n");
	removeCDAback(items);
	visualizeCDA(stdout, items);
	printf("\n");
	removeCDAback(items);
	visualizeCDA(stdout, items);
	printf("\n");
	insertCDAback(items, newINTEGER(2));
	visualizeCDA(stdout, items);
	printf("\n");
	removeCDAback(items);
	visualizeCDA(stdout, items);
	printf("\n");

	insertCDAback(items, newINTEGER(2));
	//insertCDAback(items, newINTEGER(2));                   //insert at back
	//insertCDAfront(items, newINTEGER(1));                   //insert at front
	//insertCDAback(items, newINTEGER(3));      //insert at back
	//showItems(items);
	//printf("The value ");
	//displayINTEGER(stdout, removeCDAfront(items));          //remove from front
	//printf(" was removed.\n");
	//showItems(items);
	int x = getINTEGER((INTEGER *)getCDA(items, 0));    //get the first item
	printf("The first item is %d.\n", x);
	setCDA(items, 0, newINTEGER(25));
	showItems(items);

	int size = sizeCDA(items);
	printf("The array is %d long.\n", size);

	CDA *donor = newCDA(displayINTEGER);
	showItems(donor);
	insertCDAfront(donor, newINTEGER(1));                   //insert at front
	insertCDAfront(donor, newINTEGER(2));                   //insert at front
	insertCDAback(donor, newINTEGER(3));                   //insert at back
	insertCDAfront(donor, newINTEGER(4));                   //insert at front
	removeCDAfront(donor);
	removeCDAfront(donor);
	removeCDAback(donor);
	removeCDAback(donor);
	showItems(donor);
	insertCDAfront(donor, newINTEGER(5));                   //insert at front
	insertCDAfront(donor, newINTEGER(6));                   //insert at front
	insertCDAback(donor, newINTEGER(3));                   //insert at back
	insertCDAfront(donor, newINTEGER(6));                   //insert at front
	showItems(donor);
	removeCDAfront(donor);
	showItems(donor);

	CDA *recipient = newCDA(displayINTEGER);
	showItems(recipient);
	insertCDAback(recipient, newINTEGER(80));                   //insert at back
	insertCDAback(recipient, newINTEGER(90));                   //insert at back
	insertCDAback(recipient, newINTEGER(100));                   //insert at back
	showItems(recipient);
	unionCDA(recipient, donor);
	showItems(recipient);
	extractCDA(recipient);
	showItems(recipient);

	return 0;
}
