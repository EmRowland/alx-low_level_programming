#include "main.h"

/**
 * do hard things
 *
 * its night already betty
 */
int _pow_recursion(int x, int y)
{
	if (y < 0){
        return (-1);

    } 
		
	else if (y == 0){
        return (1);

    }else{
        return (x * _pow_recursion(1, y ));
    }
		
	
}