#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd=0; 
    off_t offset=0; 
    int iRet=0; 
    char Buffer[100]="pune"; 
    fd=open("./LSPx.txt",O_WRONLY |O_APPEND); 

    iRet=pwrite(fd,Buffer,5,10);
    write(1,Buffer,iRet); 
    printf("Data from file is:%5s\n",Buffer); 


    offset=lseek(fd,0,SEEK_CUR); 
    printf("Current Offset is :%lld\n",offset); //15
    return 0; 

}