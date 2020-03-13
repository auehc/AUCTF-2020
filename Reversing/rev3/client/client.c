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

int send_data(SOCKET Connect, const char *buffer);
void receive_data(SOCKET Connect, char *buffer);
int setup(SOCKET* Connect);
void clean_buffer(char* buffer);

int main(int argc, char **argv)
{

    SOCKET ConnectSocket = INVALID_SOCKET;
    const char* sendbuf = "hello can you hear me?";
    char recvbuf[DEFAULT_BUFLEN];

    int iResult;
    WSADATA wsaData;
    struct addrinfo* result = NULL,
        * ptr = NULL,
        hints;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0)
    {
        return 1;
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
        return 1;
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
            return 1;
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
        return 1;
    }






    // Send an initial buffer
    iResult = send(ConnectSocket, sendbuf, (int) strlen(sendbuf), 0);


   
    recv(ConnectSocket, recvbuf, DEFAULT_BUFLEN, 0);
    clean_buffer(recvbuf);
    printf("%s\n", recvbuf);

    // send response
    iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);

    // get flag

    recv(ConnectSocket, NULL, NULL, 0);
    clean_buffer(NULL);
    printf("%s\n", NULL);

    // cleanup
    closesocket(ConnectSocket);
    WSACleanup();

    getchar();

    return 0;
}

int setup(SOCKET *lp_connect)
{
    SOCKET Connect = *lp_connect;
    int iResult;
    WSADATA wsaData;
    struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0)
    {
        return 1;
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
        return 1;
    }

    // Attempt to connect to an address until one succeeds
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next)
    {
        
        // Create a SOCKET for connecting to server
        Connect = socket(ptr->ai_family, ptr->ai_socktype,
                         ptr->ai_protocol);
        if (Connect == INVALID_SOCKET)
        {
            WSACleanup();
            return 1;
        }

        // Connect to server.
        iResult = connect(Connect, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR)
        {
            closesocket(Connect);
            Connect = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (Connect == INVALID_SOCKET)
    {
        WSACleanup();
        return 1;
    }

    return 0;
}

int send_data(SOCKET Connect, const char *buffer)
{
    int iResult;
    // Send an initial buffer
    iResult = send(Connect, buffer, (int) strlen(buffer), 0);
    if (iResult == SOCKET_ERROR)
    {
        closesocket(Connect);
        WSACleanup();
        return 1;
    }
    return 0;
}




void clean_buffer(char *buffer) {
    char* newline = strchr(buffer, -52);
    if (newline) {
        *newline = '\0';
    }
}