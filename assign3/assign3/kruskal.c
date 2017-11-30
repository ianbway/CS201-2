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
void TopDownMergeSort(DA *, DA *, int);
void TopDownSplitMerge(DA *, int, int, DA *);
void TopDownMerge(DA *, int, int, int, DA *);
void CopyArray(DA *, int, int, DA *);
DA *kruskal(DA *);
void displayTree(FILE *, DA *);

typedef struct edge
{
	bool visited;
	int weight;
	int u;
	int v;
} EDGE;

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

void 
displayEDGE (FILE* fp, void *value)
{
	EDGE *edge = value;
	
	fprintf(fp, "%d", edge->u);
	fprintf(fp, "(%d)", edge->v);
	fprintf(fp, "%d\n", edge->weight);
}

int
compareEDGE(void *firstValue, void *secondValue)
{
	EDGE *firstEdge = firstValue;
	EDGE *secondEdge = secondValue;
	
	return (firstEdge->weight - secondEdge->weight);
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

	DA *edgeDA;
	
	if (fopen(argv[1], "r"))
	{
		FILE *edgeFile = fopen(argv[1], "r");
		edgeDA = processIntoDA(edgeFile);
	}

	// Sort edge array before kruskal's algorithm
	DA *workArray = newDA(displayEDGE);
	TopDownMergeSort(edgeDA, workArray, sizeDA(edgeDA));

	// kruskal time
	DA* mst = kruskal(edgeDA);
	
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
	EDGE *edge;

	// Making sure u val is smaller than v for future help
	if (atoi(tokenOne) < atoi(tokenTwo))
	{
		edge = newEDGE(atoi(tokenOne), atoi(tokenTwo));
	}

	else
	{
		edge = newEDGE(atoi(tokenTwo), atoi(tokenOne));
	}

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
		}
	}

	return inputDA;
}

// Array A[] has the items to sort; array B[] is a work array.
void
TopDownMergeSort(DA *A, DA *B, int n)
{
	CopyArray(A, 0, n, B);           // duplicate array A[] into B[]
	TopDownSplitMerge(B, 0, n, A);   // sort data from B[] into A[]
}

// Sort the given run of array A[] using array B[] as a source.
// iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
void
TopDownSplitMerge(DA *B, int iBegin, int iEnd, DA *A)
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
TopDownMerge(DA *A, int iBegin, int iMiddle, int iEnd, DA *B)
{
	int i = iBegin;
	int j = iMiddle;
	int k;
	// While there are elements in the left or right runs...
	for (k = iBegin; k < iEnd; k++) {
		// If left run head exists and is <= existing right run head.
		if (i < iMiddle && (j >= iEnd || getDA(A, i) <= getDA(A, j))) {
			setDA(B, k, getDA(A, i));
			i = i + 1;
		}
		else {
			setDA(B, k, getDA(A, j));
			j = j + 1;
		}
	}
}

void
CopyArray(DA *A, int iBegin, int iEnd, DA *B)
{
	int k;

	for (k = iBegin; k < iEnd; k++)
		setDA(B, k, getDA(A, k));
}

DA *
kruskal(DA *edgeArray)
{
	SET *returnSet = newSET(displayEDGE);
	int *indexArray = malloc(sizeof(int) * (maxVertex + 1));
	assert(indexArray != 0);
	DA *kruskalEdges = newDA(displayEDGE);
	int i;

	for (i = 0; i < maxVertex + 1; i++)
	{
		indexArray[i] = -1;
	}

	for (i = 0; i < sizeDA(edgeArray); i++)
	{
		int uIndex = makeSET(returnSet, newINTEGER(getU(getDA(edgeArray, i))));
		if (indexArray[getU(getDA(edgeArray, i))] == -1)
		{
			indexArray[getU(getDA(edgeArray, i))] = uIndex;
		}

		int vIndex = makeSET(returnSet, newINTEGER(getV(getDA(edgeArray, i))));
		if (indexArray[getV(getDA(edgeArray, i))] == -1)
		{
			indexArray[getV(getDA(edgeArray, i))] = vIndex;
		}
	}

	for (i = 0; i < sizeDA(edgeArray); i++)
	{
		int rep1 = findSET(returnSet, indexArray[getU(getDA(edgeArray, i))]);
		int rep2 = findSET(returnSet, indexArray[getV(getDA(edgeArray, i))]);

		if (rep1 != rep2)
		{
			unionSET(returnSet, rep1, rep2);
			insertDA(kruskalEdges, getDA(edgeArray, i));
		}
	}

	return kruskalEdges;
}

void
displayTree(FILE *fp, DA *edgeArray)
{
	int tWeight = 0;
	int i;
	for (i = 0; i < sizeDA(edgeArray); i++)
	{
		tWeight = tWeight + getWeight(getDA(edgeArray, i));
	}

	fprintf(fp, "total weight: %d\n", tWeight);
}