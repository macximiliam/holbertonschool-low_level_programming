#include "main.h"

/**
 * string_toupper - Changes all lowercase letters of a string to uppercase
 * @str: The string to modify
 *
 * Return: Pointer to the modified string
 */
char *string_toupper(char *str)
{
	char *p = str;

	for (; *p; p++)
	{
		if (*p >= 'a' && *p <= 'z')
		{
			*p = *p - 32;
		}
	}
	return (str);
}
