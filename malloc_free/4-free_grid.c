#include "main.h"
#include <stdlib.h>

/**
 * free_grid - Deallocates (frees) a 2D integer grid (matrix)
 * previously created by alloc_grid.
 * @grid: A pointer to a pointer to integers (int **),
 * representing the 2D matrix.
 * It is the base address of the memory allocated for the grid.
 * @height: The height of the grid (number of rows).
 * This is needed to know how many rows to free.
 *
 * Return: void (the function does not return any value).
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
	{
		return;
	}

	for (i = 0; i < height; i++)
	{
		if (grid[i] != NULL)
		{
			free(grid[i]);
		}
	}

	free(grid);
}
