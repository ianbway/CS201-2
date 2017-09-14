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
    printf("QUEUE tester: 0,3\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/queue-test-0-3.c\n");
    printf("\noutput:\n\n");
    QUEUE *d = newQUEUE(displayINTEGER);
    void *p;
    printf("enqueuing items onto queue d\n");
    enqueue(d,newINTEGER(83));
    enqueue(d,newINTEGER(274));
    enqueue(d,newINTEGER(326));
    enqueue(d,newINTEGER(363));
    enqueue(d,newINTEGER(537));
    enqueue(d,newINTEGER(25));
    enqueue(d,newINTEGER(363));
    enqueue(d,newINTEGER(28));
    enqueue(d,newINTEGER(385));
    enqueue(d,newINTEGER(544));
    enqueue(d,newINTEGER(954));
    enqueue(d,newINTEGER(714));
    enqueue(d,newINTEGER(964));
    enqueue(d,newINTEGER(403));
    enqueue(d,newINTEGER(414));
    enqueue(d,newINTEGER(902));
    enqueue(d,newINTEGER(941));
    enqueue(d,newINTEGER(401));
    enqueue(d,newINTEGER(149));
    enqueue(d,newINTEGER(717));
    enqueue(d,newINTEGER(604));
    printf("queue d: ");
    displayQUEUE(stdout,d);
    printf("\n");
    printf("peeking into queue d\n");
    p = peekQUEUE(d);
    printf("the next element to come off the queue: ");
    displayINTEGER(stdout,p);
    printf("\n");
    printf("dequeuing all but one item from queue d\n");
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    p = dequeue(d);
    printf("queue d: ");
    displayQUEUE(stdout,d);
    printf("\n");
    printf("dequeuing the last item from queue d\n");
    p = dequeue(d);
    printf("queue d: ");
    displayQUEUE(stdout,d);
    printf("\n");
    printf("enqueuing one item into queue d\n");
    enqueue(d,newINTEGER(968));
    printf("dequeuing that item\n");
    p = dequeue(d);
    printf("queue d: ");
    displayQUEUE(stdout,d);
    printf("\n");
    printf("last element dequeued: ");
    displayINTEGER(stdout,p);
    printf("\n");
    return 0;
    }
