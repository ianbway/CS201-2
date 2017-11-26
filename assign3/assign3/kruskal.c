// Ian Braudaway
// main file for assign3

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
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

int maxVertex = 0;

void Fatal(char *, ...);
RBT *processIntoRBT(FILE *);
DA *processIntoDA(FILE *);

typedef struct edge
{
	bool visited;
	int weight;
	int u;
	int v;
} EDGE;

typedef struct vertex
{
	int value;
} VERTEX;

EDGE *
newEDGE(int u, int v)
{
	EDGE *edge = malloc(sizeof(EDGE));
	assert(edge != 0);
	
	edge->u = u;
	edge->v = v;
	edge->visited = false;
	edge->weight = 1;
	
	return edge;
}

VERTEX * 
newVERTEX(int value)
{
	VERTEX *vertex = malloc(sizeof(VERTEX));
	assert(vertex != 0);
	
	vertex->value = value;

	return vertex;
}

void 
displayEDGE (FILE* fp, void *value)
{
	EDGE *edge = value;
	
	fprintf(fp, "%d", edge->u);
	fprintf(fp, "(%d)", edge->v);
	fprintf(fp, "%d\n", edge->weight);
}

void 
displayVERTEX(FILE *fp, void *value)
{
	VERTEX *vertex = value;
	
	fprintf(fp, "%d", vertex->value);
}

int
compareEDGE(void *firstValue, void *secondValue)
{
	EDGE *firstEdge = firstValue;
	EDGE *secondEdge = secondValue;
	
	return (firstEdge->weight - secondEdge->weight);
}

int
compareVERTEX(void *firstValue, void *secondValue)
{
	VERTEX *vertexOne = firstValue;
	VERTEX *vertexTwo = secondValue;
	
	return (vertexOne->value - vertexTwo->value);
}

int
main(int argc, char **argv)
{
	int argIndex = 1;

	// Executable must have arguments
	if (argc == 1) Fatal("%d arguments!\n", argc - 1);

	// Before doing anything, check to see if name argument exists and print that out, exiting program.
	if (strcmp(argv[1], "-v") == 0)
	{
		printf("Ian W. Braudaway\n");
		return 0;
	}

	RBT *edgeRBT;
	DA *edgeDA;
	
	if (fopen(argv[1], "r"))
	{
		FILE *edgeFile = fopen(argv[1], "r");
		edgeRBT = processIntoRBT(edgeFile);
		edgeDA = processIntoDA(edgeFile);
	}
	
	int vertexArray[maxVertex + 1];
	
	// Should not have more than one argument after the executable.
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

RBT *
processIntoRBT(FILE *file)
{
	if (file == NULL)
	{
		Fatal("Could not open %s file.\n", file);
	}
	
	RBT *inputRBT = newRBT(displayEDGE, compareEDGE);
	char *tokenOne = readToken(file);
	char *tokenTwo = readToken(file);
	
	EDGE *edge = newEDGE(atoi(tokenOne), atoi(tokenTwo));
	
	if (atoi(tokenOne) > maxVertex)
	{
		maxVertex = atoi(tokenOne);
	}
			
	else if (atoi(tokenTwo) > maxVertex)
	{
		maxVertex = atoi(tokenTwo);
	}
	
	insertRBT(inputRBT, edge);
	char *token = readToken(file);
	//INTEGER *vertex1;
	//INTEGER *vertex2;
	//INTEGER *weight = newINTEGER(1);
	
	while (token)
	{
		if (strcmp(token, ";") == 0)
		{
			insertRBT(inputRBT, edge);
			token = readToken(file);
		}
		
		else
		{
			char *tokenOne = readToken(file);
			char *tokenTwo = readToken(file);
			edge = newEDGE(atoi(tokenOne), atoi(tokenTwo));
			
			if (atoi(tokenOne) > maxVertex)
			{
				maxVertex = atoi(tokenOne);
			}
			
			else if (atoi(tokenTwo) > maxVertex)
			{
				maxVertex = atoi(tokenTwo);
			}
			
			token = readToken(file);
			
			if (strcmp(token, ";") != 0)
			{
				int possibleWeight = atoi(readToken(file));
				edge->weight = possibleWeight;
				token = readToken(file);
			}
			/*if (vertex1 == 0)
			{
				vertex1 = newINTEGER(token);
			}
			
			else if (vertex2 == 0)
			{
				vertex2 = newINTEGER(token);
			}
			
			else
			{
				weight = newINTEGER(token);
			}*/
		}
		
		
	}

	return inputRBT;
}

DA *
processIntoDA(FILE *file)
{
	if (file == NULL)
	{
		Fatal("Could not open %s file.\n", file);
	}
	
	DA *inputDA = newDA(displayEDGE);
	char *tokenOne = readToken(file);
	char *tokenTwo = readToken(file);
	
	EDGE *edge = newEDGE(atoi(tokenOne), atoi(tokenTwo));
	insertDA(inputDA, edge);
	char *token = readToken(file);
	
	while (token)
	{
		if (strcmp(token, ";") == 0)
		{
			insertDA(inputDA, edge);
			token = readToken(file);
		}
		
		else
		{
			char *tokenOne = readToken(file);
			char *tokenTwo = readToken(file);
			edge = newEDGE(atoi(tokenOne), atoi(tokenTwo));
			
			token = readToken(file);
			
			if (strcmp(token, ";") != 0)
			{
				int possibleWeight = atoi(readToken(file));
				edge->weight = possibleWeight;
				token = readToken(file);
			}
		}
	}

	return inputDA;
}