#include "holberton.h"

/**
 * alloc_grid - create a 2 dimensional array of integers
 * inizialiced with zeros.
 * @width: width
 * @height: height
 * Return: pointer to the matrix, NULL on failure
*/
int **alloc_grid(int width, int height)
{
	void **mat;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);
	mat = (int **) malloc(sizeof(int *) * height);
	if (mat == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		*(mat + i) = malloc(sizeof(int) * width);
		if (*(mat + i) == NULL)
		{
			for (j = i - 1; j >= 0; j--)
				free(*(mat + j));
			free(mat);
			return (NULL);
		}
		/* put zeros on the just allocated pointer */
		for (j = 0; j < width; j++)
			*(*(mat + i) + j) = 0;
	}
	return (mat);
}
