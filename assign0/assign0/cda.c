#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "cda.h"

CDA *
newCDA(void(*d)(FILE *, void *))	//d is the display function
{
	//The constructor is passed a function that knows how to display the generic value stored in an array slot. 
	//That function is stored in a display field of the CDA object. 
	
	CDA *items = malloc(sizeof(CDA));

	assert(items != 0);

	items->size = 0;
	items->startIndex = 0;
	items->endIndex = 0;
	items->capacity = 1;
	items->store = malloc(sizeof(items->capacity));
	items->factor = 2;
	items->display = d;
	
	return items;
}

void
insertCDAFront(CDA *items, void *value)
{
	//This insert method places the item in the slot just prior to the first item in the filled region. 
	//If there is no room for the insertion, the array grows by doubling. 
	//It runs in amortized constant time. 

	assert(items != 0);

	if (items->size == items->capacity)
	{
		items->capacity = items->capacity * items->factor;
	}

	items->store[items->startIndex] = value;

	++items->size;
	return;
}

void
insertCDABack(CDA *items, void *value)
{
	//This insert method places the item in the slot just after the last item in the filled region. 
	//If there is no room for the insertion, the array grows by doubling. 
	//It runs in amortized constant time. 

	printf("INSERT BACK CALLED\n");

	assert(items != 0);

	if (items->size == items->capacity)
	{
		items->capacity = items->capacity * items->factor;
	}
	printf("BEFORE SET\n");
	items->store[items->endIndex] = value;
	printf("AFTER SET\n");
	++items->size;
	return;
}

void *
removeCDAFront(CDA *items)
{
	//This remove method removes the first item in the filled region. 
	//If the ratio of the size to the capacity drops below 25%, the array shrinks by half. 
	//The array should never shrink below a capacity of 1. 
	//It runs in amortized constant time. 

	assert(items->size > 0);

	if ((items->size * 4 >= items->capacity) && items->capacity != 1)
	{
		items->capacity = items->capacity / items->factor;
	}

	items->store[0] = 0;

	--items->size;
	return items->store[0];
}

void *
removeCDABack(CDA *items)
{
	//This remove method removes the last item in the filled region.
	//If the ratio of the size to the capacity drops below 25 % , the array shrinks by half.
	//The array should never shrink below a capacity of 1. 
	//It runs in amortized constant time.

	assert(items->size > 0);

	if ((items->size * 4 >= items->capacity) && items->capacity != 1)
	{
		items->capacity = items->capacity / items->factor;
	}

	items->store[items->size] = 0;

	--items->size;
	return items->store[items->size];
}

void
unionCDA(CDA *recipient, CDA *donor)
{
	//The union method takes two array and moves all the items in the donor array to the recipient array. 
	//Suppose the recipient array has the items [3,4,5] in the filled portion and the donor array has the items [1,2] in the filled portion, 
	//After the union, the donor array will be empty and recipient array will have the items [3,4,5,1,2] in the filled portion. 
	//The union method runs in linear time. 

	int i;
	int donorLen = sizeof(donor);
	for (i = 0; i < donorLen; i = i + 1)
	{
		insertCDABack(recipient, getCDA(donor, i));
	}

	for (i = 0; i < donorLen; i = i + 1)
	{
		removeCDAFront(donor);
	}

	return;

}

void *
getCDA(CDA *items, int index)
{
	//The get method returns the value at the given index. 
	//It runs in constant time.
	
	assert(index >= 0);
	assert(index < items->size);

	return items->store[index];

}

void *
setCDA(CDA *items, int index, void *value)
{
	//The set method updates the value at the given index. 
	//If the given index is equal to the size, the value is inserted via the insertCDABack method. 
	//If the given index is equal to -1, the value is inserted via the insertCDAFront method. 
	//The method returns the replaced value or zero if no value was replaced. 
	//It runs in constant time if the array does not need to grow and amortized constant time if it does.

	assert(index >= -1);
	assert(index <= items->size);

	if (index == items->size) 
	{
		insertCDABack(items, value);
	}

	else if (index == -1) 
	{
		insertCDAFront(items, value);
	}

	else if (getCDA(items, index) != 0)
	{
		getCDA(items, index);
	}

	return 0; 

}

void **
extractCDA(CDA *items)
{
	//The extract method returns the underlying C array. 
	//The array is shrunk to an exact fit prior to being returned. 
	//The CDA object gets a new array of capacity zero and size one. 
	assert(items != 0);

	void **returnList = realloc(items->store, sizeof(items));

	items->capacity = 0;
	items->size = 1;
	items->store = malloc(sizeof(items->capacity));

	free(items);

	return returnList;

}

int
sizeCDA(CDA *items)
{
	//The size method returns the number of items stored in the array. 
	return items->size;
}

void
visualizeCDA(FILE *fp, CDA *items)
{
	//The display method prints out the filled region, enclosed in brackets and separated by commas, followed by the size of the unfilled region, enclosed in brackets. 
	//If the integers 5, 6, 2, 9, and 1 are stored in the array (listed from index 0 upwards) and the array has capacity 8, the method would generate this output: (5, 6, 2, 9, 1)(3)
	//with no preceding or following whitespace.An empty array with capacity 1 displays as()(1).

	int i;

	fprintf(fp, "(");
	for (i = 0; items->size; i = i + 1)
	{
		items->display(fp, items->store[i]);
		if (items->size > 1 && i != items->size - 1)
		{
			fprintf(fp, ",");
		}
	}

	fprintf(fp, ")");
	fprintf(fp, "(");
	int unfillReg = items->capacity - items->size;
	fprintf(fp, "%d", unfillReg);
	fprintf(fp, ")");
}

void
displayCDA(FILE *fp, CDA *items)
{
	//The display method is similar to the visualize method, except the parenthesized size of the unfilled region is not printed.

	int i;

	fprintf(fp, "(");
	printf("Display loop about to start\n");
	for (i = 0; items->size; i = i + 1)
	{
		printf("Made it into the loop\n");
		items->display(fp, items->store[i]);
		if (items->size > 1 && i != items->size - 1)
		{
			fprintf(fp, ",");
		}
	}

	fprintf(fp, ")");
}