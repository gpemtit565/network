// TCP echo client program
#include "headerFiles.h"

int main(void)
{
	//Declaration and definition
	int sd;
	int fd;
	int n;
	int bytesToRecv;
	char sendBuffer[256];
	char recvBuffer[256];
	char* movePtr;
	struct sockaddr_in serverAddr;

	//Create socket
	sd = socket(PF_INET, SOCK_STREAM, 0);
	//Create server socket address
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	inet_pton(AF_INET, "server address", &serverAddr.sin_addr);
	serverAddr.sin_port = htons(7);
	//Connet
	connet(sd, (struct sockaddr*) & serverAddr, sizeof(serverAddr));
	//Send and receive data
	fgets(sendBuffer, 256, stdin);
	send(fd, sendBuffer, strlen(sendBuffer), 0);
	bytesToRecv = strlen(sendBuffer);
	movePtr = recvBuffer;
	while ((n = recv(sd, movePtr, bytesToRecv, 0)) > 0)
	{
		movePtr = movePtr + n;
		bytesToRecv = bytesToRecv - n;
	}
	recvBuffer[bytesToRecv] = 0;
	printf("Received from server:");
	fputs(recvBuffer, stdout);
	//Close and exit
	close(sd);
	exit(0);
}