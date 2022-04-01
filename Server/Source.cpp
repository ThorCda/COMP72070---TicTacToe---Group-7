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
	//gb.updateBoard(7);
	//gb.getGameBoard()->placeComputerMoveTemp(4);
	//gb.updateBoard(9);
	//gb.getGameBoard()->placeComputerMoveTemp(8);
	//gb.updateBoard(5);
	//gb.getGameBoard()->placeComputerMoveTemp(6);
	//gb.updateBoard(2);
	//gb.getGameBoard()->placeComputerMoveTemp(3);
	//gb.updateBoard(1);
	//gb.getGameBoard()->placeComputerMove();

	//if (gb.getGameBoard()->getComputerWin())
	//{
	//	cout << "comp win =[";
	//}
	//if (gb.getGameBoard()->getPlayerWin())
	//{
	//	cout << "player win =[";
	//}
	//if (gb.getGameBoard()->getDraw())
	//{
	//	cout << "big draw o7";
	//}

	//int gabr;
	//cin >> gabr;


	//adb.login(usr, pwd);
	//adb.login(usr, pwd);

	/*MovePacket* p = new MovePacket(1, 0);
	p->serializeMovePacketTxBuffer();
	p->serializeParentPacketTxBuffer();*/

	/*ImagePacket* imgPkt = new ImagePacket(50);
	imgPkt->serializeImagePacketTxBuffer();
	imgPkt->serializeParentPacketTxBuffer();*/

	Menu* menu = new Menu();
	menu->start();

}