// Ian Braudaway
// Implementation file for BST class
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "bst.h"
#include "queue.h"

struct bstnode
{
	struct bstnode *left;
	struct bstnode *right;
	struct bstnode *parent;
	void *value;
};

struct bst
{
	struct bstnode *root;
	int size;
	void(*display) (FILE *, void *);
	int(*compare) (void *, void *);
	void(*swap)(BSTNODE *, BSTNODE *);
};

static BSTNODE *
newBSTNODE(void *value)
{
	BSTNODE *node = malloc(sizeof(BSTNODE));

	assert(node != 0);

	node->value = value;
	node->left = 0;
	node->right = 0;
	node->parent = 0;

	return node;
}

BST *
newBST(void(*d)(FILE *, void *), int(*comparator)(void *, void *), void(*swapper)(BSTNODE *, BSTNODE *))
{
	// The constructor is passed three functions, one that knows how to display the generic value stored in a node, 
	// one that can compare two generic values, and one that knows how to swap the two generic values held by BSTNODEs (the swapper function is used by swapToLeafBST). 

	BST *tree = malloc(sizeof(BST));

	assert(tree != 0);

	tree->root = 0;
	tree->display = d;
	tree->compare = comparator;
	tree->swap = swapper;
	tree->size = 0;

	return tree;
}

void *
getBSTNODE(BSTNODE *n)
{
	// This method should return the value stored in the given search tree node.

	return n->value;
}

void
setBSTNODE(BSTNODE *n, void *value)
{
	n->value = value;
}

BSTNODE *
getBSTNODEleft(BSTNODE *n)
{
	return getBSTNODE(n->left);
}

void
setBSTNODEleft(BSTNODE *n, BSTNODE *replacement)
{
	n->left = getBSTNODE(replacement);
}

BSTNODE *
getBSTNODEright(BSTNODE *n)
{
	return getBSTNODE(n->right);
}

void
setBSTNODEright(BSTNODE *n, BSTNODE *replacement)
{
	n->right = getBSTNODE(replacement);
}

BSTNODE *
getBSTNODEparent(BSTNODE *n)
{
	return getBSTNODE(n->parent);
}

void
setBSTNODEparent(BSTNODE *n, BSTNODE *replacement)
{
	n->parent = getBSTNODE(replacement);
}

void
setBSTroot(BST *t, BSTNODE *replacement)
{
	// This method updates the root pointer of a BST object. It should run in constant time. 

	t->root = replacement;
}

BSTNODE *
getBSTroot(BST *t)
{
	return t->root;
}

static BSTNODE *
insertHelper(BST *tree, BSTNODE *spot, void *value)
{

	BSTNODE *returnSpot;

	int result = tree->compare(value, spot->value);

	if (result < 0 && spot->left != NULL)
	{
		insertHelper(tree, spot->left, value);
	}
	else if(result < 0)
	{
		spot->left = newBSTNODE(value);
		tree->size++;
		returnSpot = spot->left;
	}
	else if (spot->right != NULL)
	{
		insertHelper(tree, spot->right, value);
	}
	else
	{
		spot->right = newBSTNODE(value);
		tree->size++;
		returnSpot = spot->right;
	}

	return returnSpot;
}

BSTNODE *
insertBST(BST *tree, void *value)
{
	/*
	The insert method adds a leaf to the tree in the proper location, based upon the comparator passed to the constructor. 
	It is passed a generic value that is to be the key and value. 
	*/

	assert(tree != 0);

	if (tree->root == 0)
	{
		tree->root = newBSTNODE(value);
		tree->size++;
		return tree->root;
	}

	else
	{
		return insertHelper(tree, tree->root, value);
	}

}

BSTNODE *
findHelper(BST *tree, BSTNODE *node, void *value)
{
	// nothing left, return null
	if (node == 0)
	{
		return 0;
	}

	// we found it, it's equal
	else if (tree->compare(value, node->value) == 0)
	{
		return node->value;
	}

	// else it is negative, go left
	else if (tree->compare(value, node->value) < 0)
	{
		return findHelper(tree, node->left, value);
	}

	// else it is positive, go right 
	// *this is the condition for right, later use: if (tree->compare(key, node->key) > 0)
	else 
	{
		return findHelper(tree, node->right, value);
	}
}

