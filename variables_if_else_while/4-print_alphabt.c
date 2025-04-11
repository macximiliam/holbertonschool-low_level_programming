#include <stdio.h>

#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase.
 *
 * Description: This function prints all the lowercase letters of the alphabet
 * except character q and e
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
	{
		if (c == 'q' || c == 'e')
		{
			continue;
		}
		putchar(c);
	}
	putchar('\n');

	return (0);
}
