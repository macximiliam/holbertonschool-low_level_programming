#include <stdio.h>


/**
 * print_diagsums - Prints the sum of the two diagonals of
 * a square matrix of integers.
 * @a: A pointer to the first element of the
 * square matrix (represented as a 1D array).
 * @size: The size of the matrix (e.g., if the matrix is 3x3, size is 3).
 *
 * This function calculates the sum of the main diagonal (elements a[i][i])
 * and the sum of the secondary diagonal (elements a[i][size - 1 - i])
 * and then prints these sums.
 */
void print_diagsums(int *a, int size)
{
	int i;
	int sum1 = 0;
	int sum2 = 0;

	if (size <= 0 || a == NULL)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		sum1 += a[i * size + i];
		sum2 += a[i * size + (size - 1 - i)];
	}

	printf("%d, %d\n", sum1, sum2);
}
