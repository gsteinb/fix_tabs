#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"

int LINE_NUMBER = 1;

/*
 * Program that takes a text file (preferably a program file) as argument
 * and fixes the leading tabs or whitespaces
 */
int main(int argc, char *argv[]) {


    if (argc < 3 || argc > 3) {
        fprintf(stderr, "Invalid number of arguments\n");
        return 1;
    };
    if (strlen(argv[2]) > 1) {
        fprintf(stderr, "Invalid Mode given\n");
        return 1;
    }
    switch (argv[2][0]) {
        case 'S':
        replace_spaces(argv[1]);
        break;
        case 'T':
        replace_tabs(argv[1]);
        break;
        default:
        fprintf(stderr, "Invalid Mode given: expecting T, or S\n");
        exit(1);
    }

    return 0;
}
