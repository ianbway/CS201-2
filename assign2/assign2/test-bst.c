//Ian Braudaway
//Tester file for bst class
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "string.h"
#include "real.h"
#include "integer.h"

static void 
swapper(BSTNODE *a, BSTNODE *b)
{
	void *nodeAVal = getBSTNODE(a);
	void *nodeBVal = getBSTNODE(b);

	/* swap the values stored in the BST value objects */
	void *vtemp = nodeAVal;
	nodeAVal = nodeBVal;
	nodeBVal = vtemp;

	/* swap the counts stored in the BST value objects */
	//int ctemp = a->count;
	//a->count = b->count;
	//b->count = ctemp;

	/* note: colors are NOT swapped */
}

static void
displayCORPUS(FILE *fp, void *value)
{
	displaySTRING(fp, value);
}

int main()
{
	BST *tree = newBST(displaySTRING, compareSTRING, swapper);

	printf("The tree looks like this:\n");
	displayBST(stdout, tree);
	printf("\n");	

	STRING *one = newSTRING("1");
	STRING *two = newSTRING("2");
	STRING *three = newSTRING("3");
	STRING *four = newSTRING("4");
	STRING *five = newSTRING("5");

	printf("Inserting values...\n");
	insertBST(tree, three);
	insertBST(tree, two);
	insertBST(tree, one);
	insertBST(tree, four);
	insertBST(tree, five);

	printf("Finding values...\n");
	findBST(tree, one);

	printf("The tree looks like this:\n");
	displayBST(stdout, tree);
	printf("\n");
	//insertBST(tree, a, newREAL(0.000));
	//insertBST(tree, d, newREAL(3.000));
	//insertBST(tree, c, newREAL(2.000));
	//insertBST(tree, e, newREAL(4.000));

	//printf("Finding values...\n");
	//void* foundValA = findBST(tree, a);
	//void* foundValB = findBST(tree, b);
	//void* foundValC = findBST(tree, c);
	//void* foundValD = findBST(tree, d);
	//void* foundValE = findBST(tree, e);
	
	//printf("Found all values, time to display them...\n");
	//displayMATILDA(stdout, a, foundValA);
	//printf("\n");
	//displayMATILDA(stdout, b, foundValB);
	//printf("\n");
	//displayMATILDA(stdout, c, foundValC);
	//printf("\n");
	//displayMATILDA(stdout, d, foundValD);
	//printf("\n");
	//displayMATILDA(stdout, e, foundValE);
	//printf("\n");

	//int size = sizeBST(tree);
	//printf("The size is: %d. \n", size);

	//printf("The tree looks like this:\n");
	//displayBST(stdout, tree);
	//printf("\n");	

	return 0;
}
