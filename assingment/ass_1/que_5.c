/*
Read N  byte from file 
accept a filename and number of bytes N
Read exactly N byte using read () and print on console 
if file contain less than N , print only available bytes 
*/

#include<stdio.h>
#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
#include<errno.h>
#include<string.h>
 int main()
 {
     int fd; 
     char filename[100]; 
     char Buffer[100]={'\0'};
     int N_Byte; 
     int iRet=0; 
     printf("enter which file you want to open:"); 
     scanf("%s",filename); 
     

     fd=open(filename,O_RDONLY); 
     if(fd==-1)
     {
         printf("UNable to open file"); 
         //scanf("Reason :%s\n",strerror(errno)); 
           printf("Reason : %s\n",strerror(errno));
         return -1; 
     }
     else
     { 
        printf("%s file opened successfully:\n",filename); 
     }
    printf("enter how many bytes you want to read\n"); 
    scanf("%d",&N_Byte); 
    
//read system call
    iRet=read(fd,Buffer,N_Byte); 
    if(iRet==-1)
    {
        // printf("Reason :%s",strerror(errno));   
          printf("Reason : %s\n",strerror(errno));
          return -1; 
    }
    else
    {
         printf("%d bytes gets succesfully read\n",iRet);
         printf("Data from file  : %s\n",Buffer);

    }

    return 0; 
 }
