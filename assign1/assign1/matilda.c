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

int inputFlag = 0;    /* option -i FILENAME */
int postfixFlag = 0;    /* option -p FILENAME */
int bstFlag = 0;    /* option -b FILENAME */

static int processOptions(int, char **);
void Fatal(char *, ...);
QUEUE *processFile(char *);
void displayMATILDA(FILE*, void*, void*);
void printBST(BST *tree);


int
main(int argc, char **argv)
{
	int argIndex;
	BST *varDeclarations;

	// Executable must have arguments
	if (argc == 1) Fatal("%d arguments!\n", argc - 1);

	// Before doing anything, check to see if name argument exists and print that out, exiting program.
	if (strcmp(argv[1], "-v") == 0)
	{
		printf("Ian W. Braudaway\n");
		return 0;
	}

	// Process the options given, could have multiple. i, p, or b.
	argIndex = processOptions(argc, argv);
	
	// If a valid option is given but there is no filename afterwards to read input from we cannot proceed.
	if (argv[argIndex] == 0) 
	{
		printf("Must have filename after option.\n");
		return 0;
	}

	QUEUE *inputQueue = processFile(argv[argIndex]);
	
	//if (bstFlag == 1)
	//{
	//	printBST(varDeclarations);
	//}

	//printf("Special is %s\n", Special == 0 ? "false" : "true");
	//printf("Number is %d\n", Number);
	//printf("Name is %s\n", Name == 0 ? "missing" : Name);

	printf("inputFlag is %s\n", inputFlag == 0 ? "false" : "true");
	printf("postfixFlag is %s\n", postfixFlag == 0 ? "false" : "true");
	printf("bstFlag is %s\n", bstFlag == 0 ? "false" : "true");

	if (argc - argIndex > 1)
	{
		int i;
		printf("Too many arguments:\n");
		for (i = argIndex + 1; i < argc; ++i)
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

		case 'i':
			inputFlag = 1;
			break;
		case 'p':
			postfixFlag = 1;
			break;
		case 'b':
			bstFlag = 1;
			break;

		default:
			Fatal("option %s not understood\n", argv[argIndex]);
		}

		if (separateArg && argUsed)
			++argIndex;

		++argIndex;
	}

	return argIndex;
}

QUEUE *
processFile(char *file)
{
	FILE *input = fopen(file, "r");
	// Does file even exist.
	if (input == NULL)
	{
		Fatal("Could not open %s file.\n", input);
	}

	QUEUE *inputQueue = newQUEUE(NULL);
	char *token = readToken(input);

	while ((!feof(input)))
	{
		printf("Token is: %s.\n", token);
		enqueue(inputQueue, token);
		token = readToken(input);
	}

	fclose(input);

	return inputQueue;
}

void
displayMATILDA(FILE *fp, void *key, void *value)
{
	displaySTRING(fp, key);
	fprintf(fp, "=");
	displayREAL(fp, value);
}

void
printBST(BST *tree)
{
	displayBST(stdout, tree);
}