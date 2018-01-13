#include <stdio.h>


int main(int argc, char *argv[]) {


    if (argc == 1) {
        fprintf(stderr, "Not enough arguments\n");
        return 0;
    }

    FILE file = fopen(argv[1], "r+")

    return 0;

}
