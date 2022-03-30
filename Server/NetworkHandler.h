
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


//hdlr->listenSocket();
//hdlr->acceptClient();
//hdlr->listenForPacket();
//
//while (hdlr->listenForPacket()) {}

enum ServerState {

	UNINITIALIZED,
	INITIALIZING,
	CONNECTING,
	CONNECTED,
	LISTENING,
	EXECUTING

};

class NetworkHandler
{
	SOCKET ListenSocket;
	SOCKET ClientSocket;
	sockaddr_in SvrAddr;
	GameRoom* gr = new GameRoom();
	Account_DB_Handler* AccDBHandler = new Account_DB_Handler();
	ServerState currentState = UNINITIALIZED;
	
public:

	int getState() {

		return this->currentState;

	}

	void setState(ServerState state) {

		this->currentState = state;

	}

	int winsockStartup()
	{
		setState(INITIALIZING);
		//starts Winsock DLLs
		WSADATA wsaData;
		if ((WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0) {
			return 0;
		}
		cout << "Winsock: Initalized..." << endl;		

	}

	int initSocket()
	{
		setState(INITIALIZING);
		//initializes socket. SOCK_STREAM: TCP
		this->ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (this->ListenSocket == INVALID_SOCKET) {
			WSACleanup();
			return 0;
		}
		cout << "Winsock: Socket created..." << endl;
		
	}

	int bindConnect() {
		
		setState(INITIALIZING);
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
		setState(CONNECTING);
		if ((this->ClientSocket = accept(this->ListenSocket, NULL, NULL)) == SOCKET_ERROR) {
			closesocket(this->ListenSocket);
			WSACleanup();
			return 0;
		}
		cout << "Winsock: Connection Established" << endl;
		setState(CONNECTED);
		Logs::write(true, connected, NULL);
	}

	bool listenForPacket() {

		setState(LISTENING);
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
		setState(UNINITIALIZED);

	}


	void sendPacket(Packet* p)
	{
		setState(EXECUTING);
		cout << "Winsock: Sending packet..." << endl;
		
		send(ClientSocket, p->getSerializedParentTxBuffer(), sizeof(Header) + p->getHeaderBodyLength(), 0);

		Logs::write(true, buf_send, p->getSerializedParentTxBuffer());
	}

	bool routePacket(Packet* packet) {

		setState(EXECUTING);
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
				err->serializeParentPacketTxBuffer();
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

			//Sends a picture packet sendImageFromDB(acc->getUsername());

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
		case Imagep: {

			ImagePacket* imgPkt = new ImagePacket(packet->getSerializedTxBuffer());
			recvImage(imgPkt->getImageSize(), imgPkt->getUsername());

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

	//send and recv should also be ported to client and server
	void recvImage(int size, char* username) {

		char* pathname = username;

		strcat(pathname, ".jpeg");

		char* RxBuffer = new char[size];

		recv(ClientSocket, RxBuffer, size, 0);

		FILE* image;

		fopen_s(&image, username, "wb");

		fwrite(RxBuffer, sizeof(char), sizeof(RxBuffer), image);

		

		AccDBHandler->insertImage(username, pathname);

		fclose(image);
	}


	void sendImageFromDB(char* username) {

		FILE* picture;

		char* pathname = AccDBHandler->getImage(username);

		fopen_s(&picture, pathname, "rb");

		if (picture == NULL) {
			ErrorPacket* err = new ErrorPacket(Image_Err);
			err->serializeErrorPacketTxBuffer();
			err->getSerializedParentTxBuffer();
			sendPacket(err);
			Logs::write(1, Image_Err);
			return;
		}

		fseek(picture, 0, SEEK_END);

		int size = ftell(picture);

		ImagePacket* imgPkt = new ImagePacket(size, strlen(username), username);
		imgPkt->serializeImagePacketTxBuffer();
		imgPkt->serializeParentPacketTxBuffer();
		sendPacket(imgPkt);

		char* TxBuffer = new char[size];

		fseek(picture, 0, SEEK_SET);

		fread(TxBuffer, sizeof(char), size, picture);
		
		send(ClientSocket, TxBuffer, sizeof(TxBuffer), 0);
		Logs::write(true, Photo, NULL);

		fclose(picture);

	}

};