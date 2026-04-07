#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

//////////////////////////////////////////////
// ./statx    Source.txt
// argv[0]     argv[1] 
//argc =2
////////////////////////////////////////////
/*
//////////////////////Algorithm ////////////////
Accept file name from comamnd line
call access to check existance of file 
call stat system call to get files meta data 
dispaly the metadata 
*/
////////////////////////////////////////////////
int main(int argc ,char *argv[])
{
    if(argc !=2)
    {
        printf("Error : Insufficient Arguments\n"); 
        printf("Used Command as : ./statx  Filename \n"); 

        return -1; 
    } 
    if(access(argv[1],F_OK)==0)
    {
        struct stat sobj; 
        int iRet=0; 
        iRet=stat(argv[1],&sobj); 
        if(iRet==-1)
        {
            printf("Error : Unable to fetch Stastical Information\n "); 
            return -1; 
        }
        printf("File name :%s\n",argv[1]); 
        printf("File size :%ld\n",(long)sobj.st_size); 
        printf("Inode Number :%ld\n",(long)sobj.st_ino); 
    }
    else
    {
        printf("Error : File not found\n"); 
        return -1; 
        
    }

    return 0; 
}