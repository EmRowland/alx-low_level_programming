#include "shell.h"

/**
 * split_line - splits a line into tokens
 * @line: input line
 *
 * Return: array of tokens
 */
char **split_line(char *line)
{
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "lsh: allocation error
");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " 	
");
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize)
        {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "lsh: allocation error
");
                exit(EXIT_FAILURE);
            }
        }m

        token = strtok(NULL, " 	
");
    }
    tokens[position] = NULL;
    return (tokens);
}
