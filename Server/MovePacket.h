#include "../COMP72070 - TicTacToe/Packet.h"

using namespace std;

class MovePacket : public Packet {

private:

	int column;
	int row;

public:

	MovePacket(int column, int row) {

		//Free memory that may have been allocated by OS.
		if (this->serializedPacketBuffer != NULL) {
			delete this->serializedPacketBuffer;
		}
		
		//Ensure safe state of ptr.
		this->serializedPacketBuffer = NULL;

		//Assign values.
		this->column = column;
		this->row = row;

	}

	MovePacket(char* rxBuffer) {

		//Free memory that may have been allocated by OS.
		if (this->serializedPacketBuffer != NULL) {
			delete this->serializedPacketBuffer;
		}

		//Parse buffer for packet info.
		memcpy(&column, rxBuffer, sizeof(this->column));
		memcpy(&row, rxBuffer + sizeof(this->column), sizeof(row));

		//Ensure safe state for future re-serialization.
		this->serializedPacketBuffer = NULL;

	}

	~MovePacket() {

		delete this->serializedPacketBuffer;
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

		return this->serializedPacketBuffer;

	}

	void serializeMovePacketTxBuffer() {

		this->serializedPacketBuffer = new char[sizeof(this->column) + sizeof(this->row)];

		memcpy(this->serializedPacketBuffer, &this->column, sizeof(this->column));
		memcpy(this->serializedPacketBuffer + sizeof(this->column), &this->row, sizeof(row));

	}

};