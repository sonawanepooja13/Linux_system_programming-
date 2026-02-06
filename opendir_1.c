#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>
#include<dirent.h>
int main()
{
    DIR *dp=NULL; 
    dp=opendir("./Data"); 
    
    if(dp==NULL)
    {
          printf("%s unable to open",strerror(errno)); 
        return -1;
    }
    return 0;
}

