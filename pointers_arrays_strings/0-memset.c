#include "main.h"

/**
 * _memset - Llena los primeros n bytes del área de memoria apuntada por s
 * con el byte constante b.
 * @s: El puntero al área de memoria que se va a llenar.
 * @b: El byte constante con el que se llenará la memoria.
 * @n: El número de bytes a llenar.
 *
 * Return: Un puntero al área de memoria s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}
