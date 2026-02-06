#include<stdio.h> 
#include<string.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{

    int fd=0; 
    struct stat st; 
    char * ptr=NULL; 

    fd=open("Pune.txt",O_RDWR |O_CREAT,0777); 
    ftruncate(fd,4096); 
    fstat(fd,&st); 

    ptr=mmap(NULL,st.st_size,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,fd,0);
    strcpy(ptr,"Gay Ganesh..");
    printf("Data From mapped memory is :%s\n",ptr); 
    munmap(ptr,st.st_size);
    close(fd);
     return 0;  
}