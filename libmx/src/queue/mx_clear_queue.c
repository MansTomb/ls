#include "libmx.h"

void mx_clear_queue(t_queue *q) {
    if (q && q->size) {
        q->cap = MX_QUEUE_DEFAULT_SIZE;
        q->size = q->head = q->tail = 0;
        if (MX_MALLOC_SIZE(q->arr))
            free(q->arr);
        q->arr = malloc(q->bytes * MX_QUEUE_DEFAULT_SIZE);
    }
}
