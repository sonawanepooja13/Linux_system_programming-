
//Server side code 
//...............................................
#include<stdio.h> //printf,scanf
#include<sys/socket.h> //socket,bind,listen ,connect 
#include<stdlib.h> //malloc,free
#include<string.h> //memeset,memcmp
#include<unistd.h> //macro 
#include<fcntl.h> //crarte ,read
#include<netinet/in.h>  //sockaddir_in ,htons
/*
 struct sockaddr {
               sa_family_t sa_family;
               char        sa_data[14];
           } by default used 
*/
//Run code 
/*
gcc 672 as server 
gcc 673 as client 
*/
int main()
{
    int ServerSocket=0; 
    int iRet=0; 
    int port=11000; 
    int ClientSocketFD=0; 
    char *message= "Gay Ganesh from server\n"; 

    struct sockaddr_in serverAddresss; 
    //step 1: Create TCP Socket 
    ServerSocket=socket(AF_INET,SOCK_STREAM,0);
    if(ServerSocket<0)
    {
         printf("Unable to open sevrver socket\n");
         //perror();  
         return -1; 
    }
    printf("Server socket get created sucessfully with fd: %d\n",ServerSocket); 
    //Step 2: Attach socket to IP address and port number 
    memset(&serverAddresss,0,sizeof(serverAddresss)); 
    serverAddresss.sin_family = AF_INET; 
    serverAddresss.sin_addr.s_addr=INADDR_ANY; 
    serverAddresss.sin_port =htons(port); 
    iRet=bind(ServerSocket,(struct sockaddr *) &serverAddresss,sizeof(serverAddresss));
    if(iRet==-1)
    {
         printf("BInad system call failed\n"); 
         close(ServerSocket); 
         return -1; 
    }
    printf("Bind operation with socket is sucessfully\n"); 
     //step 3: Mark the socket as active socket 
     iRet=listen(ServerSocket,11); 
     if(iRet==-1)
     {
         printf("Unable to convert socket in listen mode\n"); 
         return -1; 
     }
     printf("Server is live at %d\n",port); 

     //step 4: accept new socket request 
     ClientSocketFD=accept(ServerSocket,NULL,NULL);
     if(ClientSocketFD==-1)
     {
        printf("Unable to accept request from client\n"); 
        return -1; 
     }
     printf("Request accepted by server\n"); 
     //step: 5 send message to client (mess)
     write(ClientSocketFD,message,strlen(message)); 
     //step 6: close resources 
     close(ClientSocketFD); 
     close(ServerSocket); 

     printf("Termination of server application\n"); 

     return 0; 
}