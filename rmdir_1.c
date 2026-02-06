#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>
#include<dirent.h>
int main()
{
    int iRet=0; 
    //folder name 
    iRet=rmdir("./Data"); 
    if(iRet==0)
    { 
        printf("directory get deleted\n"); 
    }
    else
    {
        printf("%s\n",strerror(errno)); 


    }

    return 0;
}

