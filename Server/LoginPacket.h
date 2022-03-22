#pragma once

#include "../COMP72070 - TicTacToe/Packet.h"

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
		this->username[this->LoginHeader.usernameLength] = 00;
		memcpy(this->username, src + sizeof(LoginHeader), this->LoginHeader.usernameLength);

		this->password = new char[this->LoginHeader.passwordLength];
		this->password[this->LoginHeader.passwordLength] = 00;
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



};
