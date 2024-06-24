CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu89

all: liball.so

liball.so: main.o
    gcc -shared -o liball.so main.o

clean:
    rm -f *.o *~

fclean: clean
    rm -f liball.so

re: fclean all
