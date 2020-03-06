#include "libmx.h"

int mx_get_unum_length(uint64_t nbr, uint32_t base) {
    int result = (nbr == 0);

    for (; nbr; nbr /= base, ++result);
    return result;
}
