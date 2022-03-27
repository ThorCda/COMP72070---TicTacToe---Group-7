#pragma once
#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")
#include "ChildPackets.h"
#include "../COMP72070 - TicTacToe/Packet.h"
#include "Account_DB_Handler.h"

using namespace std;

class NetworkHandler
{
	SOCKET ListenSocket;
	SOCKET ClientSocket;
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

	int acceptClient() {

		this->ClientSocket = SOCKET_ERROR;

		if ((this->ClientSocket = accept(this->ListenSocket, NULL, NULL)) == SOCKET_ERROR) {
			closesocket(this->ListenSocket);
			WSACleanup();
			return 0;
		}
		cout << "Connection Established" << endl;


	}

	bool listenForPacket() {

		char RxBuffer[1028];	//Max length of the biggest packet

		recv(ClientSocket, RxBuffer, sizeof(RxBuffer), 0);

		Packet* pkt = new Packet(RxBuffer);		//Not sure if RxBuffer should be reallocated 

		bool isRunning = routePacket(pkt);

		return isRunning;
	}

	void closeSocket()
	{
		closesocket(this->ClientSocket);	//closes incoming socket

		closesocket(this->ListenSocket);	    //closes server socket	

		WSACleanup();					//frees Winsock resources

	}


	void sendPacket(Packet* p)
	{
		send(ClientSocket, p->getSerializedTxBuffer(), sizeof(Header) + p->getHeaderBodyLength(), 0);

	}

	bool routePacket(Packet* packet) {

		bool isLoggedIn = true;

		Account_DB_Handler* AccDBHandler = new Account_DB_Handler();

		switch (packet->getHeaderPacketType())
		{

		case Accountp: {
			AccountPacket* newAccountPacket = new AccountPacket(packet->getSerializedTxBuffer());
			// login(newAccountPacket)
			break;
		}

		case CreateAccountp: {
			

			CreateAccountPacket* pkt = new CreateAccountPacket(packet->getSerializedTxBuffer());

			Account* acc = new Account(pkt->getFName(), pkt->getLName(), pkt->getUsername(), pkt->getPassword());
			
			//acc = AccDBHandler.createAccount(acc);  Need modification for db to return an account

			if (acc == nullptr) {
				//send error packet
				ErrorPacket* err = new ErrorPacket(CrtAcc_Err);
				err->serializeErrorPacketTxBuffer();
				err->getSerializedParentTxBuffer();
				sendPacket(err);
				return false;
			}

			AccountPacket* accpkt = new AccountPacket(acc);
			accpkt->serializeAccountPacketTxBuffer();
			accpkt->serializeParentPacketTxBuffer();
			sendPacket(accpkt);

			break;
		}

		case Errorp: {
			ErrorPacket* newErrorPacket = new ErrorPacket(packet->getSerializedTxBuffer());
			// logError

			//If the error packet is a early quit or smt that it cannot recover from then 
				//isLoggedOut = false;

			break;
		}

		case GameStatusp: {
			GameStatusPacket* newGameStatusPacket = new GameStatusPacket(packet->getSerializedTxBuffer());
			// 
			break;
		}

		case Loginp: {

			LoginPacket* linPkt = new LoginPacket(packet->getSerializedTxBuffer());
			
			string userName(linPkt->getUsername());
			string password(linPkt->getPassword());

			Account* acc = new Account(AccDBHandler->login(userName, password));
			
			if (acc == nullptr) {
				ErrorPacket* err = new ErrorPacket(Login_Err);
				err->serializeErrorPacketTxBuffer();
				err->getSerializedParentTxBuffer();
				sendPacket(err);
				return false;
			}

			AccountPacket* accPkt = new AccountPacket(acc);

			accPkt->serializeAccountPacketTxBuffer();

			sendPacket(accPkt);

			break;
		}

		case Logoutp: {
			LogoutPacket* newLogoutPacket = new LogoutPacket(packet->getSerializedTxBuffer());
			
			isLoggedIn = false;	//Will terminate the session
			break;
		}

		case Movep: {
			MovePacket* newMovePacket = new MovePacket(packet->getSerializedTxBuffer());
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

		return isLoggedIn;
		

	}






};