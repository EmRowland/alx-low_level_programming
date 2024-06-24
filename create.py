import os
import zipfile

projects = {
    "0x12-singly_linked_lists": {
        "README.md": "# 0x12. C - Singly linked lists\n",
        # Additional files...
    },
    "0x13-more_singly_linked_lists": {
        "README.md": "# 0x13. C - More singly linked lists\n",
        # Additional files...
    },
    "0x17-doubly_linked_lists": {
        "README.md": "# 0x17. C - Doubly linked lists\n",
        # Additional files...
    },
    "0x19-stacks_queues_lifo_fifo": {
        "README.md": "# 0x19. C - Stacks, Queues - LIFO, FIFO\n",
        # Additional files...
    },
    "0x1A-hash_tables": {
        "README.md": "# 0x1A. C - Hash tables\n",
        # Additional files...
    },
    "0x1B-sorting_algorithms_big_o": {
        "README.md": "# 0x1B. C - Sorting algorithms & Big O\n",
        # Additional files...
    },
    "0x1D-binary_trees": {
        "README.md": "# 0x1D. C - Binary trees\n",
        # Additional files...
    },
    "0x15-file_io": {
        "README.md": "# 0x15. C - File I/O\n",
        "0-read_textfile.c": """#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters it should read and print
 *
 * Return: the actual number of letters it could read and print, or 0 if an error occurs
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    ssize_t nread, nwritten;
    char *buf;

    if (!filename)
        return (0);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    buf = malloc(sizeof(char) * letters);
    if (!buf)
    {
        close(fd);
        return (0);
    }

    nread = read(fd, buf, letters);
    close(fd);
    if (nread == -1)
    {
        free(buf);
        return (0);
    }

    nwritten = write(STDOUT_FILENO, buf, nread);
    free(buf);

    if (nread != nwritten)
        return (0);

    return (nwritten);
}
""",
        "1-create_file.c": """#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - creates a file with the given filename and writes text_content to it
 * @filename: name of the file to create
 * @text_content: NULL-terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
    int fd, len = 0, nwritten;

    if (!filename)
        return (-1);

    if (text_content)
    {
        while (text_content[len])
            len++;
    }

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1)
        return (-1);

    if (text_content)
    {
        nwritten = write(fd, text_content, len);
        if (nwritten == -1 || nwritten != len)
        {
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}
""",
        "2-append_text_to_file.c": """#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - appends text to the end of a file
 * @filename: name of the file to append to
 * @text_content: NULL-terminated string to add at the end of the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int fd, len = 0, nwritten;

    if (!filename)
        return (-1);

    if (text_content)
    {
        while (text_content[len])
            len++;
    }

    fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1)
        return (-1);

    if (text_content)
    {
        nwritten = write(fd, text_content, len);
        if (nwritten == -1 || nwritten != len)
        {
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}
""",
        "main.h": """#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif /* MAIN_H */
"""
    },
    "0x16-simple_shell": {
        "README.md": "# 0x16. C - Simple Shell\n",
        "shell.h": """#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

char *read_line(void);
char **split_line(char *line);
int execute(char **args);
int _cd(char **args);
int _help(char **args);
int _exit(char **args);
int launch(char **args);
int num_builtins(void);
char *builtin_str[];
int (*builtin_func[]) (char **);

#endif /* SHELL_H */
""",
        "main.c": """#include "shell.h"

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
""",
        "builtin.c": """#include "shell.h"

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
        fprintf(stderr, "expected argument to \"cd\"\\n");
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

    printf("Simple Shell\n");
    printf("Type program names and arguments, and hit enter.\n");
    printf("The following are built in:\n");

    for (i = 0; i < num_builtins(); i++)
    {
        printf("  %s\n", builtin_str[i]);
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
""",
        "execute.c": """#include "shell.h"

/**
 * execute - executes shell commands
 * @args: arguments array
 *
 * Return: status code
 */
int execute(char **args)
{
    int i;

    if (args[0] == NULL)
    {
        return (1);
    }

    for (i = 0; i < num_builtins(); i++)
    {
        if (strcmp(args[0], builtin_str[i]) == 0)
        {
            return ((*builtin_func[i])(args));
        }
    }

    return (launch(args));
}
""",
        "launch.c": """#include "shell.h"

/**
 * launch - launches a program and waits for it to terminate
 * @args: arguments array
 *
 * Return: status code
 */
int launch(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror("lsh");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("lsh");
    }
    else
    {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return (1);
}
""",
        "read_line.c": """#include "shell.h"

/**
 * read_line - reads a line of input from the user
 *
 * Return: the input line
 */
char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("readline");
            exit(EXIT_FAILURE);
        }
    }

    return (line);
}
""",
        "split_line.c": """#include "shell.h"

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
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t\r\n\a");
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
                fprintf(stderr, "lsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }m

        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;
    return (tokens);
}
"""
    }
}

# Create the directory structure and files
for project, files in projects.items():
    os.makedirs(project, exist_ok=True)
    for filename, content in files.items():
        with open(os.path.join(project, filename), 'w') as f:
            f.write(content)

# Zip the directory structure
zip_filename = "alx_tasks.zip"
with zipfile.ZipFile(zip_filename, 'w') as zipf:
    for root, dirs, files in os.walk("."):
        for file in files:
            if file != zip_filename and not file.endswith('.py'):
                zipf.write(os.path.join(root, file))

print(f"{zip_filename} created successfully.")
