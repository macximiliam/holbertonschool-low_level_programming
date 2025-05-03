#include "main.h"

/**
 * _strncat - Concatena como máximo n bytes de src a dest.
 * @dest: La cadena de destino.
 * @src: La cadena de origen.
 * @n: El número máximo de bytes a añadir desde src.
 *
 * Return: Un puntero a la cadena de destino resultante (dest).
 */
char *_strncat(char *dest, char *src, int n)
{
    char *dest_end = dest;
    int i;

    while (*dest_end != '\0')
    {
        dest_end++;
    }

    for (i = 0; i < n && src[i] != '\0'; i++)
    {
        *dest_end = src[i];
        dest_end++;
    }

    *dest_end = '\0';

    return dest;
}
