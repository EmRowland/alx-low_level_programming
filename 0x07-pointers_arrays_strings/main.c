#include <stdio.h>
#include "main.h"

int main(void)
{
	char *s = "hello, world";
	char *f = "world";
	char *t;

	t = _strpbrk(s, f);
	if (t != NULL)
	{
		printf("First matching character: %c\n", *t);
	}
	else
	{
		printf("No matching character found.\n");
	}

	return (0);
}
