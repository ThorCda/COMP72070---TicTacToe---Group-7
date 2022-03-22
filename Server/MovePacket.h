#include "../COMP72070 - TicTacToe/Packet.h"

using namespace std;

class MovePacket : public Packet {

private:

	int move;

public:

	MovePacket(int move) {

		//Free memory that may have been allocated by OS.
		if (this->serializedPacketBuffer != NULL) {
			delete this->serializedPacketBuffer;
		}
		
		//Ensure safe state of ptr.
		this->serializedPacketBuffer = NULL;

		//Assign values.
		this->move = move;

	}

	MovePacket(char* rxBuffer) {

		//Free memory that may have been allocated by OS.
		if (this->serializedPacketBuffer != NULL) {
			delete this->serializedPacketBuffer;
		}

		//Parse buffer for packet info.
		memcpy(&move, rxBuffer, sizeof(this->move));

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

	const char* getSerializedMovePacketTxBuffer() {

		return this->serializedPacketBuffer;

	}

	void serializeMovePacketTxBuffer() {

		this->serializedPacketBuffer = new char[sizeof(this->move)];

		memcpy(this->serializedPacketBuffer, &this->move, sizeof(this->move));
	}

};