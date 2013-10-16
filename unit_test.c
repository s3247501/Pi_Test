#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ctype.h>

#define SERVERPORT "4955"
#define HOSTNAME   "192.168.1.3"
#define MAXBUFLEN  100

int main(int argc, char *argv[])
{
	int sockfd, bindfd;
	struct addrinfo hints, *servinfo, *p;
	int rv;
	int send_data, recv_data;
	struct sockaddr_storage their_addr;
	char buf[MAXBUFLEN];
	socklen_t addr_len;
	char input;
	char string[1];
	int loop = 1;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
	
	printf("\nTEST NETWORK\n");
	printf("--------------------------------\n");
	
	/* test get address info */
	rv = getaddrinfo(HOSTNAME, SERVERPORT, &hints, &servinfo);
	if(rv == 0)
		printf("Test getaddrinfo()    : passed\n");
	else
		printf("TEST getaddrinfo()    : failed\n");
		
	/* test socket & bind */
	for(p = servinfo; p != NULL; p = p->ai_next) {
		sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol);
				
		if(sockfd != -1)
			printf("Test socket()         : passed\n");
		else{
			printf("Test socket()         : failed\n");
			continue;
		}
		
		bindfd = bind(sockfd, p->ai_addr, p->ai_addrlen);
		
		if(bindfd != -1)
			printf("Test bind()           : passed\n");
		else{
			printf("Test bind()           : failed\n");
			continue;
		}		
		
		break;		
	}
		
	/* test bind socket */
	if(p != NULL)
		printf("Test bind socket      : passed\n");
	if (p == NULL) 
		printf("Test bind socket      : failed\n");
	
	printf("\nTEST DATA TRANSFER\n");
	printf("--------------------------------");

	printf("\nEnter any char : ");
	scanf("%c", &input);
	string[0] = input;
	
	send_data = sendto(sockfd,string,strlen(string), 0,
			 p->ai_addr, p->ai_addrlen);

	/*printf("Data sent     : %d (bytes)\n", send_data);*/

	if(send_data < 0)
		printf("Test sendto()         : failed\n");	
	else
		printf("Test sendto()         : passed\n");
		
	addr_len = sizeof(their_addr);

	recv_data = recvfrom(sockfd, buf, MAXBUFLEN-1 , 0,
			(struct sockaddr *)&their_addr, &addr_len);

	/*printf("Data received : %d (bytes)\n", recv_data);*/	

	if(recv_data < 0)
		printf("Test recvfrom()       : failed\n");
	else
		printf("Test recvfrom()       : passed\n");	

	
	printf("\n");
	freeaddrinfo(servinfo);
	close(sockfd);
	
	return 0;
	
}
