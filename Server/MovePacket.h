#include "../COMP72070 - TicTacToe/Packet.h"

using namespace std;

class MovePacket : public Packet {

private:

	int column;
	int row;
	char* serializedMovePacketBuffer;

public:

	MovePacket(int column, int row) {

		//Free memory that may have been allocated by OS.
		if (this->serializedMovePacketBuffer != NULL) {
			delete this->serializedMovePacketBuffer;
		}
		
		//Ensure safe state of ptr.
		this->serializedMovePacketBuffer = NULL;

		//Assign values.
		this->column = column;
		this->row = row;

	}

	MovePacket(char* rxBuffer) {

		//Free memory that may have been allocated by OS.
		if (this->serializedMovePacketBuffer != NULL) {
			delete this->serializedMovePacketBuffer;
		}

		//Parse buffer for packet info.
		memcpy(&column, rxBuffer, sizeof(this->column));
		memcpy(&row, rxBuffer + sizeof(this->column), sizeof(row));

		//Ensure safe state for future re-serialization.
		this->serializedMovePacketBuffer = NULL;

	}

	~MovePacket() {

		delete this->serializedMovePacketBuffer;
		delete this;

	}

	void setMovePacketColumn(int column) {

		this->column = column;

	}

	void setMovePacketRow(int row) {

		this->row = row;

	}

	int getMovePacketColumn() {

		return this->column;

	}

	int getMovePacketRow() {

		return this->row;

	}

	const char* getSerializedMovePacketTxBuffer() {

		return this->serializedMovePacketBuffer;

	}

	void serializeMovePacketTxBuffer() {

		this->serializedMovePacketBuffer = new char[sizeof(this->column) + sizeof(this->row)];

		memcpy(this->serializedMovePacketBuffer, &this->column, sizeof(this->column));
		memcpy(this->serializedMovePacketBuffer + sizeof(this->column), &this->row, sizeof(row));

	}

};