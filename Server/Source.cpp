#include <iostream>
#include "Account.h"
#include "Account_DB_Handler.h"

using namespace std;


int main() {
	Account_DB_Handler adb;
	Account acc(1, "Thomas", "Horvath", "bababooy", "ThorCda", 1, 1, 1, 1);

	adb.updateAccount(acc);
}