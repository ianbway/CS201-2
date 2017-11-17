// Implementation File for Disjoint Set data structure
// Ian Braudaway

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "set.h"

struct set 
{

	int count;
	void(*display) (FILE *, void *);
};

SET *
newSET(void(*d)(FILE *, void *))
{
	// The constructor is passed a function that knows how to display the generic values stored in the structure.  


}

int 
makeSET(SET *d, void *value)
{
	// The makeSET method inserts a wrapped value into the underlying dynamic array. It returns the index of the inserted value. 
	// Presumably, the caller of makeSET saves the return value so that findSET and unionSET can be called in the future. 

}

int 
findSET(SET *d, int index)
{
	// The findSET method returns the index of the representative of the value stored at the given index. 

}

int 
unionSET(SET *d, int index1, int index2)
{
	// The union method runs findSET on each of the arguments. 
	// If the arguments have different representatives, the two disjoint sets are unioned and a value of one is returned. 
	// If they have the same representatives, then a zero is returned. 
	// If the two differing representatives have the same rank, then the representative with the lower index becomes the parent of the other.

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


}