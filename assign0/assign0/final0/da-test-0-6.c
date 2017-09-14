#include <stdio.h>
#include <stdlib.h>
#include "da.h"
#include "integer.h"
#include "real.h"
#include "string.h"
extern long random(void);
extern void srandom(unsigned int seed);

int
main(void)
    {
    printf("DA tester: 0,6\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-0-6.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayINTEGER);
    insertDA(d,newINTEGER(299));
    insertDA(d,newINTEGER(899));
    insertDA(d,newINTEGER(871));
    insertDA(d,newINTEGER(325));
    insertDA(d,newINTEGER(443));
    insertDA(d,newINTEGER(586));
    insertDA(d,newINTEGER(97));
    insertDA(d,newINTEGER(600));
    insertDA(d,newINTEGER(153));
    insertDA(d,newINTEGER(315));
    insertDA(d,newINTEGER(321));
    insertDA(d,newINTEGER(331));
    insertDA(d,newINTEGER(526));
    insertDA(d,newINTEGER(865));
    insertDA(d,newINTEGER(720));
    insertDA(d,newINTEGER(178));
    insertDA(d,newINTEGER(746));
    insertDA(d,newINTEGER(570));
    insertDA(d,newINTEGER(736));
    insertDA(d,newINTEGER(504));
    insertDA(d,newINTEGER(963));
    insertDA(d,newINTEGER(788));
    insertDA(d,newINTEGER(504));
    insertDA(d,newINTEGER(749));
    insertDA(d,newINTEGER(884));
    insertDA(d,newINTEGER(961));
    insertDA(d,newINTEGER(392));
    insertDA(d,newINTEGER(257));
    insertDA(d,newINTEGER(230));
    insertDA(d,newINTEGER(213));
    insertDA(d,newINTEGER(934));
    insertDA(d,newINTEGER(530));
    insertDA(d,newINTEGER(112));
    insertDA(d,newINTEGER(806));
    insertDA(d,newINTEGER(855));
    insertDA(d,newINTEGER(907));
    insertDA(d,newINTEGER(744));
    printf("array d:");
    visualizeDA(stdout,d);
    printf("\n");
    int size = sizeDA(d);
    printf("extracting the underlying array\n");
    void **a = extractDA(d);
    void *p = a[0];
    printf("the first element of the extracted array: ");
    displayINTEGER(stdout,p);
    printf("\n");
    p = a[size-1];
    printf("the last element of the extracted array: ");
    displayINTEGER(stdout,p);
    printf("\n");
    printf("array d:");
    visualizeDA(stdout,d);
    printf("\n");
    return 0;
    }
