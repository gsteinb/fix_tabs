#include <stdio.h>




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
        printf("%c|\n", nchar);
    }
    fclose(file);
    printf("Closing File\n");

    return 0;

}
