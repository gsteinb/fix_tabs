# Makefile for image retrieval program.

# need the lm for the math import 
FLAGS= -Wall -g -std=gnu99 -lm

all : fix_tabs

fix_tabs : fix_tabs.o
	gcc -o $@ fix_tabs.o ${FLAGS}

# Separately compile each C file
%.o : %.c
	gcc -c $< ${FLAGS}

clean :
	-rm *.o


