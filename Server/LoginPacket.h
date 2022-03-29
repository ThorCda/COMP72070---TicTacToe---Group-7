#pragma once

#include "Packet.h"

using namespace std;

class LoginPacket : public Packet{
	
	struct LOGINHEADER {

		int usernameLength;
		int passwordLength;

	}LoginHeader;

	char* username;
	char* password;

public:

	//Safe state packet
	LoginPacket() {

		this->pktHead.packetType = Loginp;

		this->LoginHeader.passwordLength = 0;
		this->LoginHeader.usernameLength = 0;

		this->username = nullptr;
		this->password = nullptr;

	}

	//Packet with paremters
	LoginPacket(char* un, char* pwd) {
		
		if (this->serializedPacketBuffer != NULL) {
			delete serializedPacketBuffer;
		}

		this->pktHead.packetType = Loginp;

		this->LoginHeader.usernameLength = strlen(un) + 1;
		this->LoginHeader.passwordLength = strlen(pwd) + 1;

		this->username = un;
		this->password = pwd;

	}

	//From serial buffer
	LoginPacket(char* src) {

		memcpy(&this->LoginHeader.usernameLength, src, sizeof(LoginHeader.usernameLength));
		memcpy(&this->LoginHeader.passwordLength, src + sizeof(LoginHeader.usernameLength), sizeof(LoginHeader.passwordLength));

		this->username = new char[this->LoginHeader.usernameLength];
		
		memcpy(this->username, src + sizeof(LoginHeader), this->LoginHeader.usernameLength);

		this->password = new char[this->LoginHeader.passwordLength];
		
		memcpy(this->password, src + sizeof(LoginHeader) + this->LoginHeader.usernameLength, this->LoginHeader.passwordLength);


	}

	//Serizlation of packet
	void serilizeLoginPacket() {

		if (this->serializedPacketBuffer != NULL) {
			delete serializedPacketBuffer;
		}

		int totalSize = sizeof(LoginHeader) + this->LoginHeader.usernameLength + this->LoginHeader.passwordLength;

		serializedPacketBuffer = new char[totalSize];

		memcpy(serializedPacketBuffer, &this->LoginHeader, sizeof(LoginHeader));
		memcpy(serializedPacketBuffer + sizeof(LoginHeader), this->username, this->LoginHeader.usernameLength);
		memcpy(serializedPacketBuffer + sizeof(LoginHeader) + this->LoginHeader.usernameLength, this->password, this->LoginHeader.passwordLength);

	}

	~LoginPacket() {

		delete this->password;
		delete this->username;
		delete this->serializedPacketBuffer;

		delete this;

	}

	char* getUsername() {

		return this->username;

	}

	char* getPassword() {

		return this->password;

	}

    char* getUsername() const { return username; }
    void setUsername(char* username) { this->username = username; }

    char* getPassword() const { return password; }
    void setPassword(char* password) { this->password = password; }

};
