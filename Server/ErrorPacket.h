#include "../COMP72070 - TicTacToe/Packet.h"

using namespace std;

class ErrorPacket : public Packet {

private:

	int errorCode;

public:

	ErrorPacket(int errorCode) {
		//Free memory that may have been allocated by OS.
		if (this->serializedPacketBuffer != NULL) {
			delete this->serializedPacketBuffer;
		}

		this->pktHead.packetType = Errorp;

		//Ensure safe state of ptr.
		this->serializedPacketBuffer = NULL;

		//Assign values.
		this->errorCode = errorCode;

	}

	ErrorPacket(char* rxBuffer) {

		//Free memory that may have been allocated by OS.
		if (this->serializedPacketBuffer != NULL) {
			delete this->serializedPacketBuffer;
		}

		//Parse buffer for packet info.
		memcpy(&errorCode, rxBuffer, sizeof(this->errorCode));

		//Ensure safe state for future re-serialization.
		this->serializedPacketBuffer = NULL;

	}

	~ErrorPacket() {

		delete this->serializedPacketBuffer;
		delete this;

	}

	void setErrorPacketErrorCode(int errorCode) {

		this->errorCode = errorCode;

	}

	int getErrorPacketErrorCode() {

		return this->errorCode;

	}

	const char* getSerializedErrorPacketBuffer() {

		return this->serializedPacketBuffer;

	}

	void serializeErrorPacketTxBuffer() {

		this->serializedPacketBuffer = new char[sizeof(this->errorCode)];

		memcpy(this->serializedPacketBuffer, &this->errorCode, sizeof(this->errorCode));

	}

};