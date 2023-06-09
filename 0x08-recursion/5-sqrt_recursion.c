#include "main.h"

/**
 *Asleep
 *
 * Hard thing to do
 */
int _check_sqrt_perfect(int n, int i)
{  
    
     if (i * i == n)
		return (i);
        /*
        *check if the ans * ans will give the number if not it doest have a perfect root*/
	if (i * i > n)
		return (-1);
	
	return (_check_sqrt_perfect(n, i + 1));
}

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_check_sqrt_perfect(n, 0));
}