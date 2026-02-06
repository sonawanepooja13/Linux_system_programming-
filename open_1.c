#include<fcntl.h>
#include<stdio.h>
int main()
{

     int fd=0; 
     fd=open("demo.c",O_RDONLY); 
     if(fd==-1)
     {
           printf("can't open file"); 
     }
     else
     {
          printf("file opened:%d",fd); 
     }
      return 0; 

}