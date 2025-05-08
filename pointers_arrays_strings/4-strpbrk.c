#include "main.h"

/**
 * _strchr - Locates the first occurrence of a character in a string.
 * @s: Pointer to the string to be searched.
 * @c: The character to locate.
 *
 * Return: A pointer to the first occurrence of
 * the character c in the string s,
 * or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}

	if (s[i] == c)
		return (&s[i]);

	return ('\0');
}

/**
 * _strpbrk - Finds the first character in the string s that matches
 * any of the bytes in the string accept.
 * @s: The string to search through.
 * @accept: The string containing the bytes to search for in s.
 *
 * Return: Returns a pointer to the first character in s that matches
 * one of the bytes in accept, or NULL if no such byte is found.
 */

char *_strpbrk(char *s, char *accept)
{
	if (!s || !accept)
	return ('\0');

	for (; *s != '\0'; s++)
	{
		if (_strchr(accept, *s))
		return (s);
	}
	return ('\0');
}
