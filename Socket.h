#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <string.h>

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")

class reverseSocket{
public:
	reverseSocket(char* ip, int port);
	int connectSocket();
	int sendAndRecv(char* sendString, char* recvBuffer, int recvSize);
private:
	WSAData mWsa;
	char* mIp;
	int mPort;
	SOCKET mSocket;
};