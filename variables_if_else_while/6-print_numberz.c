#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (indicating success)
 */
int main(void)
{
	int c;

	for (c = 0; c <= 9; c++)
	{
		putchar('0' + c);
	}
	putchar('\n');

	return (0);
}
