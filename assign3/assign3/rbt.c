// Ian Braudaway
// Implementation file for RBT class
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "rbt.h"
#include "bst.h"

static void swapper(BSTNODE *, BSTNODE *);
static int compareRBTvalue(void *, void *);
static void displayRBTvalue(FILE *, void *);
static char color(BSTNODE *);
static void setColor(BSTNODE *, char);
static int isLinear(BSTNODE *);
static void leftRotate(RBT *, BSTNODE *);
static void rightRotate(RBT *, BSTNODE *);
static BSTNODE *parent(BSTNODE *);
static BSTNODE *grandparent(BSTNODE *);
static BSTNODE *uncle(BSTNODE *);
static BSTNODE *sibling(BSTNODE *);
static BSTNODE *nephew(BSTNODE *);
static BSTNODE *niece(BSTNODE *);

struct rbt
{
	BST *bst;
	int words;
	void(*display) (FILE *, void *);
	int(*compare) (void *, void *);
};

typedef struct rbtvalue
{
	void *value;
	char color;
	int count;
	void(*displayVal) (FILE *, void *);
	int(*compareVal) (void *, void *);
} RBTVALUE;

RBT *
newRBT(void(*d)(FILE *, void *), int(*comparator)(void *, void *))
{
	// The constructor is passed two functions, one that knows how to display the generic value 
	// to be stored and one that can compare two of these generic values.

	RBT *tree = malloc(sizeof(RBT));

	assert(tree != 0);

	tree->bst = newBST(displayRBTvalue, compareRBTvalue, swapper);
	tree->words = 0;
	tree->display = d;
	tree->compare = comparator;

	return tree;
}

RBTVALUE *
newRBTVALUE(RBT *tree, void *value)
{
	RBTVALUE *val = malloc(sizeof(RBTVALUE));
	assert(val != 0);

	val->value = value;
	val->color = 'R';
	val->count = 1;
	val->displayVal = tree->display;
	val->compareVal = tree->compare;

	return val;
}

static void
insertionFixup(RBT *tree, BSTNODE *node)
{
	// Based off of best pseudocode ever

	while (1)
	{
		// X is the root, exit
		if (getBSTroot(tree->bst) == node)
		{
			break;
		}
		
		if (color(parent(node)) == 'B')
		{
			break;
		}
		
		if (color(uncle(node)) == 'R')
		{
			setColor(parent(node), 'B');
			setColor(uncle(node), 'B');
			setColor(grandparent(node), 'R');
			node = grandparent(node);
		}
		
		else
		{
			// uncle must be black
			BSTNODE *oldParent = parent(node);

			if (!isLinear(node))
			{
				// grandparents left node is equal to parent and right node of parent is equal to node
				if ((getBSTNODEleft(grandparent(node)) == parent(node)) && (getBSTNODEright(parent(node)) == node))
				{
					leftRotate(tree, oldParent);
				}

				else
				{
					rightRotate(tree, oldParent);
				}

				BSTNODE *temp = node;
				node = oldParent;
				oldParent = temp;
			}

			setColor(parent(node), 'B');
			setColor(grandparent(node), 'R');
			
			// If parent is right child, left rotate
			if (getBSTNODEright(grandparent(node)) == parent(node))
			{
				leftRotate(tree, parent(oldParent));
			}

			else
			{
				rightRotate(tree, parent(oldParent));
			}

			break;
		}
	}

	setColor(getBSTroot(tree->bst), 'B');
}

void 
insertRBT(RBT *tree, void *value)
{
	// The insert method adds a leaf to the tree in the proper location, based upon the comparator passed to the constructor.
	// It is passed a generic value. Uses insertionFixup for a red-black tree.

	BSTNODE *valToInsert;
	RBTVALUE *rbtVal = newRBTVALUE(tree, value);
	valToInsert = findBST(tree->bst, rbtVal);
	
	// node already exists. Increase it's count by one and the overall number of words in the tree by one.
	if (valToInsert)
	{
		rbtVal = getBSTNODE(valToInsert);
		rbtVal->count++;
		tree->words++;
	}

	// node does not exist in tree yet. Add it to tree and increment the total number of words. Call insertionFixup on newly inserted node.
	else
	{
		rbtVal = newRBTVALUE(tree, value);
		valToInsert = insertBST(tree->bst, rbtVal);
		tree->words++;
		insertionFixup(tree, valToInsert);
	}
}

int 
findRBT(RBT *tree, void *value)
{
	// This method returns the frequency of the searched-for value. 
	// If the value is not in the tree, the method should return zero. 
	
	RBTVALUE *alreadyExists = newRBTVALUE(tree, value);
	BSTNODE *valInTree = findBST(tree->bst, alreadyExists);

	// In tree
	if (valInTree)
	{
		alreadyExists = getBSTNODE(valInTree);
		return alreadyExists->count;
	}

	// Not in tree
	else
	{
		return 0;
	}
}

