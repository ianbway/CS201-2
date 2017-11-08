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
newBSTNODE(BSTNODE *parent, void *value)
{
	BSTNODE *node = malloc(sizeof(BSTNODE));

	assert(node != 0);

	if (parent == NULL)
	{
		node->parent = node;
	}
	else
	{
		node->parent = parent;
	}

	node->value = value;
	node->left = 0;
	node->right = 0;

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
	return n->left;
}

void
setBSTNODEleft(BSTNODE *n, BSTNODE *replacement)
{
	n->left = replacement;
}

BSTNODE *
getBSTNODEright(BSTNODE *n)
{
	return n->right;
}

void
setBSTNODEright(BSTNODE *n, BSTNODE *replacement)
{
	n->right = replacement;
}

BSTNODE *
getBSTNODEparent(BSTNODE *n)
{
	return n->parent;
}

void
setBSTNODEparent(BSTNODE *n, BSTNODE *replacement)
{
	n->parent = replacement;
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
		spot->left = newBSTNODE(spot, value);
		tree->size++;
		returnSpot = spot->left;
	}
	else if (spot->right != NULL)
	{
		insertHelper(tree, spot->right, value);
	}
	else
	{
		spot->right = newBSTNODE(spot, value);
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
		tree->root = newBSTNODE(NULL, value);
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

	BSTNODE *returnVal = swapToLeafBST(t, findBST(t, value));

	pruneLeafBST(t, returnVal);

	return returnVal;
}

BSTNODE *
swapToLeafBST(BST *t, BSTNODE *node)
{
	// This method takes a node and recursively swaps its value with its predecessor's (or successor's) until a leaf node holds the original value. 
	// It calls the BST’s swapper function to actually accomplish the swap, sending the two nodes whose values need to be swapped. 
	// If the swapper function is NULL, then the method should just swap the values as normal.

	// We have reached the end, It has been swapped to leaf
	if ((node->left == NULL) && (node->right == NULL))
	{
		return node;
	}

	// There is a swap function
	if (t->swap != NULL)
	{
		// Less than or equal to, prefers predecessor, go left
		if (t->compare(node->value, node->left->value) <= 0)
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
		if (t->compare(node->value, node->left->value) <= 0)
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
	if (leaf->parent->left == leaf)
	{
		leaf->parent->left = NULL;
	}
	else
	{
		leaf->parent->right = NULL;
	}

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
	fprintf(fp, "Nodes: %d\n", t->size);

}

void 
displayBST(FILE *fp, BST *tree)
{
	// When showing the tree, display the nodes with a breadth-first (left-first) traversal. 
	// All nodes at a given level should be on the same line of output. 
	// The level number should precede the display of the nodes at that level. 
	// Display each node according to the following format: 
	// an equals sign if the node is a leaf, followed by
	// the node value, which may include a frequency count (if the count is greater than one) and a color, followed by
	// a parenthesized display of the parent's value (which again may include a frequency count and color), followed by
	// a - if the node is the root, a -l if the node is a left child, and a -r otherwise
	// This method should run in linear time. 
	
	// Empty tree
	if (tree->size == 0)
	{
		fprintf(fp, "EMPTY\n");
		return;
	}

	QUEUE *q = newQUEUE(tree->display);
	int levelCounter = 0;

	// Enqueue the root after verifying it's existence and a NULL value
	enqueue(q, tree->root);
	enqueue(q, NULL);
	fprintf(fp, "%d: ", levelCounter);
	// While the queue is not empty
	while (sizeQUEUE(q) > 0)
	{
		
		// Dequeue something, save it
		BSTNODE *dqVal = dequeue(q);

		// If we dequeue a NULL
		if (dqVal == NULL)
		{
			if (sizeQUEUE(q) == 0)
			{
				return;
			}
			dqVal = dequeue(q);
			++levelCounter;
			fprintf(fp, "\n");
			fprintf(fp, "%d: ", levelCounter);
			enqueue(q, NULL);
		}

		//printf("Dequeued address is %p\n", dqVal);
		// If there is a left child enqueue it
		if (dqVal->left != NULL)
		{
			enqueue(q, dqVal->left);
		}

		// If there is a right child enqueue it
		if (dqVal->right != NULL)
		{
			enqueue(q, dqVal->right);
		}

		// It's a leaf, and not root
		if ((dqVal->left == NULL) && (dqVal->right == NULL) && (dqVal != tree->root))
		{
			fprintf(fp, "=");
		}

		tree->display(fp, dqVal->value);
		fprintf(fp, "(");

		// It's root, so print itself for parent
		if (dqVal->parent == NULL)
		{
			tree->display(fp, dqVal->value);
		}

		// Else it is a child, so display parent in parens
		else 
		{
			tree->display(fp, dqVal->parent->value);
		}
		fprintf(fp, ")");

		// It's the root
		if (dqVal == tree->root)
		{
			fprintf(fp, "-");
		}

		// It's a left child
		if ((dqVal->parent) && (getBSTNODE(dqVal) == getBSTNODEleft(dqVal->parent)))
		{
			fprintf(fp, "-l");
		}

		// It's a right child
		if ((dqVal->parent) && (getBSTNODE(dqVal) == getBSTNODEright(dqVal->parent)))
		{
			fprintf(fp, "-r");
		}
		
		// We are not at the end of the level yet
		if (peekQUEUE(q) != NULL)
		{
			fprintf(fp, " ");
		}
	}
}
