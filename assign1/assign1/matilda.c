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

int main(int argc, char **argv)
{
	int argIndex = 1; //default to 1 in order to skip executable
	char *arg;
	char *fileName = 0;
	int printAuthorOption = 0;
	Comparator cmp = 0;
	Printer prt = 0;
	char type;
	FILE *input;

	while (argIndex < argc)
	{
		arg = argv[argIndex];

		if (arg[0] == '-')
		{
			// get char after hyphen
			type = arg[1];
			switch (type)
			{
			case 'v':
				printAuthorOption = 1;
				break;
			case 'i':
				break;
			case 'p':
				break;
			case 'b':
				break;
			default:
				Fatal("unknown flag '%s', valid flags are -i, -p, -b and -v\n", arg);
			}
		}
		else
		{
			fileName = arg; // assume filename
		}

		++argIndex;
	}

	if (printAuthorOption)
	{
		printAuthor();
		return 0;
	}

	if (fileName)
	{
		input = fopen(fileName, "r");
		if (input == NULL)
		{
			Fatal("could not open %s file\n", fileName);
		}
	}
	else
	{
		input = stdin;
	}

	processFile(input, type, cmp, prt);

	return 0;
}

void 
printAuthor()
{
	printf("Ian W. Braudaway\n");
}

void
displayMATILDA(FILE *fp, void* key, void* value)
{
	displaySTRING(fp, key);
	fprintf(fp, "=");
	displayREAL(fp, value);
}
