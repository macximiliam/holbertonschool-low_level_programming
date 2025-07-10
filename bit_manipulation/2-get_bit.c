#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number to extract the bit from.
 * @index: The index of the bit to retrieve (starting from 0).
 *
 * Return: The value of the bit at the given index (0 or 1),
 *         or -1 if an error occurred (e.g., index is out of range).
 */
int get_bit(unsigned long int n, unsigned int index)
{
    if (index >= (sizeof(unsigned long int) * 8))
        return (-1);

    if ((n >> index) & 1)
        return (1);
    else
        return (0);
}