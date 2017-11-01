// Ian Braudaway, based off of Dr. Lusth's integer class and header
// Implementation file for integer class

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "integer.h"

INTEGER *
newINTEGER(int x)
{
	INTEGER *p = malloc(sizeof(INTEGER));
	if (p == 0)
	{
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}
	p->value = x;
	return p;
}

int
getINTEGER(INTEGER * v)
{
	return v->value;
}

int
setINTEGER(INTEGER * v, int x)
{
	int old = v->value;
	v->value = x;
	return old;
}

void
displayINTEGER(FILE * fp, void *v)
{
	fprintf(fp, "%d", getINTEGER((INTEGER *)v));
}

int
compareINTEGER(void *v, void *w)
{
	return (((INTEGER *)v)->value - ((INTEGER *)w)->value);
}

void
freeINTEGER(INTEGER * v)
{
	free(v);
}
