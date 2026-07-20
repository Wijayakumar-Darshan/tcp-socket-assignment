#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {

    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    char buffer[BUFFER_SIZE] = {0};

    char *response = "Message received successfully from server";


    // 1. Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }


    // 2. Configure server address

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);


    // 3. Bind socket

    if (bind(server_fd, 
            (struct sockaddr *)&address,
            sizeof(address)) < 0) {

        perror("Bind failed");
        exit(EXIT_FAILURE);
    }


    // 4. Listen for clients

    if (listen(server_fd, 3) < 0) {

        perror("Listen failed");
        exit(EXIT_FAILURE);
    }


    printf("Server started...\n");
    printf("Waiting for client connection...\n");


    // 5. Accept client

    client_socket = accept(
        server_fd,
        (struct sockaddr *)&address,
        (socklen_t *)&addrlen
    );


    if (client_socket < 0) {

        perror("Accept failed");
        exit(EXIT_FAILURE);
    }


    printf("Client connected successfully\n");


    // 6. Receive message

    read(client_socket, buffer, BUFFER_SIZE);

    printf("Client message: %s\n", buffer);



    // 7. Send response

    send(
        client_socket,
        response,
        strlen(response),
        0
    );


    printf("Response sent to client\n");


    // 8. Close connection

    close(client_socket);
    close(server_fd);


    printf("Connection closed\n");


    return 0;
}