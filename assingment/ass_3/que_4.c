/*
delete all empty regualr file 
accept directory name 
delete file size=0 byte (regualr file) 
print name deleted+deleted count 
*/


#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include<limits.h>


int main()
{
    char dirname[100];
    char path[200];

    DIR *dp;
    struct dirent *entry;
    struct stat sb;

    int deleted_count = 0;

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
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        printf(path, "%s %s", dirname, entry->d_name);
        

        if (stat(path, &sb) == -1)
        {
            perror("stat");
            continue;
        }

        // Check for regular file with size 0
        if (S_ISREG(sb.st_mode) && sb.st_size == 0)
        {
            if (remove(path) == 0)
            {
                printf("Deleted: %s\n", path);
                deleted_count++;
            }
            else
            {
                perror("remove");
            }
        }
    }

    closedir(dp);

    printf("Total empty files deleted: %d\n", deleted_count);

    return 0;
}
