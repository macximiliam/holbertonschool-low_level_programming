#include "main.h"

/**
 * _strncpy - Copies a string using pointers
 * @dest: Destination buffer
 * @src: Source string
 * @n: Number of bytes to copy
 *
 * Return: Pointer to the destination string
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *dest_ptr = dest;

	while (n > 0 && *src != '\0')
	{
		*dest_ptr++ = *src++;
		n--;
	}

	while (n > 0)
	{
		*dest_ptr++ = '\0';
		n--;
	}

	return (dest);
}
