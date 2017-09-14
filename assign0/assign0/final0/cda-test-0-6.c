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
    printf("CDA tester: 0,6\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-0-6.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    insertCDAback(d,newINTEGER(299));
    insertCDAback(d,newINTEGER(899));
    insertCDAback(d,newINTEGER(871));
    insertCDAback(d,newINTEGER(325));
    insertCDAback(d,newINTEGER(443));
    insertCDAback(d,newINTEGER(586));
    insertCDAback(d,newINTEGER(97));
    insertCDAback(d,newINTEGER(600));
    insertCDAback(d,newINTEGER(153));
    insertCDAback(d,newINTEGER(315));
    insertCDAback(d,newINTEGER(321));
    insertCDAback(d,newINTEGER(331));
    insertCDAback(d,newINTEGER(526));
    insertCDAback(d,newINTEGER(865));
    insertCDAback(d,newINTEGER(720));
    insertCDAback(d,newINTEGER(178));
    insertCDAback(d,newINTEGER(746));
    insertCDAback(d,newINTEGER(570));
    insertCDAback(d,newINTEGER(736));
    insertCDAback(d,newINTEGER(504));
    insertCDAback(d,newINTEGER(963));
    insertCDAback(d,newINTEGER(788));
    insertCDAback(d,newINTEGER(504));
    insertCDAback(d,newINTEGER(749));
    insertCDAback(d,newINTEGER(884));
    insertCDAback(d,newINTEGER(961));
    insertCDAback(d,newINTEGER(392));
    insertCDAback(d,newINTEGER(257));
    insertCDAback(d,newINTEGER(230));
    insertCDAback(d,newINTEGER(213));
    insertCDAback(d,newINTEGER(934));
    insertCDAback(d,newINTEGER(530));
    insertCDAback(d,newINTEGER(112));
    insertCDAback(d,newINTEGER(806));
    insertCDAback(d,newINTEGER(855));
    insertCDAback(d,newINTEGER(907));
    insertCDAback(d,newINTEGER(744));
    printf("array d:");
    visualizeCDA(stdout,d);
    printf("\n");
    void *x = 0;
    x = getCDA(d,sizeCDA(d)-1);
    printf("last element is ");
    displayINTEGER(stdout,x);
    printf("\n");
    void *y = 0;
    y = getCDA(d,0);
    printf("first element is ");
    displayINTEGER(stdout,y);
    printf("\n");
    printf("swapping first and last elements\n");
    x = setCDA(d,0,x);
    y = setCDA(d,sizeCDA(d)-1,y);
    printf("array d:");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("setting the first available slot\n");
    y = setCDA(d,sizeCDA(d),newINTEGER(953));
    printf("array d:");
    visualizeCDA(stdout,d);
    printf("\n");
    return 0;
    }
