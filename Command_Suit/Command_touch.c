#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

//////////////////////////////////////////////
// ./touchx    Source.txt
// argv[0]     argv[1] 
//argc =2
////////////////////////////////////////////
/*
//////////////////////Algorithm ////////////////
Accept file name from comamnd lin e
check wheather file is existing or not 
if it existing return 
if it is not existing then create that file 
*/
////////////////////////////////////////////////
int main(int argc ,char *argv[])
{
    if(argc !=2)
    {
        printf("Error : Insufficient Arguments\n"); 
        printf("Used Command as : ./touchx  Filename \n"); 

        return -1; 
    } 
    if(access(argv[1],F_OK)==0)
    {
         return 0; 
    }
    else
    {
        creat(argv[1],0777); 
    }
    return 0; 
}