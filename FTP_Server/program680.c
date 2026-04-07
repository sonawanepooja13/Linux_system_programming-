#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
     printf("Pid of running process :%d",getpid()); 
     printf("PID of parent proceess :%d",getppid()); 
     return 0; 
}