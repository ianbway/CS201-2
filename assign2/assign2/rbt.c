// Ian Braudaway
// Implementation file for RBT class
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "rbt.h"
#include "bst.h"

struct rbt
{
	BST *bst;
	int words;
	void(*display) (FILE *, void *);
	int(*compare) (void *, void *);
};

typedef struct rbtvalue
{
	void *value;
	char color;
	int count;
} RBTVALUE;

RBT *
newRBT(void(*d)(FILE *, void *), int(*comparator)(void *, void *))
{
	// The constructor is passed two functions, one that knows how to display the generic value 
	// to be stored and one that can compare two of these generic values.

	RBT *tree = malloc(sizeof(RBT));

	assert(tree != 0);

	tree->bst = newBST(d, comparator, swapper);
	tree->words = 0;
	tree->display = d;
	tree->compare = comparator;

	return tree;
}

RBTVALUE *
newRBTVALUE(void *value)
{
	RBTVALUE *val = malloc(sizeof(RBTVALUE));
	assert(val != 0);

	val->value = value;
	val->color = "R";
	val->count = 1;

	return val;
}

static void
insertionFixup(RBT *tree, void *value)
{
	
}

void 
insertRBT(RBT *tree, void *value)
{
	// The insert method adds a leaf to the tree in the proper location, based upon the comparator passed to the constructor.
	// It is passed a generic value. Uses insertionFixup for a red-black tree.
	


}

int 
findRBT(RBT *tree, void *value)
{
	// This method returns the frequency of the searched-for value. 
	// If the value is not in the tree, the method should return zero. 
	
	RBTVALUE *mayExist = newRBTVALUE(value);

	// In tree
	if (findBST(tree->bst, value))
	{
		BSTNODE *inTree = findBST(tree->bst, mayExist);
		RBTVALUE *val = getBSTNODE(inTree);
		return val->count;
	}

	// Not in tree
	else
	{
		return 0;
	}
}

static void
deletionFixup(RBT *tree, void *value)
{

}

void 
deleteRBT(RBT *tree, void *value)
{
	// Removes a value from a rbt. Uses deletion fixup. 
}

int 
sizeRBT(RBT *tree)
{
	// This method returns the number of nodes currently in the tree. 
	// It should run in amortized constant time. 

	return sizeBST(tree->bst);
}

int 
wordsRBT(RBT *tree)
{
	// This method returns the number of words (including duplicates) currently in the tree. 
	// It should run in amortized constant time. 

	return tree->words;
}

void 
statisticsRBT(FILE *file, RBT *tree)
{
	// This method should display the number of words/phrases 
	// (including duplicates) and then call the BST display method.

	fprintf(file, "Words/Phrases: %d\n", wordsRBT(tree));
	statisticsBST(file, tree->bst);
}

void 
displayRBT(FILE *file, RBT *tree)
{
	// Calls displayBST on underlying tree.

	displayBST(file, tree->bst);
}

static void
swapper(BSTNODE *a, BSTNODE *b)
{
	RBTVALUE *ra = getBSTNODE(a);
	RBTVALUE *rb = getBSTNODE(b);

	/* swap the keys stored in the RBT value objects */
	void *vtemp = ra->value;
	ra->value = rb->value;
	rb->value = vtemp;

	/* swap the counts stored in the RBT value objects */
	int ctemp = ra->count;
	ra->count = rb->count;
	rb->count = ctemp;

	/* note: colors are NOT swapped */
}