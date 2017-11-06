// Ian Braudaway
// Implementation file for RBT class
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "rbt.h"
#include "bst.h"

typedef struct rbt
{
	struct BSTNODE *root;
	int size;
	void(*display) (FILE *, void *, void *);
	int(*compare) (void *, void *);
} RBT;

RBT *
newRBT(void(*d)(FILE *, void *), int(*comparator)(void *, void *))
{
	// The constructor is passed two functions, one that knows how to display the generic value 
	// to be stored and one that can compare two of these generic values.


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

	return tree->size;
}

int 
wordsRBT(RBT *tree)
{
	// This method returns the number of words (including duplicates) currently in the tree. 
	// It should run in amortized constant time. 

}

void 
statisticsRBT(FILE *file, RBT *tree)
{
	// This method should display the number of words/phrases 
	// (including duplicates) and then call the BST display method.

}

void 
displayRBT(FILE *file, RBT *tree)
{
	// Calls displayBST on underlying tree.

	displayBST(file, tree);
}