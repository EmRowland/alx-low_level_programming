#include "main.h"

/**
 *  * _sqrt_helper - Helper function to find the natural square root
 *   * @n: The number to find the square root of
 *    * @i: The current divisor being tested
 *     *
 *      * Return: The square root, or -1 if not a natural square root
 *       */
int _sqrt_helper(int n, int i)
{
	    if (i * i > n)
		        {
				        return (-1);
					    }
	        if (i * i == n)
			    {
				            return (i);
					        }
		    return (_sqrt_helper(n, i + 1));
}

/**
 *  * _sqrt_recursion - Returns the natural square root of a number using recursion
 *   * @n: The number to find the square root of
 *    *
 *     * Return: The natural square root, or -1 if not found
 *      */
int _sqrt_recursion(int n)
{
	    if (n < 0)
		        {
				        return (-1);
					    }
	        return (_sqrt_helper(n, 0));
}

