#include "main.h"

/**
 * reverse_array - Reverses the content of an array of integers
 * @a: The array to reverse
 * @n: Number of elements in the array
 */
void reverse_array(int *a, int n)
{
	int temp;
	int *start = a;
	int *end = a + n - 1;

	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;

	start++;
	end--;
	}
}
