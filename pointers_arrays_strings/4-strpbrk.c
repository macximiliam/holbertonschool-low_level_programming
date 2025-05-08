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
 * _strpbrk - Searches a string for any of a set of bytes.
 * Finds the first occurrence in the string s of any of the
 * characters in the string accept.
 *
 * Note: This implementation uses a helper function _strchr
 * and returns the null character '\0' (value 0) instead of NULL
 * to indicate that the substring was not found, which differs
 * from the standard strpbrk behavior that returns NULL.
 *
 * @s: The string where the search will be performed.
 * @accept: The string containing the characters to search for.
 *
 * Return: A pointer to the byte in s that matches one of the bytes in accept,
 * or the null character '\0' if no such byte is found.
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
