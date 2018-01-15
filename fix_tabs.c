#include <stdio.h>
#include <math.h>
#include "globals.h"


/*
 * Program that takes a text file (preferably a program file) as argument
 * and fixes the leading tabs or whitespaces
 */
int main(int argc, char *argv[]) {


    if (argc < 2 || argc > 2) {
        fprintf(stderr, "Invalid number of arguments\n");
        return 1;
    };

    fix_tabs(argv[1]);

    return 0;
}
