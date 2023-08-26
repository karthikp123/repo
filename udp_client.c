#include "udp_header.h"

extern "C"
{

int fn_udp_client()
{
    int sockfd, n, len;
    char buffer[MAXLINE + 1];
    struct sockaddr_in servaddr;
    char *clntmsg = "Hello from client";
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    if(sockfd < 0)
    {
        perror("Socket creation failed\n");
        return -1;
    }
    
    memset(&servaddr, 0, sizeof(servaddr));
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
    
    sendto(sockfd, (const char *)clntmsg, strlen(clntmsg),MSG_CONFIRM, \
              (const struct sockaddr *) &servaddr,sizeof(servaddr));
              
    n =recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&servaddr,(socklen_t*)(&len));
    
    printf("port is : %d", servaddr.sin_port);
    
    buffer[n] = '\0';
    
    printf("Server : %s\n", buffer);
    
    close(sockfd);
    
    return 0;
}

int udp_client_main()
{
    fn_udp_client();
    return 0;
}

#ifndef RELOCATABLE_OBJ

int main()
{
	udp_client_main();
}

#endif //RELOCATABLE_OBJ

}
