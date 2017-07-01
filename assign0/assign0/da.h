#ifndef __DA_INCLUDED__
#define __DA_INCLUDED__

#include <stdio.h>

typedef struct DA DA;

extern DA *newDA(void(*d)(FILE *, void *));
extern void insertDA(DA *items, void *value);
extern void *removeDA(DA *items);
extern void unionDA(DA *recipient, DA *donor);
extern void *getDA(DA *items, int index);
extern void *setDA(DA *items, int index, void *value);
extern int sizeDA(DA *items);
extern void displayDA(FILE *, DA *items);

#endif
