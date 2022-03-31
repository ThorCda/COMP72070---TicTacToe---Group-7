#pragma once

#include <iostream>

#include "Logs.h"
#include "NetworkHandler.h"

class Menu {
	bool isRunning = true;
	NetworkHandler* hdlr = new NetworkHandler();
public:


	void start();
	void options(int option);
	void print();
	void removePlayer();
	void terminate();
	void runServer();
	




};