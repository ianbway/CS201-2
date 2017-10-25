// Ian Braudaway
// Implementation file for BST class
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "bst.h"

typedef struct bstnode
{
	struct BSTNODE *left;
	struct BSTNODE *right;
	struct BSTNODE *parent;
	void *key;
	void *value;
} BSTNODE;

void *
getBSTNODE(BSTNODE *n)
{

}

void
setBSTNODE(BSTNODE *n, void *value)
{

}

BSTNODE *
getBSTNODEleft(BSTNODE *n)
{

}

void
setBSTNODEleft(BSTNODE *n, BSTNODE *replacement)
{

}

BSTNODE *
getBSTNODEright(BSTNODE *n)
{

}

void
setBSTNODEright(BSTNODE *n, BSTNODE *replacement)
{

}

BSTNODE *
getBSTNODEparent(BSTNODE *n)
{

}

void
setBSTNODEparent(BSTNODE *n, BSTNODE *replacement)
{

}

typedef struct bst 
{
	struct BSTNODE *root;
	int size;
	void(*display) (FILE *, void *, void *);
	int(*compare) (void *, void *);
} BST;

//static BSTNODE *
//newBSTNODE(void *key, void *value)
//{
//	BSTNODE *node = malloc(sizeof(BSTNODE));
//
//	assert(node != 0);
//
//	node->value = value;
//	node->key = key;
//	node->left = 0;
//	node->right = 0;
//
//	return node;
//}

BST * 
newBST(void(*d)(FILE *, void *), int(*comparator)(void *, void *))
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
setBSTroot(BST *t, BSTNODE *replacement)
{

}

BSTNODE *
getBSTroot(BST *t)
{

}

static void
insertHelper(BST *tree, BSTNODE *spot, void *key, void *value)
{

	int result = tree->compare(key, spot->key);

	if (result < 0 && spot->left != NULL)
	{
		insertHelper(tree, spot->left, key, value);
	}
	else if(result < 0)
	{
		spot->left = newBSTNODE(key, value);
	}
	else if (spot->right != NULL)
	{
		insertHelper(tree, spot->right, key, value);
	}
	else
	{
		spot->right = newBSTNODE(key, value);
	}
}

BSTNODE *
insertBST(BST *tree, void *value)
{
	/*
	The insert method adds a leaf to the tree in the proper location, based upon the comparator passed to the constructor. 
	It is passed a generic key value (upon which comparisons are made) and a generic value that is to be associated with the key. 
	*/

	assert(tree != 0);

	if (tree->root == 0)
	{
		tree->root = newBSTNODE(key, value);
	}

	else
	{
		insertHelper(tree, tree->root, key, value);
	}

	tree->size++;
}

static void *
findHelper(BST *tree, BSTNODE *node, void *key)
{
	// nothing left, return null
	if (node == 0)
	{
		return 0;
	}

	// we found it, it's equal
	else if (tree->compare(key, node->key) == 0)
	{
		return node->value;
	}

	// else it is negative, go left
	else if (tree->compare(key, node->key) < 0)
	{
		return findHelper(tree, node->left, key);
	}

	// else it is positive, go right 
	// *this is the condition for right, later use: if (tree->compare(key, node->key) > 0)
	else 
	{
		return findHelper(tree, node->right, key);
	}
}

void *
findBST(BST *tree, void *key)
{
	/*
	The find method returns the value associated with the given key. 
	The method returns a null pointer if the key is not in the tree.
	*/

	return findHelper(tree, tree->root, key);
}

BSTNODE *
deleteBST(BST *t, void *value)
{

}

BSTNODE *
swapToLeafBST(BST *t, BSTNODE *node)
{

}

void
pruneLeafBST(BST *t, BSTNODE *leaf)
{

}

int 
sizeBST(BST *tree)
{
	/*
	The size method returns the number of items stored in the tree. 
	*/

	return tree->size;
}

static void
inorder(FILE *fp, BST *tree, BSTNODE *root)
{
	if (root == 0)
	{
		return;
	}
	
	fprintf(fp, "[");

	if (root->left != 0)
	{
		inorder(fp, tree, root->left);
		fprintf(fp, " ");
	}

	tree->display(fp, root->key, root->value);

	if (root->right != 0)
	{
		fprintf(fp, " ");
		inorder(fp, tree, root->right);
	}
	
	fprintf(fp, "]");
	
}

void
statisticsBST(FILE *fp, BST *t)
{

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
	if (tree->root == 0)
	{
		fprintf(fp, "[");
		fprintf(fp, "]");
	}

	inorder(fp, tree, tree->root);
}
