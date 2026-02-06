#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>

int main()
{
    int iRet=0; 
    //folder name 
    iRet=mkdir("./Data",0777); 
    if(iRet==0)
    { 
        printf("directory get created\n"); 
    }

    return 0;
}

