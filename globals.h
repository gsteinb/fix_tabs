#define BUFFER_SIZE 30
#define TAB '\t'
#define SPACE ' '
#define NUM_SPACE_FOR_TAB 4

int num_preceding_spaces(FILE *);
int num_preceding_tabs(FILE *);
void place_spaces(FILE *, FILE *, int);
void place_tabs(FILE *, FILE *, int);
void replace_spaces(char *);
void replace_tabs(char *);
void copy_file(FILE *, FILE *);

