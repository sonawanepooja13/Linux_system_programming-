/*
check file access permission
accept a filename and mode (read, write, execute)
use access() to check permission for current process
print accessible / not accessible with reason
*/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
    char filename[100];
    char mode[10];
    int result;

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter mode (read / write / execute): ");
    scanf("%s", mode);

    if (strcmp(mode, "read") == 0)
    {
        result = access(filename, R_OK);
    }
    else if (strcmp(mode, "write") == 0)
    {
        result = access(filename, W_OK);
    }
    else if (strcmp(mode, "execute") == 0)
    {
        result = access(filename, X_OK);
    }
    else
    {
        printf("Please select correct mode\n");
        return 1;
    }

    if (result == 0)
    {
        printf("File is accessible with %s permission\n", mode);
    }
    else
    {
        printf("File is NOT accessible with %s permission\n", mode);

        if (errno == EACCES)
            printf("Reason: Permission denied\n");
        else if (errno == ENOENT)
            printf("Reason: File does not exist\n");
        else
            perror("Reason");
    }

    return 0;
}
