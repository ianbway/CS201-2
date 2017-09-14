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
    printf("DA tester: 0,0\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-0-0.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayINTEGER);
    insertDA(d,newINTEGER(886));
    insertDA(d,newINTEGER(777));
    insertDA(d,newINTEGER(915));
    insertDA(d,newINTEGER(793));
    insertDA(d,newINTEGER(335));
    insertDA(d,newINTEGER(386));
    insertDA(d,newINTEGER(492));
    insertDA(d,newINTEGER(649));
    displayDA(stdout,d);
    printf("\n");
    return 0;
    }
