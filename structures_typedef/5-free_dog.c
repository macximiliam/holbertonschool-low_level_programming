#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees the memory allocated for a dog_t structure.
 * @d: A pointer to the dog_t structure to be freed.
 *
 * This function frees the dynamically allocated memory for the dog's name,
 * owner, and the dog_t structure itself. It safely handles NULL pointers
 * to prevent segmentation faults.
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
	{
		return;
	}


	if (d->name != NULL)
	{
		free(d->name);
	}

	if (d->owner != NULL)
	{
		free(d->owner);
	}


	free(d);
}
