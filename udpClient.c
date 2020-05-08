//UDP echo client program
#include "headerFiles.h"

int main(void)
{
	//Declaration and definition
	int sd;
	int ns;
	int nr;
	char buffer[256];
	struct sockaddr_in serverAddr;
	//Create socket
	sd = socket(PF_INET, SOCK_DGRAM, 0);
	// Create server socket address
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	inet_pton(AF_INET, "server address", &serverAddr.sin_addr);
	serverAddr.sin_port = htons(7);
	//Send and receive datagrams
	fgets(buffer, 256, stdin);
	ns = sendto(sd, buffer, strlen(buffer), 0,
		(struct sockaddr)&serverAddr, sizeof(serverAddr));
	recvfrom(sd, buffer, strlen(buffer), 0, NULL, NULL);
	buffer[nr] = 0;
	printf("Received from server:");
	fputs(buffer, stdout);
	//Close and Exit
	close (sd);
	exit(0);
}