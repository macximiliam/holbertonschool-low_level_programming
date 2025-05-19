#include "main.h"

/**
 * _sqrt_helper - Helper function to find the natural square root recursively.
 * @n: The number to find the square root of.
 * @guess: The current potential root to test.
 *
 * Return: The natural square root of n, or -1 if not found.
 */
int _sqrt_helper(int n, int guess)
{
	if (guess * guess == n)
	{
		return (guess);
	}

	if (guess * guess > n || guess > n)
	{
		return (-1);
	}

	return (_sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of
 * a number using recursion.
 * @n: The number to calculate the natural square root of.
 *
 * Return: The natural square root of n.
 * Returns -1 if n does not have a natural square root or if n is negative.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}

	if (n == 0)
	{
		return (0);
	}

	return (_sqrt_helper(n, 1));
}
