#include "uls.h"

void mx_bsize(t_info *info, t_dir *dir, t_file *file, t_stat *st) {
    int bsize_len = mx_get_num_length(st->st_blocks, 10);

    file->fields.bsize = mx_lltoa(st->st_blocks);
    file->lengths.bsize = bsize_len;
    if (dir->off.bsize < bsize_len)
        dir->off.bsize = bsize_len;
    ++info;
}
