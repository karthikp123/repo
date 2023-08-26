#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10

extern "C"
{

void *handle_client(void *client_socket);

int tcp_server_main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    pthread_t thread_id;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(server_fd, MAX_CLIENTS) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) == -1) {
            perror("Accept failed");
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Create thread for the client
        if (pthread_create(&thread_id, NULL, handle_client, (void *)&client_fd) != 0) {
            perror("Thread creation failed");
            continue;
        }
    }

    close(server_fd);

    return 0;
}

void *handle_client(void *client_socket) {
    int socket_fd = *((int *)client_socket);
    char buffer[1024];

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        if (recv(socket_fd, buffer, sizeof(buffer), 0) <= 0) {
            printf("Client disconnected\n");
            break;
        }

        printf("Received from client: %s", buffer);

        char reply[] = "Hello from server\n";
        send(socket_fd, reply, strlen(reply), 0);
    }

    close(socket_fd);
    pthread_exit(NULL);
}

#ifndef RELOCATABLE_OBJ

int main ()
{
	tcp_server_main();
}

#endif //RELOCATABLE_OBJ

}

