#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 * 
 * Return: integer
 */
int _atoi(char *s)
{
    int i = 0, n = 0, sign = 1;

    while ((s[i] < '0' || s[i] > '9') && s[i] != '\0')
    {
        if (s[i] == '-')
            sign *= -1;
        i++;
    }

    while (s[i] >= '0' && s[i] <= '9')
    {
        n = n * 10 + (s[i] - '0');
        i++;
    }

    return (n * sign);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * 
 * Return: 0 if success, 98 if error
 */
int main(int argc, char *argv[])
{
    int num1, num2, result;

    if (argc != 3)
    {
        printf("Error\n");
        exit(98);
    }

    num1 = _atoi(argv[1]);
    num2 = _atoi(argv[2]);

    if (num1 < 0 || num2 < 0)
    {
        printf("Error\n");
        exit(98);
    }

    result = num1 * num2;

    printf("%d\n", result);
    return (0);
}

