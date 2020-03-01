#include "uls.h"

static inline char *get_file_name(char *av) {
    for (char *temp = mx_strchr(av, '/'); temp; temp = mx_strchr(av, '/'))
        av = temp + 1;
    return av;
}

static void parse_file(t_info *info, char *av) {
    DIR *dir = NULL;
    struct stat st;
    ++info;

    if (lstat(av, &st) == -1) {
        mx_printstr("ls: ", 2);
        perror(av);
    }
    else if ((dir = opendir(av)) == NULL) {
        mx_printstr("ls: ", 2);
        perror(get_file_name(av));
    }
    else {
        closedir(dir);
        if (MX_ISREG(st.st_mode))
            mx_push_backward(&info->files, av);
        else
            mx_push_backward(&info->directories, av);
    }

    // if ((dir = opendir(av))) {
    //     mx_push_backward(&info->directories, av);
    //     closedir(dir);
    //     return;
    // }
    // else if (access(av, F_OK) != -1) {
    //     if (access(av, R_OK) != 0) {
    //         mx_printstr("uls: ", 2);
    //         mx_printstr(get_file_name(av), 2);
    //         mx_printstr(": Permission denied\n", 2);
    //     }
    //     // Бахнуть флажок шо эт файл чтобы не пытаться его открыть а просто вывести его доступы допустим в л флаге
    //     // Или не бахать флажок и сделать такую же проверку уже когда передаем юлсу его
    //     // Не кикать из вектора arg_dir эта папка вполе себе папка
    //     mx_push_backward(&info->files, av); // Пушим файл в вектор файлов которые аргв
    //     return;
    // }
    // else {
    //     mx_printstr("uls: ", 2);
    //     perror(av);
    // }
}

static inline bool check_doubleminus(char *av) {
    if (av[2])
        mx_nelegal(av[1]);
    return false;
}

static bool parse_flag(t_vector *flags, char *av) {
    if (av[0] == '-' && av[1] == '-')
        return check_doubleminus(av);

    for (int i = 1; av[i]; ++i) {
        if (MX_EXIST(av[i])) // Проверяем флаг с [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuvwx1] если есть добавляем
            mx_push_backward(flags, av + i);
        else
            mx_nelegal(av[i]); // Выводим ошибку причём две illegal option а потом usage_error и ливаем с катки
    }
    return true;
}

void mx_parse(t_info *info, int ac, char **av) {
    t_vector *flags = mx_create_vector(0, sizeof(char));
    bool flag = true;
    int i = 1;

    for (; flag && i < ac && av[i][0] == '-'; ++i)
        flag = parse_flag(flags, av[i]);

    for (; i < ac; ++i)
        parse_file(info, av[i]);

    // парсинг флагов в функи
    mx_delete_vector(flags);
}
