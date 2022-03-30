
#pragma once

#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")
#include "ChildPackets.h"
#include "Packet.h"
#include "Account_DB_Handler.h"
#include "Logs.h"
#include "GameRoom.h"
#include <exception>

using namespace std;



class NetworkHandler
{
	SOCKET ListenSocket;
	SOCKET ClientSocket;
	sockaddr_in SvrAddr;
	GameRoom* gr = new GameRoom();
	Account_DB_Handler* AccDBHandler = new Account_DB_Handler();

public:

	int winsockStartup()
	{
		//starts Winsock DLLs
		WSADATA wsaData;
		if ((WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0) {
			return 0;
		}
		cout << "Winsock: Initalized..." << endl;
	}

	int initSocket()
	{
		//initializes socket. SOCK_STREAM: TCP
		this->ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (this->ListenSocket == INVALID_SOCKET) {
			WSACleanup();
			return 0;
		}
		cout << "Winsock: Socket created..." << endl;
	}

	int bindConnect() {
		sockaddr_in SvrAddr;
		SvrAddr.sin_family = AF_INET;
		SvrAddr.sin_addr.s_addr = INADDR_ANY;
		SvrAddr.sin_port = htons(27000);
		if (bind(ListenSocket, (struct sockaddr*)&SvrAddr, sizeof(SvrAddr)) == SOCKET_ERROR)
		{
			closesocket(ListenSocket);
			WSACleanup();
			return 0;
		}
		cout << "Winsock: Bound socket..." << endl;
	}

	int listenSocket() {
		if (listen(ListenSocket, 1) == SOCKET_ERROR) {
			closesocket(ListenSocket);
			WSACleanup();
			return 0;
		}
	}

	int acceptClient() {

		this->ClientSocket = SOCKET_ERROR;

		cout << "Winsock: Waiting for connection..." << endl;

		if ((this->ClientSocket = accept(this->ListenSocket, NULL, NULL)) == SOCKET_ERROR) {
			closesocket(this->ListenSocket);
			WSACleanup();
			return 0;
		}
		cout << "Winsock: Connection Established" << endl;

		Logs::write(true, connected, NULL);
	}

	bool listenForPacket() {

		cout << "Winsock: Lisening for packet..." << endl;

		char RxBuffer[1028] = {};	//Max length of the biggest packet

		cout << "here";


		recv(ClientSocket, RxBuffer, sizeof(RxBuffer), 0);
		
		Logs::write(true, buf_receive, RxBuffer);

		Packet* pkt = new Packet(RxBuffer);		//Not sure if RxBuffer should be reallocated 

		bool isRunning = routePacket(pkt);

		return isRunning;
	}

	void closeSocket()
	{

		Logs::write(false, disconnected, NULL);

		closesocket(this->ClientSocket);	//closes incoming socket

		closesocket(this->ListenSocket);	    //closes server socket	

		WSACleanup();					//frees Winsock resources

	}


	void sendPacket(Packet* p)
	{
		cout << "Winsock: Sending packet..." << endl;
		send(ClientSocket, p->getSerializedParentTxBuffer(), sizeof(Header) + p->getHeaderBodyLength(), 0);

		Logs::write(true, buf_send, p->getSerializedParentTxBuffer());
	}

	bool routePacket(Packet* packet) {

		bool isLoggedIn = true;


		switch (packet->getHeaderPacketType())
		{

		case Accountp: {
			AccountPacket* newAccountPacket = new AccountPacket(packet->getSerializedTxBuffer());
			// login(newAccountPacket)
			break;
		}

		case CreateAccountp: {
			

			CreateAccountPacket* pkt = new CreateAccountPacket(packet->getSerializedTxBuffer());

			Account* acc = new Account(pkt->getFName(), pkt->getLName(), pkt->getUsername());
			
			acc = this->AccDBHandler->createAccount(acc, pkt->getPassword());

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

			if (newGameStatusPacket->getGameStatusPacketGameCode() == picture) {
				//recvPicture();
			}

			// 
			break;
		}

		case Loginp: {

			LoginPacket* linPkt = new LoginPacket(packet->getSerializedTxBuffer());
			
			string userName(linPkt->getUsername());
			string password(linPkt->getPassword());

			Account* acc = AccDBHandler->login(userName, password);
			
			if (acc == nullptr) {
				ErrorPacket* err = new ErrorPacket(Login_Err);
				err->serializeErrorPacketTxBuffer();
				err->getSerializedParentTxBuffer();
				sendPacket(err);
				return false;
			}

			AccountPacket* accPkt = new AccountPacket(acc);

			accPkt->serializeAccountPacketTxBuffer();
			accPkt->serializeParentPacketTxBuffer();

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
			

			int move = newMovePacket->getMove();

			if (this->gr->updateBoard(move))
			{
				int compMove = this->gr->getGameBoard()->placeComputerMove();
				MovePacket* compMovePacket = new MovePacket(compMove);
				compMovePacket->serializeMovePacketTxBuffer();
				compMovePacket->serializeParentPacketTxBuffer();
				sendPacket(compMovePacket);
			}
			else
			{
				ErrorPacket* err = new ErrorPacket(Move_Err);
				err->serializeErrorPacketTxBuffer();
				err->getSerializedParentTxBuffer();
				sendPacket(err);
				return false;
			}
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

	//send and recv should also be ported to client
	void recvPicture() {

		//Needs a string for the name or to set it to an account?

		char RxBuffer[sizeof(int)];		//Sending just an integer protocol; not sure if it we should make an integer packet for this
		recv(ClientSocket, RxBuffer, sizeof(int), 0);

		int size;
		memcpy(&size, RxBuffer, sizeof(int));

		char* picture = new char[size];

		recv(ClientSocket, picture, size, 0);

		FILE* image;

		fopen_s(&image, "user.png", "wb");

		fwrite(picture, sizeof(char), sizeof(picture), image);

		fclose(image);


	}

	void sendPicture() {
		FILE* picture;
		fopen_s(&picture, "Dog.png", "rb");
		if (picture == NULL) {
			return;
		}

		fseek(picture, 0, SEEK_END);

		int size = ftell(picture);

		char* TxBuffer = new char[sizeof(int)];

		memcpy(TxBuffer, &size, sizeof(size));

		send(ClientSocket, TxBuffer, sizeof(size), 0);


		TxBuffer = new char[size];


		fseek(picture, 0, SEEK_SET);

		
		send(ClientSocket, TxBuffer, sizeof(TxBuffer), 0); 

		fclose(picture);

			

		
	}





};