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
void TopDownMergeSort(int [], int [], int);
void TopDownSplitMerge(int [], int, int, int []);
void TopDownMerge(int [], int, int, int, int []);
void CopyArray(int [], int, int, int []);
SET *kruskal(DA *);

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
getWeight(EDGE *edge)
{
	return edge->weight;
}

int
getU(EDGE *edge)
{
	return edge->u;
}

int
getV(EDGE *edge)
{
	return edge->v;
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

	//RBT *edgeRBT;
	DA *edgeDA;
	
	if (fopen(argv[1], "r"))
	{
		FILE *edgeFile = fopen(argv[1], "r");
		//edgeRBT = processIntoRBT(edgeFile);
		edgeDA = processIntoDA(edgeFile);
	}

	int *indexArray = malloc(sizeof(maxVertex + 1));
	
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

//RBT *
//processIntoRBT(FILE *file)
//{
//	if (file == NULL)
//	{
//		Fatal("Could not open %s file.\n", file);
//	}
//	
//	RBT *inputRBT = newRBT(displayEDGE, compareEDGE);
//	char *tokenOne = readToken(file);
//	char *tokenTwo = readToken(file);
//	
//	EDGE *edge = newEDGE(atoi(tokenOne), atoi(tokenTwo));
//	
//	if (atoi(tokenOne) > maxVertex)
//	{
//		maxVertex = atoi(tokenOne);
//	}
//			
//	else if (atoi(tokenTwo) > maxVertex)
//	{
//		maxVertex = atoi(tokenTwo);
//	}
//	
//	insertRBT(inputRBT, edge);
//	char *token = readToken(file);
//	//INTEGER *vertex1;
//	//INTEGER *vertex2;
//	//INTEGER *weight = newINTEGER(1);
//	
//	while (token)
//	{
//		if (strcmp(token, ";") == 0)
//		{
//			insertRBT(inputRBT, edge);
//			token = readToken(file);
//		}
//		
//		else
//		{
//			char *tokenOne = readToken(file);
//			char *tokenTwo = readToken(file);
//			edge = newEDGE(atoi(tokenOne), atoi(tokenTwo));
//			
//			if (atoi(tokenOne) > maxVertex)
//			{
//				maxVertex = atoi(tokenOne);
//			}
//			
//			else if (atoi(tokenTwo) > maxVertex)
//			{
//				maxVertex = atoi(tokenTwo);
//			}
//			
//			token = readToken(file);
//			
//			if (strcmp(token, ";") != 0)
//			{
//				int possibleWeight = atoi(readToken(file));
//				edge->weight = possibleWeight;
//				token = readToken(file);
//			}
//			/*if (vertex1 == 0)
//			{
//				vertex1 = newINTEGER(token);
//			}
//			
//			else if (vertex2 == 0)
//			{
//				vertex2 = newINTEGER(token);
//			}
//			
//			else
//			{
//				weight = newINTEGER(token);
//			}*/
//		}
//		
//		
//	}
//
//	return inputRBT;
//}

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

// Array A[] has the items to sort; array B[] is a work array.
void
TopDownMergeSort(int A[], int B[], int n)
{
	CopyArray(A, 0, n, B);           // duplicate array A[] into B[]
	TopDownSplitMerge(B, 0, n, A);   // sort data from B[] into A[]
}

// Sort the given run of array A[] using array B[] as a source.
// iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
void
TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[])
{
	if (iEnd - iBegin < 2)                       // if run size == 1
		return;                                 //   consider it sorted
												// split the run longer than 1 item into halves
	int iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
												// recursively sort both runs from array A[] into B[]
	TopDownSplitMerge(A, iBegin, iMiddle, B);  // sort the left  run
	TopDownSplitMerge(A, iMiddle, iEnd, B);  // sort the right run
											 // merge the resulting runs from array B[] into A[]
	TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}

//  Left source half is A[ iBegin:iMiddle-1].
// Right source half is A[iMiddle:iEnd-1   ].
// Result is            B[ iBegin:iEnd-1   ].
void
TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[])
{
	int i = iBegin;
	int j = iMiddle;
	int k;
	// While there are elements in the left or right runs...
	for (k = iBegin; k < iEnd; k++) {
		// If left run head exists and is <= existing right run head.
		if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
			B[k] = A[i];
			i = i + 1;
		}
		else {
			B[k] = A[j];
			j = j + 1;
		}
	}
}

void
CopyArray(int A[], int iBegin, int iEnd, int B[])
{
	int k;

	for (k = iBegin; k < iEnd; k++)
		B[k] = A[k];
}

SET *
kruskal(DA *edgeArray)
{
	SET *returnSet = newSET(displayEDGE);

	int i;
	for (i = 0; i < sizeDA(edgeArray); i++)
	{
		makeSET(returnSet, getDA(edgeArray, i));
	}

	for (i = 0; i < sizeDA(TopDownMergeSort(edgeArray, ,sizeDA(edgeArray))); i++)
		if (findSET(returnSet, getU(getDA(edgeArray, i))) != findSET(returnSet, getV(getDA(edgeArray, i))))
		{
			makeSET(returnSet, getDA(edgeArray, i));
			unionSET(returnSet, getU(getDA(edgeArray, i)), getV(getDA(edgeArray, i)));
		}

	return returnSet;
}

void
displayTree(FILE *fp, SET *d, DA *edgeArray)
{
	displaySET(fp, d);

	int tWeight = 0;
	int i;
	for (i = 0; i < sizeDA(edgeArray); i++)
	{
		tWeight = tWeight + getWeight(getDA(edgeArray, i));
	}

	fprintf(fp, "total weight: %d\n", tWeight);
}