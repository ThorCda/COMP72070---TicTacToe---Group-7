#include <iostream>
#include "ChildPackets.h"

using namespace std;


int main() {
		
	//Account_DB_Handler adb;

	/*char us[] = "Gabeele";
	char fis[] = "Gavin";
	char la[] = "Abeele";
	char pic[] = "C://Hello.png";

	Account a = new Account(1, fis, la, pic, us, 1, 2, 1, true);

	AccountPacket np(&a);

	np.serializeAccountPacketTxBuffer();

	char* m = np.getSerializedAccountPacketBuffer();*/

	//AccountPacket* r = new AccountPacket(m);	

	//Create accont packet test

	char us[] = "Gabeele";
	char fis[] = "Gavin";
	char la[] = "Abeeleee";
	char pw[] = "Conestoga";
	char pic[] = "C://Hello.png";

	CreateAccountPacket* np = new CreateAccountPacket(us, fis, la, pw);

	np->serializeCreateAccountPacketTxBuffer();

	np->serializeParentPacketTxBuffer();

	Packet* p = new Packet();

	p = p->constructPacket(np->getSerializedParentTxBuffer());



	//char we[] = "Gavin";
	//char p[] = "Conestoga";

	//LoginPacket* l = new LoginPacket(we, p);

	//l->serilizeLoginPacket();

	//char* o = l->getSerializedTxBuffer();

	//LoginPacket* t = new LoginPacket(o);

	//LogoutPacket* j = new LogoutPacket(false);

	//j->serilizeLogoutPacket();

	//char* v = j->getSerializedTxBuffer();

	//LogoutPacket* q = new LogoutPacket(v);

	/*MovePacket* x = new MovePacket(3);

	x->serializeMovePacketTxBuffer();

	char* z = x->getSerializedTxBuffer();

	MovePacket* u = new MovePacket(z);*/
	
	/*int gameStatus = 3;

	GameStatusPacket* xx = new GameStatusPacket(gameStatus);

	xx->serializeGameStatusPacketBuffer();

	char* zz = xx->getSerializedTxBuffer();

	GameStatusPacket* xxx = new GameStatusPacket(zz);

	int x = 0;*/

	//int xx = 2;
	//ErrorPacket * x = new ErrorPacket(xx);

	//x->serializeErrorPacketTxBuffer();

	//char* xxx = x->getSerializedTxBuffer();

	//ErrorPacket* xxxx = new ErrorPacket(xxx);



}