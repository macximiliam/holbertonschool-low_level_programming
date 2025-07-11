#include "main.h"


/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the number to modify.
 * @index: Position of the bit to clear (starting from 0).
 *
 * Return: 1 if successful, or -1 if index is out of range.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n = *n & ~(1UL << index);

	return (1);
}
