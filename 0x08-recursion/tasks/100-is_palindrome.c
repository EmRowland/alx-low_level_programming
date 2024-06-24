
/**
 *  * _strlen_recursion - Returns the length of a string using recursion
 *   * @s: The string to be measured
 *    *
 *     * Return: The length of the string
 *      */
int _strlen_recursion(char *s)
{
    if (*s == '\0')
    {
        return (0);
    }
    return (1 + _strlen_recursion(s + 1));
}

/**
 *  * is_palindrome_helper - Helper function to check if a string is a palindrome
 *   * @s: The string to be checked
 *    * @start: The starting index
 *     * @end: The ending index
 *      *
 *       * Return: 1 if the string is a palindrome, 0 otherwise
 *        */
int is_palindrome_helper(char *s, int start, int end)
{
    if (start >= end)
    {
        return (1);
    }
    if (s[start] != s[end])
    {
        return (0);
    }
    return (is_palindrome_helper(s, start + 1, end - 1));
}

/**
 *  * is_palindrome - Checks if a string is a palindrome
 *   * @s: The string to be checked
 *    *
 *     * Return: 1 if the string is a palindrome, 0 otherwise
 *      */
int is_palindrome(char *s)
{
    int len = _strlen_recursion(s);

    if (len == 0)
    {
        return (1);
    }
    return (is_palindrome_helper(s, 0, len - 1));
}

