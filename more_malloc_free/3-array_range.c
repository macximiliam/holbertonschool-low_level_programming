#include <stdlib.h>
#include "main.h"

/**
 * array_range - Creates an array of integers containing all values
 * from min (included) to max (included), ordered.
 * @min: The starting value of the range (included).
 * @max: The ending value of the range (included).
 *
 * Return: A pointer to the newly created array.
 * NULL if min > max or if malloc fails.
 */
int *array_range(int min, int max)
{
	int *arr;
	int size;
	int i;

	if (min > max)
	{
		return (NULL);
	}

	size = max - min + 1;

	arr = malloc(sizeof(int) * size);

	if (arr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		arr[i] = min + i;
	}

	return (arr);
}
