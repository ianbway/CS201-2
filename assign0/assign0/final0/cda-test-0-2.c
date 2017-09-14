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
    printf("CDA tester: 0,2\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-0-2.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displaySTRING);
    insertCDAfront(d,newSTRING("VWQ"));
    insertCDAfront(d,newSTRING("TYS"));
    insertCDAfront(d,newSTRING("KRG"));
    insertCDAfront(d,newSTRING("SED"));
    insertCDAfront(d,newSTRING("LWP"));
    insertCDAfront(d,newSTRING("MVF"));
    visualizeCDA(stdout,d);
    printf("\n");
    return 0;
    }
