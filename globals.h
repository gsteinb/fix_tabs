#define TAB '\t'
#define SPACE ' '

extern int SPACES_FOR_TAB;
extern int LINE_NUMBER;

int num_preceding_spaces(FILE *);
int num_preceding_tabs(FILE *);
void place_spaces(FILE *, FILE *, int);
void place_tabs(FILE *, FILE *, int);
void replace_spaces(char *);
void replace_tabs(char *);
void copy_file(FILE *, FILE *);

