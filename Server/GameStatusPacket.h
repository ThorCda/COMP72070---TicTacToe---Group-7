#include "../COMP72070 - TicTacToe/Packet.h"

using namespace std;

class GameStatusPacket : public Packet {

private:

	int gameCode;
	char* serializedGameStatusPacketBuffer;

public:

	GameStatusPacket(int gameCode) {

		//Free memory that may have been allocated by OS.
		if (this->serializedGameStatusPacketBuffer != NULL) {
			delete this->serializedGameStatusPacketBuffer;
		}

		//Ensure safe state of ptr.
		this->serializedGameStatusPacketBuffer = NULL;

		//Assign values.
		this->gameCode = gameCode;

	}

	GameStatusPacket(char* rxBuffer) {

		//Free memory that may have been allocated by OS.
		if (this->serializedGameStatusPacketBuffer != NULL) {
			delete this->serializedGameStatusPacketBuffer;
		}

		//Parse buffer for packet info.
		memcpy(&gameCode, rxBuffer, sizeof(this->gameCode));

	}

	~GameStatusPacket() {

		delete this->serializedGameStatusPacketBuffer;
		delete this;

	}

	void setGameStatusPacketGameCode(int gameCode) {

		this->gameCode = gameCode;

	}

	int getGameStatusPacketGameCode() {

		return this->gameCode;

	}

	const char* getSerializedGameStatusPacketBuffer() {

		return this->serializedGameStatusPacketBuffer;

	}

	void serializeGameStatusPacketBuffer() {

		this->serializedGameStatusPacketBuffer = new char[sizeof(this->gameCode)];

		memcpy(this->serializedGameStatusPacketBuffer, &this->gameCode, sizeof(gameCode));

	}

};