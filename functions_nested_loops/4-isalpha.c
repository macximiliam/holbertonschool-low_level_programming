#include "main.h"

/**
 * _isalpha - verifica si un carácter es una letra
 * @c: el carácter a verificar
 *
 * Return: 1 si c es una letra, 0 en caso contrario
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

