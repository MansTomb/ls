#include "libmx.h"

int mx_count_substr(t_cc *str, t_cc *sub) {
    if (str && sub) {
        int len1 = mx_strlen(str);
        int len2 = mx_strlen(sub);

        if (len1 >= len2) {
            int result = 0;

            for (bool f; (str = mx_strchr(str, *sub)); str += f ? 1 : len2)
                if ((f = mx_strncmp(str, sub, len2)) == 0)
                    ++result;
            return result;
        }
    }
    return str && sub ? 0 : -1;
}
