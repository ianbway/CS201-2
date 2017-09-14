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
    printf("DA tester: 0,1\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-0-1.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayREAL);
    insertDA(d,newREAL(7.19));
    insertDA(d,newREAL(7.88));
    insertDA(d,newREAL(5.75));
    insertDA(d,newREAL(0.61));
    insertDA(d,newREAL(4.98));
    visualizeDA(stdout,d);
    printf("\n");
    return 0;
    }
