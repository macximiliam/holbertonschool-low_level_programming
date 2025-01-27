#include "main.h"

/**
 * cap_string - Capitalizes all words of a string
 * @str: The string to be modified
 *
 * Return: Pointer to the modified string
 */
char *cap_string(char *str)
{
	char *ptr = str;
	int capitalize_next = 1;

	while (*ptr)
	{
		if (capitalize_next && *ptr >= 'a' && *ptr <= 'z')
			*ptr -= 32;

		capitalize_next =
			(*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == ',' ||
			 *ptr == ';' || *ptr == '.' || *ptr == '!' || *ptr == '?' ||
			 *ptr == '"' || *ptr == '(' || *ptr == ')' || *ptr == '{' || *ptr == '}');

		ptr++;
	}

	return (str);
}
