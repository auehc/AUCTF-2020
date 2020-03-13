#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Mswsock.lib")
#pragma comment(lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
#define HOST "localhost"
//#define HOST "ctf.auburn.edu"


SOCKET setup();



void clean_buffer(char* buffer) {
    char* newline = strchr(buffer, -52);
    if (newline) {
        *newline = '\0';
    }
}

void receive_buffer(SOCKET socket, char* buffer) {
    recv(socket, buffer, DEFAULT_BUFLEN, 0);
    clean_buffer(buffer);
    printf("%s\n", buffer);
}

int main(int argc, char **argv)
{

    SOCKET ConnectSocket = setup();
    const char* sendbuf = "hello can you hear me?";
    const char* request_flag = "can i have the flag?";
    char* recvbuf = calloc(DEFAULT_BUFLEN, sizeof(char));
    int iResult;


    // Send an initial buffer
    iResult = send(ConnectSocket, sendbuf, (int) strlen(sendbuf), 0);

    // receive response
    recv(ConnectSocket, recvbuf, DEFAULT_BUFLEN, 0);
    printf("%s\n", recvbuf);

    // send response
    iResult = send(ConnectSocket, request_flag, (int)strlen(request_flag), 0);

    // get flag
    char *flagbuf = calloc(10, sizeof(char));
    recv(ConnectSocket, flagbuf, 8, 0);
    clean_buffer(flagbuf);
    printf("%s\n", flagbuf);

    // cleanup
    closesocket(ConnectSocket);
    WSACleanup();

    getchar();

    return 0;
}

SOCKET setup()
{
    SOCKET ConnectSocket = INVALID_SOCKET;

    int iResult;
    WSADATA wsaData;
    struct addrinfo* result = NULL,
        * ptr = NULL,
        hints;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0)
    {
        exit(1);
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    iResult = getaddrinfo(HOST, DEFAULT_PORT, &hints, &result);
    if (iResult != 0)
    {
        WSACleanup();
        exit(1);
    }

    // Attempt to connect to an address until one succeeds
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next)
    {

        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
            ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET)
        {
            WSACleanup();
            exit(1);
        }

        // Connect to server.
        iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR)
        {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET)
    {
        WSACleanup();
        exit(1);
    }
    return ConnectSocket;
}


