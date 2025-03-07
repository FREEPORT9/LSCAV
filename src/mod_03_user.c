#include "defs.h"

void all_users()

{
    // This function lists all users on the system.

    printf("\n[*] Full User List\n\n");

    struct passwd* p_loop;

    while ((p_loop = getpwent()) != NULL) {
        printf("%-20s: %s\n", "[-] Username", p_loop->pw_name);
        printf("%-20s: %d\n", "[-] UID", (int)p_loop->pw_uid);
        printf("%-20s: %d\n", "[-] GID", (int)p_loop->pw_gid);

        // This segment lists all groups related to UID

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

    endpwent(); // Cleanup after Getpwent is finished
}

void regular_users()
{
    // This function lists only regular users on the system.

    printf("\n[*] Regular User List\n\n");

    struct passwd* p_single;

    uid_t uid = 1000; // Scan from this UID onwards.

    while ((p_single = getpwuid(uid)) != NULL) {
        printf("%-20s: %s\n", "[-] Username", p_single->pw_name);
        printf("%-20s: %d\n", "[-] UID", (int)p_single->pw_uid);
        printf("%-20s: %d\n", "[-] GID", (int)p_single->pw_gid);

        // This segment lists all groups related to UID

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
