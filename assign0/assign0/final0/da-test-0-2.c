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
    printf("DA tester: 0,2\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-0-2.c\n");
    printf("\noutput:\n\n");
    /*DA *d = newDA(displaySTRING);
    insertDA(d,newSTRING("VWQ"));
    insertDA(d,newSTRING("TYS"));
    insertDA(d,newSTRING("KRG"));
    insertDA(d,newSTRING("SED"));
    insertDA(d,newSTRING("LWP"));
    insertDA(d,newSTRING("MVF"));
    visualizeDA(stdout,d);*/
    printf("\n");
    return 0;
    }
