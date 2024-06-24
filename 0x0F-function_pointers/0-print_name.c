#include <stdio.h>
#include "main.h"

/**
 *  * print_name - Prints a name
 *   * @name: Name to print
 *    * @f: Function pointer to print the name
 *     *
 *      * Return: Void
 *       */
void print_name(char *name, void (*f)(char *))
{
	    if (name == NULL || f == NULL)
		            return;

	        f(name);
}


