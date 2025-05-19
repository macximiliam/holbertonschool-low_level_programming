#include "main.h"
#include <stddef.h>

/**
 * _strlen_recursion - Returns the length of a string.
 * @s: The string to calculate the length of.
 *
 * Return: The length of the string (excluding the null terminator).
 */
int _strlen_recursion(char *s)
{
	size_t length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}
