#include "main.h"

/**
 * print_line - draws a straight line in the terminal
 * @n: number of times the character _ should be printed
 */

void print_line(int n)
{
	int s;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}
	for (s = 0; s < n; s++)
	{
		_putchar('_');
	}
	_putchar('\n');
}
