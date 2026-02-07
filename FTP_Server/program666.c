
//Description : 
//FTP Server based communication 
//server side function call 
//socket,bind,listen,accept,
//server <------------------------>client
//socket<----------IPC------------->Client 
//Server side code 
//...............................................
#include<stdio.h>
#include<sys/socket.h>
#//include<error.h>

int main()
{
    int ServerSocket=0; 
    ServerSocket=socket(AF_INET,SOCK_STREAM,0);
    if(ServerSocket<0)
    {
         printf("Unable to open sevrver socket\n");
         //perror();  
         return -1; 
    }
    printf("Server socket get created sucessfully with fd: %d\n",ServerSocket); 
    

     return 0; 
}