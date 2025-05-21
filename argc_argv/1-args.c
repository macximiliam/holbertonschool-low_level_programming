#include <stdio.h>


/**
 * main - Prints the number of arguments passed into it,
 * excluding the program name.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings (character pointers)
 *
 * Return: Always 0 (Success).
 */
int main(int argc, char *argv[])
{
	(void) argv;
	printf("%d\n", argc - 1);
	return (0);
}
