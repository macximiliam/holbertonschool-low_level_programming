#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - Prints a series of strings separated by a delimiter.
 * @separator: String to be printed between the strings.
 * If NULL, it's not printed.
 * @n: Number of strings to be printed.
 * @...: The strings to be printed.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);
		if (str == NULL)
			str = "(nil)";

		if (separator != NULL && i > 0)
			printf("%s", separator);

		printf("%s", str);
	}

	va_end(args);

	printf("\n");
}
