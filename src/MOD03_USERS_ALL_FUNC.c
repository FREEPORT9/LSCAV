#include "../include/defs.h"

void MOD03_USERS_ALL_FUNC(void)
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
