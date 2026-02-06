/* 
 list all files from directory
 accept directory name
 use opendir() and readdir()
 print only names (skip . and ..)
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
int main()
{
    DIR *dp = NULL; 
    struct dirent *entry;
    char dirname[100];

    printf("Enter a directory name: "); 
    scanf("%s", dirname); 

    dp = opendir(dirname);
    if(dp == NULL)
    {
        printf("%s Unable to open directory\n", strerror(errno)); 
        return -1;
    }
    printf("Files in directory '%s':\n", dirname);
    while ((entry = readdir(dp)) != NULL)
    {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dp);
    return 0; 
}
