
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{

    pid_t pid=0; 
    pid=fork(); 
    if(pid==0)  //child run 
    {
        printf("Child process is running\n"); 
        printf("PID of Child is:%d & PPID of child is :%d\n",getpid(),getppid()); 
        sleep(30);
        printf("PID of Child is:%d & PPID of child is :%d\n",getpid(),getppid()); 
        exit(0);


    }
    else //parenet run 
    {
        printf("parent process is running\n"); 
        printf("PID of Parent is:%d & PPID of Parent is :%d\n",getpid(),getppid()); 
        exit(1); 

    }
     return 0; 

}