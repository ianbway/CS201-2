//Ian Braudaway
//Tester file for bst class
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "string.h"
#include "real.h"
#include "integer.h"

void
displayMATILDA(FILE *fp, void *key, void *value)
{
	displaySTRING(fp, key);
	fprintf(fp, " = ");
	displayREAL(fp, value);
}

int main()
{
	BST *tree = newBST(displayMATILDA, compareSTRING);

	printf("The tree looks like this:\n");
	displayBST(stdout, tree);
	printf("\n");	
	
	insertBST(tree, newSTRING("0"), newREAL(0.000));
	//insertBST(tree, 1, 1);
	//insertBST(tree, 2, 2);

	findBST(tree, newSTRING("0"));
	
	int size = sizeBST(tree);
	printf("The size is: %d. \n", size);

	printf("The tree looks like this:\n");
	displayBST(stdout, tree);
	printf("\n");	

	return 0;
}
