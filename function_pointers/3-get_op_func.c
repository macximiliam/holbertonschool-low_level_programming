#include"3-calc.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/**
 * get_op_func - Selects the correct function to perform the operation.
 * @s: The operator passed as argument.
 *
 * Return: A pointer to the function that corresponds to the operator.
 * Exits with status 99 if the operator is invalid.
 */
int (*get_op_func(char *s))(int, int)
{
op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op != NULL)
	{
		if (strcmp(ops[i].op, s) == 0)
			return (ops[i].f);
		i++;
	}

	 printf("Error\n");
	 exit(99);

}
