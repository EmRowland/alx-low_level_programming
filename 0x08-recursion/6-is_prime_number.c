#include "main.h"

/**
 *dont sleep
 *ce qui
 */
int _default_checker(int n, int i)
{
	if (i == 1){
        return (1);

    }
		
	if (n % i == 0 && i > 0){
        return (0);
    }else{
        return (1);
        }
    return (_default_checker(n, i - 1));
}

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (_default_checker(n, n - 1));
}