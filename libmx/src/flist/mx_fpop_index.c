#include "libmx.h"

void mx_fpop_index(t_flist *list, t_ll index) {
    t_flist_node *del_node = NULL;
    t_flist_node *prev_node = list ? list->head : NULL;

    if (list && list->head) {
        if (index <= 0)
            mx_fpop_front(list);
        else if (index >= list->size - 1)
            mx_fpop_back(list);
        else {
            for (t_ll pos = 0; ++pos < index; prev_node = prev_node->next);

            del_node = prev_node->next;
            prev_node->next = del_node->next;

            free(del_node);
            --list->size;
        }
    }
}
