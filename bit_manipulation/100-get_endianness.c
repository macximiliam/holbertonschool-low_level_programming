#include "main.h"

/**
 * get_endianness - Checks the endianness of the system
 *
 * Return: 1 if the system is little endian, 0 if big endian
 */
int get_endianness(void)
{
	unsigned int x = 1;
	char *c = (char *)&x;

	if (*c == 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
