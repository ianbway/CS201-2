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
    printf("CDA tester: 0,4\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-0-4.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    void *p = 0;
    printf("inserting items into array d\n");
    insertCDAback(d,newINTEGER(610));
    insertCDAfront(d,newINTEGER(276));
    insertCDAfront(d,newINTEGER(920));
    insertCDAback(d,newINTEGER(73));
    insertCDAback(d,newINTEGER(26));
    insertCDAfront(d,newINTEGER(860));
    insertCDAfront(d,newINTEGER(410));
    insertCDAfront(d,newINTEGER(20));
    insertCDAfront(d,newINTEGER(828));
    insertCDAfront(d,newINTEGER(414));
    insertCDAback(d,newINTEGER(679));
    insertCDAback(d,newINTEGER(331));
    insertCDAfront(d,newINTEGER(383));
    insertCDAback(d,newINTEGER(52));
    insertCDAback(d,newINTEGER(346));
    insertCDAback(d,newINTEGER(84));
    insertCDAfront(d,newINTEGER(799));
    insertCDAback(d,newINTEGER(940));
    insertCDAback(d,newINTEGER(10));
    insertCDAback(d,newINTEGER(453));
    insertCDAback(d,newINTEGER(213));
    insertCDAback(d,newINTEGER(235));
    insertCDAback(d,newINTEGER(37));
    insertCDAback(d,newINTEGER(201));
    insertCDAback(d,newINTEGER(93));
    insertCDAback(d,newINTEGER(222));
    insertCDAback(d,newINTEGER(988));
    insertCDAback(d,newINTEGER(585));
    insertCDAback(d,newINTEGER(427));
    insertCDAback(d,newINTEGER(42));
    insertCDAback(d,newINTEGER(716));
    insertCDAback(d,newINTEGER(433));
    insertCDAfront(d,newINTEGER(488));
    insertCDAback(d,newINTEGER(939));
    insertCDAfront(d,newINTEGER(90));
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("removing all but one item from array d\n");
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("removing the last item from array d\n");
    p = removeCDAback(d);
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("inserting one item into array d\n");
    insertCDAfront(d,newINTEGER(312));
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("removing that item\n");
    p = removeCDAback(d);
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("looking at the last element removed\n");
    printf("last element removed: ");
    displayINTEGER(stdout,p);
    printf("\n");
    return 0;
    }
