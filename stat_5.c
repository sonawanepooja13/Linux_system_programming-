#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sobj;
    int iRet = 0;

    iRet = stat(argv[1],&sobj);

    printf("Inode number : %ld\n",sobj.st_ino);
    printf("Hardlink count : %ld\n",sobj.st_nlink);
    printf("Total size : %ld\n",sobj.st_size);
    printf("Block size : %ld\n",sobj.st_blksize);


    printf(" File Type is :%d\n",sobj.st_mode);

    if(S_ISBLK(sobj.st_mode))
    {
         printf("Block device\n"); 
    }
    else if(S_ISCHR(sobj.st_mode))
    {
        printf("CHaracter device\n");  

    }
    else if(S_ISDIR(sobj.st_mode))
    {
        printf("Directory  device\n");  

    }
    else if(S_ISREG(sobj.st_mode))
    {
        printf(" Regular file  device\n");  

    }

    else if(S_ISSOCK(sobj.st_mode))
    {
        printf("Socke file\n");  

    }
    
else if(S_ISFIFO(sobj.st_mode))
    {
        printf("file pipe\n");  

    }
    
    return 0;
}

