#include "defs.h"

void menu(int argc, char** argv)

{

    // All values set to 0

    opterr = 0; // No Default Error Message (getopt)

    int option = 0, dflag = 0, gflag = 0, uflag = 0, rflag = 0, sflag = 0;

    // If there are no arguments, print the default usage message and exit

    if (argc < 2) {
        print_usage();
        exit(1);
    }

    // Argument Flags (Including Default Flag)

    char str[80]; // Default Message

    while ((option = getopt(argc, argv, "-:surg")) != -1)

    {
        switch (option)

        {
        case 's':
            if (sflag) {
            } else {
                sflag++;
                printf("\n");
                system_info();
            }
            break;

        case 'u':
            if (uflag) {
            } else {
                uflag++;
                printf("\n");
                all_users();
            }
            break;

        case 'r':
            if (rflag) {
            } else {
                rflag++;
                printf("\n");
                regular_users();
            }
            break;

        case 'g':
            if (gflag) {
            } else {
                gflag++;
                printf("\n");
                all_groups();
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

    puts(str); // Print the unrecognized option if any exist
}

void print_usage()

{
    // This function prints standard Usage Information

    printf("\n[*] Usage Information\n");
    printf("\n./lscav \n\n");
    printf("[-u List All Users] \n");
    printf("[-g List All Groups]\n");
    printf("[-r List Regular Users Only] \n");
    printf("[-s List System Information] \n");
    printf("\n");
}
