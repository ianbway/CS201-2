// Ian Braudaway
// Implementation file for GT class
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "gt.h"
#include "bst.h"

static void swapper(BSTNODE *, BSTNODE *);
static int compareGTvalue(void *, void *);
static void displayGTvalue(FILE *, void *);

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
	void(*displayVal) (FILE *, void *);
	int(*compareVal) (void *, void *);
} GTVALUE;

GT *
newGT(void(*d)(FILE *, void *), int(*comparator)(void *, void *))
{
	// The constructor is passed two functions, one that knows how to display the generic value 
	// to be stored and one that can compare two of these generic values. 

	GT *tree = malloc(sizeof(GT));

	assert(tree != 0);

	tree->bst = newBST(displayGTvalue, compareGTvalue, swapper);
	tree->words = 0;
	tree->display = d;
	tree->compare = comparator;

	return tree;
}

GTVALUE *
newGTVALUE(GT *tree, void *value)
{
	GTVALUE *val = malloc(sizeof(GTVALUE));

	assert(val != 0);

	val->value = value;
	val->count = 1;
	val->displayVal = tree->display;
	val->compareVal = tree->compare;

	return val;
}

void 
insertGT(GT *tree, void *value)
{
	// The insert method increments the count, or if the node does not exist yet, inserts it.
	// It is passed a generic value.

	GTVALUE *mayExist = newGTVALUE(tree, value);
	printf("made value\n");
	
	// node already exists. Increase it's count by one and the overall number of words in the tree by one.
	if (findBST(tree->bst, mayExist))
	{
		printf("it exists\n");
		GTVALUE *alreadyExists = getBSTNODE(findBST(tree->bst, mayExist));
		printf("already exists variable created\n");
		alreadyExists->count++;
		tree->words++;
	}

	// node does not exist in tree yet. Add it to tree and increment the total number of words
	else
	{
		insertBST(tree->bst, mayExist);
		printf("inserted mayexist\n");
		tree->words++;
	}
}

int 
findGT(GT *tree, void *value)
{
	// This method returns the frequency of the searched-for value. 
	// If the value is not in the tree, the method should return zero. 

	// In tree
	if (findBST(tree->bst, value)) 
	{
		GTVALUE *alreadyExists = getBSTNODE(findBST(tree->bst, value));
		return alreadyExists->count;
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
		GTVALUE *alreadyExists = getBSTNODE(findBST(tree->bst, value));
		alreadyExists->count--;
		tree->words--;
	}

	// Delete node from tree if count is one
	else
	{
		deleteBST(tree->bst, value);
		tree->words--;
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

static int
compareGTvalue(void *valueOne, void *valueTwo)
{
	GTVALUE *valOne = valueOne;
	GTVALUE *valTwo = valueTwo;
	return valOne->compareVal(valOne->value, valTwo->value);
}

static void
displayGTvalue(FILE *file, void *value)
{
	GTVALUE *gtVal = value;
	gtVal->displayVal(file, gtVal->value);

	if (gtVal->count > 1)
	{
		fprintf(file, "-%d", gtVal->count);
	}
}