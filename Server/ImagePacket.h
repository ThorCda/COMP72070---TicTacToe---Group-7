#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "Packet.h"


using namespace std;

typedef struct ImageHeader {

	int ImageByteSize;

} ImgHeader;

class ImagePacket : public Packet {

	ImgHeader head;

public:

	ImagePacket() {
		this->head.ImageByteSize = 0;
		this->pktHead.packetType = Imagep;
	}

	ImagePacket(int imageSize) {
		this->head.ImageByteSize = imageSize;
		this->pktHead.packetType = Imagep;
	}

	ImagePacket(char* buffer) {
		memcpy(&this->head, buffer, sizeof(head));
		this->pktHead.packetType = Imagep;
	}

	void setHead(int imageSize) {
		this->head.ImageByteSize = imageSize;
	}

	int getImageSize() {
		return this->head.ImageByteSize;
	}


	void serializeImagePacketTxBuffer() {
		int packetSize = sizeof(ImageHeader);

		this->serializedPacketBuffer = new char[packetSize] {};

		memcpy(this->serializedPacketBuffer, &this->head.ImageByteSize, sizeof(this->head.ImageByteSize));

		this->setHeaderBodyLength(packetSize);
	}

};
