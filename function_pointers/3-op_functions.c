#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * op_add - Returns the sum of two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: Sum of a and b.
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub - Returns the difference of two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: Difference of a and b.
 */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - Returns the product of two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: Product of a and b.
 */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
 * op_div - Returns the result of the division of two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: Quotient of a and b.
 * Exits with status 100 if b is zero.
 */

int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	else
	{
		return (a / b);
	}

}
/**
 * op_mod - Returns the remainder of the division of two integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: Remainder of a divided by b.
 * Exits with status 100 if b is zero.
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	else
	{
		return (a % b);
	}
}
