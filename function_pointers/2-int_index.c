#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array.
 * that matches with a condition
 * @array: pointer to the array
 * @size: number of elements in the array
 * @cmp: pointer to the funtion to be used to compare values
 *
 * Return: If no element matches, return -1
 * if size <= 0, return -1
 */


int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && cmp && size > 0)
	{

		for (i = 0; i < size; i++)
			if (cmp(array[i]) == 1)
				return (i);

	}
		return (-1);
}
