#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "globals.h"


void place_spaces(FILE *read_file, FILE *dest_file, int num_tabs) {

    // number of spaces relative to tabs e.g. 1 tab = 4 spaces
    // can be changed in globals.h
    int num_spaces = num_tabs * NUM_SPACE_FOR_TAB;
    while (num_spaces > 0) {
        fprintf(dest_file, "%c", ' ');
        num_tabs--;
    }
    char nchar;
    while ((nchar = fgetc(read_file)) != '\n') {
        fprintf(dest_file, "%c", nchar);
    }
    fprintf(dest_file, "%c", '\n');
}



void replace_tabs(char *filename) {

    FILE *file, *temp_file;
    // open file
    if ((file = fopen(filename, "r")) == NULL) {
        perror("Unable to open file with given name\n");
    }
    // open temp file
    if ((temp_file = fopen("temp", "w")) == NULL) {
        perror("Unable to open temp file\n");
    }
    int tab_count = 0;
    char nchar;
    while ((nchar = fgetc(file)) != EOF) {
        if (nchar == TAB) {
           space_count = num_preceding_tabs(file);
        }
        if (nchar != TAB) {

            fseek(file, -1, SEEK_CUR);
            place_spaces(file, temp_file, tab_count);
    }

    if (fclose(file) == EOF) {
        perror("Error closing file\n");
    }
    if (fclose(temp_file) == EOF) {
        perror("Error closing temp file\n");
    }
    if (remove(filename) == -1) {
        perror("Could not remove file\n");
    }
    if (rename("temp", filename) == -1) {
        perror("Could not rename temp file\n");
    }
    printf("Success...\n");

}