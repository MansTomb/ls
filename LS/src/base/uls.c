#include "uls.h"

static void free_dir(t_dir *dir) {
    t_file *end = mx_end(&dir->array);

    for (t_file *i = (t_file *)dir->array.arr; i < end; ++i) {
        i->fields.arrow ? free(i->fields.arrow) : (void)0;
        i->fields.bsize ? free(i->fields.bsize) : (void)0;
        i->fields.grp ? free(i->fields.grp) : (void)0;
        i->fields.inode ? free(i->fields.inode) : (void)0;
        i->fields.links ? free(i->fields.links) : (void)0;
        i->fields.size ? free(i->fields.size) : (void)0;
        i->fields.time ? free(i->fields.time) : (void)0;
        i->fields.user ? free(i->fields.user) : (void)0;
        free(i->fields.name);
    }
    free(dir->array.arr);
}

static void get_info(t_info *info, t_dir *dir, t_dirent *file) {
    static t_stat st;
    t_file file_info = {{0}, {0}, {0}, 0, 0};
    void (**func)(t_dir *, t_file *, t_stat *) =
        (void (**)(t_dir *, t_file *, t_stat *))&info->get;

    dir->filename = mx_get_path_name(dir->name, dir->len, file->d_name, file->d_namlen);
    lstat(dir->filename, &st);
    dir->total += st.st_blocks;
    file_info.size = st.st_size;
    file_info.mode = st.st_mode;
    mx_memcpy(&file_info.time, &st.st_atimespec + info->time_type, sizeof(t_timespec));

    for (int i = 0; i < 11; ++i)
        func[i](dir, &file_info, &st);
    mx_push_backward(&dir->array, &file_info);
    mx_strdel(&dir->filename);
}

static inline void process(t_info *info, t_dir *dir) {
    t_dirent *(*read)(DIR *) = info->read;

    dir->file = read(dir->dir);
    for (DIR *pdir = dir->dir; dir->file; dir->file = read(pdir))
        get_info(info, dir, dir->file);

    mx_sort(dir->array.arr, dir->array.size, dir->array.bytes, info->cmp);
    info->print_total(info, dir);
    info->write(info, dir);
}

void mx_uls(t_info *info, t_dir *dir) {
    process(info, dir);
    free_dir(dir);
}

void mx_recursion(t_info *info, t_dir *dir) {
    t_file *end = NULL;
    char *fullname = NULL;

    process(info, dir);
    end = (t_file *)mx_end(&dir->array);
    for (t_file *i = (t_file *)dir->array.arr; i < end; ++i) {
        if (MX_ISDIR(i->mode) && !MX_DOTS(i->fields.name)) {
            fullname = mx_get_path_name(
                dir->name, dir->len, i->fields.name, i->lengths.name);
            mx_printchar('\n', 1);
            mx_printstr(fullname, 1);
            mx_printstrlen(":\n", 2, 1);
            mx_process_dir(info, fullname);
            free(fullname);
        }
    }
    free_dir(dir);
}
