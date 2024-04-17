#include "count_spaces.h"
#include <stdio.h>

int count_spaces(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return -1;
    }
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ') count++;
    }
    fclose(file);
    return count;
}
