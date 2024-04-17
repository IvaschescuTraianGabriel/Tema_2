#include "process_directory.h"
#include "process_file.h"
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void process_directory(const char *src_dir, const char *dst_dir, int space_threshold) {
    DIR *dir = opendir(src_dir);
    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        char src_path[1024];
        char dst_path[1024];
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, entry->d_name);

        struct stat statbuf;
        if (lstat(src_path, &statbuf) != 0) continue;

        if (S_ISDIR(statbuf.st_mode)) {
            mkdir(dst_path, statbuf.st_mode);
            process_directory(src_path, dst_path, space_threshold);
        } else if (S_ISREG(statbuf.st_mode)) {
            process_file(src_path, dst_path, space_threshold);
        }
    }
    closedir(dir);
}
