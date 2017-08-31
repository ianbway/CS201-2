#ifndef __CDA_INCLUDED__
#define __CDA_INCLUDED__

#include <stdio.h>

typedef struct cda CDA;

extern CDA *newCDA(void(*d)(FILE *, void *));
extern void insertCDAFront(CDA *items, void *value);
extern void insertCDABack(CDA *items, void *value);
extern void *removeCDAFront(CDA *items);
extern void *removeCDABack(CDA *items);
extern void unionCDA(CDA *recipient, CDA *donor);
extern void *getCDA(CDA *items, int index);
extern void *setCDA(CDA *items, int index, void *value);
extern void **extractCDA(CDA *items);
extern int sizeCDA(CDA *items);
extern void visualizeCDA(FILE *fp, CDA *items);
extern void displayCDA(FILE *fp, CDA *items);

#endif