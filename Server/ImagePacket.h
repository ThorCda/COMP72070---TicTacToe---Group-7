#pragma once

#include "Packet.h"


using namespace std;

typedef struct ImageHeader {

	int ImageByteSize;
	int UsernameLength;

} ImgHeader;

class ImagePacket : public Packet {

	ImgHeader head;
	char* username;

public:

	ImagePacket() {
		this->head.ImageByteSize = 0;
		this->head.UsernameLength = 0;
		this->username = nullptr;

	}

	ImagePacket(int imageSize, int usernameLength, char* username) {
		this->head.ImageByteSize = imageSize;
		this->head.UsernameLength = usernameLength + 1;

		strcpy(this->username, username);

	}

	ImagePacket(char* buffer) {
		memcpy(&this->head, buffer, sizeof(head));
		this->username = new char[this->head.UsernameLength];
		memcpy(this->username, buffer + sizeof(head), this->head.UsernameLength);

	}

	void setUsername(char* username) {

		strcpy(this->username, username);
	}

	void setHead(int imageSize, int usernameLength) {
		this->head.ImageByteSize = imageSize;
		this->head.UsernameLength = usernameLength;
	}

	int getImageSize() {
		return this->head.ImageByteSize;
	}

	int getUsernameLength() {
		return this->head.UsernameLength;
	}

	char* getUsername() {
		return this->username;
	}

	void serializeAccountPacketTxBuffer() {
		int packetSize = sizeof(ImageHeader) + this->head.UsernameLength;

		this->serializedPacketBuffer = new char[packetSize] {};

		memcpy(this->serializedPacketBuffer, &this->head.ImageByteSize, sizeof(this->head.ImageByteSize));
		memcpy(this->serializedPacketBuffer, &this->head.UsernameLength, sizeof(this->head.UsernameLength));
		memcpy(this->serializedPacketBuffer, this->username, sizeof(this->head.UsernameLength));
	}

};
