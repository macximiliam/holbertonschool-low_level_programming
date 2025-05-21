#include <stdio.h>

/**
 * main - Prints the name of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings (pointers to characters)
 *
 * Return: 0 upon successful execution.
 */
int main(int argc, char *argv[])
{
	(void) argc;
	printf("%s\n", argv[0]);
	return (0);

}