static void
deletionFixup(RBT *tree, BSTNODE *node)
{
	// Based off of best pseudocode ever

	while (1)
	{
		// X is the root, exit
		if (getBSTroot(tree->bst) == node)
		{
			break;
		}

		if (color(node) == 'R')
		{
			break;
		}

		if (color(sibling(node)) == 'R')
		{
			setColor(parent(node), 'R');
			setColor(sibling(node), 'B');
			
			// sibling is left, right rotation
			if (getBSTNODEleft(parent(sibling(node))) == sibling(node))
			{
				rightRotate(tree, sibling(node));
			}

			// sibling is right, left rotation
			else
			{
				leftRotate(tree, sibling(node));
			}
			// should have black sibling now
		}

		else if (color(nephew(node)) == 'R')
		{
			setColor(sibling(node), color(parent(node)));
			setColor(parent(node), 'B');
			setColor(nephew(node), 'B');

			// sibling is left, right rotation
			if (getBSTNODEleft(parent(sibling(node))) == sibling(node))
			{
				rightRotate(tree, sibling(node));
			}

			// sibling is right, left rotation
			else
			{
				leftRotate(tree, sibling(node));
			}
			// subtree and tree is black height balanced

			break;
		}

		else if (color(niece(node)) == 'R')
		{
			// nephew must be black
			setColor(niece(node), 'B');
			setColor(sibling(node), 'R');
			
			if (getBSTNODEright(sibling(node)) == niece(node))
			{
				leftRotate(tree, niece(node));
			}

			else
			{
				rightRotate(tree, niece(node));
			}
			// should have red nephew now
		}

		else // sibling, niece, and nephew must be black
		{
			setColor(sibling(node), 'R');
			node = parent(node);
			// this subtree is black height balanced, but the tree is not
		}
	}

	setColor(node, 'B');
}

void 
deleteRBT(RBT *tree, void *value)
{
	// Removes value from tree. If multiple of value reduce count by one. Uses deletion fixup.

	BSTNODE *valToDelete;
	RBTVALUE *rbtVal = newRBTVALUE(tree, value);
	valToDelete = findBST(tree->bst, rbtVal);

	// Count of value is more than one in the tree, decrement count
	if (findRBT(tree, value) > 1)
	{
		RBTVALUE *rbtVal = getBSTNODE(valToDelete);
		rbtVal->count--;
		tree->words--;
	}

	// Delete node from tree if count is one
	else if (findRBT(tree, value) == 1)
	{
		valToDelete = deleteBST(tree->bst, rbtVal);
		tree->words--;
		deletionFixup(tree, valToDelete);
	}

	// Ignore, but report an attempt to delete something that does not exist in the tree. 
	// Thus you ought to be able to randomly generate a large number commands and have your application run without failing. 
	// The error message printed when attempting to delete a value not in the tree should have the form: 
	// Value x not found.
	// There should be no quotes around the value. Normally, one would print error messages to stderr, but for testing purposes, print them to stdout. 

	else
	{
		printf("Value ");
		tree->display(stdout, value);
		printf(" not found.\n");
	}
}

int 
sizeRBT(RBT *tree)
{
	// This method returns the number of nodes currently in the tree. 
	// It should run in amortized constant time. 

	return sizeBST(tree->bst);
}

int 
wordsRBT(RBT *tree)
{
	// This method returns the number of words (including duplicates) currently in the tree. 
	// It should run in amortized constant time. 

	return tree->words;
}

void 
statisticsRBT(FILE *file, RBT *tree)
{
	// This method should display the number of words/phrases 
	// (including duplicates) and then call the BST display method.

	fprintf(file, "Words/Phrases: %d\n", wordsRBT(tree));
	statisticsBST(file, tree->bst);
}

void 
displayRBT(FILE *file, RBT *tree)
{
	// Calls displayBST on underlying tree.

	displayBST(file, tree->bst);
}

static void
swapper(BSTNODE *a, BSTNODE *b)
{
	RBTVALUE *ra = getBSTNODE(a);
	RBTVALUE *rb = getBSTNODE(b);

	/* swap the keys stored in the RBT value objects */
	void *vtemp = ra->value;
	ra->value = rb->value;
	rb->value = vtemp;

	/* swap the counts stored in the RBT value objects */
	int ctemp = ra->count;
	ra->count = rb->count;
	rb->count = ctemp;

	/* note: colors are NOT swapped */
}

static int
compareRBTvalue(void *valueOne, void *valueTwo)
{
	RBTVALUE *valOne = valueOne;
	RBTVALUE *valTwo = valueTwo;
	return valOne->compareVal(valOne->value, valTwo->value);
}

static void
displayRBTvalue(FILE *file, void *value)
{
	RBTVALUE *rbtVal = value;
	rbtVal->displayVal(file, rbtVal->value);

	if (rbtVal->count > 1)
	{
		fprintf(file, "-%d", rbtVal->count);
	}

	if (rbtVal->color == 'R')
	{
		fprintf(file, "-R");
	}

	else
	{
		fprintf(file, "-B");
	}
}

static char
color(BSTNODE *node)
{
	if (node == NULL)
	{
		return 'B';
	}

	else
	{
		RBTVALUE *rbtVal = getBSTNODE(node);
		return rbtVal->color;
	}
}

