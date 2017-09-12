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
    printf("STACK tester: 0,0\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/stack-test-0-0.c\n");
    printf("\noutput:\n\n");
    STACK *d = newSTACK(displayINTEGER);
    push(d,newINTEGER(886));
    push(d,newINTEGER(777));
    push(d,newINTEGER(915));
    push(d,newINTEGER(793));
    push(d,newINTEGER(335));
    push(d,newINTEGER(386));
    push(d,newINTEGER(492));
    push(d,newINTEGER(649));
    displaySTACK(stdout,d);
    printf("\n");
    return 0;
    }
