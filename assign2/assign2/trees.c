// Ian Braudaway
// assign2 main file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bst.h"
#include "gt.h"
#include "rbt.h"
#include "scanner.h"
#include "string.h"

/* options */
int insertFlag = 0;    /* option -i WORD */
int deleteFlag = 0;    /* option -d WORD */
int freqFlag = 0;    /* option -f WORD */
int showFlag = 0;    /* option -s */
int statsFlag = 0;    /* option -r */

static int processOptions(int, char **);
void Fatal(char *, ...);

int
main(int argc, char **argv)
{
	int argIndex;

	// Executable must have arguments
	if (argc == 1) Fatal("%d arguments!\n", argc - 1);

	// Process the options given, could have multiple. i, p, or b.
	argIndex = processOptions(argc, argv);

	// If a valid option is given but there is no filename afterwards to read input from we cannot proceed.
	if (argv[argIndex] == 0)
	{
		printf("Must have filename after option.\n");
		return 0;
	}

	// If flag for -i option, insert 
	if (insertFlag == 1)
	{
		// do insert thing
	}

	// If flag for -d option, delete
	if (deleteFlag == 1)
	{
		// do delete thing
	}

	// If flag for -f option, frequency
	if (freqFlag == 1)
	{
		// do frequency thing
	}

	// If flag for -s option, show tree
	if (showFlag == 1)
	{
		// do show thing
	}

	// If flag for -r option, report statistics
	if (statsFlag == 1)
	{
		// do stats thing
	}

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

static int
processOptions(int argc, char **argv)
{
	int argIndex;
	int argUsed;
	int separateArg;

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
			separateArg = 1;
		}

		switch (argv[argIndex][1])
		{

		case 'i':
			insertFlag = 1;
			break;
		case 'd':
			deleteFlag = 1;
			break;
		case 'f':
			freqFlag = 1;
			break;
		case 's':
			showFlag = 1;
			break;
		case 'r':
			statsFlag = 1;
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