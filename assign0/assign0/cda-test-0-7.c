#include <stdio.h>
#include <stdlib.h>
#include "cda.h"
#include "integer.h"
#include "real.h"
#include "string.h"
extern long random(void);
extern void srandom(unsigned int seed);

int
main(void)
    {
    printf("CDA tester: 0,7\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-0-7.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    insertCDAfront(d,newINTEGER(744));
    insertCDAfront(d,newINTEGER(242));
    insertCDAfront(d,newINTEGER(549));
    insertCDAfront(d,newINTEGER(311));
    insertCDAfront(d,newINTEGER(93));
    insertCDAfront(d,newINTEGER(182));
    insertCDAfront(d,newINTEGER(21));
    insertCDAfront(d,newINTEGER(777));
    insertCDAfront(d,newINTEGER(313));
    insertCDAfront(d,newINTEGER(47));
    insertCDAfront(d,newINTEGER(981));
    insertCDAfront(d,newINTEGER(196));
    insertCDAfront(d,newINTEGER(47));
    insertCDAfront(d,newINTEGER(655));
    insertCDAfront(d,newINTEGER(694));
    insertCDAfront(d,newINTEGER(100));
    insertCDAfront(d,newINTEGER(398));
    insertCDAfront(d,newINTEGER(265));
    insertCDAfront(d,newINTEGER(597));
    insertCDAfront(d,newINTEGER(705));
    insertCDAfront(d,newINTEGER(38));
    insertCDAfront(d,newINTEGER(897));
    insertCDAfront(d,newINTEGER(462));
    insertCDAfront(d,newINTEGER(940));
    insertCDAfront(d,newINTEGER(247));
    insertCDAfront(d,newINTEGER(334));
    insertCDAfront(d,newINTEGER(937));
    insertCDAfront(d,newINTEGER(55));
    insertCDAfront(d,newINTEGER(883));
    insertCDAfront(d,newINTEGER(353));
    insertCDAfront(d,newINTEGER(952));
    insertCDAfront(d,newINTEGER(980));
    insertCDAfront(d,newINTEGER(947));
    insertCDAfront(d,newINTEGER(501));
    insertCDAfront(d,newINTEGER(643));
    insertCDAfront(d,newINTEGER(393));
    printf("array d:");
    visualizeCDA(stdout,d);
    printf("\n");
    int size = sizeCDA(d);
    printf("extracting the underlying array\n");
    void **a = extractCDA(d);
    void *p = a[0];
    printf("the first element of the extracted array: ");
    displayINTEGER(stdout,p);
    printf("\n");
    p = a[size-1];
    printf("the last element of the extracted array: ");
    displayINTEGER(stdout,p);
    printf("\n");
    printf("array d:");
    visualizeCDA(stdout,d);
    printf("\n");
    return 0;
    }
