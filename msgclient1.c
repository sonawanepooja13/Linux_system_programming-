#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<stdlib.h>
int main()
{
     key_t key; 
     key=ftok(".",'a'); 
     int id=0; 
     id=msgget(key,0666); 
     if(id==-1)
     {
         printf("Unable to allocate msg Queue \n"); 
         return -1; 
     }
     return 0; 

}