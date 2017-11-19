// Ian Braudaway
// assign2 main file
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include "bst.h"
#include "gt.h"
#include "rbt.h"
#include "scanner.h"
#include "string.h"

/* options */
int greenFlag = 0;
int redFlag = 0;

/* command i WORD */
/* command d WORD */
/* command f WORD */
/* command s */
/* command r */

static int processOptions(int, char **);
void Fatal(char *, ...);
GT *processFileGT(FILE *);
RBT *processFileRBT(FILE *);
void processCommandsGT(GT *, FILE *, FILE *);
void processCommandsRBT(RBT *, FILE *, FILE *);
static char *clean(char*);

int
main(int argc, char **argv)
{
	int argIndex;

	// Executable must have arguments
	if (argc == 1) Fatal("%d arguments!\n", argc - 1);

	// Before doing anything, check to see if name argument exists and print that out, exiting program.
	if (strcmp(argv[1], "-v") == 0)
	{
		printf("Ian W. Braudaway\n");
		return 0;
	}

	// Process the option given. g or r.
	argIndex = processOptions(argc, argv);

	// If a valid option is given but there is no filename afterwards to read input from we cannot proceed.
	if (argv[argIndex] == 0)
	{
		printf("Must have filename after option.\n");
		return 0;
	}

	// Open and set up files before flag checks
	FILE *corpus = fopen(argv[argIndex], "r");
	FILE *commands = fopen(argv[argIndex + 1], "r");
	FILE *outputfile;

	if (argv[argIndex + 2] != NULL)
	{
		outputfile = fopen(argv[argIndex + 2], "w");
	}

	else
	{
		outputfile = NULL;
	}

	// If flag for -g option, we are using a green tree 
	if (greenFlag == 1)
	{
		GT *tree = processFileGT(corpus);
		processCommandsGT(tree, commands, outputfile);
	}

	// If flag for -r option, we are using a red-black tree
	if (redFlag == 1)
	{
		RBT *tree = processFileRBT(corpus);
		processCommandsRBT(tree, commands, outputfile);
	}

	// Neither flag, so use rbt
	if ((redFlag == 0) && (greenFlag == 0))
	{
		RBT *tree = processFileRBT(corpus);
		processCommandsRBT(tree, commands, outputfile);
	}


	if (argc - argIndex > 2)
	{
		int i;
		printf("Too many arguments:\n");
		for (i = argIndex + 2; i < argc; ++i)
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

		case 'g':
			greenFlag = 1;
			break;
		case 'r':
			redFlag = 1;
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

GT *
processFileGT(FILE *file)
{
	if (file == NULL)
	{
		Fatal("Could not open %s file.\n", file);
	}

	GT *inputGT = newGT(displaySTRING, compareSTRING);
	char *token = clean(readToken(file));

	while (token)
	{
		insertGT(inputGT, newSTRING(token));
		token = clean(readToken(file));
	}

	return inputGT;
}

RBT *
processFileRBT(FILE *file)
{
	if (file == NULL)
	{
		Fatal("Could not open %s file.\n", file);
	}

	RBT *inputRBT = newRBT(displaySTRING, compareSTRING);
	char *token = clean(readToken(file));

	while (token)
	{
		insertRBT(inputRBT, newSTRING(token));
		token = clean(readToken(file));
	}

	return inputRBT;
}

void processCommandsGT(GT *tree, FILE *file, FILE *output)
{
	if (file == NULL)
	{
		Fatal("Could not open %s file.\n", file);
	}

	if (output == NULL)
	{
		output = stdout;
	}

	char *token = clean(readToken(file));

	while (token)
	{
		// insert word or phrase W into the tree
		if (compareSTRING(token, "i") == 0)
		{
			char *token = clean(readToken(file));
			insertGT(tree, token);
		}

		// delete word or phrase W from the tree
		else if (compareSTRING(token, "d") == 0)
		{
			char *token = clean(readToken(file));
			deleteGT(tree, token);
		}

		// report the frequency of word or phrase W
		else if (compareSTRING(token, "f") == 0)
		{
			char *token = clean(readToken(file));
			int frequency = findGT(tree, token);
			fprintf(output, "Frequency of %s: %d\n", token, frequency);
		}

		// show the tree
		else if (compareSTRING(token, "s") == 0)
		{
			displayGT(output, tree);
		}

		// report statistics
		else
		{
			statisticsGT(output, tree);
		}

		token = clean(readToken(file));
	}
}

void processCommandsRBT(RBT *tree, FILE *file, FILE *output)
{
	if (file == NULL)
	{
		Fatal("Could not open %s file.\n", file);
	}

	if (output == NULL)
	{
		output = stdout;
	}

	char *token = clean(readToken(file));

	while (token)
	{
		// insert word or phrase W into the tree
		if (compareSTRING(token, "i") == 0)
		{
			char *token = clean(readToken(file));
			insertRBT(tree, token);
		}

		// delete word or phrase W from the tree
		else if (compareSTRING(token, "d") == 0)
		{
			char *token = clean(readToken(file));
			deleteRBT(tree, token);
		}

		// report the frequency of word or phrase W
		else if (compareSTRING(token, "f") == 0)
		{
			char *token = clean(readToken(file));
			int frequency = findRBT(tree, token);
			fprintf(output, "Frequency of %s: %d\n", token, frequency);
		}

		// show the tree
		else if (compareSTRING(token, "s") == 0)
		{
			displayRBT(output, tree);
		}

		// report statistics
		else
		{
			statisticsRBT(output, tree);
		}

		token = clean(readToken(file));
	}
}

static char *
clean(char *word) 
{
	if (word == NULL)
	{
		return NULL;
	}

	char *cleanedWord = word;
	int cleanIndex = 0;

	int spaceBefore = 0;
	int beginningLetter = 0;
	int i;
	for (i = 0; strlen(word); i++)
	{
		if (word[i] == '\0')
		{
			break;
		}

		else if (isalpha(word[i])) 
		{
			if ((beginningLetter == 0))
			{
				beginningLetter = 1;
				cleanedWord[cleanIndex] = word[i];
				cleanIndex++;
			}

			else
			{
				spaceBefore = 0;
				cleanedWord[cleanIndex] = word[i];
				cleanIndex++;
			}
		}

		else if (isspace(word[i]))
		{
			if (spaceBefore == 0)
			{
				spaceBefore = 1;
				cleanedWord[cleanIndex] = ' ';
				cleanIndex++;
			}
		}

		else
		{
			cleanedWord[i] = ' ';
		}
	}

	if (cleanIndex == 0)
	{
		return NULL;
	}

	if (isspace(cleanedWord[cleanIndex - 1]))
	{
		cleanedWord[cleanIndex - 1] = '\0';
	}

	else
	{
		cleanedWord[cleanIndex] = '\0';
	}
	
	return cleanedWord;
}