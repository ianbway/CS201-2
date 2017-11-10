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

}

int main()
{
	BST *tree = newBST(displaySTRING, compareSTRING, swapper);

	printf("An empty tree...\n");
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
	findBST(tree, two);
	findBST(tree, three);
	findBST(tree, four);
	findBST(tree, five);

	//printf("%s\n", getSTRING(getBSTNODE(foundFive)));

	printf("Finding size...\n");
	int size = sizeBST(tree);
	printf("The size is: %d. \n", size);

	printf("The tree looks like this:\n");
	displayBST(stdout, tree);
	printf("\n");
	
	printf("Statistics...\n");
	statisticsBST(stdout, tree);
	printf("\n");

	printf("Deleting values...\n");
	deleteBST(tree, five);

	printf("The tree looks like this:\n");
	displayBST(stdout, tree);
	printf("\n");

	return 0;
}
