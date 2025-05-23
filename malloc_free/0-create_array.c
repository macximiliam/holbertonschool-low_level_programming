#include <stdlib.h>

/**
 * create_array - Crea un arreglo de caracteres e inicializa con un carácter específico.
 * @size: Tamaño del arreglo.
 * @c: Carácter con el que inicializar cada elemento.
 *
 * Return: Puntero al arreglo, o NULL si falla.
 */
char *create_array(unsigned int size, char c)
{
    if (size == 0)
        return NULL;

    char *array = malloc(size * sizeof(char));
    if (array == NULL)
        return NULL;

    unsigned int i;
    for (i = 0; i < size; i++)
        array[i] = c;

    return array;
}
