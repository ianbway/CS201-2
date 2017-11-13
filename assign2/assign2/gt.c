// Ian Braudaway
// Implementation file for GT class
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "gt.h"
#include "bst.h"

struct gt
{
	BST *bst;
	int words;
	void(*display) (FILE *, void *);
	int(*compare) (void *, void *);
};

typedef struct gtvalue 
{
	void *value;
	int count;
} GTVALUE;

GT *
newGT(void(*d)(FILE *, void *), int(*comparator)(void *, void *))
{
	// The constructor is passed two functions, one that knows how to display the generic value 
	// to be stored and one that can compare two of these generic values. 

	GT *tree = malloc(sizeof(GT));

	assert(tree != 0);

	tree->bst = newBST(d, comparator, swapper);
	tree->words = 0;
	tree->display = d;
	tree->compare = comparator;

	return tree;
}

GTVALUE *
newGTVALUE(void *value)
{
	GTVALUE *val = malloc(sizeof(GTVALUE));
	assert(val != 0);

	val->value = value;
	val->count = 1;

	return val;
}

void 
insertGT(GT *tree, void *value)
{
	// The insert method increments the count, or if the node does not exist yet, inserts it.
	// It is passed a generic value.

	GTVALUE *mayExist = newGTVALUE(value);

	// node already exists. Increase it's count by one and the overall number of words in the tree by one.
	if (findBST(tree->bst, mayExist))
	{
		GTVALUE *alreadyExists = getBSTNODE(findBST(tree->bst, mayExist));
		alreadyExists->count++;
		tree->words++;
	}

	// node does not exist in tree yet. Add it to tree and increment the total number of words
	else
	{
		insertBST(tree->bst, mayExist);
		tree->words++;
	}
}

int 
findGT(GT *tree, void *value)
{
	// This method returns the frequency of the searched-for value. 
	// If the value is not in the tree, the method should return zero. 

	GTVALUE *mayExist = newGTVALUE(value);

	// In tree
	if (findBST(tree->bst, value)) 
	{
		BSTNODE *inTree = findBST(tree->bst, mayExist);
		GTVALUE *val = getBSTNODE(inTree);
		return val->count;
	}

	// Not in tree
	else
	{
		return 0;
	}
}

void 
deleteGT(GT *tree, void *value)
{
	// Removes value from tree. If multiple of value reduce count by one.

	// Count of value is more than one in the tree, decrement count
	if (findGT(tree, value) > 1)
	{
		GTVALUE *alreadyExists = newGTVALUE(getBSTNODE(findBST(tree->bst, value)));
		alreadyExists->count--;
	}

	// Delete node from tree if count is one
	else
	{
		deleteBST(tree->bst, value);
	}
}

int 
sizeGT(GT *tree)
{
	// This method returns the number of nodes currently in the tree. 
	// It should run in amortized constant time.

	return sizeBST(tree->bst);
}

int 
wordsGT(GT *tree)
{
	// This method returns the number of words (including duplicates) currently in the tree. 
	// It should run in amortized constant time.

	return tree->words;
}

void 
statisticsGT(FILE *file, GT *tree)
{
	// This method should display the number of words/phrases 
	// (including duplicates) and then call the BST display method.

	fprintf(file, "Words/Phrases: %d\n", wordsGT(tree));
	statisticsBST(file, tree->bst);
}

void 
displayGT(FILE *file, GT *tree)
{
	// Calls underlying display BST method.

	displayBST(file, tree->bst);
}

static void
swapper(BSTNODE *a, BSTNODE *b)
{
	GTVALUE *ga = getBSTNODE(a);
	GTVALUE *gb = getBSTNODE(b);

	/* swap the keys stored in the RBT value objects */
	void *vtemp = ga->value;
	ga->value = gb->value;
	gb->value = vtemp;

	/* swap the counts stored in the RBT value objects */
	int ctemp = ga->count;
	ga->count = gb->count;
	gb->count = ctemp;

	/* note: colors are NOT swapped */
}