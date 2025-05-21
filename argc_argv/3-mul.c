#include <stdio.h>
#include <stdlib.h>

/**
 * main - Multiplies two numbers passed as command-line arguments.
 * @argc: The number of command-line arguments.
 * (Includes the program name as the first argument).
 * @argv: An array of strings (character pointers) where each string
 * is a command-line argument.
 * argv[0] is the program's name.
 * argv[1] is the first argument (the first number).
 * argv[2] is the second argument (the second number).
 *
 * Return: 0 if the multiplication is successful.
 * 1 if the number of arguments is incorrect (error).
 */
int main(int argc, char *argv[])
{
	int mult1, mult2, result;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	mult1 = atoi(argv[1]);
	mult2 = atoi(argv[2]);

	result = mult1 * mult2;

	printf("%d\n", result);
	return (0);
}