static void
setColor(BSTNODE *node, char color)
{
	RBTVALUE *rbtVal = getBSTNODE(node);
	rbtVal->color = color;
}

static int
isLinear(BSTNODE *node)
{
	// node is on left side
	if (getBSTNODEleft(parent(node)) == node)
	{
		// Now if grandparent left child is our nodes parent, we are linear left
		if (getBSTNODEleft(grandparent(node)) == (parent(node))) 
		{
			return 1;
		}

		// child node is on left side, parent is right child of grandparent, nonlinear
		else
		{
			return 0;
		}
	}

	// node is on right side, saving off conditional: if (getBSTNODEright(parent(node)) == node)
	else 
	{
		// Now if grandparent right child is our nodes parent, we are linear right
		if (getBSTNODEright(grandparent(node)) == (parent(node)))
		{
			return 1;
		}

		// child node is on right side, parent is left child of grandparent, nonlinear
		else
		{
			return 0;
		}
	}
}

static void 
leftRotate(RBT *tree, BSTNODE *node)
{
	// Based off of book pseudocode, 13.2

	BSTNODE *secondNode = getBSTNODEright(node);
	setBSTNODEright(node, getBSTNODEleft(secondNode));

	if (getBSTNODEleft(secondNode) != NULL) 
	{
		setBSTNODEparent(getBSTNODEleft(secondNode), node);
	}

	setBSTNODEparent(secondNode, parent(node));

	if (parent(node) == node) 
	{
		setBSTroot(tree->bst, secondNode);
		setBSTNODEparent(secondNode, secondNode);
	}

	else if (node == getBSTNODEleft(parent(node))) 
	{
		setBSTNODEleft(parent(node), secondNode);
	}

	else 
	{
		setBSTNODEright(parent(node), secondNode);
	}

	setBSTNODEleft(secondNode, node);
	setBSTNODEparent(node, secondNode);
}

static void
rightRotate(RBT *tree, BSTNODE *node)
{
	// Symmetric to leftRotate

	BSTNODE *secondNode = getBSTNODEleft(node);
	setBSTNODEleft(node, getBSTNODEright(secondNode));

	if (getBSTNODEright(secondNode) != NULL) 
	{
		setBSTNODEparent(getBSTNODEright(secondNode), node);
	}

	setBSTNODEparent(secondNode, parent(node));

	if (parent(node) == node) 
	{
		setBSTroot(tree->bst, secondNode);
		setBSTNODEparent(secondNode, secondNode);
	}

	else if (node == getBSTNODEright(parent(node))) 
	{
		setBSTNODEright(parent(node), secondNode);
	}

	else 
	{
		setBSTNODEleft(parent(node), secondNode);
	}

	setBSTNODEright(secondNode, node);
	setBSTNODEparent(node, secondNode);

	//printf("%p\n", getBSTNODE(node));
	//printf("%p\n", getBSTNODE(getBSTNODEleft(node)));
	//printf("%p\n", getBSTNODE(getBSTNODEright(node)));
	//printf("%p\n", getBSTNODE(getBSTNODEparent(node)));
	//printf("%p\n", getBSTNODE(secondNode));
	//printf("%p\n", getBSTNODE(getBSTNODEleft(secondNode)));
	//printf("%p\n", getBSTNODE(getBSTNODEright(secondNode)));
	//printf("%p\n", getBSTNODE(getBSTNODEparent(secondNode)));
}

static BSTNODE *
parent(BSTNODE *node)
{
	// Return parent

	return getBSTNODEparent(node);
}

static BSTNODE *
grandparent(BSTNODE *node)
{
	// Return parent of parent

	return parent(parent(node));
}

static BSTNODE*
uncle(BSTNODE *node)
{
	// If parent is left child, return the right child of parent's parent
	if (getBSTNODEleft(grandparent(node)) == parent(node))
	{
		return getBSTNODEright(grandparent(node));
	}

	// Else parent is right child, return the left child of the parent's parent
	else
	{
		return getBSTNODEleft(grandparent(node));
	}
}

static BSTNODE*
sibling(BSTNODE *node)
{
	// If left child, get right child
	if (getBSTNODEleft(parent(node)) == node)
	{
		return getBSTNODEright(parent(node));
	}

	// Else if right child, get left child
	else
	{
		return getBSTNODEleft(parent(node));
	}
}

static BSTNODE*
nephew(BSTNODE *node)
{
	// If the sibling of the node is a left child, return its left child, the furthest child of the sibling
	if (sibling(node) == getBSTNODEleft(parent(node)))
	{
		return getBSTNODEleft(sibling(node));
	}

	// Else if the sibling of the node is a right child, return its right child, the furthest child of the sibling
	else
	{
		return getBSTNODEright(sibling(node));
	}
}

static BSTNODE*
niece(BSTNODE *node)
{
	// If the sibling of the node is a left child, return its right child, the closest child of the sibling
	if (sibling(node) == getBSTNODEleft(parent(node)))
	{
		return getBSTNODEright(sibling(node));
	}

	// Else if the sibling of the node is a right child, return its left child, the closest child of the sibling
	else
	{
		return getBSTNODEleft(sibling(node));
	}
}