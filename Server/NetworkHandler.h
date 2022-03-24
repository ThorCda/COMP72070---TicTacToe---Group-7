#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")
#include "ChildPackets.h"
#include "../COMP72070 - TicTacToe/Packet.h"

using namespace std;

class NetworkHandler
{
	SOCKET ListenSocket;
	sockaddr_in SvrAddr;
public:

	int winsockStartup()
	{
		//starts Winsock DLLs
		WSADATA wsaData;
		if ((WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0) {
			return 0;
		}
	}

	int initSocket()
	{
		//initializes socket. SOCK_STREAM: TCP
		this->ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (this->ListenSocket == INVALID_SOCKET) {
			WSACleanup();
			return 0;
		}
	}

	int initConnection()
	{
		//Connect socket to specified server
		this->SvrAddr.sin_family = AF_INET;                        //Address family type itnernet
		this->SvrAddr.sin_port = htons(27000);                    //port (host to network conversion)
		this->SvrAddr.sin_addr.s_addr = inet_addr("127.0.0.1");    //IP address
		if ((connect(this->ListenSocket, (struct sockaddr*)&this->SvrAddr, sizeof(this->SvrAddr))) == SOCKET_ERROR) {
			closesocket(this->ListenSocket);
			WSACleanup();
			return 0;
		}
	}

	void closeSocket()
	{
		closesocket(this->ListenSocket);
		WSACleanup();
	}


	void sendPacket(Packet p)
	{
		
	}


};