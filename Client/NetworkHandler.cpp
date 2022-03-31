#include "NetworkHandler.h"

using namespace std;

NetworkHandler::NetworkHandler()
{
	winsockStartup();
	initSocket();
	initConnection();
}

int NetworkHandler::winsockStartup()
{
	//starts Winsock DLLs
	WSADATA wsaData;
	if ((WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0) {
		return 0;
	}
}

int NetworkHandler::initSocket()
{
	//initializes socket. SOCK_STREAM: TCP
	this->ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (this->ClientSocket == INVALID_SOCKET) {
		WSACleanup();
		return 0;
	}
}

int NetworkHandler::initConnection()
{
	//Connect socket to specified server
	this->SvrAddr.sin_family = AF_INET;                        //Address family type itnernet
	this->SvrAddr.sin_port = htons(27000);                    //port (host to network conversion)
	this->SvrAddr.sin_addr.s_addr = inet_addr("127.0.0.1");    //IP address
	if ((::connect(this->ClientSocket, (struct sockaddr*)&this->SvrAddr, sizeof(this->SvrAddr))) == SOCKET_ERROR) {
		closesocket(this->ClientSocket);
		WSACleanup();
		return 0;
	}
}

void NetworkHandler::listenForPacket() 
{
	char RxBuffer[1028];	//Max length of the biggest packet
	recv(ClientSocket, RxBuffer, sizeof(RxBuffer), 0);
	Packet* pkt = new Packet(RxBuffer);		//Not sure if RxBuffer should be reallocated 
	routePacket(pkt);
}

void NetworkHandler::closeSocket()
{
	closesocket(this->ClientSocket);	//closes incoming socket
	WSACleanup();					//frees Winsock resources
}

void NetworkHandler::sendPacket(Packet* p)
{
	send(ClientSocket, p->getSerializedParentTxBuffer(), sizeof(Header) + p->getHeaderBodyLength(), 0);
}

void NetworkHandler::routePacket(Packet* packet) {

	bool isLoggedIn = true;

	switch (packet->getHeaderPacketType())
	{

	case Accountp: {
		AccountPacket* newAccountPacket = new AccountPacket(packet->getSerializedTxBuffer());
		Account* acc = new Account(newAccountPacket->getAccount());
		emit LOGIN_SUCCESS(acc);
		break;
	}
	//case CreateAccountp: {


	//	CreateAccountPacket* pkt = new CreateAccountPacket(packet->getSerializedTxBuffer());

	//	Account* acc = new Account(pkt->getFName(), pkt->getLName(), pkt->getUsername());


	//	if (acc == nullptr) {
	//		//send error packet
	//		ErrorPacket* err = new ErrorPacket(CrtAcc_Err);
	//		err->serializeErrorPacketTxBuffer();
	//		err->getSerializedParentTxBuffer();
	//		sendPacket(err);
	//		return false;
	//	}

	//	AccountPacket* accpkt = new AccountPacket(acc);
	//	accpkt->serializeAccountPacketTxBuffer();
	//	accpkt->serializeParentPacketTxBuffer();
	//	sendPacket(accpkt);

	//	break;
	//}
	case Errorp: {
		ErrorPacket* newErrorPacket = new ErrorPacket(packet->getSerializedTxBuffer());
		emit LOGIN_FAILURE();
		// logError

		//If the error packet is a early quit or smt that it cannot recover from then 
			//isLoggedOut = false;

		break;
	}
	case GameStatusp: {
		//GameStatusPacket* newGameStatusPacket = new GameStatusPacket(packet->getSerializedTxBuffer());
		GameStatusPacket* gameStatusPacket = new GameStatusPacket(packet->getSerializedTxBuffer());
		emit GAME_STATUS(gameStatusPacket->getGameStatusPacketGameCode());
		break;
	}
	//case Loginp: {

	//	LoginPacket* linPkt = new LoginPacket(packet->getSerializedTxBuffer());

	//	string userName(linPkt->getUsername());
	//	string password(linPkt->getPassword());


	//	/*if (acc == nullptr) {
	//		ErrorPacket* err = new ErrorPacket(Login_Err);
	//		err->serializeErrorPacketTxBuffer();
	//		err->getSerializedParentTxBuffer();
	//		sendPacket(err);
	//		return false;
	//	}*/

	//	//AccountPacket* accPkt = new AccountPacket(acc);

	//	//accPkt->serializeAccountPacketTxBuffer();

	//	//sendPacket(accPkt);

	//	break;
	//}
	//case Logoutp: {
	//	LogoutPacket* newLogoutPacket = new LogoutPacket(packet->getSerializedTxBuffer());

	//	isLoggedIn = false;	//Will terminate the session
	//	break;
	//}
	case Movep: {
		MovePacket* newMovePacket = new MovePacket(packet->getSerializedTxBuffer());
		emit UPDATE_GAME_BOARD(newMovePacket->getMove());
		if (newMovePacket->getGameStatus() == 2)
		{
			emit GAME_STATUS(newMovePacket->getGameStatus());
		}
		
		break;
	}
	
	//case PacketPacket: {
	//	//Parent packet creator???
	//	break;
	//}
	default: {
		break;
	}
	}
}

//******** SLOTS *********//

void NetworkHandler::LOGIN(char* usr, char* pwd)
{
	/*char usr[] = "xxKarlxx";
	char pwd[] = "Conestoga";*/
	LoginPacket* p = new LoginPacket(usr, pwd);
	p->serializeLoginPacket();
	p->serializeParentPacketTxBuffer();
	sendPacket(p);
	listenForPacket();
}

void NetworkHandler::LOGOUT()
{
	LogoutPacket* p = new LogoutPacket();
	p->serializeParentPacketTxBuffer();
	p->serializeLogoutPacket();
	sendPacket(p);
	/*listenForPacket();*/
}

void NetworkHandler::CREATE_ACCOUNT(char* username, char* fName, char* lName, char* pwd)
{
	CreateAccountPacket* p = new CreateAccountPacket(username, fName, lName, pwd);
	p->serializeCreateAccountPacketTxBuffer();
	p->serializeParentPacketTxBuffer();
	sendPacket(p);
	listenForPacket();
}

//void NetworkHandler::START_CONNECTION()
//{
//	winsockStartup();
//	initSocket();
//	initConnection();
//}
//
//void NetworkHandler::STOP_CONNECTION()
//{
//	closeSocket();
//}

//************* Images **************//

	//send and recv should also be ported to client and server
void NetworkHandler::recvImage(int size) {

	char* RxBuffer = new char[size];

	recv(ClientSocket, RxBuffer, size, 0);

	FILE* image;
	 
	fopen_s(&image, "Avatar.jpeg", "wb"); //Not sure where to get the pathname from

	fwrite(RxBuffer, sizeof(char), sizeof(RxBuffer), image);

	fclose(image);
}


void  NetworkHandler::sendImage(char* username) 
{

	FILE* picture;

	fopen_s(&picture, username, "rb");

	if (picture == NULL) {
		ErrorPacket* err = new ErrorPacket(Image_Err);
		err->serializeErrorPacketTxBuffer();
		err->getSerializedParentTxBuffer();
		sendPacket(err);
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

	fclose(picture);
}

void NetworkHandler::GAME_MOVE(int gridNum)
{
	MovePacket* p = new MovePacket(gridNum, 0);
	p->serializeMovePacketTxBuffer();
	p->serializeParentPacketTxBuffer();
	sendPacket(p);
	listenForPacket();
}