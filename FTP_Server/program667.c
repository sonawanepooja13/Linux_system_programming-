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
int main()
{
    int ServerSocket=0; 
    int iRet=0; 
    int port=11000; 

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
     return 0; 
}