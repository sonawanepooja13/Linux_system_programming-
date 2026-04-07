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
Accept file name from comamnd lin e
call access to check existance of file 
call stat system call to get files meta data 
dispaly the metadata 
*/
////////////////////////////////////////////////
void DisplayPermission(mode_t m)
{
    char Arr[11]="-----------"; 
    if( m & S_ISDIR(m)) Arr[0]='d'; 
     if( m & S_ISLNK(m)) Arr[0]='l'; 

    //Regular file file permission 
    if(m & S_IRUSR)
    {
        Arr[1]='r'; 

    }
     if(m & S_IWUSR)
    {
        Arr[2]='w'; 
    }
     if(m & S_IXUSR)
    {
        Arr[3]='x'; 

    }
     if(m & S_IRGRP)
    {
        Arr[4]='r'; 

    }
   if(m & S_IWGRP)
    {
        Arr[5]='w'; 

    }
   if(m & S_IXGRP)
    {
        Arr[6]='x'; 

    }
     if(m & S_IROTH)
    {
        Arr[7]='r'; 

    }
     if(m & S_IWOTH)
    {
        Arr[8]='w'; 

    }

    if(m & S_IXOTH)
    {
        Arr[9]='x'; 

    }
    printf("File Permission :%s\n",Arr); 
}

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
        DisplayPermission(sobj.st_mode);
    }
    else
    {
        printf("Error : File not found\n"); 
        return -1; 
        
    }

    return 0; 
}