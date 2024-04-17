#include "process_file.h"
#include "count_spaces.h"
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void process_file(const char *src_path, const char *dst_path, int space_threshold) {
    struct stat statbuf;
    if (stat(src_path, &statbuf) != 0) {
        perror("Failed to get file stats");
        return;
    }

    if (S_ISREG(statbuf.st_mode)) {
        const char *ext = strrchr(src_path, '.');
        if (ext && strcmp(ext, ".txt") == 0) {
            int space_count = count_spaces(src_path);
            if (space_count > space_threshold) {
                char new_path[1024];
                snprintf(new_path, sizeof(new_path), "%s_spaces", dst_path);
                symlink(src_path, new_path);
            }
        } else {
            link(src_path, dst_path);
            chmod(dst_path, S_IRUSR | S_IRGRP);
        }
    }
}
