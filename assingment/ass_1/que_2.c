/*open file given  mode 
accept a file name and mode (R,W,RW,A)
Convert mode to flags (O_RDONLY,O_WRONLY,0_RDWR,0_APPEND)
open a file accordingly and display descriptor 
*/
#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int fd=0; 
    char filename[100];
    char mode[3]; 
    int flags; 
    printf("enter a file which you want to open"); 
    scanf("%s",filename); 

    printf("enter which mode you want to open:"); 
    scanf("%s",mode); 
    

    if (strcmp(mode, "R") == 0)
    {
        flags=O_RDONLY; 
    }
    else if (strcmp(mode, "W") == 0)
    {
        flags=O_WRONLY; 
    }
    else if(strcmp(mode,"RW")==0)
    {
        flags=O_RDWR; 
    }
   else if(strcmp(mode,"A")==0)
    {
        flags=O_WRONLY | O_APPEND; 
    }
   else
   {
     printf("Please select proper mode"); 
   }

   fd=open(filename,flags); 
   if(fd==-1)
   {
    printf("There is error in opening file"); 
   }
   else
  {
    printf("file opened sucessfully "); 
    printf("File descriptor:%d ",fd); 
  }
      return 0; 

}