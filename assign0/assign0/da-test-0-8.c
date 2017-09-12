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
    printf("DA tester: 0,8\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-0-8.c\n");
    printf("\noutput:\n\n");
    int count = 0;
    srandom(9);
    DA *d = newDA(displayINTEGER);
    printf("doing a bunch of inserts\n");
    int i;
    for (i = 0; i < 14915; ++i)
        {
        insertDA(d,newINTEGER(random()%1000));
        ++count;
        }
    printf("randomly doing a bunch of inserts and deletes\n");
    void *p = 0;
    for (i = 0; i < 14915; ++i)
        {
        if (random() % 2 == 0)
            {
            insertDA(d,newINTEGER(random()%1000));
            ++count;
            }
        else if (count > 0)
            {
            p = removeDA(d);
            --count;
            }
        }
    printf("doing a bunch of removes\n");
    while (count > 10)
        {
        p = removeDA(d);
        --count;
        }
    printf("array d:");
    visualizeDA(stdout,d);
    printf("\n");
    printf("the last element removed: ");
    displayINTEGER(stdout,p);
    printf("\n");
    return 0;
    }
