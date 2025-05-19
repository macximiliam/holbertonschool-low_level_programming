#include "main.h"

/**
 * _puts_recursion - Prints a string, followed by a new line, using recursion.
 * @s: The string to be printed.
 *
 * This function prints each character of the string one by one
 * until it reaches the null terminator, then it prints a newline character.
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}

	_putchar(*s);
	_puts_recursion(s + 1);
}
