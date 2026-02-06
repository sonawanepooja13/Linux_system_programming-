#include<fcntl.h>
#include<stdio.h>
int main()
{
    int fd=0; 
    fd=creat("LSP.txt",0777); 
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
