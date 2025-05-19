#include "main.h"

/**
 * _print_rev_recursion - Prints a string in reverse order, using recursion.
 * @s: The string to be printed in reverse.
 *
 * This function prints each character of the string in reverse order
 * using a recursive approach.
 */
void _print_rev_recursion(char *s)
{
	if (*s == '\0')
	{
		return;
	}

	_print_rev_recursion(s + 1);
	_putchar(*s);
}
