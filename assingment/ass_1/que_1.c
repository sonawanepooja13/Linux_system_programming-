//Write a program which handle below task 
//accept a file name from user and open it using open() function 
//print sucess message and returned file descriptor 
//handle error using prror

#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
int main()
{

    char filename[100]; 
    int fd=0; 
    //to accept file 
    printf("Enter which fil you want to opened:"); 
    scanf("%s",filename);

    fd=open(filename,O_RDONLY); 
    if(fd==-1)
      {
       perror("Error is in opening file"); 
       return -1; 
      }
      else
      {
        printf("file opened sucessfully"); 
        printf("file descriptor :%d",fd);
        
      }

    return 0; 

}