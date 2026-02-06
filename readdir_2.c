#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <dirent.h>

int main()
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;

    dp = opendir(".");   // open current directory
    if (dp == NULL)
    {
        printf("%s unable to open\n", strerror(errno));
        return -1;
    }

  

    while( ptr = readdir(dp))
   {
        printf("Inode number: %ld\n", ptr->d_ino);
        printf("File name: %s\n", ptr->d_name);
   }

    closedir(dp);
    return 0;
}
