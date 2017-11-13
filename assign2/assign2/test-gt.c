//Ian Braudaway
//Tester file for gt class
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "gt.h"
#include "string.h"
#include "real.h"
#include "integer.h"

int main()
{
	GT *tree = newGT(displaySTRING, compareSTRING);

	printf("An empty tree...\n");
	printf("The tree looks like this:\n");
	displayGT(stdout, tree);
	printf("\n");

	//INTEGER *one = newINTEGER(1);
	INTEGER *two = newINTEGER(2);
	INTEGER *three = newINTEGER(3);
	INTEGER *four = newINTEGER(4);
	/*INTEGER *five = newINTEGER(5);
	INTEGER *six = newINTEGER(6);
	INTEGER *seven = newINTEGER(7);
	INTEGER *eight = newINTEGER(8);
	INTEGER *nine = newINTEGER(9);
	INTEGER *ten = newINTEGER(10);
	INTEGER *eleven = newINTEGER(11);
	INTEGER *twelve = newINTEGER(12);
	INTEGER *thirteen = newINTEGER(13);
	INTEGER *fourteen = newINTEGER(14);
	INTEGER *fifteen = newINTEGER(15);*/

	printf("Inserting values, including duplicates...\n");
	insertGT(tree, three);
	insertGT(tree, four);
	insertGT(tree, two);
	insertGT(tree, three);
	insertGT(tree, three);
	insertGT(tree, three);

	printf("The tree looks like this:\n");
	displayGT(stdout, tree);
	printf("\n");

	return 0;
}