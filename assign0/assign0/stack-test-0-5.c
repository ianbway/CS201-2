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
    printf("STACK tester: 0,5\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/stack-test-0-5.c\n");
    printf("\noutput:\n\n");
    int count = 0;
    srandom(6);
    STACK *d = newSTACK(displayINTEGER);
    printf("doing a bunch of pushes\n");
    int i;
    for (i = 0; i < 12541; ++i)
        {
        push(d,newINTEGER(random()%1000));
        ++count;
        }
    printf("randomly doing a bunch of pushes and pops\n");
    void *p;
    for (i = 0; i < 12541; ++i)
        {
        if (random() % 2 == 0)
            {
            push(d,newINTEGER(random()%1000));
            ++count;
            }
        else if (count > 0)
            {
            p = pop(d);
            --count;
            }
        }
    printf("doing a bunch of pops\n");
    while (count > 10)
        {
        pop(d);
        --count;
        }
    printf("stack d:");
    displaySTACK(stdout,d);
    printf("\n");
    printf("the last element popped: ");
    displayINTEGER(stdout,p);
    printf("\n");
    return 0;
    }
