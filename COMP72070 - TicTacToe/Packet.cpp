#define _CRT_SECURE_NO_WARNINGS

#include "Packet.h"
#include "../Server/ChildPackets.h"

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
	this->pktHead.packetType = PacketPacket;

	serializedPacketBuffer = NULL;
	serializedParentBuffer = NULL;

}

//Packet::Packet(char* RxBuffer) {
//
//	int byteBuffer = 0;
//
//	//Instantiate pktHead based on bytes in RxBuffer.
//	memcpy(&this->pktHead.destinationID, RxBuffer, sizeof(this->pktHead.destinationID));
//	byteBuffer += sizeof(this->pktHead.destinationID);
//
//	memcpy(&this->pktHead.sourceID, RxBuffer + byteBuffer, sizeof(this->pktHead.sourceID));
//	byteBuffer += sizeof(this->pktHead.sourceID);
//
//	memcpy(&this->pktHead.bodyLength, RxBuffer + byteBuffer, sizeof(this->pktHead.bodyLength));
//	byteBuffer += sizeof(this->pktHead.bodyLength);
//
//	memcpy(&this->pktHead.packetType, RxBuffer + byteBuffer, sizeof(this->pktHead.packetType));
//	byteBuffer += sizeof(this->pktHead.packetType);
//
//	//Instantiate pktTail checkSum.
//	//memcpy(&this->pktTail.checkSum, RxBuffer + byteBuffer, sizeof(this->pktTail.checkSum));
//	
//}
	
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

	this->pktHead.bodyLength = strlen(this->serializedPacketBuffer);

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

	this->setHeaderBodyLength();

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

Packet* Packet::constructPacket(char* rxBuffer) {

	//	0 Accountp,
	//	CreateAccountp,
	//	Errorp,
	//	GameStatusp,
	//	Loginp,
	//	Logoutp,
	//	Movep,
	//	7 PacketPacket

	memcpy(&this->pktHead, rxBuffer, sizeof(pktHead));

	memcpy(&this->serializedPacketBuffer, rxBuffer + sizeof(pktHead), this->pktHead.bodyLength);
	
	switch (this->pktHead.packetType)
	
	{

	case Accountp: {
		AccountPacket* newAccountPacket = new AccountPacket(this->serializedPacketBuffer);
		return newAccountPacket;
		break;
	}

	case CreateAccountp: {
		CreateAccountPacket* newCreateAccountPacket = new CreateAccountPacket(this->serializedPacketBuffer);
		return newCreateAccountPacket;
		break;
	}

	case Errorp: {
		ErrorPacket* newErrorPacket = new ErrorPacket(this->serializedPacketBuffer);
		return newErrorPacket;
		break;
	}

	case GameStatusp: {
		GameStatusPacket* newGameStatusPacket = new GameStatusPacket(this->serializedPacketBuffer);
		return newGameStatusPacket;
		break;
	}

	case Loginp: {
		LoginPacket* newLoginPacket = new LoginPacket(this->serializedPacketBuffer);
		return newLoginPacket;
		break;
	}

	case Logoutp: {
		LogoutPacket* newLogoutPacket = new LogoutPacket(this->serializedPacketBuffer);
		return newLogoutPacket;
		break;
	}

	case Movep: {
		MovePacket* newMovePacket = new MovePacket(this->serializedPacketBuffer);
		return newMovePacket;
		break;
	}

	case PacketPacket: {
		//Parent packet creator???
		break;
	}

	default: {
		break;
	}

	}

}
