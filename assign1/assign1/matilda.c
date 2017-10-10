// Ian Braudaway
// main matilda program for assignment 1

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

void
displayMATILDA(FILE *fp, void* key, void* value)
{
	displaySTRING(fp, key);
	fprintf(fp, "=");
	displayREAL(fp, value);
}

int main(int argc, char **argv)
{
	int argIndex = 1; //default to 1 in order to skip executable
	char *arg;
	char *fileName = 0;
	int printAuthorOption = 0;
	int originalInputOption = 0;
	int postfixConvertOption = 0;
	int bstPrintOption = 0;
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
				originalInputOption = 1;
				break;
			case 'p':
				postfixConvertOption = 1;
				break;
			case 'b':
				bstPrintOption = 1;
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
		//give author's name and exit
		printAuthor();
		return 0;
	}

	if (originalInputOption)
	{
		//print the original input to evaluating the expression
		originalInput();
		if (postfixConvertOption == 0 && bstPrintOption == 0)
		{
			return 0;
		}
	}

	if (postfixConvertOption)
	{
		//print the postfix conversion of the last infix expression
		//before evaluating the expression
		postfixConvert();
		if (bstPrintOption == 0)
		{
			return 0;
		}
	}

	if (bstPrintOption)
	{
		//print the BST holding variable values
		//before evaluating the expression
		bstPrint();
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

	processFile(input, type);

	return 0;
}

void 
printAuthor()
{
	//give author's name and exit
	printf("Ian W. Braudaway\n");
}

void
originalInput() 
{
	//print the original input to evaluating the expression
}

void
postfixConvert()
{
	//print the postfix conversion of the last infix expression
	//before evaluating the expression
}

void
bstPrint(FILE *output, BST *bst)
{
	//print the BST holding variable values
	//before evaluating the expression
	displayBST(output, bst);
}

void
processFile(FILE *input, char type)
{

	BST *bst = newBST(displayMATILDA, compareSTRING);

	FILE *file = fopen( "r", input);

	while (readToken(file) != 0)
	{
		char *token = readToken(file);
		if (token == "var")
		{
			insertBST(bst, readToken(file), readToken(file));
		}
	}

}