#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

//////////////////////////////////////////////
// ./pwdx    
// argv[0]     
//argc =1
////////////////////////////////////////////
/*
//////////////////////Algorithm ////////////////
call system call getcwd 
print the result of getcwd 

*/
////////////////////////////////////////////////
int main(int argc ,char *argv[])
{
    char Buffer[1024]={'\0'}; 
    getcwd(Buffer,sizeof(Buffer)); 
    printf("this command is used to print   Current working Directory\n");
    printf("%s\n",Buffer); 

    return 0; 
}