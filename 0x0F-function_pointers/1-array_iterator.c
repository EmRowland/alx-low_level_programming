#include <stdio.h>
#include "main.h"

/**
 *  * array_iterator - Executes a function given as a parameter on each element of an array
 *   * @array: Array of integers
 *    * @size: Size of the array
 *     * @action: Function pointer to the action to be performed
 *      *
 *       * Return: Void
 *        */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	    size_t i;

	        if (array == NULL || action == NULL)
			        return;

		    for (i = 0; i < size; i++)
			            action(array[i]);
}


