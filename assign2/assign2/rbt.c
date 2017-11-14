// Ian Braudaway
// Implementation file for RBT class
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "rbt.h"
#include "bst.h"

static void swapper(BSTNODE *, BSTNODE *);
static char color(BSTNODE *);
static void setColor(BSTNODE *, char);
static int isLinear(BSTNODE *);
static void leftRotate(RBT *, BSTNODE *);
static void rightRotate(RBT *, BSTNODE *);
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
	void(*display) (FILE *, void *);
	int(*compare) (void *, void *);
} RBTVALUE;

RBT *
newRBT(void(*d)(FILE *, void *), int(*comparator)(void *, void *))
{
	// The constructor is passed two functions, one that knows how to display the generic value 
	// to be stored and one that can compare two of these generic values.

	RBT *tree = malloc(sizeof(RBT));

	assert(tree != 0);

	tree->bst = newBST(d, comparator, swapper);
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
	val->color = "R";
	val->count = 1;
	val->display = tree->display;
	val->compare = tree->compare;

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

		if (color(getBSTNODEparent(node)) == "B")
		{
			break;
		}

		if (color(uncle(node)) == "R")
		{
			setColor(getBSTNODEparent(node), "B");
			setColor(uncle(node), "B");
			setColor(getBSTNODEparent(getBSTNODEparent(node)), "R");
			node = getBSTNODEparent(getBSTNODEparent(node));
		}

		else
		{
			// uncle must be black
			BSTNODE *parent = getBSTNODEparent(node);

			if (isLinear(node) == 0)
			{
				// grandparents left node is equal to parent and right node of parent is equal to node
				if (getBSTNODEleft(getBSTNODEparent(getBSTNODEparent(node)) == getBSTNODEparent(node)) && getBSTNODEright(getBSTNODEparent(node)) == node)
				{
					leftRotate(tree, parent);
				}

				else
				{
					rightRotate(tree, parent);
				}

				BSTNODE *temp = node;
				node = parent;
				parent = temp;
			}

			setColor(getBSTNODEparent(node), "B");
			setColor(getBSTNODEparent(getBSTNODEparent(node)), "R");
			
			// If parent is right child, left rotate
			if (getBSTNODEright(getBSTNODEparent(getBSTNODEparent(node))) == getBSTNODEparent(node))
			{
				leftRotate(tree, parent);
			}

			else
			{
				rightRotate(tree, parent);
			}

			break;
		}
	}

	setColor(getBSTroot(tree->bst), "B");
}

void 
insertRBT(RBT *tree, void *value)
{
	// The insert method adds a leaf to the tree in the proper location, based upon the comparator passed to the constructor.
	// It is passed a generic value. Uses insertionFixup for a red-black tree.
	
	RBTVALUE *mayExist = newRBTVALUE(tree, value);

	// node already exists. Increase it's count by one and the overall number of words in the tree by one.
	if (findBST(tree->bst, mayExist))
	{
		RBTVALUE *alreadyExists = getBSTNODE(findBST(tree->bst, mayExist));
		alreadyExists->count++;
		tree->words++;
	}

	// node does not exist in tree yet. Add it to tree and increment the total number of words. Call insertionFixup on newly inserted node.
	else
	{
		insertBST(tree->bst, mayExist);
		tree->words++;
		insertionFixup(tree, mayExist);
	}
}

