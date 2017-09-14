// Ian Braudaway
// Implementation file for BST class
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "bst.h"

struct BST 
{
	//BSTNODE *root;
	int size;
	void(*display) (FILE *, void *);
	int(*compare) (void *, void *);
};

BST *
newBST(void(*d) (FILE *, void *, void *), int(*comparator) (void *, void *))
{
	BST *tree = malloc(sizeof(BST));
	
	assert(tree != 0);

	tree->root = 0;
	tree->display = d;
	tree->compare = comparator;
	tree->size = 0;

	return tree;
}

void 
insertBST(BST *tree, void *key, void *value)
{

	assert(tree != 0);

}

void *
findBST(BST *tree, void *key)
{

}

int 
sizeBST(BST *tree)
{

}

void 
displayBST(FILE *fp, BST *tree)
{

}