#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#define MAX_BUFFER_SIZE 1024 
//////////////////////////////////////////////
// ./touchx    Source.txt
// argv[0]     argv[1] 
//argc =2
////////////////////////////////////////////
/*
//////////////////////Algorithm ////////////////
Accept file name from comamnd lin e
check wheather file is existing or not 
if it existing then print on console 
display no such file on directory 
*/
////////////////////////////////////////////////
int main(int argc,char *argv[])
{
    if(argc !=2)
    {
        printf("Error : Insufficient Arguments\n"); 
        printf("Used Command as : ./catxx  Filename \n"); 

        return -1; 
    } 
    if(access(argv[1],F_OK)!=0)
    {
           printf("cat :%s No Such file or directory \n",argv[1]); 
           return -1; 

    }
    else
    {
        int fd=0; 
        fd=open(argv[1],O_RDONLY); 
        if(fd <0)
        {
            printf("Error : Unable to open file\n"); 
            return -1; 
        }
        char Buffer[MAX_BUFFER_SIZE]={'\0'}; 
        int iRet=0; 
        while((iRet =read(fd,Buffer,sizeof(Buffer)))!=0)
        {
            write(1,Buffer,iRet); 
        }
        printf("\n"); 
    }

    return 0; 
}