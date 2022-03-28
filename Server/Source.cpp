#include <iostream>
#include "ChildPackets.h"

#include "Account_DB_Handler.h"
#include "Logs.h"
#include "Menu.h"

using namespace std;

int main() {

	//Menu* menu = new Menu();

	//menu->start();

	Account_DB_Handler db;
	char c[] = "Computer";
	Account acc = new Account(c,c,c);

	acc.setAvatarloc(c);

	char p[] = "Hello";
	db.createAccount(acc, p);

}