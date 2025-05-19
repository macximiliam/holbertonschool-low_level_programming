#include "main.h"

/**
 * is_prime_helper - Helper function to check for primality recursively.
 * @n: The number to check.
 * @i: The current divisor to test.
 *
 * Return: 1 if n is prime, 0 otherwise.
 */
int is_prime_helper(int n, int i)
{
	if (i * i > n)
	{
		return (1);
	}

	if (n % i == 0)
	{
		return (0);
	}

	return (is_prime_helper(n, i + 2));
}

/**
 * is_prime_number - Checks if a number is a prime number using recursion.
 * @n: The number to check.
 *
 * Return: 1 if n is a prime number, 0 otherwise.
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}

	if (n == 2)
	{
		return (1);
	}

	if (n % 2 == 0)
	{
		return (0);
	}

	return (is_prime_helper(n, 3));
}
