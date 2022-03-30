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
	send(ClientSocket, p->getSerializedTxBuffer(), sizeof(Header) + p->getHeaderBodyLength(), 0);
}

void NetworkHandler::routePacket(Packet* packet) {

	bool isLoggedIn = true;

	switch (packet->getHeaderPacketType())
	{

	case Accountp: {
		AccountPacket* newAccountPacket = new AccountPacket(packet->getSerializedTxBuffer());
		// login(newAccountPacket)
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
		// logError

		//If the error packet is a early quit or smt that it cannot recover from then 
			//isLoggedOut = false;

		break;
	}
	//case GameStatusp: {
	//	GameStatusPacket* newGameStatusPacket = new GameStatusPacket(packet->getSerializedTxBuffer());
	//	// 
	//	break;
	//}
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
	//case Movep: {
	//	MovePacket* newMovePacket = new MovePacket(packet->getSerializedTxBuffer());
	//	// PlayMove(newMovePacket)
	//	break;
	//}
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

void NetworkHandler::LOGIN()
{
	char usr[] = "xxKarlxx";
	char pwd[] = "Conestoga";
	LoginPacket* p = new LoginPacket(usr, pwd);
	p->serializeLoginPacket();
	p->serializeParentPacketTxBuffer();
	sendPacket(p);
	//listenForPacket();
}