#ifndef DEFINITIONS_H
#define DEFINITIONS_H

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
void MOD01_USAGE_FUNC();
void MOD02_SYSTEM_INFO_FUNC();
void MOD03_USERS_ALL_FUNC();
void MOD03_USERS_REG_FUNC();
void MOD04_GROUPS_FUNC();

#endif // DEFINITIONS_H
