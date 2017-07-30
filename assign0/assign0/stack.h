#ifndef __STACK_INCLUDED__
#define __STACK_INCLUDED__

#include <stdio.h>

typedef struct STACK
{
	void **store;
} STACK;

extern STACK *newSTACK(void(*d)(FILE *, void *));
extern void push(STACK *items, void *value);
extern void *pop(STACK *items);
extern int peekSTACK(STACK *items);
extern int sizeSTACK(STACK *items);
extern void displaySTACK(FILE *, STACK *items);
extern void displaySTACKds(FILE *, STACK *items);

#endif