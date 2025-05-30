#include <stdlib.h>
#include "dog.h"

/**
 * init_dog  -  initialize a variable of type struct dog
 * @d: pointer to the strct dog to be initialized
 * @name: the name of the dog
 * @age: the age of te dog
 * @owner: the owner of the dog
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
	{
		return;
	}
	d->name = name;
	d->age = age;
	d->owner = owner;
}
