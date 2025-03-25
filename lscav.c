// Macros

#define _GNU_SOURCE // Enables GNU extensions in glibc [DELETE WHEN POSIX]
#define _POSIX_C_SOURCE 200809L // Enables POSIX 2008 Standard Features
#define _XOPEN_SOURCE 700 // Enables X/Open Version 7 Standard Features

// Header Files

#include <getopt.h> // Command-Line Option Parsing
#include <grp.h> // Group Account Information
#include <pwd.h> // User Account Information
#include <stdio.h> // Standard I/O Functions
#include <stdlib.h> // General Utility Functions
#include <sys/types.h> // Defines System Data Types
#include <sys/utsname.h> // System Information
#include <unistd.h> // POSIX System Calls

// Function Prototypes

void M000_USAGE(void); // Displays Usage Instructions
void M001_MENU(int argc, char** argv); // Displays Menu & Handles Arguments
void M002_SYSTEM(void); // Collects System Information
void M003_ALL_USERS(void); // Collects All Users Information
void M003_REG_USERS(void); // Collects Regular User Information
void M004_GROUPS(void); // Collects Group Information

int main(int argc, char** argv)
{
    M001_MENU(argc, argv);

    return 0;
}

void M000_USAGE(void)
{
    printf("\n[*] Usage Information\n");
    printf("\n./lscav \n\n");
    printf("[-u List All Users] \n");
    printf("[-g List All Groups]\n");
    printf("[-r List Regular Users Only] \n");
    printf("[-s List System Information] \n");
    printf("\n");
}

void M001_MENU(int argc, char** argv)
{
    opterr = 0;

    int option = 0, dflag = 0, gflag = 0, uflag = 0, rflag = 0, sflag = 0;

    if (argc < 2) {

        M000_USAGE();

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
                M002_SYSTEM();
            }
            break;

        case 'u':
            if (uflag) {
            } else {
                uflag++;
                printf("\n");
                M003_ALL_USERS();
            }
            break;

        case 'r':
            if (rflag) {
            } else {
                rflag++;
                printf("\n");
                M003_REG_USERS();
            }
            break;

        case 'g':
            if (gflag) {
            } else {
                gflag++;
                printf("\n");
                M004_GROUPS();
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

void M002_SYSTEM(void)
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

void M003_ALL_USERS(void)
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
}

void M003_REG_USERS(void)
{
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

void M004_GROUPS(void)
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
