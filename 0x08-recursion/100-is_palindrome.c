#include "main.h"

/**
 * @define code by documenting soon
 * Return: On success 1 else -1
 */
int _palindrome_check(char *a, int l)
{
	if (*a == 0){
		return (l - 1);
        }
	return (_palindrome_check(a + 1, l + 1));
}

int _palindrom_exec(char *a, int l)
{
	if (*a != *(a + l)){
		return (0);
        }
	else if (*a == 0){
		return (1);
        }
	return (_palindrom_exec(a + 1, l - 2));
}

int is_palindrome(char *s)
{
	int l;

	l = _palindrome_check(s, 0);
	return (_palindrom_exec(s, l));
}