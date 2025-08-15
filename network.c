#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>


void main()
{
	struct sockaddr_in addr = {AF_INET, htons(80), inet_addr("192.168.1.1")};
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	printf("%d\n", sock);
	int result = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
	if (result == 0)
	{
		printf("Success: %d\n", result);		
	}
	else
	{
		printf("Failure: %d\n", result); 
	}
}
