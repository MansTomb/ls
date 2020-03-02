#pragma once
#include "uls.h"

#define MX_ISBLK(m)    (((m) & S_IFMT) == S_IFBLK)     // block special
#define MX_ISCHR(m)    (((m) & S_IFMT) == S_IFCHR)     // char special
#define MX_ISDIR(m)    (((m) & S_IFMT) == S_IFDIR)     // directory
#define MX_ISFIFO(m)   (((m) & S_IFMT) == S_IFIFO)     // fifo or socket
#define MX_ISREG(m)    (((m) & S_IFMT) == S_IFREG)     // regular file
#define MX_ISLNK(m)    (((m) & S_IFMT) == S_IFLNK)     // symbolic link
#define MX_ISSOCK(m)   (((m) & S_IFMT) == S_IFSOCK)    // socket
#if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
#define MX_ISWHT(m)    (((m) & S_IFMT) == S_IFWHT)     // whiteout
#endif

#define MX_MINOR(x) ((x) & 0xFFFFFF)
#define MX_MAJOR(x) (((x) >> 24) & 0xFF)

#define MX_EXIST(x) mx_strchr(MX_FLAGS, x)
#define MX_WRITE(x) mx_strchr("l1mCx", x)
#define MX_LADDS(x) mx_strchr("ghnOT@e", x)
#define MX_OTHER(x) mx_strchr("isGRr", x)
