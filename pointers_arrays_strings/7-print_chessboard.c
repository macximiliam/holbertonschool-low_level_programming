#include "main.h"

/**
 * print_chessboard - Prints a chessboard.
 * @a: A pointer to an 8x8 array of characters
 * representing the chessboard.
 *
 * This function iterates through the 8x8 array and prints each character,
 * followed by a newline after each row.
 */
void print_chessboard(char (*a)[8])
{
	int i;
	int j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			_putchar(a[i][j]);
		}
		_putchar('\n');
	}
}
