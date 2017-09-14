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
    printf("CDA tester: 0,1\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-0-1.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayREAL);
    insertCDAback(d,newREAL(7.19));
    insertCDAback(d,newREAL(7.88));
    insertCDAback(d,newREAL(5.75));
    insertCDAback(d,newREAL(0.61));
    insertCDAback(d,newREAL(4.98));
    displayCDA(stdout,d);
    printf("\n");
    return 0;
    }
