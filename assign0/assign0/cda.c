#include cda.h

CDA *
newCDA(void(*d)(FILE *, void *))	//d is the display function
{
	CDA *items = malloc(sizeof(CDA));

	assert(items > 0);

	items->size = 0;
	items->display = d;
	return items;
}

void
insertCDAFront(CDA *items, int index, void *value)
{


}

void
insertCDABack(CDA *items, int index, void *value)
{


}

void *
removeCDAFront(CDA *items, int index)
{


}

void
unionCDA(CDA *recipient, CDA *donor)
{


}

void *
getCDA(CDA *items, int index)
{
	assert(index >= 0);
	assert(index < items->size);

}

void *
setCDA(CDA *items, int index, void *value)
{
	assert(index >= -1);
	assert(index <= items->size);

}

int
sizeCDA(CDA *items)
{


}

void
displayCDA(FILE *, CDA *items)
{


}