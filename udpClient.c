#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 5000
#define MAX_BUFFER_SIZE 1024

int main() {
    int sockfd;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in serverAddr;

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

    while (1)
    {
        printf("Enter a message: ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);

        // Send message to server
        if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
            perror("Error in sendto");
            exit(1);
        }

        // Receive acknowledgement from server
        int numBytes = recvfrom(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0, NULL, NULL);
        if (numBytes < 0) {
            perror("Error in recvfrom");
            exit(1);
        }

        buffer[numBytes] = '\0';
        printf("Received acknowledgement from server: %s\n", buffer);

    }
    return 0;
}
