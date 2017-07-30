#include <stdio.h>
#include <stdlib.h>
#include "da.h"

DA *newDA(void (*d)(FILE *, void *))	//d is display function
{
	//The constructor is passed a function that knows how to display the generic value stored in an array slot. 
	//That function is stored in a display field of the DA object. 

	DA *items = malloc(sizeof(DA));

	assert(items > 0);

	items->size = 0;
	items->front = 0;
	items->back = -1;
	items->capacity = 1;
	items->store = malloc(sizeof(items->capacity));
	items->factor = 2;
	items->display = d;

	return items;
}

void
insertDA(DA *items, void *value)
{
	//The insert method places the item in the leftmost unfilled slot. 
	//If there is no room for the insertion, the array grows by doubling. 
	//It runs in amortized constant time. 

	if (items->size == items->capacity)
	{
		items->capacity = items->capacity * items->factor;
	}

	items->store[items->size] = value;

	items->size++;
	return;
}

void *
removeDA(DA *items)
{
	//The remove method removes the rightmost item in the filled region. 
	//If the ratio of the size to the capacity drops below 25%, the array shrinks by half. 
	//The array should never shrink below a capacity of 1. It runs in amortized constant time. 

	if ((items->size * 4 >= items->capacity) && items->capacity != 1)
	{
		items->capacity = items->capacity / items->factor;
	}

	items->store[items->size - 1] = 0;

	items->size--;
	return;
}

void
unionDA(DA *recipient, DA *donor)
{
	//The union method takes two array and moves all the items in the donor array to the recipient array. 
	//If the recipient array has the items [3,4,5] and the donor array has the items [1,2], then, after the union, the donor array will be empty and recipient array will have the items [3,4,5,1,2]. 
	//The union method runs in linear time. 

	int i;
	int donorLen = sizeof(donor);
	for (i = 0; i < donorLen; i = i + 1)
	{
		insertDA(recipient, getDA(donor,i));
		
	}

	for (i = 0; i < donorLen; i = i + 1)
	{
		removeDA(donor);
	}

	return;
}

void *
getDA(DA *items, int index)
{
	//The get method returns the value at the given index. It runs in constant time.


	assert(index >= 0);
	assert(index < items->size);

	return items->store[index];

}

void *
setDA(DA *items, int index, void *value)
{
	//If the given index is equal to the size, the value is inserted via the insert method. 
	//The method returns the replaced value or zero if no value was replaced. 
	//It runs in constant time if the array does not need to grow and amortized constant time if it does. 


	assert(index >= 0);
	assert(index <= items->size);

	if (index != items->size)
	{
		return 0;
	}

	void *oldVal = getDA(items, index);
	insertDA(items, value);
	return oldVal;
}

int
sizeDA(DA *items)
{
	//The size method returns the number of items stored in the array. 
	return items->size;

}

void
displayDA(FILE *file, DA *items)
{
	//The display method prints out the filled region, enclosed in brackets and separated by commas, followed by the size of the unfilled region, enclosed in brackets. 
	//If the integers 5, 6, 2, 9, and 1 are stored in the array (listed from index 0 upwards) and the array has capacity 8, the method would generate this output:
	//[5, 6, 2, 9, 1][3]
	//with no preceding or following whitespace.
	//An empty array with capacity 1 displays as[][1].

	int i;
	int length = sizeof(items->store);

	fprintf(file, "[");
	for (i = 0; i < length; i = i + 1)
	{
		if (i < length - 1)
		{
			fprintf(file, strcat("%d", items->store[i], ", "));
		}

		else
		{
			fprintf(file, "%d", items->store[i]);
		}
	}

	fprintf(file, "]");
	fprintf(file, "[");
	int unfillReg = items->capacity - items->size;
	fprintf(file, "%d", unfillReg);
	fprintf(file, "]");
}