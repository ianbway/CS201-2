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
int minVertex = 0;

typedef struct edge
{
	bool visited;
	int weight;
	int u;
	int v;
} EDGE;

void displayEDGE (FILE*, void *);
typedef int (*Comparator)(void *, void *);
int compareU(void *, void *);
int compareV(void *, void *);
int compareEDGE(void *, void *);
int getWeight(EDGE *);
int getU(EDGE *);
int getV(EDGE *);
void swapVtoU(EDGE*, int);
void Fatal(char *, ...);
RBT *processIntoRBT(FILE *);
DA *processIntoDA(FILE *);
void TopDownMergeSort(DA *, DA *, int, Comparator);
void TopDownSplitMerge(DA *, int, int, DA *, Comparator);
void TopDownMerge(DA *, int, int, int, DA *, Comparator);
void CopyArray(DA *, int, int, DA *);
DA *kruskal(DA *);
DA **processIntoAdjacencyList(DA *);
void displayTree(FILE *, DA **, DA *);

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
	
	fprintf(fp, " %d", edge->u);
	fprintf(fp, "(%d)", edge->v);
	fprintf(fp, "%d", edge->weight);
}

int 
compareU(void *firstValue, void *secondValue)
{	
	EDGE *firstEdge = firstValue;
	EDGE *secondEdge = secondValue;

	int returnInt = getU(firstEdge) - getU(secondEdge);
	if (getU(firstEdge) == getU(secondEdge))
	{
		returnInt = getV(firstEdge) - getV(secondEdge);
	}

	return returnInt;
}

int 
compareV(void *firstValue, void *secondValue)
{
	EDGE *firstEdge = firstValue;
	EDGE *secondEdge = secondValue;

	int returnInt = getV(firstEdge) - getV(secondEdge);
	if (getV(firstEdge) == getV(secondEdge))
	{
		returnInt = getU(firstEdge) - getU(secondEdge);
	}

	return returnInt;
}

// call compare weight
int
compareEDGE(void *firstValue, void *secondValue)
{
	EDGE *firstEdge = firstValue;
	EDGE *secondEdge = secondValue;

	int returnInt = firstEdge->weight - secondEdge->weight;

	if (firstEdge->weight == secondEdge->weight)
	{
		returnInt = getU(firstEdge) - getU(secondEdge);
		if (getU(firstEdge) == getU(secondEdge))
		{
			returnInt = getV(firstEdge) - getV(secondEdge);
		}
	}	

	return returnInt;
}

int
getWeight(EDGE *edge)
{
	return edge->weight;
}

