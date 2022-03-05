#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <sys/types.h>
#include <stdint.h>
#include <time.h>
#include <sys/sysmacros.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>

int main(int argc, char *argv[])
{
    struct stat sb;
    DIR *d;
    struct dirent *dir;
    struct passwd *pws;

    d = opendir(".");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
            if (stat(dir->d_name, &sb) < 0)
            {
                printf("File Error Message = %s\n", strerror(errno));
            }
            else
            {
                pws = getpwuid(sb.st_uid);
                printf("Ownership: %s\n", pws->pw_name);
                printf("Permissions: %o\n", sb.st_mode & S_IFMT);
                printf("Last status change:       %s", ctime(&sb.st_ctime));
            }
        }
        closedir(d);
    }

    return 0;
}