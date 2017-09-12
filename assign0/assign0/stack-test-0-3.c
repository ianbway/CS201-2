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
    printf("STACK tester: 0,3\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/stack-test-0-3.c\n");
    printf("\noutput:\n\n");
    STACK *d = newSTACK(displayINTEGER);
    void *p;
    printf("pushing items onto stack d\n");
    push(d,newINTEGER(83));
    push(d,newINTEGER(274));
    push(d,newINTEGER(326));
    push(d,newINTEGER(363));
    push(d,newINTEGER(537));
    push(d,newINTEGER(25));
    push(d,newINTEGER(363));
    push(d,newINTEGER(28));
    push(d,newINTEGER(385));
    push(d,newINTEGER(544));
    push(d,newINTEGER(954));
    push(d,newINTEGER(714));
    push(d,newINTEGER(964));
    push(d,newINTEGER(403));
    push(d,newINTEGER(414));
    push(d,newINTEGER(902));
    push(d,newINTEGER(941));
    push(d,newINTEGER(401));
    push(d,newINTEGER(149));
    push(d,newINTEGER(717));
    push(d,newINTEGER(604));
    printf("stack d: ");
    displaySTACK(stdout,d);
    printf("\n");
    printf("peeking into stack d\n");
    p = peekSTACK(d);
    printf("the next element to come off the stack: ");
    displayINTEGER(stdout,p);
    printf("\n");
    printf("popping all but one item from stack d\n");
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    p = pop(d);
    printf("stack d: ");
    displaySTACK(stdout,d);
    printf("\n");
    printf("popping the last item from stack d\n");
    p = pop(d);
    printf("stack d: ");
    displaySTACK(stdout,d);
    printf("\n");
    printf("pushing one item into stack d\n");
    push(d,newINTEGER(968));
    printf("popping that item\n");
    p = pop(d);
    printf("stack d: ");
    displaySTACK(stdout,d);
    printf("\n");
    printf("last element popped: ");
    displayINTEGER(stdout,p);
    printf("\n");
    return 0;
    }
