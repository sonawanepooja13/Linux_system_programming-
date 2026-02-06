#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void fun()
{
     printf("inside Fun function\n"); 
}
void gun()
{
     printf("inside Gun function\n");    
}

int main()
{
    printf("Process is created :\n"); 
    atexit(fun); 
    atexit(gun);
     exit(11); 
}   