#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int sock = 0;
    struct sockaddr_in server_address;

    char *message = "Hello Server";

    char buffer[BUFFER_SIZE] = {0};


    // 1. Create socket

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }


    // 2. Configure server address

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);


    // Convert IP address

    if (inet_pton(AF_INET, "127.0.0.1",
                  &server_address.sin_addr) <= 0)
    {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }


    // 3. Connect to server

    if (connect(sock,
        (struct sockaddr *)&server_address,
        sizeof(server_address)) < 0)
    {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }


    printf("Connected to server\n");


    // 4. Send message

    send(sock, message, strlen(message), 0);

    printf("Message sent: %s\n", message);


    // 5. Receive response

    read(sock, buffer, BUFFER_SIZE);

    printf("Server response: %s\n", buffer);


    // 6. Close connection

    close(sock);

    printf("Connection closed\n");


    return 0;
}