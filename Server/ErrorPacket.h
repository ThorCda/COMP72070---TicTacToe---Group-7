#include "../COMP72070 - TicTacToe/Packet.h"

using namespace std;

class ErrorPacket : public Packet {

private:

	int errorCode;
	char* serializedErrorPacketBuffer;

public:

	ErrorPacket(int errorCode) {

		//Free memory that may have been allocated by OS.
		if (this->serializedErrorPacketBuffer != NULL) {
			delete this->serializedErrorPacketBuffer;
		}

		//Ensure safe state of ptr.
		this->serializedErrorPacketBuffer = NULL;

		//Assign values.
		this->errorCode = errorCode;

	}

	ErrorPacket(char* rxBuffer) {

		//Free memory that may have been allocated by OS.
		if (this->serializedErrorPacketBuffer != NULL) {
			delete this->serializedErrorPacketBuffer;
		}

		//Parse buffer for packet info.
		memcpy(&errorCode, rxBuffer, sizeof(this->errorCode));

		//Ensure safe state for future re-serialization.
		this->serializedErrorPacketBuffer = NULL;

	}

	~ErrorPacket() {

		delete this->serializedErrorPacketBuffer;
		delete this;

	}

	void setErrorPacketErrorCode(int errorCode) {

		this->errorCode = errorCode;

	}

	int getErrorPacketErrorCode() {

		return this->errorCode;

	}

	const char* getSerializedErrorPacketBuffer() {

		return this->serializedErrorPacketBuffer;

	}

	void serializeErrorPacketTxBuffer() {

		this->serializedErrorPacketBuffer = new char[sizeof(this->errorCode)];

		memcpy(this->serializedErrorPacketBuffer, &this->errorCode, sizeof(this->errorCode));

	}

};