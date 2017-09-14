// Ian Braudaway
// Implementation file for BST class
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "bst.h"

typedef struct BSTNODE
{
	struct BSTNODE *left;
	struct BSTNODE *right;
	struct BSTNODE *parent;
	void *value;
} bstNode;

struct BST 
{
	BSTNODE *root;
	int size;
	void(*display) (FILE *, void *);
	int(*compare) (void *, void *);
};

BST *
newBST(void(*d) (FILE *, void *, void *), int(*comparator) (void *, void *))
{
	/*
	The constructor is passed two functions: one that knows how to display the generic key-value pair stored in the tree and one that knows how to compare two generic keys. 
	*/

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
	/*
	The insert method adds a leaf to the tree in the proper location, based upon the comparator passed to the constructor. 
	It is passed a generic key value (upon which comparisons are made) and a generic value that is to be associated with the key. 
	*/

	assert(tree != 0);

}

void *
findBST(BST *tree, void *key)
{
	/*
	The find method returns the value associated with the given key. 
	The method returns a null pointer if the key is not in the tree.
	*/


}

int 
sizeBST(BST *tree)
{
	/*
	The size method returns the number of items stored in the tree. 
	*/

}

void 
displayBST(FILE *fp, BST *tree)
{
	/*
	The display method performs an in-order traversal of the tree. At any given node, the method displays the left and right subtrees, each enclosed with brackets, but only if they exist. 
	A space is placed between any existing subtree (e.g. after the bracket for a left subtree) and the node value. 
	An empty tree is displayed as []. To display a node in the tree, the cached display function is passed the key and the value stored at the node. 
	No characters are to be printed after the last closing bracket.
	*/

}