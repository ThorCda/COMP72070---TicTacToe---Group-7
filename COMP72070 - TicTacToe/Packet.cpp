#include "Packet.h"

using namespace std;

Packet::Packet() {

	if (this->pktBody.msgPtr != NULL) {
		delete this->pktBody.msgPtr;
	}

	if (this->serializedPacketBuffer != NULL) {
		delete this->serializedPacketBuffer;
	}

	this->pktHead.destinationID = SERVER_ID;
	this->pktHead.sourceID = CLIENT_ID;
	this->pktHead.bodyLength = 0;
	this->pktHead.packetType = DEFAULT_PACKET;

	pktBody.msgPtr = NULL;
	serializedPacketBuffer = NULL;

}

Packet::Packet(char* RxBuffer) {

	int byteBuffer = 0;

	//Instantiate pktHead based on bytes in RxBuffer.
	memcpy(&this->pktHead.destinationID, RxBuffer, sizeof(this->pktHead.destinationID));
	byteBuffer += sizeof(this->pktHead.destinationID);

	memcpy(&this->pktHead.sourceID, RxBuffer + byteBuffer, sizeof(this->pktHead.sourceID));
	byteBuffer += sizeof(this->pktHead.sourceID);

	memcpy(&this->pktHead.bodyLength, RxBuffer + byteBuffer, sizeof(this->pktHead.bodyLength));
	byteBuffer += sizeof(this->pktHead.bodyLength);

	memcpy(&this->pktHead.packetType, RxBuffer + byteBuffer, sizeof(this->pktHead.packetType));
	byteBuffer += sizeof(this->pktHead.packetType);

	//Instantiate pktBody msgPtr.
	memcpy(this->pktBody.msgPtr, RxBuffer + byteBuffer, this->pktHead.bodyLength);
	byteBuffer += this->pktHead.bodyLength;

	//Instantiate pktTail checkSum.
	//memcpy(&this->pktTail.checkSum, RxBuffer + byteBuffer, sizeof(this->pktTail.checkSum));
	
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

void Packet::setHeaderBodyLength() {

	if (this->pktBody.msgPtr != NULL) {

		this->pktHead.bodyLength = strlen(this->pktBody.msgPtr);

	}

}

void Packet::setHeaderPacketType(char packetType) {

	//Discuss a constant format for packet types.
	this->pktHead.packetType = packetType;

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

char Packet::getHeaderPacketType() {

	return this->pktHead.packetType;

}

//Body Setter Methods
void Packet::setBodyMsgPtr(char* msg) {

	this->pktBody.msgPtr = msg;

}

//Body Getter Methods
char* Packet::getBodyMsgPtr() {

	return this->pktBody.msgPtr;

}

//Tail Setter Methods
void Packet::setTailCheckSum() {



}

//Tail Getter Methods
//void getTailCheckSum();

//Serialization Method
void Packet::serializePacketTxBuffer() {
	
	int byteBuffer = 0;

	memcpy(serializedPacketBuffer, &this->pktHead.destinationID, sizeof(this->pktHead.destinationID));
	byteBuffer += sizeof(this->pktHead.destinationID);

	memcpy(serializedPacketBuffer + byteBuffer, &this->pktHead.sourceID, sizeof(this->pktHead.sourceID));
	byteBuffer += sizeof(this->pktHead.sourceID);

	memcpy(serializedPacketBuffer + byteBuffer, &this->pktHead.bodyLength, sizeof(this->pktHead.bodyLength));
	byteBuffer += sizeof(this->pktHead.bodyLength);

	memcpy(serializedPacketBuffer + byteBuffer, &this->pktHead.packetType, sizeof(this->pktHead.packetType));
	byteBuffer += sizeof(this->pktHead.packetType);

	strcpy(&serializedPacketBuffer[byteBuffer], this->pktBody.msgPtr);
	byteBuffer += this->pktHead.bodyLength;

	//memcpy(serializedPacketBuffer + byteBuffer, &this->pktTail.checksum, sizeof(this->pktTail.checksum));

}

char* Packet::getSerializedTxBuffer() {

	return this->serializedPacketBuffer;

}
