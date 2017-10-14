// Ian Braudaway
// main matilda program for assignment 1

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
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
QUEUE *processFileIntoQueue(char *);
BST *makeVarBST(char *);
QUEUE *createPostfixQueue(QUEUE *);
double evaluateExpression(QUEUE *, BST *);
void displayMATILDA(FILE*, void*, void*);
static void printInput(char*);
static void printLastPostfix(QUEUE*);
static void printBST(BST *tree);
static int precedence(char*);
STRING *evaluate(double firstVal, double secondVal, char *op);


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
	argIndex = processOptions(argc, argv);
	
	// If a valid option is given but there is no filename afterwards to read input from we cannot proceed.
	if (argv[argIndex] == 0) 
	{
		printf("Must have filename after option.\n");
		return 0;
	}

	QUEUE *inputQueue = processFileIntoQueue(argv[argIndex]);
	BST *varBST = makeVarBST(argv[argIndex]);
	QUEUE *postfixQueue = createPostfixQueue(inputQueue);
	QUEUE *dummyPrintQ = postfixQueue;
	double answer = evaluateExpression(postfixQueue, varBST);

	if (inputFlag == 1)
	{
		printInput(argv[argIndex]);
	}

	if (postfixFlag == 1)
	{
		printLastPostfix(dummyPrintQ);
	}

	if (bstFlag == 1)
	{
		printBST(varBST);
	}

	printf("%s", answer);

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
processFileIntoQueue(char *file)
{
	// This queue will contain the expression, or everything after variable declarations.
	FILE *input = fopen(file, "r");
	// Does file even exist.
	if (input == NULL)
	{
		Fatal("Could not open %s file.\n", input);
	}

	QUEUE *inputQueue = newQUEUE(displaySTRING);
	char *token = readToken(input);

	while (token)
	{
		if (strcmp(token, "var") == 0)
		{
			// We already put the variable declarations from the file into our BST. 
			// So we can skip them when creating input queue.
			token = readToken(input);
			token = readToken(input);
			token = readToken(input);
			token = readToken(input);
			token = readToken(input);
		}
		else 
		{
			enqueue(inputQueue, newSTRING(token));
			token = readToken(input);
		}
		
	}

	displayQUEUE(stdout, inputQueue);
	printf("\n");

	fclose(input);

	return inputQueue;
}

BST *
makeVarBST(char *inputFile)
{
	BST *variableBST = newBST(displayMATILDA, compareSTRING);
	FILE *input = fopen(inputFile, "r");
	STRING *key;
	REAL *val;
	// Does file even exist.
	if (input == NULL)
	{
		Fatal("Could not open %s file.\n", input);
	}
	char *token = readToken(input);
	while (token)
	{
		if (strcmp(token, "var") == 0)
		{
			token = readToken(input);
			key = newSTRING(token);
			readToken(input);
			token = readToken(input);
			val = newREAL(strtod(token,NULL));
			insertBST(variableBST, key, val);
		}
		token = readToken(input);
	}

	fclose(input);

	return variableBST;
}

QUEUE *createPostfixQueue(QUEUE *infixQueue)
{
	STACK* operatorStack = newSTACK(displaySTRING);
	QUEUE* postfixQueue = newQUEUE(displaySTRING);
	
	char *val;

	while (sizeQUEUE(infixQueue) > 0)
	{
		
		val = getSTRING(dequeue(infixQueue));
		
		// Number or variable, add to queue.
		if (isalnum(val[0]))
		{
			enqueue(postfixQueue, newSTRING(val));
		}
		
		// Push open parenthesis on to operator stack.
		else if (strcmp(val, "(") == 0)
		{
			push(operatorStack, newSTRING(val));
		}
		
		// If close parenthesis, pop all operators off of stack
		// up to open parenthesis and put them on postfix queue.
		else if (strcmp(val, ")") == 0)
		{
			if (sizeSTACK(operatorStack) > 0)
			{
				char *op = getSTRING(peekSTACK(operatorStack));
				
				while (strcmp(op, "(") != 0)
				{
					enqueue(postfixQueue, peekSTACK(operatorStack));
					pop(operatorStack);
					op = getSTRING(peekSTACK(operatorStack));
				}
				
				pop(operatorStack);
			}
		}
		
		// Stack is empty and it is an operator, put on stack
		else if ((precedence(val) != -1) && sizeSTACK(operatorStack) == 0)
		{
			push(operatorStack, newSTRING(val));
		}
		
		// Operator on top of stack has higher precedence than one being read,
		// pop from stack and enqueue to postfix queue, then push new symbol.
		// This also covers equality by left association.
		else if ((precedence(val) <= precedence(getSTRING(peekSTACK(operatorStack)))) && (precedence(val) != -1))
		{
			enqueue(postfixQueue, peekSTACK(operatorStack));
			pop(operatorStack);
			push(operatorStack, newSTRING(val));
		}

		// Else value being read has higher precendence than what is on top of stack,
		// so put it on the stack.
		else if ((precedence(val) > precedence(getSTRING(peekSTACK(operatorStack)))) && (precedence(val) != -1))
		{
			push(operatorStack, newSTRING(val));
		}
		
		// Else it is a semicolon. End of expression
		else if (strcmp(val, ";") == 0)
		{
			while (sizeSTACK(operatorStack) > 0)
			{
				enqueue(postfixQueue, peekSTACK(operatorStack));
				pop(operatorStack);
			}
		}
		
		// Else character not defined in spec.
		else
		{
			printf("Unknown character.\n");
		}
	}

	displayQUEUE(stdout, postfixQueue);
	printf("\n");

	return postfixQueue;
}

