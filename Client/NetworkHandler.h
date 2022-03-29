#pragma once
#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")
#include <QWidget>
#include "../Server/ChildPackets.h"
#include "../Server/Packet.h"
using namespace std;

enum ACTION_TYPE { type_not_defined, buf_send, buf_receive, connected, disconnected };
enum MATCH_STATUS { status_not_defined, playing, ended, picture };
enum FILE_TYPE { error_log, game_log, conn_log };
enum ERROR_CODE { Login_Err, CrtAcc_Err, Quit_Err, Conn_Err, Move_Err };

class NetworkHandler : public QWidget
{
	Q_OBJECT

	SOCKET ListenSocket;
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

public slots:
	void LOGIN(char*, char*);

signals:

};