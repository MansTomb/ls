#include "uls.h"

int mx_compare_time(const void *a, const void *b) {
    const t_file *f1 = b;
    const t_file *f2 = a;

    if (f1->time.tv_sec != f2->time.tv_sec) {
        return f1->time.tv_sec - f2->time.tv_sec;
    }
    if (f1->time.tv_nsec != f2->time.tv_nsec) {
        return f1->time.tv_nsec - f2->time.tv_nsec;
    }
    return mx_strcmp(f2->fields.name, f1->fields.name);
}
