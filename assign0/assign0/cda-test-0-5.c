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
    printf("CDA tester: 0,5\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-0-5.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    insertCDAback(d,newINTEGER(985));
    insertCDAback(d,newINTEGER(112));
    insertCDAback(d,newINTEGER(665));
    insertCDAback(d,newINTEGER(308));
    insertCDAback(d,newINTEGER(285));
    insertCDAback(d,newINTEGER(286));
    insertCDAback(d,newINTEGER(43));
    insertCDAback(d,newINTEGER(2));
    insertCDAback(d,newINTEGER(778));
    insertCDAback(d,newINTEGER(935));
    insertCDAback(d,newINTEGER(323));
    insertCDAback(d,newINTEGER(605));
    insertCDAback(d,newINTEGER(93));
    insertCDAback(d,newINTEGER(842));
    insertCDAback(d,newINTEGER(616));
    insertCDAback(d,newINTEGER(400));
    insertCDAback(d,newINTEGER(92));
    insertCDAback(d,newINTEGER(23));
    insertCDAback(d,newINTEGER(944));
    insertCDAback(d,newINTEGER(951));
    insertCDAback(d,newINTEGER(270));
    printf("array d:");
    visualizeCDA(stdout,d);
    printf("\n");
    CDA *e = newCDA(displayINTEGER);
    insertCDAfront(e,newINTEGER(540));
    insertCDAfront(e,newINTEGER(622));
    insertCDAfront(e,newINTEGER(189));
    insertCDAfront(e,newINTEGER(11));
    insertCDAfront(e,newINTEGER(620));
    insertCDAfront(e,newINTEGER(28));
    insertCDAfront(e,newINTEGER(557));
    insertCDAfront(e,newINTEGER(575));
    insertCDAfront(e,newINTEGER(455));
    insertCDAfront(e,newINTEGER(450));
    insertCDAfront(e,newINTEGER(912));
    insertCDAfront(e,newINTEGER(919));
    insertCDAfront(e,newINTEGER(116));
    insertCDAfront(e,newINTEGER(221));
    insertCDAfront(e,newINTEGER(556));
    insertCDAfront(e,newINTEGER(754));
    insertCDAfront(e,newINTEGER(616));
    insertCDAfront(e,newINTEGER(559));
    insertCDAfront(e,newINTEGER(885));
    insertCDAfront(e,newINTEGER(552));
    insertCDAfront(e,newINTEGER(234));
    insertCDAfront(e,newINTEGER(842));
    insertCDAfront(e,newINTEGER(997));
    insertCDAfront(e,newINTEGER(76));
    insertCDAfront(e,newINTEGER(459));
    insertCDAfront(e,newINTEGER(398));
    insertCDAfront(e,newINTEGER(169));
    insertCDAfront(e,newINTEGER(482));
    insertCDAfront(e,newINTEGER(694));
    insertCDAfront(e,newINTEGER(472));
    insertCDAfront(e,newINTEGER(104));
    insertCDAfront(e,newINTEGER(587));
    insertCDAfront(e,newINTEGER(94));
    insertCDAfront(e,newINTEGER(293));
    insertCDAfront(e,newINTEGER(598));
    insertCDAfront(e,newINTEGER(66));
    insertCDAfront(e,newINTEGER(673));
    insertCDAfront(e,newINTEGER(508));
    insertCDAfront(e,newINTEGER(641));
    insertCDAfront(e,newINTEGER(128));
    insertCDAfront(e,newINTEGER(958));
    insertCDAfront(e,newINTEGER(906));
    printf("array e:");
    visualizeCDA(stdout,e);
    printf("\n");
    printf("performing unionCDA(d,e)\n");
    unionCDA(d,e);
    printf("\n");
    printf("array d: ");
    displayCDA(stdout,d);
    printf("\n");
    printf("array e: ");
    displayCDA(stdout,e);
    printf("\n");
    printf("performing unionCDA(d,e)\n");
    unionCDA(d,e);
    printf("\n");
    printf("array d: ");
    displayCDA(stdout,d);
    printf("\n");
    printf("array e: ");
    displayCDA(stdout,e);
    printf("\n");
    printf("performing unionCDA(e,d)\n");
    unionCDA(e,d);
    printf("\n");
    printf("array d: ");
    displayCDA(stdout,d);
    printf("\n");
    printf("array e: ");
    displayCDA(stdout,e);
    printf("\n");
    return 0;
    }
