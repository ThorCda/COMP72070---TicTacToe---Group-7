#include <iostream>
#include "Account.h"
#include "Account_DB_Handler.h"

using namespace std;


int main() {
	Account_DB_Handler adb;
	
	string u = "hi";

	Account a = new Account(1, u, u,  u, u, 1, 2, 1, true);

	AccountPacket np(&a);

	np.serializeAccountPacketTxBuffer();

	char* m = np.getSerializedAccountPacketBuffer();

	AccountPacket r(m);

}