#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L
#define _XOPEN_SOURCE 700

// STANDARD_FUNCTION

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// MOD00_MENU_FUNC

#include <getopt.h>

// MOD02_SYSTEM_INFO_FUNC

#include <sys/utsname.h>

// MOD03_USERS_FUNC

#include <pwd.h>

// MOD04_GROUPS_FUNC

#include <grp.h>

void MOD00_MENU_FUNC(int argc, char** argv);
void MOD01_USAGE_FUNC(void);
void MOD02_SYSTEM_INFO_FUNC(void);
void MOD03_USERS_ALL_FUNC(void);
void MOD03_USERS_REG_FUNC(void);
void MOD04_GROUPS_FUNC(void);

#endif // DEFINITIONS_H
