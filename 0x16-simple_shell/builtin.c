#include "shell.h"

/**
 * builtin commands - an array of builtin command names
 */
char *builtin_str[] = {
    "cd",
    "help",
    "exit"
};

/**
 * builtin functions - an array of functions to execute built-in commands
 */
int (*builtin_func[]) (char **) = {
    &_cd,
    &_help,
    &_exit
};

/**
 * num_builtins - returns the number of builtin commands
 *
 * Return: number of builtins
 */
int num_builtins(void)
{
    return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * _cd - changes the current directory of the process
 * @args: arguments array
 *
 * Return: Always 1
 */
int _cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "expected argument to "cd"\n");
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("cd");
        }
    }
    return (1);
}

/**
 * _help - prints the help information
 * @args: arguments array
 *
 * Return: Always 1
 */
int _help(char **args)
{
    int i;

    printf("Simple Shell
");
    printf("Type program names and arguments, and hit enter.
");
    printf("The following are built in:
");

    for (i = 0; i < num_builtins(); i++)
    {
        printf("  %s
", builtin_str[i]);
    }

    return (1);
}

/**
 * _exit - exits the shell
 * @args: arguments array
 *
 * Return: Always 0
 */
int _exit(char **args)
{
    return (0);
}
