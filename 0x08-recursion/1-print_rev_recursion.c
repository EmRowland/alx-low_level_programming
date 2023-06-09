
/**
*A function to print a string and print a new line
*alx-task
*betty-comment-multiline
*/

void _print_rev_recursion(char *s){
    try{
		if (*s){
			_puts_recursion(s + 1);
            _putchar(*s);
		}
		
	}
	catch (Exception e){
		_putchar('\n');
	}
}