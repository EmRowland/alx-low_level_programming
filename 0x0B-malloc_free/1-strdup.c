#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory, which contains a copy of the string given as a parameter
 * @str: string to duplicate
 * 
 * Return: pointer to the duplicated string, or NULL if it fails
 */
char *_strdup(char *str)
{
    char *copy;
    unsigned int i, len;

    if (str == NULL)
        return (NULL);

    for (len = 0; str[len]; len++)
        ;

    copy = malloc((len + 1) * sizeof(char));
    if (copy == NULL)
        return (NULL);

    for (i = 0; i < len; i++)
        copy[i] = str[i];
    copy[len] = '\0';

    return (copy);
}

