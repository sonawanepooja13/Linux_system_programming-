
///////////////////////////////////////////////////////////////
//client  Side Application 
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
// 1st argument : IP Address
//2nd argument :  port number
//3      target file name 
// 4 new file name 
//./client  127
//  argv[0]       argv[1]
////////////////////////////////////////////////////////////////////////////
int main(int argc ,char *argv[])
{
    int Sock=0; 
    int Port=0; 
    int iRet=0;
    char *ip=NULL;  //argv[1]
    char *Filename=NULL; //argv[2]
    char *OutFilename=NULL; //argv[3]
     
    struct sockaddr_in ServerAddr; 

    if(argc <5 || argc>5)
    {
        printf("Unable to proced invalid no of argument\n"); 
        printf("PLease provide below arguments\n"); 
        printf("1st Argument:IP address\n"); 
        printf("2nd Argument :IP Address\n"); 
        printf("3rd Argument : Port Number\n"); 
        printf("3rd Argumentc: Target File Name\n"); 
        printf("4 th :New File name\n"); 
        return -1; 

    }
    ///////////////////////////////////////////////
    //stored command line argument into a variable.
    ip=argv[1]; 
    Port=atoi(argv[2]); 
    Filename=argv[3]; 
    OutFilename=argv[4]; 
////////////////////////////////////////////////
//Step 1: Create TCP Socket 
/////////////////////////////////////////////////
Sock=socket(AF_INET,SOCK_STREAM,0); 
if(Sock<0)
{
     printf("UNable to create a client socket\n"); 
     return -1; 
}
/////////////////////////////////////////////////////
//Step 2: Connect with server 
//////////////////////////////////////////////////
memset(&ServerAddr,0,sizeof(ServerAddr));
ServerAddr.sin_family=AF_INET;
ServerAddr.sin_port=htons(Port);
//////////////////////////////////////////////////
//Convert IP Address into binary format 
////////////////////////////////////////////////////
inet_pton(AF_INET,ip,&ServerAddr.sin_addr);

iRet=connect(Sock,(struct sockaddr *)&ServerAddr,sizeof(ServerAddr));
if(iRet==-1)
{
     printf("Unable to connect with server\n"); 
     close(Sock); 
     return -1; 
}
//sending filname to server 

write(Sock,Filename,strlen(Filename)); 

    return 0;
}