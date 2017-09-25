//Ian Braudaway
//Tester file for bst class
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "string.h"
#include "real.h"
#include "integer.h"
#include "comparator.h"

int main()
{
	BST *tree = newBST(displayINTEGER, compareINTEGER);

	printf("The tree looks like this:\n");
	displayBST(stdout, tree);
	printf("\n");	
	
	insertBST(tree, 0, 0);
	//insertBST(tree, 1, 1);
	//insertBST(tree, 2, 2);

	findBST(tree, 0);
	
	int size = sizeBST(tree);
	printf("The size is: %d. \n", size);

	printf("The tree looks like this:\n");
	displayBST(stdout, tree);
	printf("\n");	

	return 0;
}
