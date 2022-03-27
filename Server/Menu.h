#pragma once

#include <iostream>

#include "Logs.h"
#include "NetworkHandler.h"

class Menu {

public:
	bool isRunning = true;

	void start();
	void options(int option);
	void print();
	void terminate();
	void runServer();
	




};