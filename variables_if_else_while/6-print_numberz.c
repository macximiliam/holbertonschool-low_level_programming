#include<stdio.h>

/**
 * main - Prints the numbers from 0 to 9, each on a new line
 *
 * Description: This function prints numbers of base 10 starting from 0,
 * used only putchar and character in ASCII.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

		for (n = 0; n <= 9; n++)
		{
			putchar(n + '0');
		}
		putchar('\n');

		return (0);

}
