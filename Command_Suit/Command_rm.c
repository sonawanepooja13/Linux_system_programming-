#include<stdio.h>
#include<string.h>
#include<sys/utsname.h>

#include<fcntl.h>
#include<unistd.h>


//////////////////////
//.rmx 
//argv[0]
//argc=1
int main(int argc, char *argv[])
{
     if(argc!=2)
     {
         printf("Error : unable to open file\n "); 
         printf("Usage : provide source path\n"); 
         return -1; 
     }
   if(access(argv[1],F_OK)==0)
    {
      if(unlink(argv[1])==-1)
      {
        printf("Error :Unable to delete \n"); 
        return -1; 
      }
      else
      {
        printf(" Sucess : File get Deleted\n"); 
      }
    }
    else
    {
        printf("Unable to open to file has no permission\n"); 
        return -1; 
    }
return 0; 

}
