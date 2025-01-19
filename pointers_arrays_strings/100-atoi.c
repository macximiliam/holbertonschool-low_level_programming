#include "main.h"
#include <limits.h>
/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the integer value of the string
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;
	int started = 0;

	while (*s)
	{
		if (*s == '-')
			sign *= -1;
		else if (*s == '+')
			sign *= 1;
		else if (*s >= '0' && *s <= '9')
		{
			started = 1;
			if (result > (INT_MAX - (*s - '0')) / 10)
			{
				if (sign == 1)
					return (INT_MAX);
				else
					return (INT_MIN);
			}
			result = result * 10 + (*s - '0');
		}
		else if (started)
			break;
		s++;
	}

	return (result * sign);
}
