#include "libmx.h"

t_ll mx_atoll(t_cc *str) {
    bool sign = 0;
    t_ll sum = 0;

    for (; mx_isspace(*str); ++str);
    if (*str == '+' || *str == '-')
        sign = *str++ == '-';
    for (; *str && mx_isdigit(*str); ++str)
        sum = sum * 10 + *str - 48;
    return sign ? -sum : sum;
}