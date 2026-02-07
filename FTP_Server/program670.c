
//Client side code 
//...............................................
#include<stdio.h> //printf,scanf
#include<sys/socket.h> //socket,bind,listen ,connect 
#include<stdlib.h> //malloc,free
#include<string.h> //memeset,memcmp
#include<unistd.h> //macro 
#include<fcntl.h> //crarte ,read
#include<netinet/in.h>  //sockaddir_in ,htons
int main()
{
    int ServersocketFD=0; 
//Step 1: Create TCP Socket 
    ServersocketFD=socket(AF_INET,SOCK_STREAM,0); 
    
    if(ServersocketFD <0)
    {
        printf("Unable to create socket"); 
        return -1; 
    }
   printf("Socket get created sucessfully with fd :%d\n", ServersocketFD); 


    return 0; 
} 