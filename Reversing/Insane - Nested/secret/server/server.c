#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 8192
#define PORT 27015
#define SA struct sockaddr

void func(int sockfd);

int main(void)
{
    int sockfd, connfd;
    unsigned int len;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0)
    {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0)
    {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);

    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA *)&cli, &len);
    if (connfd < 0)
    {
        printf("server acccept failed...\n");
        exit(0);
    }
    else
        printf("server acccept the client...\n");

    // Function for chatting between client and server
    func(connfd);

    // After chatting close the socket
    close(sockfd);
}

// Function designed for chat between client and server.
void func(int sockfd)
{
    char *init = "Ahh. I see you've found me... here comes the flag :)\n";
    char *secret = "auctf{r3s0urc3_h4cK1Ng_1S_n3at0_1021}";
    char recv[MAX];
    int n;
    // infinite loop for chat

    bzero(recv, MAX);

    // read the message from client and copy it in buffer
    read(sockfd, recv, sizeof(recv));
    // print buffer which contains the client contents
    printf("From client: %s\t To client : %s\n", recv, init);
    bzero(recv, MAX);
    n = 0;

    // and send that buffer to client
    write(sockfd, init, strlen(init));

    read(sockfd, recv, sizeof(recv));
    // print buffer which contains the client contents
    printf("From client: %s\t To client : %s\n", recv, secret);
    bzero(recv, MAX);

    // send data to client

    // and send that buffer to client
    write(sockfd, secret, strlen(secret));
}
