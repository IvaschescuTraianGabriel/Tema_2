#include "process_directory.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <source_dir> <destination_dir> <space_threshold>\n", argv[0]);
        return 1;
    }

    const char *src_dir = argv[1];
    const char *dst_dir = argv[2];
    int space_threshold = atoi(argv[3]);

    process_directory(src_dir, dst_dir, space_threshold);
    return 0;
}
