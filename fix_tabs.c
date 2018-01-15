#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "globals.h"


/*
 * Program that takes a text file (preferably a program file) as argument
 * and fixes the leading tabs or whitespaces
 */
int main(int argc, char *argv[]) {


    if (argc < 3 || argc > 3) {
        fprintf(stderr, "Invalid number of arguments\n");
        return 1;
    };

    switch (argv[2]) {
        case "TAB":
        replace_spaces(argv[1]);
        break;
        case "SPACE":
        replace_tabs(argv[1]);
        break;
        default:
        fprintf(stderr, "Invalid Mode given: expecting TAB, or SPACE\n");
        exit(1);
    }

    return 0;
}
