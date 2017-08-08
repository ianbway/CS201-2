#ifndef __DA_INCLUDED__
#define __DA_INCLUDED__

#include <stdio.h>

typedef struct da
{
	int size;
	int front;
	int back;
	int capacity;
	void **store;
	int factor;
	void (*display) (FILE *, void *);

} DA;

extern DA *newDA(void(*d)(FILE *, void *));
extern void insertDA(DA *items, void *value);
extern void *removeDA(DA *items);
extern void unionDA(DA *recipient, DA *donor);
extern void *getDA(DA *items, int index);
extern void *setDA(DA *items, int index, void *value);
extern void **extractDA(DA *items);
extern int sizeDA(DA *items);
extern void visualizeDA(FILE *fp, DA *items);
extern void displayDA(FILE *fp, DA *items);

#endif
