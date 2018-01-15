#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "globals.h"


void place_tabs(FILE *read_file, FILE *dest_file, int space_num) {

    // place the tabs in the temp file
    float num_tabs = (float) space_num / (float) NUM_SPACE_FOR_TAB;
    int tab_num = round(num_tabs);
    // add the tabs to the file
    while (tab_num > 0) {
        fprintf(dest_file, "%c", '\t');
        tab_num--;
    }
    char nchar;
    while((nchar = fgetc(read_file)) != '\n') {
        fprintf(dest_file, "%c", nchar);
    }
    fprintf(dest_file, "%c", '\n');
}


void fix_tabs(char *filename) {

    FILE *file, *temp_file;
    // open files
    if ((file = fopen(filename, "r")) == NULL) {
        perror("Unable to open file with given name\n");
    }
    if ((temp_file = fopen("temp", "w")) == NULL) {
        perror("Unable to open temporary file\n");
    }
    int space_count = 0;
    char nchar;
    while ((nchar = fgetc(file)) != EOF) {
        if (nchar == SPACE) {
            space_count = num_preceding_spaces(file);
        }
        if (nchar != SPACE) {

            fseek(file, -1, SEEK_CUR);
            place_tabs(file, temp_file, space_count);
        }
    }
    // file closing and removal of temp files
    if (fclose(file) == EOF) {
        fprintf(stderr, "Error closing %s\n", filename);
        exit(EXIT_FAILURE);
    }
    if (fclose(temp_file) == EOF) {
        perror("Error closing temp file\n");
    }
    if (remove(filename) == -1) {
        fprintf(stderr,"Could not remove file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    if (rename("temp", filename) == -1) {
        fprintf(stderr, "Could not rename temp to %s\n", filename);
	exit(EXIT_FAILURE);
    }
    printf("Success...\n");
}

