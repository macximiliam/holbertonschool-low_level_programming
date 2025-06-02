#include <stdlib.h>
#include "dog.h"

/**
 * _copy_string_safe - Creates a safe copy of
 * a string by allocating new memory.
 * @src: The source string to be copied.
 *
 * Return: A pointer to the newly allocated and copied string,
 * or NULL if src is NULL or if memory allocation fails.
 */
static char *_copy_string_safe(char *src)
{
	char *dest;
	unsigned int len = 0;
	unsigned int i;

	if (src == NULL)
		return (NULL);


	while (src[len] != '\0')
	{
		len++;
	}


	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);


	for (i = 0; i <= len; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}

/**
 * new_dog - Creates a new dog, storing copies of name and owner.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The name of the dog's owner.
 *
 * Return: A pointer to the newly created dog_t structure, or NULL on failure.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog_ptr;


	new_dog_ptr = malloc(sizeof(dog_t));
	if (new_dog_ptr == NULL)
	{
		return (NULL);
	}

	new_dog_ptr->name = _copy_string_safe(name);

	if (name != NULL && new_dog_ptr->name == NULL)
	{
		free(new_dog_ptr);
		return (NULL);
	}


	new_dog_ptr->owner = _copy_string_safe(owner);

	if (owner != NULL && new_dog_ptr->owner == NULL)
	{

		if (new_dog_ptr->name != NULL)
			free(new_dog_ptr->name);
		free(new_dog_ptr);
		return (NULL);
	}


	new_dog_ptr->age = age;

	return (new_dog_ptr);
}
