#if ! defined MANY || MANY < 1
#define MANY 10
#endif
#include "new.h"
#include "object.h"
#include "set.h"

static int heap[MANY];

/**
 * new - creates new data item
 * @type: type of data
 * @... arguments to initialize data item
 *
 * Return: pointer to data item, or NULL
 */
void *new(const void *type, ...)
{
	int *p;

	(void)type;
	for (p = heap + 1; p < heap + MANY; p++)
		if (!*p)
			break;
	assert(p < heap + MANY);
	*p = MANY;
	return (p);
}

/**
 * delete - deletes data item
 * @_item - item to delete
 */
void delete(void *_item)
{
	int *item = _item;

	if (item)
	{
		assert(item > heap && item < heap + MANY);
		*item = 0;
	}
}


/**
 * add - adds an element to a set
 * @_set: pointer to set
 * @_element: element to add
 *
 * Return: new element or original set value
 */
void *add(void *_set, const void *_element)
{
	int *set = _set;
	const int *element = _element;

	assert(set > heap && set < heap + MANY);
	assert(*set == MANY);
	assert(element > heap && element < heap + MANY);

	if (*element == MANY)
		*(int *)element = set - heap;
	else
		assert(*element == set - heap);
	return ((void *)element);
}

/**
 * find - looks for an element in a set
 * @_set: set
 * @_element: search element
 *
 * Return: pointer to element or 0
 */
void *find(const void *_set, const void *_element)
{
	const int *set = _set;
	const int *element = _element;

	assert(set > heap && set < heap + MANY);
	assert(*set == MANY);
	assert(element > heap && element < heap + MANY);
	assert(*element);
	return (*element == set - heap ? (void *)_element : 0);
}

/**
 * contains - converts the result of find() into  a truth value
 * @_set: set
 * @_element: search element
 *
 * Return 0 if not found
 */
int contains(const void *_set, const void *_element)
{
	return (find(_set, _element) != 0);
}

/**
 * drop - drops an element in a set
 * @_set: set
 * @_element: drop element
 *
 * Return: pointer to dropped element
 */
void *drop(void *_set, const void *_element)
{
	int *element = find(_set, _element);

	if (element)
		*element = MANY;
	return (element);
}

/**
 * differ - compares objects
 * @a: first object
 * @b: second object
 *
 * Return: 0 if objects are equal
 */
int differ(const void *a, const void *b)
{
	return (a != b);
}
