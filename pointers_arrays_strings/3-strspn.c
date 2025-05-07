#include "main.h"
#include <string.h>

/**
 * _strspn - Funtion that gets the length of a prefix substring.
 *
 * @s: pointer initial segment
 * @accept: the characters to match from the beginning of s
 *
 * Return: The number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0;

	for (; s[i] && strchr(accept, s[i]); i++)
	;

	return (i);
}
