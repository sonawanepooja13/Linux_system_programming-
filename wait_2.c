#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
   pid_t pid=0; 
   pid_t x=0; 
   int status=0; 
   pid=fork(); 
   if(pid==0) //child
   {
    sleep(10);
    exit(11);
   
   }
   else
   {
     x=wait(&status);
     printf("Child with pid %d gets terminated with status %d\n",x,WEXITSTATUS(status));

   }
     return 0; 

}