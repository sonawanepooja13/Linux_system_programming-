
///////////////////////////////////////////////////////////////
//server Side Application 
///////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdbool.h>
///////////////////////////////////////////////////////////////////////////
//  Command line Argument Application 
// 1st argument : Port NUmber 
//2nd argument : ./server 90000
//  argv[0]       argv[1]
////////////////////////////////////////////////////////////////////////////
int main(int argc ,char *argv[])
{
    int ServerSocket =0; 
    int ClientSocket =0; 
    int Port=0; 
    int iRet=0; 
    struct sockaddr_in ServerAddr; 
    struct sockaddr_in ClientAddr; 


    socklen_t AddrLen=sizeof(ClientSocket); 
    if((argc>2 )||(argc<2))
    {
       printf("UNable to processed as invalid number of argumnet\n"); 
       printf("Please provide port Number\n"); 
       return -1; 
    }
    // port number of server 
    Port=atoi(argv[1]); 
    ////////////////////////////////////////////////////////////////////////
    // Step 1: Create TCP sockt 
    /////////////////////////////////////////////////////////////////////////
    ServerSocket=socket(AF_INET,SOCK_STREAM,0); 
    if(ServerSocket<0)
    {
        printf("Unable to craete a server socket\n"); 
        return -1; 
    }
//////////////////////////////////////////////////////////////
//Step 2: Bind socket to IP and Port 
//////////////////////////////////////////////////////////////
memset(&ServerAddr,0,sizeof(ServerAddr)); 
//initilize the structure 
ServerAddr.sin_family=AF_INET; 
ServerAddr.sin_port=htons(Port); 
ServerAddr.sin_addr.s_addr=INADDR_ANY; 
iRet=bind(ServerSocket,(struct sockaddr *)&ServerAddr,sizeof(ServerAddr)); 
return 0; 
if(iRet==-1)
{
    printf("UNable to bind\n"); 
    close(ServerSocket); 

    return -1; 
}
////////////////////////////////////////////////////////////////////
//Step : Listen fo r client connection 
/////////////////////////////////////////////////////////////////////
iRet=listen(ServerSocket,11); 
if(iRet==-1)
{
    printf("Server unable to listen request \n"); 
    close(ServerSocket); 
    return -1; 

}
printf("Server is runnning on port :%d\n",Port); 
return 0; 
}