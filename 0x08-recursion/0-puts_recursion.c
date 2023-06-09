


#include "main.h"





/**
*A function to print a string and print a new line
*alx-task
*betty-comment-multiline
*/

void _puts_recursion(char *s){	

	if (*s){
			_putchar(*s);
			_puts_recursion(s + 1);
		}
		else{
			_putchar('\n');
		}
	
}

