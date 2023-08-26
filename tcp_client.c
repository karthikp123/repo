#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 8080

extern "C"
{

int tcp_client_main() {
    int client_fd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    int client_no = getpid();
    char message[1024];

    while (1) {
        sprintf(message, "Hello from client %d\n", client_no);
        send(client_fd, message, strlen(message), 0);

        memset(message, 0, sizeof(message));
        if (recv(client_fd, message, sizeof(message), 0) <= 0) {
            printf("Server disconnected\n");
            break;
        }

        printf("Received from server: %s", message);

        sleep(1); 
    }

    close(client_fd);

    return 0;
}

#ifndef RELOCATABLE_OBJ

int main ()
{
	tcp_client_main();
}

#endif //RELOCATABLE_OBJ 

}

