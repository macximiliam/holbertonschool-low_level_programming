#include <stdio.h>


/**
 * main - entry point
 *
 *  Return: Always 0 (indicating success)
 */
int main(void)
{
	char c;

	for (c = 'z'; c >= 'a'; c--)
	{
		putchar(c);
	}
	putchar('\n');

	return (0);
}
