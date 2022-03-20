#pragma once

#include "../COMP72070 - TicTacToe/Packet.h"

using namespace std;


class LogoutPacket : public Packet {

	bool isLoggedOut;

	char* serLoginBuf;

public:

	//Safe state packet
	LogoutPacket() {

		this->isLoggedOut = true;

	}

	//Packet with paremters
	LogoutPacket(bool logout) {
	
		this->isLoggedOut = logout;

	}

	//From serial buffer
	LogoutPacket(char* src) {
	
		memcpy(&this->isLoggedOut, src, sizeof(this->isLoggedOut));

	}

	//Serizlation of packet
	void serilizeLogoutPacket() {

		if (this->serLoginBuf != NULL) {
			delete serLoginBuf;
		}

		serLoginBuf = new char[sizeof(this->isLoggedOut)];

		memcpy(serLoginBuf, &this->isLoggedOut, sizeof(this->isLoggedOut));

	}

	~LogoutPacket() {

		delete this;

	}



};
