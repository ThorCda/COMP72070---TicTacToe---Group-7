#include "Menu.h"
#include "DB_Handler.h"

void Menu::start()
{
	do {
		int option;
		Menu::print();
		do {
			std::cout << "\n\nMenu option: ";
			std::cin >> option;

		} while (option < 1 || option > 5);

		Menu::options(option);

		system("pause");
		system("cls");

	} while (isRunning);

}

//Facilitates the program flow
void Menu::options(int option) {
	


	switch (option)
	{
	case 1:
		runServer();
		break;
	case 2:
		Logs::read(error_log);
		break;
	case 3:
		Logs::read(conn_log);
		break;
	case 4:
		Logs::read(game_log);
		break;
	case 5:
		Menu::terminate();
		isRunning = false;
	default:
		break;
	}
}

void Menu::print() {

	std::cout << "Server Interface\n";
	std::cout << "\t1) Initalize server\n";
	std::cout << "\t2) Print error logs\n";
	std::cout << "\t3) Print connection logs\n";
	std::cout << "\t4) Print game logs\n";
	std::cout << "\t5) Terminate and exit\n";

}

void Menu::terminate() {
	//enter any server termination code here

	hdlr->closeSocket();

}

void Menu::runServer() {

	hdlr->winsockStartup();
	hdlr->initSocket();
	hdlr->bindConnect();
	hdlr->listenSocket();
	hdlr->acceptClient();
	hdlr->listenForPacket();
	
	while (hdlr->listenForPacket()) {}

}
