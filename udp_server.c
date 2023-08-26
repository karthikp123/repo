#include "udp_header.h"


extern "C"
{

int fn_udp_server()
{
    int sockfd, len, n;
    char buffer[MAXLINE + 1];
    char *sendmsg = "Hello from server";
    struct sockaddr_in servaddr, clntaddr;
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    if(sockfd < 0)
    {
        perror("Socket creation failed\n");
        return -1;
    }
    
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&clntaddr, 0, sizeof(clntaddr));
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
    
    if ( bind(sockfd, (const struct sockaddr *)&servaddr,   \
			          sizeof(servaddr)) < 0 )
    {
	perror("bind failed");
	return -2;
    }
    
    len = sizeof(clntaddr);
    
    n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &clntaddr, (socklen_t*)(&len));
    
    printf("port is : %d", clntaddr.sin_port);
    
    buffer[n] = '\0';
    
    printf("Client : %s\n", buffer);
    
    sendto(sockfd, (const char *)sendmsg, strlen(sendmsg),MSG_CONFIRM, \
                              (const struct sockaddr *) &clntaddr, len);
    
    close(sockfd);                        
    return 0;
}

int udp_server_main()
{
    fn_udp_server();
    return 0;
}

#ifndef RELOCATABLE_OBJ

int main()
{
	udp_server_main();
}

#endif


}
