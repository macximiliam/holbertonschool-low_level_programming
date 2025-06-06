#include "function_pointers.h"
#include <stddef.h>

/**
 * print_name - Prints a name using a provided function
 * @name: The name to print
 * @f: A pointer to the function that will print the name
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (f != NULL)
	{
		f(name);
	}
}
