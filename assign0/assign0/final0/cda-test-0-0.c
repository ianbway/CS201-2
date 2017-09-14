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
    printf("CDA tester: 0,0\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-0-0.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    insertCDAfront(d,newINTEGER(886));
    insertCDAfront(d,newINTEGER(777));
    insertCDAfront(d,newINTEGER(915));
    insertCDAfront(d,newINTEGER(793));
    insertCDAfront(d,newINTEGER(335));
    insertCDAfront(d,newINTEGER(386));
    insertCDAfront(d,newINTEGER(492));
    insertCDAfront(d,newINTEGER(649));
    displayCDA(stdout,d);
    printf("\n");
    return 0;
    }
