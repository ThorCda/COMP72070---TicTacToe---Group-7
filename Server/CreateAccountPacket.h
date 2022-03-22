#include "../COMP72070 - TicTacToe/Packet.h"
#include "../Server/Account.h"
#include <iostream>

using namespace std;

typedef struct CreateAccountPacketHeader {

	int userNameLength;
	int firstNameLength;
	int lastNameLength;
	int passwordLength;

} CrtAccPktHead;

class CreateAccountPacket : public Packet {

private:

	CrtAccPktHead accHead;
	char* fName; 
	char* lName;
	char* username;
	char* password;

public:

	CreateAccountPacket() {

		//Free memory that may have been allocated by OS.
		if (this->serializedPacketBuffer != NULL) {
			delete this->serializedPacketBuffer;
		}

		//Ensure safe state of ptr.
		this->serializedPacketBuffer = NULL;

		//Ensure safe state of header lengths.
		this->accHead.userNameLength = 0;
		this->accHead.firstNameLength = 0;
		this->accHead.lastNameLength = 0;
		this->accHead.passwordLength = 0;

		

		this->password = nullptr;
		this->username = nullptr;
		this->fName = nullptr;
		this->lName = nullptr;


	}

	CreateAccountPacket(char* username, char* fName, char* lName, char* pwd) {

		this->accHead.firstNameLength = strlen(fName) + 1;
		this->accHead.lastNameLength = strlen(lName) + 1;
		this->accHead.userNameLength = strlen(username) + 1;
		this->accHead.passwordLength = strlen(pwd) + 1;

		if (this->serializedPacketBuffer != NULL) {
			delete this->serializedPacketBuffer;
		}

		//Ensure safe state of ptr.
		this->serializedPacketBuffer = NULL;

		this->password = new char[this->accHead.passwordLength];
		memcpy(this->password, pwd, this->accHead.passwordLength);

		this->username = new char[this->accHead.userNameLength];
		memcpy(this->username, username, this->accHead.userNameLength);

		this->lName = new char[this->accHead.lastNameLength];
		memcpy(this->lName, lName, this->accHead.lastNameLength);

		this->fName = new char[this->accHead.firstNameLength];
		memcpy(this->fName, fName, this->accHead.firstNameLength);


	}

	CreateAccountPacket(char* rxBuffer) {

		//Free memory that may have been allocated by OS.
		if (this->serializedPacketBuffer != NULL) {
			delete this->serializedPacketBuffer;
		}

		//Ensure safe state of txBuffer.
		this->serializedPacketBuffer = NULL;

		//Assign header values
		memcpy(&this->accHead.userNameLength, rxBuffer, sizeof(this->accHead.userNameLength));
		memcpy(&this->accHead.firstNameLength, rxBuffer + sizeof(this->accHead.userNameLength), sizeof(this->accHead.firstNameLength));
		memcpy(&this->accHead.lastNameLength, rxBuffer + sizeof(this->accHead.userNameLength) + sizeof(this->accHead.firstNameLength), sizeof(this->accHead.lastNameLength));
		memcpy(&this->accHead.passwordLength, rxBuffer + sizeof(this->accHead.userNameLength) + sizeof(this->accHead.firstNameLength) + sizeof(this->accHead.lastNameLength), sizeof(this->accHead.passwordLength));

		this->username = new char[this->accHead.userNameLength];
		memcpy(this->username, rxBuffer + sizeof(this->accHead), this->accHead.userNameLength);
		
		this->fName = new char[this->accHead.firstNameLength];
		memcpy(this->fName, rxBuffer + sizeof(this->accHead) + this->accHead.userNameLength, this->accHead.firstNameLength);

		this->lName = new char[this->accHead.lastNameLength];
		memcpy(this->lName, rxBuffer + sizeof(this->accHead) + this->accHead.userNameLength + this->accHead.firstNameLength, this->accHead.lastNameLength);
		
		this->password = new char[this->accHead.passwordLength];
		memcpy(this->password, rxBuffer + sizeof(this->accHead) + this->accHead.userNameLength + this->accHead.firstNameLength + this->accHead.lastNameLength, this->accHead.passwordLength);

	}

	~CreateAccountPacket() {

		delete this->username;
		delete this->fName;
		delete this->lName;
		delete this->password;
		delete this;

	}

	void serializeCreateAccountPacketTxBuffer() {

		//Allocate memory for the serializedPacketBuffer size of the Account object, plus the packet overhead.
		this->serializedPacketBuffer = new char[sizeof(CreateAccountPacketHeader) + this->accHead.userNameLength +this->accHead.firstNameLength + this->accHead.lastNameLength + this->accHead.passwordLength]; //Does sizeof(*this->accountPtr return the dynamically sized account or simply the sizeof an empty account???

		int byteBuffer = 0;

		memcpy(this->serializedPacketBuffer, &this->accHead, sizeof(this->accHead));
		byteBuffer += sizeof(this->accHead);

		memcpy(this->serializedPacketBuffer + byteBuffer, this->username, this->accHead.userNameLength);
		byteBuffer += this->accHead.userNameLength;

		memcpy(this->serializedPacketBuffer + byteBuffer, this->fName, this->accHead.firstNameLength);
		byteBuffer += this->accHead.firstNameLength;


		memcpy(this->serializedPacketBuffer + byteBuffer, this->lName, this->accHead.lastNameLength);
		byteBuffer += this->accHead.lastNameLength;

		memcpy(this->serializedPacketBuffer + byteBuffer, this->password, this->accHead.passwordLength);
		byteBuffer += this->accHead.passwordLength;


	}

};