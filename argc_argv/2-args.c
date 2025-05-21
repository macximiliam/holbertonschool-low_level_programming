#include <stdio.h>

/**
 * main - Entry point of the program.
 * This program prints all command-line arguments, each on a new line.
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Return: 0 upon successful execution.
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)

		printf("%s\n", argv[i]);
	return (0);
}
