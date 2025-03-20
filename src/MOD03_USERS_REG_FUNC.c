#include "../include/defs.h"

void MOD03_USERS_REG_FUNC(void)
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
