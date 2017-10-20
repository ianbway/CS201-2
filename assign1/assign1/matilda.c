// Ian Braudaway
// main matilda program for assignment 1

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include "scanner.h"
#include "bst.h"
#include "stack.h"
#include "queue.h"
#include "integer.h"
#include "real.h"
#include "string.h"

/* options */
int inputFlag = 0;    /* option -i FILENAME */
int postfixFlag = 0;    /* option -p FILENAME */
int bstFlag = 0;    /* option -b FILENAME */

static int processOptions(int, char **);
void Fatal(char *, ...);
QUEUE *processFileIntoQueue(FILE *);
BST *makeVarBST(QUEUE *);
QUEUE *createPostfixQueue(QUEUE *);
static int isNumber(STRING *);
REAL *evaluateExpression(QUEUE *, BST *);
void displayMATILDA(FILE*, void*, void*);
static void printInput(QUEUE*);
static void printLastPostfix(QUEUE*);
static void printBST(BST *tree);
static int precedence(char*);
REAL *evaluate(double firstVal, double secondVal, STRING *op);


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

	// Read file into Input Queue of strings, tokenizing everything.
	FILE *inputFile = fopen(argv[argIndex], "r");
	QUEUE *inputQueue = processFileIntoQueue(inputFile);
	fclose(inputFile);

	// If flag is for -i option, print input.
	if (inputFlag == 1)
	{
		printInput(inputQueue);
	}

	// Create BST by taking var declarations from beginning of Input Queue.
	BST *varBST = makeVarBST(inputQueue);
	
	// Create Postfix Queue from Infix Queue. Makes calculation easier.
	QUEUE *postfixQueue = createPostfixQueue(inputQueue);

	// If flag for -p option, print postfix
	if (postfixFlag == 1)
	{
		printLastPostfix(postfixQueue);
	}

	// If flag for -b option, print BST
	if (bstFlag == 1)
	{
		printBST(varBST);
	}

	// Finally, evaluate the math on the Postfix Queue and return the REAL type result.
	REAL *answer = evaluateExpression(postfixQueue, varBST);

	displayREAL(stdout, answer);
	printf("\n");

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
processFileIntoQueue(FILE *input)
{
	// This queue will contain the expression, or everything after variable declarations.
	// Does file even exist.
	if (input == NULL)
	{
		Fatal("Could not open %s file.\n", input);
	}

	QUEUE *inputQueue = newQUEUE(displaySTRING);
	char *token = readToken(input);

	while (token)
	{
		enqueue(inputQueue, newSTRING(token));
		token = readToken(input);
	}

	return inputQueue;
}

BST *
makeVarBST(QUEUE *input)
{
	// This method will also take away the variable declarations in our input queue.
	BST *variableBST = newBST(displayMATILDA, compareSTRING);
	
	while (sizeQUEUE(input) > 0)
	{
		if (strcmp(getSTRING(peekQUEUE(input)), "var") == 0)
		{
			// dequeue "var"
			dequeue(input);

			// key is immediately after "var"
			STRING *key = dequeue(input);

			// dequeue "="
			dequeue(input);

			// dequeue real value. This line also converts from string to real.
			REAL *val = newREAL(atof(getSTRING(dequeue(input))));

			// dequeue ";"
			dequeue(input);

			// insert declared variable into our tree
			insertBST(variableBST, key, val);
		}

		else
		{
			break;
		}
	}

	return variableBST;
}

QUEUE *createPostfixQueue(QUEUE *infixQueue)
{
	STACK* operatorStack = newSTACK(displaySTRING);
	QUEUE* postfixQueue = newQUEUE(displaySTRING);

	while (sizeQUEUE(infixQueue) > 0)
	{
		
		STRING *strVal = dequeue(infixQueue);
		char *val = getSTRING(strVal);

		// Number or variable, add to queue.
		if (isNumber(strVal) || isalpha(val[0]))
		{
			enqueue(postfixQueue, strVal);
		}
		
		// Push open parenthesis on to operator stack.
		else if (strcmp(val, "(") == 0)
		{
			push(operatorStack, strVal);
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
					enqueue(postfixQueue, pop(operatorStack));
					op = getSTRING(peekSTACK(operatorStack));
				}
				// pop "("
				pop(operatorStack);
			}
		}
		
		// Stack is empty and it is an operator, put on stack
		else if ((precedence(val) != -1) && sizeSTACK(operatorStack) == 0)
		{
			push(operatorStack, strVal);
		}
		
		// Operator on top of stack has higher precedence than (or equal to) one being read,
		// pop from stack and enqueue to postfix queue, then push new symbol.
		// This also covers equality by left association.
		else if ((precedence(val) <= precedence(getSTRING(peekSTACK(operatorStack)))) && (precedence(val) != -1))
		{

			// While the operator stack still has something on it,
			// and the precedence of it's top value is higher or equal to the one being read
			// enqueue the popped top value to the postfix queue.
			while ((sizeSTACK(operatorStack) > 0) && (precedence(val) <= precedence(getSTRING(peekSTACK(operatorStack)))))
			{
				enqueue(postfixQueue, pop(operatorStack));
			}

			push(operatorStack, strVal);
		}

		// Else value being read has higher precendence than what is on top of stack,
		// so put it on the stack.
		else if ((precedence(val) > precedence(getSTRING(peekSTACK(operatorStack)))) && (precedence(val) != -1))
		{
			push(operatorStack, strVal);
		}
		
		// Else it is a semicolon. End of expression
		else if (strcmp(val, ";") == 0)
		{
			while (sizeSTACK(operatorStack) > 0)
			{
				enqueue(postfixQueue, pop(operatorStack));
			}
		}
		
		// Else character not defined in spec.
		else
		{
			printf("Unknown character.\n");
		}
	}

	return postfixQueue;
}

