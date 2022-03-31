#pragma once

#include "Packet.h"

using namespace std;


class LogoutPacket : public Packet {

	bool isLoggedOut;

public:

	//Safe state packet
	LogoutPacket() {

		this->pktHead.packetType = Logoutp;

		this->isLoggedOut = true;

	}

	//Packet with paremters
	LogoutPacket(bool logout) {
	
		this->pktHead.packetType = Logoutp;

		this->isLoggedOut = logout;

	}

	//From serial buffer
	LogoutPacket(char* src) {
	
		memcpy(&this->isLoggedOut, src, sizeof(this->isLoggedOut));

	}

	//Serizlation of packet
	void serializeLogoutPacket() {

		if (this->serializedPacketBuffer != NULL) {
			delete serializedPacketBuffer;
		}

		int totalSize = sizeof(this->isLoggedOut);
		serializedPacketBuffer = new char[totalSize];
		this->setHeaderBodyLength(totalSize);

		memcpy(serializedPacketBuffer, &this->isLoggedOut, sizeof(this->isLoggedOut));

	}

	~LogoutPacket() {

		delete this->serializedPacketBuffer;
		delete this;

	}

    bool getIsLoggedOut() const { return isLoggedOut; }

    void setIsLoggedOut(bool isLoggedOut) { this->isLoggedOut = isLoggedOut; }

};
