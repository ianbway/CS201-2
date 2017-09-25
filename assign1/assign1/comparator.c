//Ian Braudaway
//Implementation for comparator
#include "comparator.h"
#include "string.h"
#include "real.h"
#include "integer.h"

int compareINTEGER(void *v, void *w)
{
	return ((integer *) v)->value - ((integer *) w)->value;
}

int compareREAL(void *v, void *w)
{
	return ((real *) v)->value - ((real *) w)->value;
}

int compareSTRING(void *v, void *w)
{
	string *s1 = (string*)v;
	string *s2 = (string*)w;
	char* c1 = (char *)s1->value;
	char* c2 = (char *)s2->value;
	return strcmp(c1,c2);
}


void displayINTEGER(FILE *fp, void *v)
{
	fprintf (fp, "%d", getINTEGER ((integer *) v));
}

void displayREAL(FILE *fp, void *v)
{
	fprintf (fp, "%f", getREAL ((real *) v));
}
	
void displaySTRING(FILE *fp, void *v)
{
	fprintf (fp, "\"%s\"", getSTRING ((string *) v));
}

