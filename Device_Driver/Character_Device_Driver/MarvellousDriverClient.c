//to write a client 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

#define DEVICE_PATH "/dev/marvellous_driver"
#define BUFFER_SIZE 1024
int main()
{


    int fd; 
    int iRet=0; 
    char read_buffer[BUFFER_SIZE]; 
    char write_buffer[BUFFER_SIZE]; 
    //
    printf("Opening a Marvellous Driver"); 
    fd=open(DEVICE_PATH,O_RDWR); 
    if(fd<0)
    {
        printf("Error :Unable to open Marvelllous Driver\n"); 
        return -1; 
    }
    printf("Marvellous driver open sucessfullly\n"); 
    printf("Enter data for Marvellous driver\n"); 
    fgets(write_buffer,BUFFER_SIZE,stdin); 
    //echo "jay ganesh ..." /dev/
    write_buffer[strcspn(write_buffer,"\n")]=0; 
    printf("writin to Marvellous Device\n"); 

  iRet=  write(fd,write_buffer,strlen(write_buffer)); 
  if(iRet<0)
  {
    printf("Error : Unable to write into Marvellous Device\n"); 
    close(fd); 
    return -1; 

  }
  printf("Data Sucessfully written into Marvellous Driver\n"); 
  printf("Reading data from Marvellous Driver..\n"); 
  // cat  /dev/marvellous/driver 
  iRet=read(fd,read_buffer,BUFFER_SIZE); 
  if(iRet<0)
  {
    printf("Unable to read data from Marvellous Driver\n"); 
    close(fd); 
    return -1; 
  }
  read_buffer[iRet]='\0'; 
  printf("Data Received from Marvellous Driver :%s\n",read_buffer); 
  printf("Closing Marvellous Driver\n"); 
  close(fd); 

     return 0; 
}