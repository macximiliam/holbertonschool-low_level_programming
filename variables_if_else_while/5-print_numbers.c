#include<stdio.h>

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
	int n;

		for (n = 0; n <= 9; n++)
		{
			putchar(n + '0');
		}
		putchar('\n');

		return (0);

}
