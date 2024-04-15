#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: pointer to the string to be searched
 * @needle: pointer to the substring to locate
 *

 */
char *_strstr(char *haystack, char *needle)
{
    while (*haystack != '\0')
    {
        char *start = haystack;
        char *pattern = needle;

        while (*pattern != '\0' && *haystack != '\0' && *haystack == *pattern)
        {
            haystack++;
            pattern++;
        }

        if (*pattern == '\0')
            return start;

        haystack = start + 1;
    }

    return NULL;
}