static int
isNumber(STRING *value)
{
	// This method determines if the string value pulled off of the postfixQueue is a number
	
	if ((getSTRING(value)[0] == '-') && (getSTRING(value)[1] != 0))
	{
		return 1;
	}
	
	else if (getSTRING(value)[0] == '.')
	{
		return 1;
	}
	
	else if (isdigit(getSTRING(value)[0]))
	{
		return 1;
	}

	// String did not start with "-", ".", or a number. Therefore it is not a number.
	else
	{
		return 0;
	}
}

REAL * 
evaluateExpression(QUEUE *postfixQueue, BST *varTree)
{
	STACK *evaluateStack = newSTACK(displayREAL);

	while (sizeQUEUE(postfixQueue) > 0)
	{
		// Take val from postfix queue and look at it
		STRING *val = dequeue(postfixQueue);

		// Its a number
		if (isNumber(val) != 0)
		{
			REAL *realVal = newREAL(atof(getSTRING(val)));
			push(evaluateStack, realVal);
		}

		// Its a string
		else if (isalpha(getSTRING(val)[0]) != 0)
		{
			// find var value in bst, if not in tree print error
			if (findBST(varTree, val) == 0)
			{
				printf("variable %s was not declared\n", getSTRING(val));
				exit(0);
			}

			REAL *returnedVal = findBST(varTree, val);
			push(evaluateStack, returnedVal);
		}

		// Else must be operator
		else
		{
			double firstVal = getREAL(pop(evaluateStack));
			double secondVal = getREAL(pop(evaluateStack));
			REAL *solvedVal = evaluate(firstVal, secondVal, val);
			push(evaluateStack, solvedVal);
		}
	}

	// After loop is finished this should be the final answer
	return pop(evaluateStack);
}

void
displayMATILDA(FILE *fp, void *key, void *value)
{
	displaySTRING(fp, key);
	fprintf(fp, "=");
	displayREAL(fp, value);
}

static void
printInput(QUEUE* input)
{
	// Print each value from input queue with a space afterwards, newline after ;
	// enqueue the dequeue values onto the back
	int i;
	for (i = 0; i < sizeQUEUE(input); i++)
	{

		if (strcmp(getSTRING(peekQUEUE(input)), ";") != 0)
		{
			printf("%s ", getSTRING(peekQUEUE(input)));
		}
		
		else if (strcmp(getSTRING(peekQUEUE(input)), ";") == 0)
		{
			printf("%s\n", getSTRING(peekQUEUE(input)));
		}

		enqueue(input, dequeue(input));
	}
}

static void 
printLastPostfix(QUEUE *postfixQueue)
{
	int i;
	int size = sizeQUEUE(postfixQueue);
	for (i = 0; i < size; i++)
	{
		if (i < size - 1)
		{
			printf("%s ", getSTRING(peekQUEUE(postfixQueue)));
			enqueue(postfixQueue, dequeue(postfixQueue));
		}

		// No space at the end, need newline
		else
		{
			printf("%s\n", getSTRING(peekQUEUE(postfixQueue)));
			enqueue(postfixQueue, dequeue(postfixQueue));
		}
	}
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
	else
	{
		return -1;
	}
}

REAL *evaluate(double firstVal, double secondVal, STRING *op) {
	
	double resultingVal;

	if (strcmp(getSTRING(op), "+") == 0)
	{
		resultingVal = secondVal + firstVal;
	}
	else if (strcmp(getSTRING(op), "-") == 0)
	{
		resultingVal = secondVal - firstVal;
	}
	else if (strcmp(getSTRING(op), "*") == 0)
	{
		resultingVal = secondVal * firstVal;
	}
	else if (strcmp(getSTRING(op), "/") == 0)
	{
		resultingVal = secondVal / firstVal;
	}
	else if (strcmp(getSTRING(op), "%") == 0)
	{
		resultingVal = fmod(secondVal, firstVal);
	}
	else if (strcmp(getSTRING(op), "^") == 0)
	{
		resultingVal = pow(secondVal, firstVal);
	}
	else
	{
		printf("Operator not defined in spec.\n");
	}

	REAL *resultReal = newREAL(resultingVal);

	return resultReal;
}