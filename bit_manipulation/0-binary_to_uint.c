#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts a binary string to an unsigned int.
 * @b: Pointer to a string of 0 and 1 characters.
 *
 * Return: The converted number, or 0 if b is NULL
 *         or contains characters different from 0 or 1.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int len, i;

	if (b == NULL)
		return (0);

	/* First loop: find the length of the string */
	for (len = 0; b[len] != '\0'; len++)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);
	}

	/* Second loop: convert binary to unsigned int */
	for (i = 0; i < len; i++)
	{
		result = result * 2 + (b[i] - '0');
	}

	return (result);
}

