// Ian Braudaway, based off of Dr. Lusth's integer class and header
// Header file for integer class
#include <stdio.h>

#ifndef __INTEGER_INCLUDED__
#define __INTEGER_INCLUDED__

typedef struct INTEGER
{
	int value;
} INTEGER;

extern INTEGER *newINTEGER(int);
extern int getINTEGER(INTEGER *);
extern int setINTEGER(INTEGER *, int);
extern void displayINTEGER(FILE *, void *);
extern int compareINTEGER(void *, void *);
extern void freeINTEGER(INTEGER *);

#define PINFINITY IN_MAX
#define NINFINITY IN_MIN

#endif
