#include <iostream>
#include "ChildPackets.h"
#include "Account_DB_Handler.h"
#include "Logs.h"
#include "Menu.h"

using namespace std;

int main() {

	//char usr[] = "xxKarlxx";
	//char pwd[] = "Conestoga";
	//LoginPacket* p = new LoginPacket(usr, pwd);
	//p->serializeLoginPacket();
	//p->serializeParentPacketTxBuffer();

	//Packet* pkt = new Packet(p->getSerializedParentTxBuffer());		//Not sure if RxBuffer should be reallocated 
	//LoginPacket* linPkt = new LoginPacket(pkt->getSerializedTxBuffer());

	Menu* menu = new Menu();
	menu->start();

}