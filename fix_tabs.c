#include <stdio.h>

#define TAB '\t'
#define SPACE ' '



/*
 * function that skips the rest of the line
 * @param file -> File that is being read
 */
void skip_line(FILE *file) {

    while (fgetc(file) != '\n');
}


void print_num_tabs(FILE *file) {

    int tab_count = 1;
    while (fgetc(file) == TAB) {
        tab_count++;
    }
    printf("%d\n", tab_count);
}


void print_num_spaces(FILE *file) {

    // space is one because we have already
    // read one space
    int space_number = 1;
    while (fgetc(file) == SPACE) {
        space_number++;
    }
    printf("%d\n", space_number);
}



/*
 * Program that takes a text file (preferably a program file) as argument
 * and fixes the leading tabs or whitespaces
 */
int main(int argc, char *argv[]) {


    if (argc == 1) {
        fprintf(stderr, "Not enough arguments\n");
        return 1;
    }

    if (argc > 2) {
        fprintf(stderr, "Too many arguments\n");
        return 1;
    }

    FILE *file;
    file = fopen(argv[1], "r+");
    printf("Opening File\n");

    int nchar;
    while ((nchar = fgetc(file)) != EOF) {

        if (nchar == TAB) {
            print_num_tabs(file);
        }

        else if (nchar == SPACE) {
            print_num_spaces(file);
        }

        else {
            skip_line(file);
        }
    }
    fclose(file);
    printf("Closing File\n");

    return 0;

}
