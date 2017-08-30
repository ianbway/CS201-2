#include <stdio.h>
#include <stdlib.h>
#include "da.h"
#include "integer.h"

static void showItems(DA *items)
{
	printf("The items are ");
	displayDA(stdout, items);
	printf(".\n");
	printf("Items with space left are ");
	visualizeDA(stdout, items);
	printf(".\n");
}
//int argc, char **argv
int main()
{
	DA *items = newDA(displayInteger);
	showItems(items);
	insertDA(items, newInteger(3));					//insert first
	insertDA(items, newInteger(2));					//insert second
	insertDA(items, newInteger(1));					//insert third
	showItems(items);
	int size = sizeDA(items);
	printf("The array is %d long.\n", size);
	setDA(items, 2, newInteger(4));
	showItems(items);
	setDA(items, 3, newInteger(5));
	showItems(items);
	printf("The value ");
	displayInteger(stdout, removeDA(items));          //remove
	printf(" was removed.\n");
	showItems(items);
	int x = getInteger((INTEGER *)getDA(items, 0));    //get the first item
	printf("The first item is %d.\n", x);
	DA *donor = newDA(displayInteger);
	insertDA(donor, newInteger(4));
	insertDA(donor, newInteger(5));
	insertDA(donor, newInteger(6));
	showItems(donor);
	DA *recipient = newDA(displayInteger);
	insertDA(recipient, newInteger(1));
	insertDA(recipient, newInteger(2));
	insertDA(recipient, newInteger(3));
	showItems(recipient);
	unionDA(recipient, donor);
	showItems(recipient);
	int y = getInteger((INTEGER *)getDA(recipient, 0));    //get the first item
	printf("The first item is %d.\n", y);
	extractDA(recipient);
	showItems(recipient);
	return 0;
}
