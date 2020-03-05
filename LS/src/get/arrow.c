#include "uls.h"

void mx_arrow(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    static char buff[1024];
    ssize_t len = readlink(dir->filename, buff, 1024);

    buff[len] = '\0';
    file->fields.arrow = mx_strncpy(mx_strncpy(malloc(len + 5), " -> ", 4) + 4, buff, len + 1) - 4;
    ++info;
    ++st;
}
