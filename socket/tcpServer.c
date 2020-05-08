//Declaration and definition
int listensd;
int connectsd;
int n;
int bytesToRecv;
int processID;
char buffer[256];
char* movePtr;
struct sockaddr_in serverAddr;
struct sockaddr_in clientAddr;
int clAddrLen;
//Create listen socket
listensd = socket(PF_INET, SOCK_STREAM, 0);
//Bind listen socket to the local address and port
memset(&serverAddr, 0, sizeof(serverAddr));
serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(7); // We assume port 7
bind(listensd, &serverAddr, sizeof(serverAddr));
//Listen to connection requests
listen(listensd, 5);
//Handle the connection
for (;;)
{
	connetsd = accept(listend, &clientAddr, &clAddrLen);
	processID = fork();
	if (processID == 0)
	{
		close(listensd);
		bytesToRecv = 256;
		movePtr = buffer;
		while ((n = recv(connectfd, movePtr, bytesToRecv, 0)) > 0)
		{
			movePtr = movePtr + n;
			bytesToRecv = movePtr - n;
		}
		send(connectsd, buffer, 256, 0);
		exit(0);
	}
	close(connectsd);
}