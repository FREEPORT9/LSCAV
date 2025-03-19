/*
 * =======================================================================
 * Project:    Linux Scavenger (LSCAV)
 * File:       lscav.c
 * Author:     Nikola Kipariz Stamov
 * Date:       March 2025
 * License:    Creative Commons Attribution-NonCommercial 4.0 International (CC BY-NC 4.0)
 *             For more details, please refer to the following URL:
 *             https://creativecommons.org/licenses/by-nc/4.0/
 *
 * Description:
 *
 * Linux Scavenger is a versatile and powerful tool designed to assist in the
 * comprehensive collection, analysis, and presentation of critical system
 * information on Linux-based operating systems.
 *
 * The tool aims to provide users with a reliable, user-friendly means of
 * exploring and understanding key system metrics, promoting informed decision-making
 * and enhancing system administration processes.
 *
 * With a focus on efficiency and precision, Linux Scavenger is an invaluable
 * resource for developers, system administrators, and users who require
 * detailed insights into their Linux environment.
 *
 * =======================================================================
 */

// INCLUDES

#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <unistd.h>

// PROTOTYPES

void MOD01_MENU_FUNC(int argc, char** argv);
void MOD02_SYSTEM_INFO_FUNC();
void MOD03_USERS_FUNC();
void MOD04_GROUPS_FUNC();

// MAIN

int main(int argc, char** argv)

{
    MOD01_MENU_FUNC(argc, argv);

    return 0;
}

// FUNCTIONS

void MOD01_MENU_FUNC(int argc, char** argv)
{
    opterr = 0;

    int option = 0, dflag = 0, gflag = 0, uflag = 0, rflag = 0, sflag = 0;

    if (argc < 2) {

        printf("\n[*] Usage Information\n");
        printf("\n./lscav \n\n");
        printf("[-u List All Users] \n");
        printf("[-g List All Groups]\n");
        printf("[-r List Regular Users Only] \n");
        printf("[-s List System Information] \n");
        printf("\n");

        exit(1);
    }

    char str[80];

    while ((option = getopt(argc, argv, "-:surg")) != -1)

    {
        switch (option)

        {
        case 's':
            if (sflag) {
            } else {
                sflag++;
                printf("\n");
                MOD02_SYSTEM_INFO_FUNC();
            }
            break;

        case 'u':
            if (uflag) {
            } else {
                uflag++;
                printf("\n");
                MOD03_USERS_FUNC(1);
            }
            break;

        case 'r':
            if (rflag) {
            } else {
                rflag++;
                printf("\n");
                MOD03_USERS_FUNC(0);
            }
            break;

        case 'g':
            if (gflag) {
            } else {
                gflag++;
                printf("\n");
                MOD04_GROUPS_FUNC();
            }
            break;

        default:
            if (dflag) {
            } else {
                dflag++;
                snprintf(str, 80, "\n[*] Warning Information\n\nWARNING: Bad input detected! -%c\n",
                    optopt);
            }
        }
    }

    puts(str);
}

void MOD02_SYSTEM_INFO_FUNC()
{

    printf("\n[*] System Information\n\n");

    struct utsname uts;

    if (uname(&uts) < 0)
        perror("uname() error");
    else {
        printf("%-20s: %s\n", "[-] OS", uts.sysname);
        printf("%-20s: %s\n", "[-] Hostname", uts.nodename);
        printf("%-20s: %s\n", "[-] Release", uts.release);
        printf("%-20s: %s\n", "[-] Version", uts.version);
        printf("%-20s: %s\n", "[-] Architecture", uts.machine);
        printf("\n");
    }
}

void MOD03_USERS_FUNC(int choice)
{

    if (choice)

    {
        printf("\n[*] Full User List\n\n");

        struct passwd* p_loop;

        while ((p_loop = getpwent()) != NULL) {
            printf("%-20s: %s\n", "[-] Username", p_loop->pw_name);
            printf("%-20s: %d\n", "[-] UID", (int)p_loop->pw_uid);
            printf("%-20s: %d\n", "[-] GID", (int)p_loop->pw_gid);

            int ngroups = 0;

            getgrouplist(p_loop->pw_name, p_loop->pw_gid, NULL, &ngroups);
            __gid_t groups[ngroups];

            getgrouplist(p_loop->pw_name, p_loop->pw_gid, groups, &ngroups);

            printf("%-20s: ", "[-] Groups");

            for (int i = 0; i < ngroups; i++) {
                struct group* g_single = getgrgid(groups[i]);

                printf("%s ", g_single->gr_name);
            }

            printf("\n");

            printf("%-20s: %s\n", "[-] Default Shell", p_loop->pw_shell);
            printf("%-20s: %s\n", "[-] Home Directory", p_loop->pw_dir);
            printf("%-20s: %s\n", "[-] Information", p_loop->pw_gecos);

            printf("\n\n");
        }

        endpwent();
    } else {
        printf("\n[*] Regular User List\n\n");

        struct passwd* p_single;

        uid_t uid = 1000;

        while ((p_single = getpwuid(uid)) != NULL) {
            printf("%-20s: %s\n", "[-] Username", p_single->pw_name);
            printf("%-20s: %d\n", "[-] UID", (int)p_single->pw_uid);
            printf("%-20s: %d\n", "[-] GID", (int)p_single->pw_gid);

            int ngroups = 0;

            getgrouplist(p_single->pw_name, p_single->pw_gid, NULL, &ngroups);
            __gid_t groups[ngroups];

            getgrouplist(p_single->pw_name, p_single->pw_gid, groups, &ngroups);

            printf("%-20s: ", "[-] Groups");

            for (int i = 0; i < ngroups; i++) {
                struct group* g_single = getgrgid(groups[i]);

                printf("%s ", g_single->gr_name);
            }

            printf("\n");

            printf("%-20s: %s\n", "[-] Default Shell", p_single->pw_shell);
            printf("%-20s: %s\n", "[-] Home Directory", p_single->pw_dir);
            printf("%-20s: %s\n", "[-] Information", p_single->pw_gecos);
            printf("\n");
            uid++;
        }
    }
}

void MOD04_GROUPS_FUNC()
{

    printf("\n[*] Full Group List\n\n");

    struct group* g_loop;

    while ((g_loop = getgrent()) != NULL) {
        printf("%-20s: %s\n", "[-] Groupname", g_loop->gr_name);
        printf("%-20s: %d\n", "[-] GID", (int)g_loop->gr_gid);
        printf("%-20s: ", "[-] Users");
        for (size_t i = 0;; i++) {
            if (g_loop->gr_mem[i] == NULL)
                break;
            printf("%s ", g_loop->gr_mem[i]);
        }

        printf("\n\n");
    }
    endgrent();
}
