#include<stdio.h>
#include<unistd.h>

#include<unistd.h>
int main()
{
    pid_t pid=0; 
    pid=fork(); 
    if(pid<0)
    {
        printf("Unabl eto craete a  child process \n");
        return -1; 

    }
    if(pid==0)
    {
         printf("Child process gets created Sucessfully\n"); 
         
    }
    return 0; 
}
