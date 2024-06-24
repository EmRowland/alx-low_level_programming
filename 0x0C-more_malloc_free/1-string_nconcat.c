#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes of s2 to concatenate
 * 
 * Return: pointer to the newly allocated space in memory containing the concatenated strings, or NULL if it fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    char *concat;
    unsigned int len1 = 0, len2 = 0, i, j;

    if (s1 != NULL)
        for (len1 = 0; s1[len1]; len1++)
            ;
    if (s2 != NULL)
        for (len2 = 0; s2[len2]; len2++)
            ;

    if (n >= len2)
        n = len2;

    concat = malloc((len1 + n + 1) * sizeof(char));
    if (concat == NULL)
        return (NULL);

    for (i = 0; i < len1; i++)
        concat[i] = s1[i];
    for (j = 0; j < n; j++, i++)
        concat[i] = s2[j];
    concat[i] = '\0';

    return (concat);
}

