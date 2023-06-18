#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 5000
#define MAX_BUFFER_SIZE 1024

int main() {
    int sockfd;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrLen = sizeof(clientAddr);

    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error in socket");
        exit(1);
    }

    // Configure server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to the server address
    if (bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error in binding");
        exit(1);
    }

    printf("UDP server is listening on port %d...\n", PORT);

    while (1) {
        // Receive message from client
        int numBytes = recvfrom(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0, (struct sockaddr *)&clientAddr, &addrLen);
        if (numBytes < 0) {
            perror("Error in recvfrom");
            exit(1);
        }

        buffer[numBytes] = '\0';
        printf("Received message from client: %s\n", buffer);

        // Send acknowledgement to client
        if (sendto(sockfd, "Message Received", 15, 0, (struct sockaddr *)&clientAddr, addrLen) < 0) {
            perror("Error in sendto");
            exit(1);
        }
    }

    return 0;
}
