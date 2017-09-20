#include <stdio.h>
#include "set.h"
#include "object.h"
#include "new.h"


int main(void)
{
	const void *set = 0, *object = 0;
	void *s = new(set);
	void *a = add(s, new(object));
	void *b = add(s, new(object));
	void *c = new(object);

	if (contains(s, a) && contains(s, b))
		puts("OK");
	if(contains(s, c))
		puts("contains?");
	if (differ(a, add(s, a)))
		puts("differ?");
	if (contains(s, drop(s, a)))
		puts("drop?");
	delete(drop(s, b));
	delete(drop(s, c));

	return (0);
}
