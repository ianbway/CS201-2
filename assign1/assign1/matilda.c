// Ian Braudaway
// main matilda program for assignment 1

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include "scanner.h"
#include "bst.h"
#include "stack.h"
#include "queue.h"
#include "integer.h"
#include "real.h"
#include "string.h"

/* options */
//int Special = 0;    /* option -s      */
//int Number = 0;     /* option -n XXXX */
//char* Name = 0;     /* option -N YYYY */

int authorFlag = 0;    /* option -v      */
int inputFlag = 0;    /* option -i      */
int postfixFlag = 0;    /* option -p      */
int bstFlag = 0;    /* option -b      */

static int processOptions(int, char **);
void Fatal(char *, ...);
void printAuthor();

int
main(int argc, char **argv)
{
	int argIndex;

	if ((argc == 1) && (authorFlag == 0)) Fatal("%d arguments!\n", argc - 1);

	argIndex = processOptions(argc, argv);

	//printf("Special is %s\n", Special == 0 ? "false" : "true");
	//printf("Number is %d\n", Number);
	//printf("Name is %s\n", Name == 0 ? "missing" : Name);

	printf("authorFlag is %s\n", authorFlag == 0 ? "false" : "true");
	printf("inputFlag is %s\n", inputFlag == 0 ? "false" : "true");
	printf("postfixFlag is %s\n", postfixFlag == 0 ? "false" : "true");
	printf("bstFlag is %s\n", bstFlag == 0 ? "false" : "true");

	if (argIndex == argc)
		printf("No arguments\n");
	else
	{
		int i;
		printf("Remaining arguments:\n");
		for (i = argIndex; i < argc; ++i)
			printf("    %s\n", argv[i]);
	}

	return 0;
}

void
Fatal(char *fmt, ...)
{
	va_list ap;

	fprintf(stderr, "An error occured: ");
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	exit(-1);
}

/* only -oXXX  or -o XXX options */

static int
processOptions(int argc, char **argv)
{
	int argIndex;
	int argUsed;
	int separateArg;
	char *arg;

	argIndex = 1;

	while (argIndex < argc && *argv[argIndex] == '-')
	{
		/* check if stdin, represented by "-" is an argument */
		/* if so, the end of options has been reached */
		if (argv[argIndex][1] == '\0') return argIndex;

		separateArg = 0;
		argUsed = 0;

		if (argv[argIndex][2] == '\0')
		{
			arg = argv[argIndex + 1];
			separateArg = 1;
		}
		else
			arg = argv[argIndex] + 2;

		switch (argv[argIndex][1])
		{
			/*
			* when option has an argument, do this
			*
			*     examples are -m4096 or -m 4096
			*
			*     case 'm':
			*         MemorySize = atol(arg);
			*         argUsed = 1;
			*         break;
			*
			*
			* when option does not have an argument, do this
			*
			*     example is -a
			*
			*     case 'a':
			*         PrintActions = 1;
			*         break;
			*/

		//case 'n':
		//	Number = atoi(arg);
		//	argUsed = 1;
		//	break;
		case 'v':
			authorFlag = 1;
			printAuthor();
			break;
		//case 'N':
		//	Name = strdup(arg);
		//	argUsed = 1;
		//	break;
		default:
			Fatal("option %s not understood\n", argv[argIndex]);
		}

		if (separateArg && argUsed)
			++argIndex;

		++argIndex;
	}

	return argIndex;
}

void
printAuthor()
{
	//give author's name and exit
	printf("Ian W. Braudaway\n");
}