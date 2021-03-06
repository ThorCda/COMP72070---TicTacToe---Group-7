#pragma once
#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")
#include <QWidget>
#include <iostream>
#include <fstream>
#include "../Server/ChildPackets.h"
#include "../Server/Packet.h"
using namespace std;
enum ACTION_TYPE
{type_not_defined, buf_send, buf_receive, connected, disconnected, Photo};

enum MATCH_STATUS
{status_not_defined, playing, ended, picture};

enum FILE_TYPE
{error_log, game_log, conn_log};

enum ERROR_CODE
{Login_Err, CrtAcc_Err, Quit_Err, Conn_Err, Move_Err, Image_Err};


class NetworkHandler : public QWidget
{
	Q_OBJECT
public:
	SOCKET ClientSocket;
	sockaddr_in SvrAddr;
	
public:
	NetworkHandler();
	int winsockStartup();
	int initSocket();
	int initConnection();
	int acceptClient();
	void listenForPacket();
	void closeSocket();
	void sendPacket(Packet* p);
	void routePacket(Packet* packet);
	void recvImage(int size);

public slots:
	//void START_CONNECTION();
	//void STOP_CONNECTION();

	void LOGIN(char*, char*);
	void LOGOUT();
	void GAME_MOVE(int);
	void CREATE_ACCOUNT(char*, char*, char*, char*);
	void SEND_IMAGE(string);
	void REQUEST_IMAGE();

signals:
	void LOGIN_SUCCESS(Account*);
	void LOGIN_FAILURE();
	void UPDATE_GAME_BOARD(int);
	void GAME_STATUS(int);
	void IMAGE_RECIEVED();

};