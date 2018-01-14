#include <stdio.h>
#include "globals.h"

int num_preceding_spaces(FILE *file) {

    // space is one because we have already
    // read one space
    int space_number = 1;
    while (fgetc(file) == SPACE) {
        space_number++;
    }
    fseek(file, -1, SEEK_CUR);
    return space_number;
}

int num_preceding_tabs(FILE *file) {

    // already read one tab
    int tab_number = 1;
    while (fgetc(file) == TAB) {
        tab_number++;
    }
    fseek(file, -1, SEEK_CUR);
    return tab_number;
}
