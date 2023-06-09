#include "main.h"

/**
 * do hard things
 *
 * Return: length of the string
 */
int _strlen_recursion(char *s)
{
    /*
    check if the memory address in no
    */
	if (*s == '\0'){

        return (0);
    }else{
        /*
        if not null return the number*/
        return (1 + _strlen_recursion(s + 1));
    }
		
    
	
}