bool
getVisited(EDGE *edge)
{
	return edge->visited;
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

void
swapVtoU(EDGE* edge, int index)
{
	if (getV(edge) == index)
	{
		int temp = getV(edge);
		edge->v = edge->u;
		edge->u = temp;
	}
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
	
	FILE *edgeFile = fopen(argv[1], "r");
	DA *edgeDA = processIntoDA(edgeFile);

	// Sort edge array before kruskal's algorithm
	DA *workArray = newDA(displayEDGE);
	TopDownMergeSort(edgeDA, workArray, sizeDA(edgeDA), compareEDGE);

	// kruskal time, sort afterwards based on U vertice
	DA* mst = kruskal(edgeDA);
	DA *workArrayTwo = newDA(displayEDGE);
	TopDownMergeSort(mst, workArrayTwo, sizeDA(mst), compareU);
	
	// Make adjacency list from mst
	DA **adjList = processIntoAdjacencyList(mst);

	// display the tree
	displayTree(stdout, adjList, mst);
	
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
	// Save off first two vertices
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

	char *token = readToken(file);

	if (strcmp(token, ";") != 0)
	{
		int possibleWeight = atoi(token);
		edge->weight = possibleWeight;
		token = readToken(file);
	}

	insertDA(inputDA, edge);
	
	while (token)
	{
		if (strcmp(token, ";") == 0)
		{
			insertDA(inputDA, edge);
			token = readToken(file);
		}
		
		else
		{
			// save off both vertice tokens
			char *tokenOne = token;
			char *tokenTwo = readToken(file);

			// Making sure u val is smaller than v for future help
			if (atoi(tokenOne) < atoi(tokenTwo))
			{
				edge = newEDGE(atoi(tokenOne), atoi(tokenTwo));
			}

			else
			{
				edge = newEDGE(atoi(tokenTwo), atoi(tokenOne));
			}

			if (atoi(tokenOne) > maxVertex)
			{
				maxVertex = atoi(tokenOne);
			}
			
			else if (atoi(tokenTwo) > maxVertex)
			{
				maxVertex = atoi(tokenTwo);
			}

			if (atoi(tokenOne) < minVertex)
			{
				minVertex = atoi(tokenOne);
			}

			else if (atoi(tokenTwo) < minVertex)
			{
				minVertex = atoi(tokenTwo);
			}
			
			// possible weight read
			token = readToken(file);

			if (strcmp(token, ";") != 0)
			{
				int possibleWeight = atoi(token);
				edge->weight = possibleWeight;
				token = readToken(file);
			}
			insertDA(inputDA, edge);
		}
	}

	return inputDA;
}

// Array A[] has the items to sort; array B[] is a work array.
void
TopDownMergeSort(DA *A, DA *B, int n, Comparator compare)
{
	CopyArray(A, 0, n, B);           // duplicate array A[] into B[]
	TopDownSplitMerge(B, 0, n, A, compare);   // sort data from B[] into A[]
}

// Sort the given run of array A[] using array B[] as a source.
// iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
void
TopDownSplitMerge(DA *B, int iBegin, int iEnd, DA *A, Comparator compare)
{
	if (iEnd - iBegin < 2)                       // if run size == 1
		return;                                 //   consider it sorted
												// split the run longer than 1 item into halves
	int iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
												// recursively sort both runs from array A[] into B[]
	TopDownSplitMerge(A, iBegin, iMiddle, B, compare);  // sort the left  run
	TopDownSplitMerge(A, iMiddle, iEnd, B, compare);  // sort the right run
											 // merge the resulting runs from array B[] into A[]
	TopDownMerge(B, iBegin, iMiddle, iEnd, A, compare);
}

//  Left source half is A[ iBegin:iMiddle-1].
// Right source half is A[iMiddle:iEnd-1   ].
// Result is            B[ iBegin:iEnd-1   ].
void
TopDownMerge(DA *A, int iBegin, int iMiddle, int iEnd, DA *B, Comparator compare)
{
	int i = iBegin;
	int j = iMiddle;
	int k;
	// While there are elements in the left or right runs...
	for (k = iBegin; k < iEnd; k++) {
		// If left run head exists and is <= existing right run head.
		if (i < iMiddle && (j >= iEnd || compare(getDA(A, i), getDA(A, j)) == 0 || compare(getDA(A, i), getDA(A, j)) < 0 )) {
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

DA **
processIntoAdjacencyList(DA *mst)
{
	DA **adjList = malloc(sizeof(DA *) * (maxVertex + 1));
	int i;

	for (i = 0; i < maxVertex + 1; i++)
	{
		adjList[i] = newDA(displayEDGE);
	}

	for (i = 0; i < sizeDA(mst); i++)
	{
		int uIndex = getU(getDA(mst, i));
		insertDA(adjList[uIndex], getDA(mst, i));
		int vIndex = getV(getDA(mst, i));
		insertDA(adjList[vIndex], getDA(mst, i));
	}

	return adjList;
}

void
displayTree(FILE *fp, DA **adjList, DA *mst)
{
	QUEUE *q = newQUEUE(displayEDGE);
	DA *printArray = newDA(displayEDGE);	
	DA *workArray = newDA(displayEDGE);
	int levelCounter;
	int tWeight;
	
	int i;
	for (i = 0; i < sizeDA(mst); i++)
	{
		levelCounter = 0;
		tWeight = 0;
		if (getVisited(getDA(mst, i)) == false)
		{
			enqueue(q, newINTEGER(getU(getDA(mst, i))));
		}
		fprintf(fp, "%d : %d\n",levelCounter++, getU(getDA(mst, i)));
		enqueue(q, NULL);

		while(sizeQUEUE(q) > 0)
		{
			void* index = dequeue(q);
			if (index != NULL)
			{
				int v = getINTEGER(index);
				int j;
				for (j = 0; j < sizeDA(adjList[v]); j++)
				{
					if (getVisited(getDA(adjList[v], j)) == false)
					{
						EDGE *e = getDA(adjList[v], j);
						e->visited = true;
						tWeight += getWeight(e);
						if (getU(getDA(adjList[v], j)) == v)
						{
							enqueue(q, newINTEGER(getV(getDA(adjList[v], j))));
							insertDA(printArray, getDA(adjList[v], j));
						}  

						else if (getV(getDA(adjList[v], j)) == v)
						{	
							enqueue(q, newINTEGER(getU(getDA(adjList[v], j))));
							swapVtoU(getDA(adjList[v], j), v);
							insertDA(printArray, getDA(adjList[v], j));
						}
					}
				}
			}

			else // v is NULL
			{
				if (sizeDA(printArray) > 0)
				{
					TopDownMergeSort(printArray, workArray, sizeDA(printArray), compareV);
					fprintf(fp, "%d :", levelCounter);
					levelCounter++;
				
					int storeSize = sizeDA(printArray);
					void **store = extractDA(printArray);
				
					int k;
					for (k = 0; k < storeSize; k++)
					{
						displayEDGE(fp, (EDGE*)store[k]);
					}
					fprintf(fp, "\n");
				}
				
				if (sizeQUEUE(q) != 0)
				{
					enqueue(q, NULL);
				}
			}
		}

		fprintf(fp, "total weight: %d\n", tWeight);
		fprintf(fp, "----\n");
	}
}
