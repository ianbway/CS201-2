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
	//printf("WE IN MAIN\n");
	DA *items = newDA(displayInteger);
	//printf("DECLARED ITEMS\n");
	showItems(items);
	//printf("WE DID SHOW\n");
	insertDA(items, newInteger(3));					//insert first
	//printf("WE INSERTED\n");
	insertDA(items, newInteger(2));					//insert second
	insertDA(items, newInteger(1));					//insert third
	showItems(items);
	int size = sizeDA(items);
	printf("The array is %d long.\n", size);
	setDA(items, 3, newInteger(4));

	//setDA(items, 6, newInteger(4));

	printf("The value ");
	displayInteger(stdout, removeDA(items));          //remove
	printf(" was removed.\n");
	showItems(items);
	int x = getInteger((INTEGER *)getDA(items, 0));    //get the first item
	printf("The first item is %d.\n", x);
	return 0;
}