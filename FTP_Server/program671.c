
//Client side code 
//...............................................
#include<stdio.h> //printf,scanf
#include<sys/socket.h> //socket,bind,listen ,connect 
#include<stdlib.h> //malloc,free
#include<string.h> //memeset,memcmp
#include<unistd.h> //macro 
#include<fcntl.h> //crarte ,read
#include<netinet/in.h>  //sockaddir_in ,htons
#include<arpa/inet.h>
int main()
{
    int ServersocketFD=0; 
    int iRet=0; 
    int port=11000; 
     struct sockaddr_in serverAddresss; 
//Step 1: Create TCP Socket 
    ServersocketFD=socket(AF_INET,SOCK_STREAM,0); 
    
    if(ServersocketFD <0)
    {
        printf("Unable to create socket"); 
        return -1; 
    }
   printf("Socket get created sucessfully with fd :%d\n", ServersocketFD); 

 //step 2: connect with server 
    memset(&serverAddresss,0,sizeof(serverAddresss)); 
    serverAddresss.sin_family=AF_INET; 
    serverAddresss.sin_port=htons(port); 
    //127.0.0.1 convert port no into binary form 
    inet_pton(AF_INET,"127.0.0.1",&serverAddresss.sin_addr); 

    iRet=connect(ServersocketFD,(struct sockaddr *)&serverAddresss,sizeof(serverAddresss)); 

    if(iRet==1)
    {
        printf("Unable to connect server\n"); 

    }
    printf("Server connected sucessfully\n"); 
    return 0; 
} 