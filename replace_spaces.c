#include <stdio.h>
#include <math.h>
#include "globals.h"


void place_chars(FILE *read_file, FILE *dest_file, int space_num) {

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
        if (nchar != SPACE && nchar != TAB) {

            fseek(file, -1, SEEK_CUR);
            place_chars(file, temp_file, space_count);
        }
    }
    char error_msg[BUFFER_SIZE];
    if (fclose(file) == EOF) {
        sprintf(error_msg, "Error closing %s\n", filename);
        perror(error_msg);
    }
    if (fclose(temp_file) == EOF) {
        perror("Error closing temp file\n");
    }
    if (remove(filename) == -1) {
        sprintf(error_msg, "Could not remove file %s\n", filename);
        perror(error_msg);
    }
    if (rename("temp", filename) == -1) {
        sprintf(error_msg, "Could not rename temp to %s\n", filename);
        perror(error_msg);
    }
    printf("Success...\n");
}
