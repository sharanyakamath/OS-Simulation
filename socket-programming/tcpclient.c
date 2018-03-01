// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
  
int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    struct sockaddr_in serv_addr;
    int sock;
    char buffer[1024] = {0};
    sock = socket(AF_INET, SOCK_STREAM, 0);
    
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
      
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)); 
  while(1)

{ 
	printf("send to server:");
	bzero(buffer,0); 
 	fgets(buffer,1024,stdin);
 	send(sock ,buffer , strlen(buffer) , 0 );
    	recv( sock , buffer, 1024, 0);
	printf("\nreceived from server:");
    	printf("%s\n",buffer );
}
    return 0;
}
