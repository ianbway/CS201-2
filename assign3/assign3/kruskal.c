#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>
#include "da.h"
#include "queue.h"
#include "rbt.h"
#include "set.h"
#include "string.h"
#include "integer.h"
#include "real.h"
#include "scanner.h"

//static int processOptions(int, char **);
void Fatal(char *, ...);

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

	// Process the options given, could have multiple. i, p, or b.
	//argIndex = processOptions(argc, argv);
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