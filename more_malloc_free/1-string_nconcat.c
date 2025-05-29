#include "main.h"
#include <stdlib.h>


/**
 * string_nconcat - Concatenates two strings with first n bytes of s2
 * @s1: First string
 * @s2: Second string
 * @n: Number of bytes to take from s2
 *
 * Return: Pointer to newly allocated memory
 * containing s1 + first n bytes of s2
 * NULL if memory allocation fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, j,  len1 = 0, len2 = 0;
	char *concat = NULL;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
		len1++;

	for (i = 0; s2[i] != '\0'; i++)
		len2++;

	if (n >= len2)
		n = len2;

	concat = malloc(sizeof(char) * (len1 + n + 1));
	if (concat == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	for (j = 0; j < n; j++)
		concat[i + j] = s2[j];

	concat[i + j] = '\0';

	return (concat);

}
