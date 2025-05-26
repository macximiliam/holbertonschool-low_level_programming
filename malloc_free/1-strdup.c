#include <stdlib.h>
#include "main.h"

/**
 * _strdup - Duplicates a string without using string.h functions,
 * calculating length with a for loop.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the newly allocated duplicated string, or NULL if
 * str is NULL or if memory allocation fails.
 */
char *_strdup(char *str)
{


	char *dup;
	unsigned int len;
	unsigned int i;

	if (str == NULL)
	{
		return (NULL);
	}

	for (len = 0; str[len] != '\0'; len++)
	{
	}

	dup = (char *) malloc((len + 1) * sizeof(char));

	if (dup == NULL)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		dup[i] = str[i];
	}

	return (dup);
}
