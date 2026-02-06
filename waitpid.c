#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
     pid_t childpid=0; 
     pid_t ret=0; 
     int status=0; 
     childpid=fork(); 
     if(childpid==0)
     {
        printf("Child is RUnning with pid :%d",getpid()); 
        
        sleep(10); 
        printf("child process is exitsing\n"); 
        exit(11); 

     }
     else
     {
         printf("Parent  is Running\n"); 
         printf("Parent is waiting for child :%d\n",childpid); 
         ret=waitpid(childpid,&status,0); 
         

         if(WIFEXITED(status))
         {
            printf("Child exited with PID :%d\n",ret); 
            printf("EXit Status of Child is :%d\n",WIFEXITED(status));
            
         }

         waitpid(-1,)


     }
}