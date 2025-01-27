#include "main.h"

/**
 * leet - Encodes a string into 1337
 * @str: The string to be encoded
 *
 * Return: Pointer to the encoded string
 */
char *leet(char *str)
{
	char *ptr = str;
	char leet_map[10] = {'a', 'A', 'e', 'E', 'o', 'O', 't', 'T', 'l', 'L'};
	char leet_replace[10] = {'4', '4', '3', '3', '0', '0', '7', '7', '1', '1'};
	int i;

	while (*ptr)
	{
		for (i = 0; i < 10; i++)
		{
			if (*ptr == leet_map[i])
			{
				*ptr = leet_replace[i];
				break;
			}
		}
		ptr++;
	}

	return (str);
}
