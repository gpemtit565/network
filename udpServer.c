// UDP echo server program
#include "headerFiles.h"

int main(void)
{
	int sd;
	int nr;
	char buffer[256];
	struct sockaddr_in serverAddr;
	struct sockaddr_in clientAddr;
	int clAddrLen;
	//Create socket
	sd = socket(PF_INET, SOCK_DGRAM, 0);
	//Bind socket to local daaress and port
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr=htonl(INADDR_ANY); //Default address
	serverAddr.sin_port = htons(7); //We assume port 7
	bind(sd, (struct sockaddr*) & serverAddr, sizeof(serverAddr));
	//Receiving and echoing datagrams
	for (; ;)
	{
		nr = recvfrom(sd, buffer, 256, 0, (struct sockaddr*) & clientAddr, &clAddrLen);
		sendto(sd, buffer, nr, 0, (struct sockaddr*) & clientAddr, sizeof(clientAddr));
	}
}
