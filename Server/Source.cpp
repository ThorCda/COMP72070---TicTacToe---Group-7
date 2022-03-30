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

	char usr[] = "xxKarlxx";
	char pwd[] = "Conestoga";

	//Account_DB_Handler adb;

	//adb.login(usr, pwd);
	//adb.login(usr, pwd);

	Menu* menu = new Menu();
	menu->start();

}