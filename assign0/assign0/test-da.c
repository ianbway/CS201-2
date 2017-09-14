// Ian Braudaway
// Tester file for da class
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

int main()
{
	DA *items = newDA(displayINTEGER);

	DA *longerItems = newDA(displayINTEGER);
	showItems(longerItems);
	insertDA(longerItems, newINTEGER(1));					//insert first
	insertDA(longerItems, newINTEGER(2));					//insert second
	insertDA(longerItems, newINTEGER(3));					//insert third
	insertDA(longerItems, newINTEGER(4));					//insert fourth
	insertDA(longerItems, newINTEGER(5));					//insert fifth
	insertDA(longerItems, newINTEGER(6));					//insert sixth
	insertDA(longerItems, newINTEGER(7));					//insert seventh
	insertDA(longerItems, newINTEGER(8));					//insert eighth
	insertDA(longerItems, newINTEGER(9));					//insert ninth
	showItems(longerItems);
	removeDA(longerItems);
	visualizeDA(stdout, longerItems);
	printf(".\n");
	removeDA(longerItems);
	visualizeDA(stdout, longerItems);
	printf(".\n");
	removeDA(longerItems);
	visualizeDA(stdout, longerItems);
	printf(".\n");
	removeDA(longerItems);
	visualizeDA(stdout, longerItems);
	printf(".\n");
	removeDA(longerItems);
	visualizeDA(stdout, longerItems);
	printf(".\n");
	removeDA(longerItems);
	visualizeDA(stdout, longerItems);
	printf(".\n");
	removeDA(longerItems);
	visualizeDA(stdout, longerItems);
	printf(".\n");
	removeDA(longerItems);
	showItems(longerItems);
	removeDA(longerItems);
	showItems(longerItems);
	insertDA(longerItems, newINTEGER(5));
	showItems(longerItems);
	removeDA(longerItems);
	showItems(longerItems);

	//**********************************//
	//showItems(items);								//seeing if shrinking works
	//insertDA(items, newINTEGER(3));					//insert first
	//insertDA(items, newINTEGER(2));					//insert second
	//insertDA(items, newINTEGER(1));					//insert third
	//showItems(items);
	//int size = sizeDA(items);
	//printf("The array is %d long.\n", size);
	//setDA(items, 2, newINTEGER(4));
	//showItems(items);
	//setDA(items, 3, newINTEGER(5));
	//showItems(items);
	//printf("The value ");
	//displayINTEGER(stdout, removeDA(items));          //remove
	//printf(" was removed.\n");
	//showItems(items);
	//int x = getINTEGER((INTEGER *)getDA(items, 0));    //get the first item
	//printf("The first item is %d.\n", x);
	//DA *donor = newDA(displayINTEGER);
	//insertDA(donor, newINTEGER(4));
	//insertDA(donor, newINTEGER(5));
	//insertDA(donor, newINTEGER(6));
	//showItems(donor);
	//DA *recipient = newDA(displayINTEGER);
	//insertDA(recipient, newINTEGER(1));
	//insertDA(recipient, newINTEGER(2));
	//insertDA(recipient, newINTEGER(3));
	//showItems(recipient);
	//unionDA(recipient, donor);
	//showItems(recipient);
	//int y = getINTEGER((INTEGER *)getDA(recipient, 0));    //get the first item
	//printf("The first item is %d.\n", y);
	//extractDA(recipient);
	//showItems(recipient);
	return 0;
}
