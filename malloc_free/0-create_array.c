#include "main.h"
#include <stdlib.h>

/**
 * create_array - Creates an array of characters and initializes
 * it with a specific character.
 * @size: Size of the array.
 * @c: Character to initialize each element with.
 *
 * Return: Pointer to the array, or NULL if memory allocation fails.
 */
char *create_array(unsigned int size, char c)
{
    unsigned int i;
    char *array;

    if (size == 0)
        return (NULL);

    array = malloc(size * sizeof(char));
    if (array == NULL)
        return (NULL);

    for (i = 0; i < size; i++)
        array[i] = c;

    return (array);
}
