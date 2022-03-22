#include <iostream>
#include "Account.h"
#include "AccountPacket.h"
#include "CreateAccountPacket.h"
#include "Account_DB_Handler.h"

using namespace std;


int main() {
		
	//Account_DB_Handler adb;

	//char us[] = "Gabeele";
	//char fis[] = "Gavin";
	//char la[] = "Abeele";
	//char pic[] = "C://Hello.png";

	//Account a = new Account(1, fis, la, pic, us, 1, 2, 1, true);

	//AccountPacket np(&a);

	//np.serializeAccountPacketTxBuffer();

	//char* m = np.getSerializedAccountPacketBuffer();

	//AccountPacket* r = new AccountPacket(m);	//Ask elliott why we need new in release mode. Optimization?


	//Create accont packet test

	char us[] = "Gabeele";
	char fis[] = "Gavin";
	char la[] = "Abeele";
	char pw[] = "Conestoga";
	char pic[] = "C://Hello.png";

	CreateAccountPacket* np = new CreateAccountPacket(us, fis, la, pw);

	np->serializeCreateAccountPacketTxBuffer();

	char* m = np->getSerializedTxBuffer();

	AccountPacket* r = new AccountPacket(m);	//Ask elliott why we need new in release mode. Optimization?


}