#ifndef SHELL_H
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
