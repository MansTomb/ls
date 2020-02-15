#pragma once

#include "defines.h"
#include "errors.h"
#include "libmx.h"
#include "macro.h"
#include "structs.h"

#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <sys/acl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>

void mx_parse(int argnum, char **argum);
