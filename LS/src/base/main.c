#include "uls.h"

// тут сначала выводим файлы
// потом запускаем для папок

// static inline void process_args(t_info *info) {
//     // структура, в которую по-очереди забивается инфа об открытой папке
//     // из argv. (фича: dir->name = av[index])
//     t_dir dir = {0};
//     info->output_dst = dir.has_bc;

//     // фор чёта там
// }

void init_getters(t_get *get) {
    get->access = zaglushka;
    get->acl = zaglushka;
    get->attr = zaglushka;
    get->bsize = zaglushka;
    get->flags = zaglushka;
    get->grp = zaglushka;
    get->inode = zaglushka;
    get->links = zaglushka;
    get->name = mx_get_name;
    get->size = zaglushka;
    get->suffix = mx_get_suffix;
    get->time = mx_get_time;
    get->user = zaglushka;
}

void init_info(t_info *info) {
    info->read = mx_standart;
    info->cmp = mx_compare_ascii;
    info->time_type = modification;
    info->output_dst = !isatty(1);
    info->write = info->output_dst ? mx_write_1 : mx_write_C;
    info->print_name = mx_nocolor;
    info->directories = {MX_VECTOR_DEFAULT_SIZE, 0, sizeof(char *),
    malloc(sizeof(char *) * MX_VECTOR_DEFAULT_SIZE)};
    info->files = {MX_VECTOR_DEFAULT_SIZE, 0, sizeof(char *),
    malloc(sizeof(char *) * MX_VECTOR_DEFAULT_SIZE)};
    init_getters(&info->get);
}

int main(int ac, char **av) {
    t_info info = {0};

    if (ac > 1) {
        init_info(info);
        mx_parse(&info, ac, av);
        // process_args(&info);
    }
    else
        mx_error_usage();

    return info.return_val;
}
