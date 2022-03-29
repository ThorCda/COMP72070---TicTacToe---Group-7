#define _CRT_SECURE_NO_WARNINGS

#include "Packet.h"
#include "ChildPackets.h"

using namespace std;

Packet::Packet() {

	if (this->serializedParentBuffer) {
		delete this->serializedParentBuffer;
	}

	if (this->serializedPacketBuffer != NULL) {
		delete this->serializedPacketBuffer;
	}

	this->pktHead.destinationID = SERVER_ID;
	this->pktHead.sourceID = CLIENT_ID;
	this->pktHead.bodyLength = 0;

	serializedPacketBuffer = NULL;
	serializedParentBuffer = NULL;

}

Packet::Packet(char* RxBuffer) {

	memcpy(&this->pktHead, RxBuffer, sizeof(pktHead));

	this->serializedPacketBuffer = new char[this->pktHead.bodyLength];
	memcpy(&this->serializedPacketBuffer, RxBuffer + sizeof(pktHead), this->pktHead.bodyLength);
	
}
	
Packet::~Packet() {

	delete this;

}

//Header Setter Methods
void Packet::setHeaderDestinationID(int customDestinationID) {

	this->pktHead.destinationID = customDestinationID;

}

void Packet::setHeaderDestinationID() {

	//Discuss a constant SERVER_ID.
	this->pktHead.destinationID = SERVER_ID;

}

void Packet::setHeaderSourceID(int customSourceID) {

	//Discuss a constant CLIENT_ID.
	this->pktHead.sourceID = customSourceID;

}

void Packet::setHeaderSourceID() {

	//Discuss a constant CLIENT_ID.
	this->pktHead.sourceID = CLIENT_ID;

}

void Packet::setHeaderBodyLength(int len) {

	this->pktHead.bodyLength = len;

}

void Packet::swapHeaderDestAndSource() {

	int temp;

	temp = this->pktHead.destinationID;
	this->pktHead.destinationID = this->pktHead.sourceID;
	this->pktHead.sourceID = temp;

}

//Header Getter Methods
int Packet::getHeaderDestinationID() {

	return this->pktHead.destinationID;

}

int Packet::getHeaderSourceID() {

	return this->pktHead.sourceID;

}

int Packet::getHeaderBodyLength() {

	return this->pktHead.bodyLength;

}

packetType Packet::getHeaderPacketType() {

	return this->pktHead.packetType;

}

//Tail Setter Methods
void Packet::setTailCheckSum() {



}

//Tail Getter Methods
//void getTailCheckSum();

//Serialization Method

char* Packet::getSerializedTxBuffer() {

	return this->serializedPacketBuffer;

}

void Packet::serializeParentPacketTxBuffer() {

	int byteBuffer = 0;

	this->serializedParentBuffer = new char[getHeaderBodyLength() + sizeof(this->pktHead)];

	memcpy(this->serializedParentBuffer, &this->pktHead.destinationID, sizeof(this->pktHead.destinationID));
	byteBuffer += sizeof(this->pktHead.destinationID);

	memcpy(this->serializedParentBuffer + byteBuffer, &this->pktHead.sourceID, sizeof(this->pktHead.sourceID));
	byteBuffer += sizeof(this->pktHead.sourceID);

	memcpy(this->serializedParentBuffer + byteBuffer, &this->pktHead.packetType, sizeof(this->pktHead.packetType));
	byteBuffer += sizeof(this->pktHead.packetType);

	memcpy(this->serializedParentBuffer + byteBuffer, &this->pktHead.bodyLength, sizeof(this->pktHead.bodyLength));
	byteBuffer += sizeof(this->pktHead.bodyLength);

	memcpy(this->serializedParentBuffer + byteBuffer, &this->serializedPacketBuffer, this->pktHead.bodyLength);
	byteBuffer += this->pktHead.bodyLength;

}

char* Packet::getSerializedParentTxBuffer() {

	return this->serializedParentBuffer;

}

