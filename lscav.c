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
#include <string.h>
#include <sys/types.h> // Defines System Data Types
#include <sys/utsname.h> // System Information
#include <unistd.h> // POSIX System Calls

// Function Prototypes

void M001_MENU(int argc, char** argv); // Displays Menu & Handles Arguments
void M002_SYSTEM(void); // Collects System Information
void M003_USERS(int REG_USR); // Collects Users Information
void M004_GROUPS(void); // Collects Group Information

int main(int argc, char** argv)
{
    M001_MENU(argc, argv);

    return 0;
}

void M001_MENU(int argc, char** argv)
{

    if (argc < 2) {

        printf("\n[*] Usage Information\n");
        printf("\n./lscav \n\n");
        printf("[-u List All Users] \n");
        printf("[-g List All Groups]\n");
        printf("[-r List Regular Users Only] \n");
        printf("[-s List System Information] \n");
        printf("\n");

        exit(1);
    } // Print Usage Message if no Arguments

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && strspn(&argv[i][1], "surg") == strlen(&argv[i][1])) {
            continue;
        }

        printf("\n[*] Warning Information\n\nWARNING: Bad input detected! %s\n\n", argv[i]);
        exit(1);
    }

    opterr = 0; // Disable Error Message for GETOPT

    int flags[] = { 0, 0, 0, 0, 0, 0 }; // option, sflag, uflag, rflag, gflag, dflag

    while ((flags[0] = getopt(argc, argv, "-:surg")) != -1) {

        {
            switch (flags[0])

            {
            case 's':
                if (!flags[1]++) {
                    printf("\n");
                    M002_SYSTEM();
                }
                break;

            case 'u':
                if (!flags[2]++) {
                    printf("\n");
                    M003_USERS(0);
                }
                break;

            case 'r':
                if (!flags[3]++) {
                    printf("\n");
                    M003_USERS(1);
                }
                break;

            case 'g':
                if (!flags[4]++) {
                    printf("\n");
                    M004_GROUPS();
                }
                break;

            default:
                break;
            }
        }
    }
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

void M003_USERS(int REG_USR)
{
    printf("\n[*] Full User List\n\n");

    struct passwd* p_loop;

    uid_t uid = (REG_USR) ? 1000 : 0; // 1000 for Regular Users Only

    // Loop through users (either all or regular ones)
    while ((p_loop = (REG_USR ? getpwuid(uid) : getpwent())) != NULL) {

        // Print user details
        printf("%-20s: %s\n", "[-] Username", p_loop->pw_name);
        printf("%-20s: %d\n", "[-] UID", (int)p_loop->pw_uid);
        printf("%-20s: %d\n", "[-] GID", (int)p_loop->pw_gid);

        int ngroups = 0;

        // Get List of Groups the User Belongs To
        getgrouplist(p_loop->pw_name, p_loop->pw_gid, NULL, &ngroups);

        gid_t groups[ngroups];

        // Fill the Array with those Groups
        getgrouplist(p_loop->pw_name, p_loop->pw_gid, groups, &ngroups);

        printf("%-20s: ", "[-] Groups");

        // Print Group Information

        for (int i = 0; i < ngroups; i++) {
            struct group* g_single = getgrgid(groups[i]);
            printf("%s ", g_single->gr_name);
        }

        printf("\n");

        printf("%-20s: %s\n", "[-] Default Shell", p_loop->pw_shell);
        printf("%-20s: %s\n", "[-] Home Directory", p_loop->pw_dir);
        printf("%-20s: %s\n", "[-] Information", p_loop->pw_gecos);

        printf("\n\n");

        // Move to the next user (increment UID if we're showing regular users)
        if (REG_USR) {
            uid++;
        }
    }

    // End the user enumeration when done
    endpwent();
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
