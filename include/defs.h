// Guards [ DEFS_H ]

#ifndef DEFS_H
#define DEFS_H

// General Purpose [ mod_00 ]

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void menu(int argc, char** argv);

void print_usage();

// Command Line Arguments [ mod_01 ]

#include <unistd.h>

// System Information [ mod_02 ]

#include <sys/types.h>
#include <sys/utsname.h>

void system_info();

// Group & User Information [ mod_03, mod_04 ]

#include <grp.h>
#include <pwd.h>

void all_users();

void all_groups();

void regular_users();

//

#endif
