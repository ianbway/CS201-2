#include <stdio.h>

#ifndef __INTEGER_INCLUDED__
#define __INTEGER_INCLUDED__

typedef struct INTEGER
{
	int value;
} INTEGER;

extern INTEGER *newInteger(int);
extern int getInteger(INTEGER *);
extern int setInteger(INTEGER *, int);
extern void displayInteger(FILE *, void *);
extern int compareInteger(void *, void *);
extern void freeInteger(INTEGER *);

#define PINFINITY IN_MAX
#define NINFINITY IN_MIN

#endif