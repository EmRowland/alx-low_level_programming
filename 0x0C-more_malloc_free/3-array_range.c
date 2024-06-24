#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: minimum value
 * @max: maximum value
 * 
 * Return: pointer to the newly created array, or NULL if it fails
 */
int *array_range(int min, int max)
{
    int *array, i, size;

    if (min > max)
        return (NULL);

    size = max - min + 1;

    array = malloc(size * sizeof(int));
    if (array == NULL)
        return (NULL);

    for (i = 0; i < size; i++, min++)
        array[i] = min;

    return (array);
}


