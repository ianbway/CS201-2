#include <stdio.h>
#include <stdlib.h>
#include "da.h"
#include "integer.h"
#include "real.h"
#include "string.h"

int
main(void)
    {
    printf("DA tester: 0,3\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/da-test-0-3.c\n");
    printf("\noutput:\n\n");
    DA *d = newDA(displayINTEGER);
    insertDA(d,newINTEGER(83));
    insertDA(d,newINTEGER(326));
    insertDA(d,newINTEGER(537));
    insertDA(d,newINTEGER(363));
    insertDA(d,newINTEGER(385));
    insertDA(d,newINTEGER(954));
    insertDA(d,newINTEGER(964));
    insertDA(d,newINTEGER(414));
    displayDA(stdout,d);
    printf("\n");
    printf("removing all but one item from array d\n");
    int i;
    for(i=0, i<sizeDA(d) - 1, ++i)
    {
        removeDA(d);
    }
    displayDA(stdout,d);
    printf("\n");
    printf("removing the last item from array d");
    removeDA(d);
    displayDA(stdout,d);
    printf("\n");
    printf("inserting one item into array d\n");
    insertDA(d, newINTEGER(968));
    displayDA(stdout,d);
    printf("\n");
    printf("removing that item\n");
    removeDA(d);
    displayDA(stdout,d);
    return 0;
    }
