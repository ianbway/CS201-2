#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "scanner.h"
#include "bst.h"
#include "stack.h"
#include "queue.h"
#include "integer.h"
#include "real.h"
#include "string.h"

int
main(int argc, char **argv)
{

	if (argc < 1)
	{
		printf("not enough args");
	}

	char *input = argv[1];
	FILE *file = fopen("r", input);

	QUEUE *tokenQueue = newQUEUE(displaySTRING);

	while (!feof(readToken(file)))
	{
		char *token = readToken(file);
		enqueue(tokenQueue, token);
	}

	displayQUEUE(stdout, tokenQueue);

	return 0;
}