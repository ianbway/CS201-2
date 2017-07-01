#include da.h

DA *
newDA(void (*d) (FILE *, void *), int capacity)	//d is display function
{
	DA *items = malloc(sizeof(DA));

	assert(items > 0);

	items->size = 0;
	items->front = 0;
	items->back = items->size - 1;
	void store[items->size];
	items->store = store[items->size];
	items->capacity = capacity;
	items->factor = 2;
	items->display = d;
	return items;
}

void
insertDA(DA *items, void *value)
{
	if (items->size)

}

void *
removeDA(DA *items)
{


}

void
unionDA(DA *recipient, DA *donor)
{


}

void *
getDA(DA *items, int index)
{

	assert(index >= 0);
	assert(index < items->size);

}

void *
setDA(DA *items, int index, void *value)
{

	assert(index >= 0);
	assert(index <= items->size);

}

int
sizeDA(DA *items)
{


}

void
displayDA(FILE *, DA *items)
{


}