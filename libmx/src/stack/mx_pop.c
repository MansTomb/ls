#include "libmx.h"

void mx_pop(t_stack *st) {
    if (st && st->arr) {
        --st->size;

        if ((float)st->cap / st->size > 4 && st->cap > STACK_DEFAULT_SIZE) {
            st->cap /= 2;
            st->arr = mx_realloc(st->arr, st->cap * st->bytes);
        }
    }
}
