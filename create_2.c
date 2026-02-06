#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd=0; 
    fd=creat(argv[1],0777); 

    if(fd==-1)
    {
         printf("Unable to craete file\n"); 

    }
    else
    {
        printf("file get sucessfully created with fd:%d\n",fd); 
    }

     return 0; 

}
