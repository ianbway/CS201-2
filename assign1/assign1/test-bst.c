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
	fprintf(fp, "=");
	displayREAL(fp, value);
}

int main()
{
	BST *tree = newBST(displayMATILDA, compareSTRING);

	printf("The tree looks like this:\n");
	displayBST(stdout, tree);
	printf("\n");	
	
	STRING *a = newSTRING("a");
	STRING *b = newSTRING("b");
	STRING *c = newSTRING("c");
	STRING *d = newSTRING("d");
	STRING *e = newSTRING("e");

	printf("Inserting key/value pairs...\n");
	insertBST(tree, b, newREAL(1.000));
	insertBST(tree, a, newREAL(0.000));
	insertBST(tree, d, newREAL(3.000));
	insertBST(tree, c, newREAL(2.000));
	insertBST(tree, e, newREAL(4.000));

	printf("Finding values...\n");
	void* foundValA = findBST(tree, a);
	void* foundValB = findBST(tree, b);
	void* foundValC = findBST(tree, c);
	void* foundValD = findBST(tree, d);
	void* foundValE = findBST(tree, e);
	
	printf("Found all values, time to display them...\n");
	displayMATILDA(stdout, a, foundValA);
	printf("\n");
	displayMATILDA(stdout, b, foundValB);
	printf("\n");
	displayMATILDA(stdout, c, foundValC);
	printf("\n");
	displayMATILDA(stdout, d, foundValD);
	printf("\n");
	displayMATILDA(stdout, e, foundValE);
	printf("\n");

	int size = sizeBST(tree);
	printf("The size is: %d. \n", size);

	printf("The tree looks like this:\n");
	displayBST(stdout, tree);
	printf("\n");	

	return 0;
}
