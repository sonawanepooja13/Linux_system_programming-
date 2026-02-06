#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>

int main()
{

    char Arr[50]; 
    memset(Arr,'\0',sizeof(Arr)); 
    getcwd(Arr,sizeof(Arr)); 
   printf(" current directire %s\n",Arr); 
    return 0; 
}
