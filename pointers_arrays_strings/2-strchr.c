#include "main.h"
#include <stddef.h>
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

	return (NULL);
}
