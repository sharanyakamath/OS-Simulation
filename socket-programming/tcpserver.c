#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    int server_fd, new_socket;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
      
    // Creating socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    // Forcefully attaching socket to the port 8080
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons( PORT );
      
    // Forcefully attaching socket to the port 8080
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

listen(server_fd, 3);
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    while(1)
{ 
    recv( new_socket , buffer, 1024,0);
    printf("\nreceived from client:");
    printf("%s\n",buffer );
    printf("send to client:");
    bzero(buffer,0);
    fgets(buffer,1024,stdin);
    send(new_socket , buffer , strlen(buffer) , 0 );
   }
    return 0;
}
