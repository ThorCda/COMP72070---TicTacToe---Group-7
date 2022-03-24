#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")
#include "ChildPackets.h"
#include "../COMP72070 - TicTacToe/Packet.h"
#include "Account_DB_Handler.h"

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

	void routePacket(Packet packet) {

		Account_DB_Handler AccDBHandler;

		switch (packet.getHeaderPacketType())
		{

		case Accountp: {
			AccountPacket* newAccountPacket = new AccountPacket(packet.getSerializedTxBuffer());
			// login(newAccountPacket)
			break;
		}

		case CreateAccountp: {
			CreateAccountPacket* newCreateAccountPacket = new CreateAccountPacket(packet.getSerializedTxBuffer());
			// createAccount(newCreateAccountPacket)
			break;
		}

		case Errorp: {
			ErrorPacket* newErrorPacket = new ErrorPacket(packet.getSerializedTxBuffer());
			// logError
			break;
		}

		case GameStatusp: {
			GameStatusPacket* newGameStatusPacket = new GameStatusPacket(packet.getSerializedTxBuffer());
			// 
			break;
		}

		case Loginp: {

			LoginPacket* newLoginPacket = new LoginPacket(packet.getSerializedTxBuffer());
			
			string userName(newLoginPacket->getUsername());
			string password(newLoginPacket->getPassword());

			Account* tempAccount = new Account(AccDBHandler.login(userName, password));
			
			if (tempAccount == nullptr) {
				//Change this to error packet eventually.
				cout << "Didn't work";
				return;
			}

			AccountPacket* newAccountPacket = new AccountPacket(tempAccount);

			newAccountPacket->serializeAccountPacketTxBuffer();

			//send(accountPacket) back to client.

			break;
		}

		case Logoutp: {
			LogoutPacket* newLogoutPacket = new LogoutPacket(packet.getSerializedTxBuffer());
			break;
		}

		case Movep: {
			MovePacket* newMovePacket = new MovePacket(packet.getSerializedTxBuffer());
			// PlayMove(newMovePacket)
			break;
		}

		case PacketPacket: {
			//Parent packet creator???
			break;
		}

		default: {
			break;
		}

		}

	}


};