int 
findRBT(RBT *tree, void *value)
{
	// This method returns the frequency of the searched-for value. 
	// If the value is not in the tree, the method should return zero. 
	
	RBTVALUE *mayExist = newRBTVALUE(tree, value);

	// In tree
	if (findBST(tree->bst, value))
	{
		BSTNODE *inTree = findBST(tree->bst, mayExist);
		RBTVALUE *val = getBSTNODE(inTree);
		return val->count;
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

		if (color(node) == "R")
		{
			break;
		}

		if (color(sibling(node)) == "R")
		{
			setColor(getBSTNODEparent(node), "R");
			setColor(sibling(node), "B");
			
			// sibling is left, right rotation
			if (getBSTNODEleft(getBSTNODEparent(sibling(node)) == sibling(node)))
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

		else if (color(nephew(node)) == "R")
		{
			setColor(sibling(node), color(getBSTNODEparent(node)));
			setColor(getBSTNODEparent(node), "B");
			setColor(nephew(node), "B");

			// sibling is left, right rotation
			if (getBSTNODEleft(getBSTNODEparent(sibling(node)) == sibling(node)))
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

		else if (color(niece(node)) == "R")
		{
			// nephew must be black
			setColor(niece(node), "B");
			setColor(sibling(node), "R");
			
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
			setColor(sibling(node), "R");
			node = getBSTNODEparent(node);
			// this subtree is black height balanced, but the tree is not
		}
	}

	setColor(node, "B");
}

void 
deleteRBT(RBT *tree, void *value)
{
	// Removes a value from a rbt. Uses deletion fixup. 

	// Count of value is more than one in the tree, decrement count
	if (findRBT(tree, value) > 1)
	{
		RBTVALUE *alreadyExists = newRBTVALUE(tree, getBSTNODE(findBST(tree->bst, value)));
		alreadyExists->count--;
		tree->words--;
	}

	// Delete node from tree if count is one
	else
	{
		deleteBST(tree->bst, value);
		tree->words--;
		deletionFixup(tree, findBST(tree->bst, value));
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

static char
color(BSTNODE *node)
{
	RBTVALUE *rbtVal = getBSTNODE(node);
	if (node == NULL)
	{
		return "B";
	}
	else
	{
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
	if (getBSTNODEleft(getBSTNODEparent(node)) == node)
	{
		// Now if grandparent left child is our nodes parent, we are linear left
		if (getBSTNODEleft(getBSTNODEparent(getBSTNODEparent(node))) == (getBSTNODEparent(node))) 
		{
			return 1;
		}

		// child node is on left side, parent is right child of grandparent, nonlinear
		else
		{
			return 0;
		}
	}

	// node is on right side
	else if (getBSTNODEright(getBSTNODEparent(node)) == node)
	{
		// Now if grandparent right child is our nodes parent, we are linear right
		if (getBSTNODEright(getBSTNODEparent(getBSTNODEparent(node))) == (getBSTNODEparent(node)))
		{
			return 1;
		}

		// child node is on right side, parent is left child of grandparent, nonlinear
		else
		{
			return 0;
		}
	}

	// Else some other unforseen combination of nodes that is nonlinear
	else 
	{
		return 0;
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

	setBSTNODEparent(secondNode, getBSTNODEparent(node));

	if (getBSTNODEparent(node) == NULL) 
	{
		setBSTroot(tree->bst, secondNode);
	}

	else if (node == getBSTNODEleft(getBSTNODEparent(node))) 
	{
		setBSTNODEleft(getBSTNODEparent(node), secondNode);
	}

	else 
	{
		setBSTNODEright(getBSTNODEparent(node), secondNode);
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

	setBSTNODEparent(secondNode, getBSTNODEparent(node));

	if (getBSTNODEparent(node) == NULL) 
	{
		setBSTroot(tree->bst, secondNode);
	}

	else if (node == getBSTNODEright(getBSTNODEparent(node))) 
	{
		setBSTNODEright(getBSTNODEparent(node), secondNode);
	}

	else 
	{
		setBSTNODEleft(getBSTNODEparent(node), secondNode);
	}

	setBSTNODEright(secondNode, node);
	setBSTNODEparent(node, secondNode);
}

static BSTNODE*
uncle(BSTNODE *node)
{
	// If parent is left child, return the right child of parent's parent
	if (getBSTNODEleft(getBSTNODEparent(getBSTNODEparent(node))) == getBSTNODEparent(node))
	{
		return getBSTNODEright(getBSTNODEparent(getBSTNODEparent(node)));
	}

	// Else parent is right child, return the left child of the parent's parent
	else
	{
		return getBSTNODEleft(getBSTNODEparent(getBSTNODEparent(node)));
	}
}

static BSTNODE*
sibling(BSTNODE *node)
{
	// If left child, get right child
	if (getBSTNODEleft(getBSTNODEparent(node)) == node)
	{
		return getBSTNODEright(getBSTNODEparent(node));
	}

	// Else if right child, get left child
	else
	{
		return getBSTNODEleft(getBSTNODEparent(node));
	}
}

static BSTNODE*
nephew(BSTNODE *node)
{
	// If the sibling of the node is a left child, return its left child, the furthest child of the sibling
	if (sibling(node) == getBSTNODEleft(getBSTNODEparent(node)))
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
	if (sibling(node) == getBSTNODEleft(getBSTNODEparent(node)))
	{
		return getBSTNODEright(sibling(node));
	}

	// Else if the sibling of the node is a right child, return its left child, the closest child of the sibling
	else
	{
		return getBSTNODEleft(sibling(node));
	}
}