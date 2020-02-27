#pragma once

#include <dirent.h>

#include "defines.h"
#include "errors.h"
#include "libmx.h"
#include "macro.h"
#include "structs.h"

#include <grp.h>
#include <pwd.h>
#include <sys/acl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>

void mx_parse(int argnum, char **argum);

struct dirent *mx_full(t_dir *dir);
struct dirent *mx_hidden(t_dir *dir);
struct dirent *mx_standart(t_dir *dir);

void mx_write_1(t_dir *dir);
void mx_write_C(t_dir *dir);
void mx_write_l(t_dir *dir);
void mx_write_m(t_dir *dir);
void mx_write_x(t_dir *dir);

void mx_write_CG(t_dir *dir);
void mx_write_xG(t_dir *dir);

int mx_compare_ascii(const void *a, const void *b);
int mx_compare_size(const void *a, const void *b);
int mx_compare_time(const void *a, const void *b);
