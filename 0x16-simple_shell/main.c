#include "shell.h"

/**
 * main - entry point for the shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char *line;
    char **args;
    int status;

    do {
        printf("$ ");
        line = read_line();
        args = split_line(line);
        status = execute(args);

        free(line);
        free(args);
    } while (status);

    return (0);
}