double 
evaluateExpression(QUEUE *postfixQueue, BST *varTree)
{
	STACK *evaluateStack = newSTACK(displaySTRING);

	while (sizeQUEUE(postfixQueue) > 0)
	{
		// Take val off postfix queue
		// Its a number
		if (getREAL(peekQUEUE(postfixQueue)))
		{
			double val = getREAL(peekQUEUE(postfixQueue));
			push(evaluateStack, newREAL(val));
			dequeue(postfixQueue);
		}
		// Its a string
		else if (getSTRING(peekQUEUE(postfixQueue)))
		{
			char *val = getSTRING(peekQUEUE(postfixQueue));
			// find var value in bst, if not in tree print error
			if (findBST(varTree, val) == NULL) 
			{
				printf("Cannot find variable in tree.\n");
				exit(0);
			}
			double dVal = getREAL(findBST(varTree, val));
			push(evaluateStack, newREAL(dVal));
			dequeue(postfixQueue);
		}

		else if (precedence(val) != -1)
		{
			char *firstVal = getSTRING(peekSTACK(evaluateStack));
			pop(evaluateStack);
			char *secondVal = getSTRING(peekSTACK(evaluateStack));
			pop(evaluateStack);
			char *solvedVal = evaluate(firstVal,secondVal,val);
			push(evaluateStack, solvedVal);
		}
		
	}
}

void
displayMATILDA(FILE *fp, void *key, void *value)
{
	displaySTRING(fp, key);
	fprintf(fp, "=");
	displayREAL(fp, value);
}

static void
printInput(char* inputFile)
{
	FILE *input = fopen(inputFile, "r");
	// Does file even exist.
	if (input == NULL)
	{
		Fatal("Could not open %s file.\n", input);
	}
	char *token = readToken(input);

	while (token)
	{
		printf("%s ", token);
		if (strcmp(token, ";") == 0)
		{
			printf("\n");
		}
		token = readToken(input);
	}

	fclose(input);
}

static void 
printLastPostfix(QUEUE *dummyPrintQ)
{
	int i;
	int size = sizeQUEUE(dummyPrintQ);

	for (i = 0; i < size; i = i + 1)
	{
		printf("%s ", getSTRING(peekQUEUE(dummyPrintQ)));
		dequeue(dummyPrintQ);
	}
	printf("\n");
}

static void
printBST(BST *tree)
{
	displayBST(stdout, tree);
	printf("\n");
}

static int
precedence(char* op)
{
	// Higher number return if higher precedence, 
	// -1 if not one of six possible operators.
	if (strcmp(op, "+") == 0)
	{
		return 1;
	}
	else if (strcmp(op, "-") == 0)
	{
		return 2;
	}
	else if (strcmp(op, "*") == 0)
	{
		return 3;
	}
	else if (strcmp(op, "/") == 0)
	{
		return 4;
	}
	else if (strcmp(op, "%") == 0)
	{
		return 5;
	}
	else if (strcmp(op, "^") == 0)
	{
		return 6;
	}
	return -1;
}

STRING *evaluate(double firstVal, double secondVal, char *op) {
	double resultingVal;
	char *str = malloc(sizeof(char *));

	if (strcmp(op, "+") == 0)
	{
		resultingVal = secondVal + firstVal;
	}
	else if (strcmp(op, "-") == 0)
	{
		resultingVal = secondVal - firstVal;
	}
	else if (strcmp(op, "*") == 0)
	{
		resultingVal = secondVal * firstVal;
	}
	else if (strcmp(op, "/") == 0)
	{
		resultingVal = secondVal / firstVal;
	}
	else if (strcmp(op, "%") == 0)
	{
		resultingVal = fmod(secondVal, firstVal);
	}
	else if (strcmp(op, "^") == 0)
	{
		resultingVal = pow(secondVal, firstVal);
	}

	sprintf(str, "%lf", resultingVal);
	STRING *resultString = newSTRING(str);

	return resultString;
}