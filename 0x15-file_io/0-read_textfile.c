#include "main.h"
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
