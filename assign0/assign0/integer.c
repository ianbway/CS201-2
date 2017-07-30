#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "integer.h"

INTEGER *
newInteger(int x)
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
getInteger(INTEGER * v)
{
	return v->value;
}

int
setInteger(INTEGER * v, int x)
{
	int old = v->value;
	v->value = x;
	return old;
}

void
displayInteger(FILE * fp, void *v)
{
	fprintf(fp, "%d", getInteger((INTEGER *)v));
}

int
compareInteger(void *v, void *w)
{
	return ((INTEGER *)v)->value - ((INTEGER *)w)->value;
}

void
freeInteger(INTEGER * v)
{
	free(v);
}