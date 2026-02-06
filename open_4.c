#include<fcntl.h>
#include<stdio.h>
int main()
{

     int fd=0; 
     fd=open("second.c",O_CREAT ||O_TRUNC,0777); 
     if(fd==-1)
     {
           printf("can't create a file "); 
     }
     else
     {
          printf("file Created: Suceesfully :- %d",fd); 
     }
      return 0; 

}