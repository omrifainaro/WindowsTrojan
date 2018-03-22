#include "Socket.h"

reverseSocket::reverseSocket(char* ip, int port)
{
	WSAStartup(MAKEWORD(2, 2), &mWsa);
	this->mSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	this->mIp = ip;
	this->mPort = port;
}

int reverseSocket::connectSocket()
{
	sockaddr_in clientService;
	clientService.sin_family = AF_INET;
	clientService.sin_addr.s_addr = inet_addr(this->mIp);
	clientService.sin_port = htons(this->mPort);

	int iResult = connect(this->mSocket, (SOCKADDR *)& clientService, sizeof(clientService));
	if (iResult == SOCKET_ERROR) {
		printf("Failed to connect: %d\n", WSAGetLastError());
		closesocket(this->mSocket);
		return 0;
	}
	return 1;
}

int reverseSocket::sendAndRecv(char* sendString, char* recvBuffer, int recvSize)
{
	int iResult;
	iResult = send(this->mSocket, sendString, (int)strlen(sendString), 0);
	if (iResult == SOCKET_ERROR) {
		printf("Error sending data: %d\n", WSAGetLastError());
		closesocket(this->mSocket);
		return 0;
	}
	printf("%d bytes sent!\n", iResult);

	iResult = recv(this->mSocket, recvBuffer, recvSize, 0);
	if (iResult <= 0) {
		printf("Error receiving data: %d\n", WSAGetLastError());
		closesocket(this->mSocket);
		return 0;
	}
	printf("%d bytes received!\n", iResult);

	return 1;
}
