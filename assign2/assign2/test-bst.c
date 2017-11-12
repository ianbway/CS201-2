//Ian Braudaway
//Tester file for bst class
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "string.h"
#include "real.h"
#include "integer.h"

//static void 
//swapper(BSTNODE *a, BSTNODE *b)
//{
//	void *nodeAVal = getBSTNODE(a);
//	void *nodeBVal = getBSTNODE(b);
//
//	/* swap the values stored in the BST value objects */
//	void *vtemp = nodeAVal;
//	nodeAVal = nodeBVal;
//	nodeBVal = vtemp;
//
//}

int main()
{
	BST *tree = newBST(displayINTEGER, compareINTEGER, NULL);

	printf("An empty tree...\n");
	printf("The tree looks like this:\n");
	displayBST(stdout, tree);
	printf("\n");	

	/*STRING *one = newSTRING("one");
	STRING *two = newSTRING("two");
	STRING *three = newSTRING("three");
	STRING *four = newSTRING("four");
	STRING *five = newSTRING("five");
	STRING *six = newSTRING("six");
	STRING *seven = newSTRING("seven");
	STRING *eight = newSTRING("eight");
	STRING *nine = newSTRING("nine");
	STRING *ten = newSTRING("ten");
	STRING *eleven = newSTRING("eleven");
	STRING *twelve = newSTRING("twelve");
	STRING *thirteen = newSTRING("thirteen");
	STRING *fourteen = newSTRING("fourteen");
	STRING *fifteen = newSTRING("fifteen");*/

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

	printf("Inserting values...\n");
	insertBST(tree, seven);
	insertBST(tree, three);
	insertBST(tree, two);
	insertBST(tree, one);
	insertBST(tree, four);
	insertBST(tree, five);
	insertBST(tree, fifteen);
	insertBST(tree, eight);
	insertBST(tree, nine);
	insertBST(tree, ten);
	insertBST(tree, six);
	insertBST(tree, eleven);
	insertBST(tree, twelve);
	insertBST(tree, thirteen);
	insertBST(tree, fourteen);

	printf("Finding values...\n");
	findBST(tree, one);
	findBST(tree, two);
	findBST(tree, three);
	findBST(tree, four);
	findBST(tree, five);
	findBST(tree, six);
	findBST(tree, seven);
	findBST(tree, eight);
	findBST(tree, nine);
	findBST(tree, ten);
	findBST(tree, eleven);
	findBST(tree, twelve);
	findBST(tree, thirteen);
	findBST(tree, fourteen);
	findBST(tree, fifteen);

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
	deleteBST(tree, two);
	deleteBST(tree, nine);
	deleteBST(tree, fifteen);
	deleteBST(tree, six);
	deleteBST(tree, one);
	deleteBST(tree, three);
	deleteBST(tree, four);
	deleteBST(tree, seven);
	deleteBST(tree, eight);
	deleteBST(tree, ten);
	deleteBST(tree, eleven);
	deleteBST(tree, twelve);
	deleteBST(tree, thirteen);
	deleteBST(tree, fourteen);

	printf("The tree looks like this:\n");
	displayBST(stdout, tree);
	printf("\n");

	return 0;
}
