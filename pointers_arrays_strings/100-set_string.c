#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char.
 * @s: Double pointer to be updated.
 * @to: Pointer to the string to assign to `*s`.
 *
 * Description: This function updates the value of the pointer `*s`
 * to point to the string `to`.
 */
void set_string(char **s, char *to)
{
	*s = to;
}

