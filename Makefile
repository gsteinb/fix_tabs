# Makefile for image retrieval program.

FLAGS= -Wall -std=gnu99

all : fix_tabs

fix_tabs : fix_tabs.o
	gcc -o $@ fix_tabs.o ${FLAGS}

# Separately compile each C file
%.o : %.c
	gcc -c $< ${FLAGS}

clean :
	-rm *.o


