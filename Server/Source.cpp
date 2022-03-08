#include <iostream>
#include "Account.h"
#include "DB_Handler.h"

using namespace std;


int main() {
	Database_Info db;
	db.connect();
	Account acc(1, "Thomas", "Horvath", "bababooy", 1, 1, 1, 1);
}