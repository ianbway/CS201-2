#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "integer.h"
#include "real.h"
#include "string.h"
extern long random(void);
extern void srandom(unsigned int seed);

int
main(void)
    {
    printf("STACK tester: 0,2\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/stack-test-0-2.c\n");
    printf("\noutput:\n\n");
    /*STACK *d = newSTACK(displaySTRING);
    push(d,newSTRING("VWQ"));
    push(d,newSTRING("TYS"));
    push(d,newSTRING("KRG"));
    push(d,newSTRING("SED"));
    push(d,newSTRING("LWP"));
    push(d,newSTRING("MVF"));
    displaySTACK(stdout,d);*/
    printf("\n");
    return 0;
    }
