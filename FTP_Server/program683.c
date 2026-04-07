///////////////////////////////////////////////////////////////
// server Side Application 
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

int main(int argc ,char *argv[])
{
    int ServerSocket = 0; 
    int ClientSocket = 0; 
    int Port = 0; 
    int iRet = 0; 
    int pid = 0;                       // ✅ FIX 1
    struct sockaddr_in ServerAddr; 
    struct sockaddr_in ClientAddr; 

    socklen_t AddrLen = sizeof(ClientAddr);
    char clientIP[INET_ADDRSTRLEN];    // ✅ FIX 2

    if(argc != 2)
    {
       printf("Unable to process: invalid number of arguments\n"); 
       printf("Usage: %s <port>\n", argv[0]); 
       return -1; 
    }

    Port = atoi(argv[1]); 

    ////////////////////////////////////////////////////////////////////////
    // Step 1: Create TCP socket 
    /////////////////////////////////////////////////////////////////////////
    ServerSocket = socket(AF_INET, SOCK_STREAM, 0); 
    if(ServerSocket < 0)
    {
        perror("socket");
        return -1; 
    }

    //////////////////////////////////////////////////////////////
    // Step 2: Bind socket
    //////////////////////////////////////////////////////////////
    memset(&ServerAddr, 0, sizeof(ServerAddr)); 
    ServerAddr.sin_family = AF_INET; 
    ServerAddr.sin_port = htons(Port); 
    ServerAddr.sin_addr.s_addr = INADDR_ANY; 

    iRet = bind(ServerSocket,
                (struct sockaddr *)&ServerAddr,
                sizeof(ServerAddr)); 

    if(iRet == -1)                     // ✅ FIX 3 (removed return 0)
    {
        perror("bind");
        close(ServerSocket); 
        return -1; 
    }

    ////////////////////////////////////////////////////////////////////
    // Step 3: Listen
    ////////////////////////////////////////////////////////////////////
    iRet = listen(ServerSocket, 11); 
    if(iRet == -1)
    {
        perror("listen");
        close(ServerSocket); 
        return -1; 
    }

    printf("Server is running on port: %d\n", Port); 

    ////////////////////////////////////////////////////////////////////
    // Step 4: Accept clients
    ////////////////////////////////////////////////////////////////////
    while(1)
    {
        memset(&ClientAddr, 0, sizeof(ClientAddr)); 
        printf("Server is waiting for client request...\n"); 

        ClientSocket = accept(ServerSocket,          // ✅ FIX 4
                              (struct sockaddr *)&ClientAddr,
                              &AddrLen); 

        if(ClientSocket < 0)
        {
            perror("accept");
            continue; 
        }

        inet_ntop(AF_INET,                           // ✅ FIX 5
                  &ClientAddr.sin_addr,
                  clientIP,
                  sizeof(clientIP));

        printf("Client connected from %s\n", clientIP); 

        /////////////////////
        // Step 5: fork
        /////////////////////
        pid = fork(); 
        if(pid < 0)
        {
            perror("fork");
            close(ClientSocket);
            continue;
        }

        // Child process
        if(pid == 0)
        {
            printf("New process created for client\n"); 
            close(ServerSocket);      // child doesn't need server socket
            close(ClientSocket);      // for now
            exit(0);
        }
        else
        {
            close(ClientSocket);      // parent closes client socket
        }
    }

    close(ServerSocket);
    return 0; 
}
