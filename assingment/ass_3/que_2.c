/*
check a file present in directory 
accept directory name and filename 
check wheather filename present in directory 
print absolute path if present 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <limits.h>  
#include <unistd.h>   

#define DIR_PATH 256
#define FILE_MAX 256

int main() {
    char dir_path[DIR_PATH];
    char file_name[FILE_MAX];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char abs_path[PATH_MAX];

    printf("Accept a Directory name: ");
    scanf("%s", dir_path);

    printf("Enter a filename: ");
    scanf("%s", file_name);

    dp = opendir(dir_path);
    if (dp == NULL) {
        perror("Unable to open directory");
        return 1;
    }

    int found = 0;

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, file_name) == 0) {
            // Construct absolute path
            if (realpath(dir_path, abs_path) != NULL) {
                strcat(abs_path, "/");
                strcat(abs_path, file_name);
                printf("File found at: %s\n", abs_path);
            } else {
                perror("Error getting absolute path");
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("File not found in directory.\n");
    }

    closedir(dp);
    return 0;
}
