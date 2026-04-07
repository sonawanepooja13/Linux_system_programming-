#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int ServerSocket, ClientSocket;
    int Port;
    struct sockaddr_in ServerAddr, ClientAddr;
    socklen_t AddrLen;
    char ip[INET_ADDRSTRLEN];

    if (argc != 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        return -1;
    }

    Port = atoi(argv[1]);

    // Step 1: Create socket
    ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (ServerSocket < 0)
    {
        perror("socket");
        return -1;
    }

    // Step 2: Bind
    memset(&ServerAddr, 0, sizeof(ServerAddr));
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(Port);
    ServerAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(ServerSocket, (struct sockaddr *)&ServerAddr, sizeof(ServerAddr)) < 0)
    {
        perror("bind");
        close(ServerSocket);
        return -1;
    }

    // Step 3: Listen
    if (listen(ServerSocket, 5) < 0)
    {
        perror("listen");
        close(ServerSocket);
        return -1;
    }

    printf("Server running on port %d\n", Port);

    // Step 4: Accept clients
    while (1)
    {
        AddrLen = sizeof(ClientAddr);
        ClientSocket = accept(ServerSocket,
                              (struct sockaddr *)&ClientAddr,
                              &AddrLen);

        if (ClientSocket < 0)
        {
            perror("accept");
            continue;
        }

        inet_ntop(AF_INET, &ClientAddr.sin_addr, ip, sizeof(ip));
        printf("Client connected from %s\n", ip);

        close(ClientSocket);
    }

    close(ServerSocket);
    return 0;
}
