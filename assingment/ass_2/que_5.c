
/*
 find largest file in directory
 accept directory name
 find and print largest file name
 and its size in bytes
 consider only regular files (ignore directories)
*/
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main()
{
    char dirname[100];
    char path[200];
    char largest[100] = "";

    DIR *dp;
    struct dirent *entry;
    struct stat sb;

    long max = 0;

    printf("Enter a directory: ");
    scanf("%s", dirname);

    dp = opendir(dirname);
    if (dp == NULL)
    {
        printf("Unable to open directory\n");
        return 1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        if (entry->d_name[0] == '.')   // skip . and ..
            continue;

       sprintf(path, "%s/%s", dirname, entry->d_name);

        stat(path, &sb);

        if (S_ISREG(sb.st_mode) && sb.st_size > max)
        {
            max = sb.st_size;
            strcpy(largest, entry->d_name);
        }
    }

    closedir(dp);

    printf("Largest file: %s\n", largest);
    printf("Size: %ld bytes\n", max);

    return 0;
}
