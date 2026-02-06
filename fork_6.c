#include<stdio.h>
#include<unistd.h>

int main()
{
    if(fork()==0) 
    {
          printf("child process schedule\n"); 
    }
    else
    {
        printf("Parent process SCheduled\n"); 
    }
      
    return 0;
}

