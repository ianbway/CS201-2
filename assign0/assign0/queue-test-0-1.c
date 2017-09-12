#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "integer.h"
#include "real.h"
#include "string.h"
extern long random(void);
extern void srandom(unsigned int seed);

int
main(void)
    {
    printf("QUEUE tester: 0,1\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/queue-test-0-1.c\n");
    printf("\noutput:\n\n");
    QUEUE *d = newQUEUE(displayREAL);
    enqueue(d,newREAL(7.19));
    enqueue(d,newREAL(7.88));
    enqueue(d,newREAL(5.75));
    enqueue(d,newREAL(0.61));
    enqueue(d,newREAL(4.98));
    printf("trying the visualizer (should call displayCDA)\n");
    visualizeQUEUE(stdout,d);
    printf("\n");
    return 0;
    }
