#include "main.h"

/**
 * puts2 - prints every other character of a string,
 * starting with the first character, followed by a new line
 * @str: pointer to the string to be printed
 *
 * Return - void
 */
void puts2(char *str)
{
	int i = 0;

	for (; str[i]; i++)
	{
		if (i % 2 == 0)
			_putchar(str[i]);
	}
		_putchar('\n');
}
