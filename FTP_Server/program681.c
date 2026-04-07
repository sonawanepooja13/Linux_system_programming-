#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
     int iRet=0; 
     iRet=fork(); 
     if(iRet==0)
     {
        printf("Child process of running with PID :%d\n",getpid()); 
     }
     else
     {
        printf("Parent process of running process with PID:%d\n",getppid()); 
        
     }
}