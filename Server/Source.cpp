#include <iostream>
#include "ChildPackets.h"
#include "Account_DB_Handler.h"
#include "Logs.h"
#include "Menu.h"

using namespace std;

int main() {

	//char usr[] = "xxKarlxx";
	//char pwd[] = "Conestoga";
	//Account acc = new Account();

	//AccountPacket* p = new AccountPacket();
	//p->serializeLoginPacket();
	//p->serializeParentPacketTxBuffer();

	//Packet* pkt = new Packet(p->getSerializedParentTxBuffer());		//Not sure if RxBuffer should be reallocated 
	//LoginPacket* linPkt = new LoginPacket(pkt->getSerializedTxBuffer());

	//char usr[] = "xxKarlxx";
	//char pwd[] = "Conestoga";


	//Account_DB_Handler adb;
	//adb.createConnection();
	//adb.insertImage(usr, pwd);
	//cout << adb.getImage(usr);

	//GameRoom gb;
	//gb.updateBoard(6);
	//gb.updateBoard(3);
	//gb.updateBoard(9);
	//if (gb.getGameBoard()->getPlayerWin())
	//{
	//	cout << "big win";
	//}


	//adb.login(usr, pwd);
	//adb.login(usr, pwd);

	/*MovePacket* p = new MovePacket(1, 0);
	p->serializeMovePacketTxBuffer();
	p->serializeParentPacketTxBuffer();*/

	Menu* menu = new Menu();
	menu->start();

}