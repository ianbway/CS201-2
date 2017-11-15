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
	GT *tree = newGT(displayINTEGER, compareINTEGER);

	printf("An empty tree...\n");
	printf("The tree looks like this:\n");
	displayGT(stdout, tree);
	printf("\n");

	INTEGER *one = newINTEGER(1);
	INTEGER *two = newINTEGER(2);
	INTEGER *three = newINTEGER(3);
	INTEGER *four = newINTEGER(4);
	INTEGER *five = newINTEGER(5);
	INTEGER *six = newINTEGER(6);
	INTEGER *seven = newINTEGER(7);
	INTEGER *eight = newINTEGER(8);
	INTEGER *nine = newINTEGER(9);
	INTEGER *ten = newINTEGER(10);
	INTEGER *eleven = newINTEGER(11);
	INTEGER *twelve = newINTEGER(12);
	INTEGER *thirteen = newINTEGER(13);
	INTEGER *fourteen = newINTEGER(14);
	INTEGER *fifteen = newINTEGER(15);

	printf("Inserting values, including duplicates...\n");
	insertGT(tree, seven);
	insertGT(tree, three);
	insertGT(tree, two);
	insertGT(tree, one);
	insertGT(tree, four);
	insertGT(tree, five);
	insertGT(tree, fifteen);
	insertGT(tree, eight);
	insertGT(tree, nine);
	insertGT(tree, five);
	insertGT(tree, ten);
	insertGT(tree, six);
	insertGT(tree, eleven);
	insertGT(tree, twelve);
	insertGT(tree, thirteen);
	insertGT(tree, five);
	insertGT(tree, five);
	insertGT(tree, fourteen);
	insertGT(tree, three);
	insertGT(tree, four);
	insertGT(tree, two);
	insertGT(tree, three);
	insertGT(tree, three);
	insertGT(tree, three);

	printf("The tree looks like this:\n");
	displayGT(stdout, tree);
	printf("\n");

	int twoCount = findGT(tree, two);
	printf("There are %d twos in the tree.\n", twoCount);

	int threeCount = findGT(tree, three);
	printf("There are %d threes in the tree.\n", threeCount);

	int fiveCount = findGT(tree, five);
	printf("There are %d fives in the tree.\n", fiveCount);

	printf("The tree looks like this:\n");
	displayGT(stdout, tree);
	printf("\n");

	printf("Deleting values, including duplicates...\n");
	deleteGT(tree, five);
	deleteGT(tree, two);
	deleteGT(tree, nine);
	deleteGT(tree, fifteen);
	deleteGT(tree, six);
	deleteGT(tree, one);
	deleteGT(tree, three);
	deleteGT(tree, four);
	deleteGT(tree, seven);
	deleteGT(tree, eight);
	deleteGT(tree, ten);
	deleteGT(tree, eleven);
	deleteGT(tree, twelve);
	deleteGT(tree, thirteen);
	deleteGT(tree, fourteen);
	deleteGT(tree, three);
	deleteGT(tree, three);
	deleteGT(tree, three);
	deleteGT(tree, three);

	printf("The tree looks like this:\n");
	displayGT(stdout, tree);
	printf("\n");

	printf("Printing statistics...\n");
	statisticsGT(stdout, tree);

	printf("Printing size...\n");
	printf("%d\n", sizeGT(tree));

	return 0;
}