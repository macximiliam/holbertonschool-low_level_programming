#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - Allocates memory for a 2D array of
 * integers of size height x width
 * and initializes all its elements to 0.
 * @width: The number of columns in the array.
 * @height: The number of rows in the array.
 *
 * Return: A pointer to the 2D array of integers, or NULL if allocation fails.
 */
int **alloc_grid(int width, int height)
{
	int **grid = NULL;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = (int **) malloc(height * sizeof(int *));
	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = (int *) malloc(width * sizeof(int));
		if (grid[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return (NULL);
		}
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}
	return (grid);
}
