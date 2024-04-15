#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: pointer to the string to be searched
 * @accept: pointer to the string containing the bytes to search for
 
 */
char *_strpbrk(char *s, char *accept)
{
    while (*s != '\0')
    {
        char *ptr = accept;
        while (*ptr != '\0')
        {
            if (*s == *ptr)
                return s;
            ptr++;
        }
        s++;
    }

    return NULL;
}
