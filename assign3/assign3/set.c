// Implementation File for Disjoint Set data structure
// Ian Braudaway

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "set.h"
#include "da.h"

struct set 
{
	DA *da;
	int count;
	void(*display) (FILE *, void *);
};

typedef struct setElement
{
	void *value;
	int rank;
	int index;
	struct setElement *parent;
	void(*display) (FILE *, void *);
} SETELEMENT;

SET *
newSET(void(*d)(FILE *, void *))
{
	// The constructor is passed a function that knows how to display the generic values stored in the structure.  
	SET *set = malloc(sizeof(SET));
	assert(set != 0);

	set->da = newDA(d);
	set->count = 0;
	set->display = d;

	return set;
}

static SETELEMENT *
newSETELEMENT(void(*d)(FILE *, void *), void *value)
{
	SETELEMENT *setElem = malloc(sizeof(SETELEMENT));
	assert(setElem != 0);

	setElem->value = value;
	setElem->rank = 0;
	setElem->index = 0;
	setElem->parent = setElem;
	setElem->display = d;

	return setElem;
}

int 
makeSET(SET *d, void *value)
{
	// The makeSET method inserts a wrapped value into the underlying dynamic array. It returns the index of the inserted value. 
	// Presumably, the caller of makeSET saves the return value so that findSET and unionSET can be called in the future. 

	SETELEMENT *setVal = newSETELEMENT(d->display, value);

	setVal->index = sizeDA(d->da);
	insertDA(d->da, setVal);
	d->count++;

	return setVal->index;
}

int 
findSET(SET *d, int index)
{
	// The findSET method returns the index of the representative of the value stored at the given index. 

	SETELEMENT *setVal = getDA(d->da, index);

	// if setVal is not representative. Path compression
	if (setVal->parent != setVal)
	{
		setVal->parent = getDA(d->da, findSET(d, setVal->parent->index));
	}

	return setVal->parent->index;
}

int 
unionSET(SET *d, int index1, int index2)
{
	// The union method runs findSET on each of the arguments. 
	// If the arguments have different representatives, the two disjoint sets are unioned and a value of one is returned. 
	// If they have the same representatives, then a zero is returned. 
	// If the two differing representatives have the same rank, then the representative with the lower index becomes the parent of the other.

	SETELEMENT *one = getDA(d->da, findSET(d, index1));
	SETELEMENT *two = getDA(d->da, findSET(d, index2));
	d->count--;

	if (one == two)
	{
		return 0;
	}

	// Union by rank
	if (one->rank < two->rank)
	{
		one->parent = two;
		return 1;
	}

	else if (one->rank > two->rank)
	{
		two->parent = one;
		return 1;
	}

	else
	{
		if (one->index < two->index)
		{
			two->parent = one;
			one->rank++;
			return 1;
		}

		else
		{
			one->parent = two;
			one->rank++;
			return 1;
		}
	}
}

int 
countSET(SET *d)
{
	// The count method returns current number of representatives in the set. 
	return d->count;
}

int 
displaySET(FILE *file, SET *d)
{
	// The method should print each value in the underlying dynamic array. See the example below.

	int i;
	for (i = 0; i < sizeDA(d->da); i++)
	{
		SETELEMENT *elem = getDA(d->da, i);

		fprintf(file, "%d: ", i);
		
		while (elem != elem->parent) 
		{
			elem->display(file, elem->value);
			fprintf(file, " ");
			elem = elem->parent;
		}

		elem->display(file, elem->value);

		fprintf(file, "\n");
	}

	return 0;
}