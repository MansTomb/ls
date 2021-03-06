#include "libmx.h"

static inline void reduce_queue(t_queue *q) {
    uint8_t *temp_arr = q && q->arr ? malloc((q->cap / 2) * q->bytes) : NULL;

    if (temp_arr) {
        if (q->tail < q->head) {
            mx_memcpy(temp_arr, q->arr + q->head * q->bytes,
                (q->cap - q->head + 1) * q->bytes);
            mx_memcpy(temp_arr + (q->cap - q->head + 1) * q->bytes,
                q->arr, (q->tail + 1) * q->bytes);
        }
        else
            mx_memcpy(temp_arr, q->arr, q->cap * q->bytes);
        if (MX_MALLOC_SIZE(q->arr))
            free(q->arr);
        q->arr = temp_arr;
        q->cap /= 2;
        q->head = 0;
        q->tail = q->size - 1;
    }
}

void *mx_dequeue(t_queue *q) {
    void *item = mx_front(q);

    if (q && q->arr && q->size) {
        q->head = q->head + 1 == q->cap ? 0 : q->head + 1;
        --q->size;
        if ((float)q->cap / q->size > 4 && q->cap > MX_QUEUE_DEFAULT_SIZE)
            reduce_queue(q);
    }
    return item;
}
