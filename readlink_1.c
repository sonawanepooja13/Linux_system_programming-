#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>


 int main()
 {
    int fd=0; 
    fd=open("./Test/LSPl.txt",O_RDONLY);  //issue 
    if(fd==-1)
    {
        printf("Unable to open file :%s",strerror(errno)); 
        return -1; 

    }
    printf("File Opened with fd:%d\n",fd); 
    close(fd);

     return 0; 

 }