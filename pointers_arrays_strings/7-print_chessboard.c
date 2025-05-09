#include "main.h"
#include <stdio.h>

/**
 * print_chessboard - Imprime un tablero de ajedrez.
 * @a: Un puntero a un arreglo bidimensional de 8x8 caracteres
 * que representa el tablero de ajedrez.
 *
 * Esta función itera a través del arreglo 8x8 e imprime cada carácter,
 * seguido de un salto de línea después de cada fila.
 */
void print_chessboard(char (*a)[8])
{
	int i, j;

	for (i = 0; i < 8; i ++)
	{
		for (j = 0; j < 8; j ++)
		{
		   if (a[i][j] != 0)
			putchar(a[i][j]);
		}
		putchar('\n');
	}
}
