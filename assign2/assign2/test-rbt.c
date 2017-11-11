//Ian Braudaway
//Tester file for rbt class
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "rbt.h"
#include "string.h"
#include "real.h"
#include "integer.h"

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

int main()
{
	RBT *tree = newRBT(displaySTRING, compareSTRING);

	return 0;
}