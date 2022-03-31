#pragma once

#include "Packet.h"

using namespace std;

class MovePacket : public Packet {

private:

	int move;
	bool gameStatus;

public:

	MovePacket(int move, bool gameStatus) {

		//Free memory that may have been allocated by OS.
		if (this->serializedPacketBuffer != NULL) {
			delete this->serializedPacketBuffer;
		}
		
		this->pktHead.packetType = Movep;

		//Ensure safe state of ptr.
		this->serializedPacketBuffer = NULL;

		//Assign values.
		this->move = move;
		this->gameStatus = gameStatus;

	}

	MovePacket(char* rxBuffer) {

		//Free memory that may have been allocated by OS.
		if (this->serializedPacketBuffer != NULL) {
			delete this->serializedPacketBuffer;
		}

		this->pktHead.packetType = Movep;

		//Parse buffer for packet info.
		memcpy(&move, rxBuffer, sizeof(this->move));
		memcpy(&gameStatus, rxBuffer + sizeof(this->move), sizeof(this->gameStatus));

		//Ensure safe state for future re-serialization.
		this->serializedPacketBuffer = NULL;

	}

	~MovePacket() {

		delete this->serializedPacketBuffer;
		delete this;

	}

	void setMove(int move) {

		this->move = move;

	}

	int getMove() {

		return this->move;

	}

	void setGameStatus(bool gameStatus)
	{
		this->gameStatus = gameStatus;
	}

	bool getGameStatus()
	{
		return this->gameStatus;
	}

	const char* getSerializedMovePacketTxBuffer() {

		return this->serializedPacketBuffer;

	}

	void serializeMovePacketTxBuffer() {

		int totalSize = sizeof(this->move) + sizeof(this->gameStatus);
		this->serializedPacketBuffer = new char[totalSize];
		this->setHeaderBodyLength(totalSize);
		memcpy(this->serializedPacketBuffer, &this->move, sizeof(this->move));
		memcpy(this->serializedPacketBuffer, &this->gameStatus, sizeof(this->gameStatus));
	}

};