// Ian Braudaway
// Implementation file for GT class
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "gt.h"
#include "bst.h"

typedef struct gt
{
	struct BSTNODE *root;
	int size;
	void(*display) (FILE *, void *, void *);
	int(*compare) (void *, void *);
} GT;

GT *
newGT(void(*d)(FILE *, void *), int(*comparator)(void *, void *))
{
	// The constructor is passed two functions, one that knows how to display the generic value 
	// to be stored and one that can compare two of these generic values. 

}

void 
insertGT(GT *tree, void *value)
{
	// The insert method adds a leaf to the tree in the proper location, based upon the comparator passed to the constructor.
	// It is passed a generic value.

}

int 
findGT(GT *tree, void *value)
{
	// This method returns the frequency of the searched-for value. 
	// If the value is not in the tree, the method should return zero. 

}

void 
deleteGT(GT *tree, void *value)
{
	// Removes value from tree.


}

int 
sizeGT(GT *tree)
{
	// This method returns the number of nodes currently in the tree. 
	// It should run in amortized constant time.

}

int 
wordsGT(GT *tree)
{
	// This method returns the number of words (including duplicates) currently in the tree. 
	// It should run in amortized constant time.


}

void 
statisticsGT(FILE *file, GT *tree)
{
	// This method should display the number of words/phrases 
	// (including duplicates) and then call the BST display method.

}

void 
displayGT(FILE *file, GT *tree)
{
	// Calls underlying display BST method.

}