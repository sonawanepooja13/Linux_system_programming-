/*
List Files with type 
accept directory nme
print each entry its type: Regular/directory/link/fifo/socket/char/block
use lstat() for accurate type
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

int main()
{
    char filename[100];
    struct stat sobj;
    int iRet = 0;

    printf("Enter file/directory name:\n");
    scanf("%s", filename);

    iRet = lstat(filename, &sobj);
    if (iRet == -1)
    {
        perror("lstat");
        return -1;
    }
    printf("File type for '%s':\n", filename);
    if (S_ISREG(sobj.st_mode))
        printf("Regular File\n");
    else if (S_ISDIR(sobj.st_mode))
        printf("Directory\n");
    else if (S_ISLNK(sobj.st_mode))
        printf("Symbolic Link\n");
    else if (S_ISFIFO(sobj.st_mode))
        printf("FIFO (Named Pipe)\n");
    else if (S_ISSOCK(sobj.st_mode))
        printf("Socket\n");
    else if (S_ISCHR(sobj.st_mode))
        printf("Character Device\n");
    else if (S_ISBLK(sobj.st_mode))
        printf("Block Device\n");
    else
        printf("Unknown Type\n");

    return 0;
}