BSTNODE *
findBST(BST *tree, void *value)
{
	// This method returns the node that holds the searched-for value. If the value is not in the tree, the method should return null. 
	// It should run in linear time for a green tree and logarithmic time for a red-black tree. 

	return findHelper(tree, tree->root, value);
}

BSTNODE *
deleteBST(BST *t, void *value)
{
	// This method is implemented with a call to the swap-to-leaf method followed by a call to the prune-leaf method, returning the pruned node. 
	// It should run in linear time for a green tree and logarithmic time for a red-black tree. 

	swapToLeafBST(t, getBSTNODE(value));

	BSTNODE *returnVal = getBSTNODE(value);

	pruneLeafBST(t, getBSTNODE(value));

	return returnVal;
}

BSTNODE *
swapToLeafBST(BST *t, BSTNODE *node)
{
	// This method takes a node and recursively swaps its value with its predecessor's (or successor's) until a leaf node holds the original value. 
	// It calls the BST’s swapper function to actually accomplish the swap, sending the two nodes whose values need to be swapped. 
	// If the swapper function is NULL, then the method should just swap the values as normal.

	// There is a swap function
	if (t->swap != NULL)
	{
		// Less than or equal to, prefers predecessor, go left
		if (node->value <= node->left->value)
		{
			t->swap(node->value, node->left->value);
			swapToLeafBST(t, node);
		}

		// Greater than go right
		else
		{
			t->swap(node->value, node->right->value);
			swapToLeafBST(t, node);
		}
	}

	// There is no swap function
	else
	{
		// Less than or equal to, prefers predecessor, go left
		if (node->value <= node->left->value)
		{
			void *tempValue = node->left->value;
			node->left->value = node->value;
			node->value = tempValue;
			swapToLeafBST(t, node);
		}

		// Greater than go right
		else
		{
			void *tempValue = node->right->value;
			node->right->value = node->value;
			node->value = tempValue;
			swapToLeafBST(t, node);
		}
	}

	return node;
}

void
pruneLeafBST(BST *t, BSTNODE *leaf)
{
	leaf->value = NULL;

	--t->size;
}

int 
sizeBST(BST *tree)
{
	// This method returns the number of nodes currently in the tree. It should run in amortized constant time.

	return tree->size;
}

void
statisticsBST(FILE *fp, BST *t)
{
	// This method should display the number of nodes in the tree as well as the minimum and maximum heights of the tree. It should run in linear time. 
	fprintf(fp, "%d\n", t->size);

}

static void
displayHelper(FILE *fp, BST *tree, BSTNODE *root)
{

	QUEUE *displayQUEUE = newQUEUE(NULL);

	fprintf(fp, "[");

	if (root->left != 0)
	{
		enqueue(displayQUEUE, root->left);
		displayHelper(fp, tree, root->left);
		fprintf(fp, " ");
	}

	tree->display(fp, dequeue(displayQUEUE));

	if (root->right != 0)
	{
		fprintf(fp, " ");
		enqueue(displayQUEUE, root->right);
		displayHelper(fp, tree, root->right);
	}

	fprintf(fp, "]");

}

void 
displayBST(FILE *fp, BST *tree)
{
	// The display method performs an in-order traversal of the tree. At any given node, the method displays the left and right subtrees, each enclosed with brackets, but only if they exist. 
	// A space is placed between any existing subtree (e.g. after the bracket for a left subtree) and the node value. 
	// An empty tree is displayed as []. To display a node in the tree, the cached display function is passed the value stored at the node. 
	// No characters are to be printed after the last closing bracket.
	// This method should run in linear time. 
	
	if (tree->root == 0)
	{
		fprintf(fp, "[");
		fprintf(fp, "]");

		return;
	}

	displayHelper(fp, tree, tree->root);
}
