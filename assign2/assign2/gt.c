// Ian Braudaway
// Implementation file for GT class
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "gt.h"
#include "bst.h"

typedef struct gtvalue 
{
	void *value;
	int count;
} GTVALUE;

struct gt
{
	BST *bst;
	int words;
	void(*display) (FILE *, void *);
	int(*compare) (void *, void *);
};

GT *
newGT(void(*d)(FILE *, void *), int(*comparator)(void *, void *))
{
	// The constructor is passed two functions, one that knows how to display the generic value 
	// to be stored and one that can compare two of these generic values. 

	GT *tree = newBST(d, comparator, NULL);
	assert(tree != 0);

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

	return val;
}

void 
insertGT(GT *tree, void *value)
{
	// The insert method adds a leaf to the tree in the proper location, based upon the comparator passed to the constructor.
	// It is passed a generic value.

	if (findGT(tree, value))
	{
		GTVALUE *alreadyExists = findGT(tree, value);
		alreadyExists->count++;
	}

	else
	{
		insertBST(tree, value);
	}
}

int 
findGT(GT *tree, void *value)
{
	// This method returns the frequency of the searched-for value. 
	// If the value is not in the tree, the method should return zero. 

	if (findBST(tree, value)) 
	{
		BSTNODE *inTree = findBST(tree, value);
		
		return ;
	}

	else
	{
		return 0;
	}
}

void 
deleteGT(GT *tree, void *value)
{
	// Removes value from tree.
	if (findGT(tree, value) > 1)
	{
		// reduce size by one
	}

	else
	{
		deleteBST(tree, value);
	}
}

int 
sizeGT(GT *tree)
{
	// This method returns the number of nodes currently in the tree. 
	// It should run in amortized constant time.

	return sizeBST(tree);
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
	displayBST(file, tree);
}

void 
displayGT(FILE *file, GT *tree)
{
	// Calls underlying display BST method.

	displayBST(file, tree);
}