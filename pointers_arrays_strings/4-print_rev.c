#include "main.h"
#include <unistd.h>
/**
 * print_rev - Prints a string in reverse followed by a new line
 * @s: pointer to the string to be printed
 */
void print_rev(char *s)
{
	int length = 0;
	char *end = s;

	while (*end != '\0')
	{
		length++;
		end++;
	}

	while (length > 0)
	{
		end--;
		write(1, end, 1);
		length--;
	}

	write(1, "\n", 1);
}
