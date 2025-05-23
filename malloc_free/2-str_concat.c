#include "main.h"
#include <stdlib.h>

/**
 * str_concat -  concatenates two strings.
 * @s1:first string
 * @s2:second string
 * Return: pointer to char with the address of the result
 */
char *str_concat(char *s1, char *s2)
{
	char *new_str = NULL;
	int i, j, len1 = 0, len2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
		len1++;

	for (i = 0; s2[i] != '\0'; i++)
		len2++;

	new_str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (new_str == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		new_str[i] = s1[i];

	for (j = 0; j < len2; j++)
		new_str[i + j] = s2[j];

	new_str[i + j] = '\0';

	return (new_str);

}
