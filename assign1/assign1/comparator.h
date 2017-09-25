//Ian Braudaway
//Header file for comparator
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef __COMPARATOR_INCLUDED__
#define __COMPARATOR_INCLUDED__
typedef int (*Comparator)(void*,void*);
typedef void (*Printer)(FILE*,void*);
int compareINTEGER(void *, void *);
int compareREAL(void *, void *);
int compareSTRING(void *,void *);
void displayINTEGER(FILE *, void *);
void displayREAL(FILE *, void *);
void displaySTRING(FILE *, void *);

#endif
