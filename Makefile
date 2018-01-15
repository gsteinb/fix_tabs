# Makefile for image retrieval program.

# need the lm for the math import 
FLAGS= -Wall -g -std=gnu99 -lm

all : fix_tabs

fix_tabs : fix_tabs.o globals.o replace_spaces.o replace_tabs.o
	gcc -o $@ fix_tabs.o globals.o replace_spaces.o ${FLAGS}

# Separately compile each C file
%.o : %.c
	gcc -c $< ${FLAGS}

fix_tabs.o : globals.h
replace_tabs.o : globals.h
replace_spaces.o : globals.h
globals.c : globals.h

clean :
	-rm *.o fix_tabs


