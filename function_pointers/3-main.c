#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * main - Entry point of the program.
 * Takes command-line arguments to perform a mathematical operation.
 * @argc: Number of arguments passed to the program.
 * @argv: Array of pointers to the arguments.
 *
 * Return: 0 on success, 98 if the number of arguments is incorrect.
 */
int main(int argc, char *argv[])
{
	int m, j, l;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	m = atoi(argv[1]);
	j = atoi(argv[3]);
	l = (*get_op_func(argv[2]))(m, j);

	printf("%d\n", l);
	return (0);

}
