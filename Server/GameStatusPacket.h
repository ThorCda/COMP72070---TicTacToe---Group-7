#include "../COMP72070 - TicTacToe/Packet.h"

using namespace std;

class GameStatusPacket : public Packet {

private:

	int gameCode;

public:

	GameStatusPacket(int gameCode) {

		//Free memory that may have been allocated by OS.
		if (this->serializedPacketBuffer != NULL) {
			delete this->serializedPacketBuffer;
		}

		this->pktHead.packetType = GameStatusp;

		//Ensure safe state of ptr.
		this->serializedPacketBuffer = NULL;

		//Assign values.
		this->gameCode = gameCode;

	}

	GameStatusPacket(char* rxBuffer) {

		//Free memory that may have been allocated by OS.
		if (this->serializedPacketBuffer != NULL) {
			delete this->serializedPacketBuffer;
		}

		//Parse buffer for packet info.
		memcpy(&gameCode, rxBuffer, sizeof(this->gameCode));

	}

	~GameStatusPacket() {

		delete this->serializedPacketBuffer;
		delete this;

	}

	void setGameStatusPacketGameCode(int gameCode) {

		this->gameCode = gameCode;

	}

	int getGameStatusPacketGameCode() {

		return this->gameCode;

	}

	const char* getSerializedGameStatusPacketBuffer() {

		return this->serializedPacketBuffer;

	}

	void serializeGameStatusPacketBuffer() {

		this->serializedPacketBuffer = new char[sizeof(this->gameCode)];

		memcpy(this->serializedPacketBuffer, &this->gameCode, sizeof(gameCode));

	}

};