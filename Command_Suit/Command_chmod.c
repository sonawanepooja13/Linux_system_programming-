#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
//////////////////////////////////////////
// ./chmodx  mode   filename.txt 
//////////////////////////////////////////
/// Algorithm ////////////////////////
/*

start 
read a filename and permission from command liine 
call algorithm 
print a message 
stop 
*/

int main(int argc,char *argv[])
{
    mode_t mode;
    int iRet=0; 

    if(argc!=3)
    {
       printf("Error :Insufficient Arguments\n"); 
       printf("Usage : ./chmodx <permission> <filename>\n"); 
       return -1; 
    }
    //to check file exit or not  using access command 
    if(access(argv[2],F_OK)!=0)
    {
        printf("File not present\n"); 
        return -1; 
    }
    //step 3: convert file of string into octol 
    mode = strtol(argv[1],NULL,8); 

    //call chmod system 
    iRet=chmod(argv[2],mode); 

    if(iRet==-1)
    {
        perror("chmod"); 
        return -1; 
    }
    printf("Permission changed sucessfully\n"); 
    return 0; 
}