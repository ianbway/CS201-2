// Ian Braudaway
// Implementation file for BST class
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "bst.h"

struct BSTNODE
{
	struct BSTNODE *left;
	struct BSTNODE *right;
	struct BSTNODE *parent;
	void *key;
	void *value;
};

struct BST 
{
	BSTNODE *root;
	int size;
	void(*display) (FILE *, void *, void *);
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

	BSTNODE *node = malloc(sizeof(BSTNODE));
	BSTNODE *current = 0;
	BSTNODE *parent = 0;

	assert(node != 0);

	node->value = value;
	node->key = key;
	node->left = 0;
	node->right = 0;

	if (tree->root == 0)
	{
		tree->root = node;
	}

	else
	{
		current = tree->root;
		parent = 0;
	}

	while(1)
	{
		parent = current;
		//go to the left of the tree
		if (tree->compare(node->key, parent->key))
		{
			current = current->left;

			if (current == 0)
			{
				parent->left = node;
				break;
			}	
		}	
		//go to the right of the tree
		else
		{
			current = current->right;

			if (current == 0)
			{
				parent->right = node;
				break;
			}
		}
	}

	tree->size++;
}

void *
findBST(BST *tree, void *key)
{
	/*
	The find method returns the value associated with the given key. 
	The method returns a null pointer if the key is not in the tree.
	*/
	BSTNODE *current = tree->root;

	while(current->key != key)
	{
		if (current != 0)
		{
			//go to the left tree
			if (tree->compare(current->key, key))
			{
				current = current->left;
			}
			//go to the right tree
			else
			{
				current = current->right;
			}
			//not found
			if (current == 0)
			{
				return 0;
			}
		}
	}
	return current->value;
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

	inorder(fp, tree, root->left);
	fprintf(fp, "[ ");
	tree->display(fp, root->key, root->value);
	fprintf(fp, " ]");
	inorder(fp, tree, root->right);
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
	fprintf(fp,"[");
	inorder(fp, tree, tree->root);
	fprintf(fp,"]");
}
