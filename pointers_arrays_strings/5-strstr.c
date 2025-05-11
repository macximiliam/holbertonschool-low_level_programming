#include "main.h"
#include <stddef.h>
/**
 * _strstr - Localiza una subcadena.
 * Encuentra la primera ocurrencia de
 * la subcadena needle en la cadena haystack.
 * Los bytes nulos de terminación (\0) no se comparan.
 * @haystack: La cadena principal donde se realizará la búsqueda.
 * @needle: La subcadena que se va a buscar.
 *
 * Return: Un puntero al inicio de la subcadena localizada en haystack,
 * o NULL si la subcadena no es encontrada.
 */
char *_strstr(char *haystack, char *needle)
{
	char *h, *n;

	if (*needle == '\0')
	{
		return (haystack);
	}

	for (; *haystack != '\0'; haystack++)
	{
		h = haystack;
		n = needle;

		for (; *n != '\0' && *h == *n; h++, n++)
		{
			/* body is empty */
		}

		if (*n == '\0')
		{
			return (haystack);
		}
	}

	return (NULL);
}
