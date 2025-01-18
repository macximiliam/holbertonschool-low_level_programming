#include "main.h"
#include <unistd.h>

/**
 * puts2 - Prints every other character of a string.
 * starting with the first character,
 * followed by a new line.
 * @str: The string to be processed.
 */
void puts2(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i % 2 == 0)
		{
			write(1, &str[i], 1);
		}
	}
	write(1, "\n", 1);
}
