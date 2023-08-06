#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 12345
#define SERVER_IP "127.0.0.1"

int main() {
    int client_socket;
    struct sockaddr_in server_address;
    
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &(server_address.sin_addr));

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error connecting to the server");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server.\n");

    FILE *file = fopen("received_file.txt", "wb");
    if (file == NULL) {
        perror("Error creating file");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    int bytes_received;
    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
    }

    printf("File received successfully.\n");

    fclose(file);
    close(client_socket);

    return 0;
}
