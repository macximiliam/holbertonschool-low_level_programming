#include "main.h"
#include <unistd.h>

/**
 * puts_half - prints half of a string, followed by a new line
 * @str: the string to be printed
 */
void puts_half(char *str)
{
	int len = 0, n;

	while (str[len] != '\0')
		len++;

	n = (len % 2 == 0) ? len / 2 : (len - 1) / 2 + 1;

	write(1, str + n, len - n);
	write(1, "\n", 1);
}
