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

	char* serializedCreateAccountPacketBuffer;

public:

	CreateAccountPacket() {

		//Free memory that may have been allocated by OS.
		if (this->serializedCreateAccountPacketBuffer != NULL) {
			delete this->serializedCreateAccountPacketBuffer;
		}

		//Ensure safe state of ptr.
		this->serializedCreateAccountPacketBuffer = NULL;

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

	CreateAccountPacket(string username, string fName, string lName, string pwd) {

		this->accHead.firstNameLength = fName.length();
		this->accHead.lastNameLength = lName.length();
		this->accHead.userNameLength = username.length();
		this->accHead.passwordLength = pwd.length();

		if (this->serializedCreateAccountPacketBuffer != NULL) {
			delete this->serializedCreateAccountPacketBuffer;
		}

		//Ensure safe state of ptr.
		this->serializedCreateAccountPacketBuffer = NULL;

		strcpy(this->password, pwd.c_str());
		strcpy(this->username, username.c_str());
		strcpy(this->lName, lName.c_str());
		strcpy(this->fName, fName.c_str());


	}

	CreateAccountPacket(char* rxBuffer) {

		//Free memory that may have been allocated by OS.
		if (this->serializedCreateAccountPacketBuffer != NULL) {
			delete this->serializedCreateAccountPacketBuffer;
		}

		//Ensure safe state of txBuffer.
		this->serializedCreateAccountPacketBuffer = NULL;

		//Assign header values
		memcpy(&this->accHead.userNameLength, rxBuffer, sizeof(this->accHead.userNameLength));
		memcpy(&this->accHead.firstNameLength, rxBuffer + sizeof(this->accHead.userNameLength), sizeof(this->accHead.firstNameLength));
		memcpy(&this->accHead.lastNameLength, rxBuffer + sizeof(this->accHead.userNameLength) + sizeof(this->accHead.firstNameLength), sizeof(this->accHead.lastNameLength));
		memcpy(&this->accHead.passwordLength, rxBuffer + sizeof(this->accHead.userNameLength) + sizeof(this->accHead.firstNameLength) + sizeof(this->accHead.lastNameLength), sizeof(this->accHead.passwordLength));


		memcpy(&this->username, rxBuffer + sizeof(this->accHead), this->accHead.userNameLength);
		memcpy(&this->fName, rxBuffer + sizeof(this->accHead) + this->accHead.userNameLength, this->accHead.firstNameLength);
		memcpy(&this->lName, rxBuffer + sizeof(this->accHead) + this->accHead.userNameLength + this->accHead.firstNameLength, this->accHead.lastNameLength);
		memcpy(&this->password, rxBuffer + sizeof(this->accHead) + this->accHead.userNameLength + this->accHead.firstNameLength + this->accHead.lastNameLength, this->accHead.passwordLength);

	}

	~CreateAccountPacket() {

		delete this->username;
		delete this->fName;
		delete this->lName;
		delete this->password;
		delete this;

	}

	void serializeCreateAccountPacketTxBuffer() {

		//Allocate memory for the entire size of the Account object, plus the packet overhead.
		this->serializedCreateAccountPacketBuffer = new char[sizeof(CreateAccountPacketHeader) + this->accHead.userNameLength +this->accHead.firstNameLength + this->accHead.lastNameLength + this->accHead.passwordLength]; //Does sizeof(*this->accountPtr return the dynamically sized account or simply the sizeof an empty account???

		int byteBuffer = 0;

		memcpy(this->serializedCreateAccountPacketBuffer, &this->accHead, sizeof(this->accHead));
		byteBuffer += sizeof(this->accHead);

		memcpy(this->serializedCreateAccountPacketBuffer + byteBuffer, &this->username, this->accHead.userNameLength);
		byteBuffer += sizeof(this->accHead.userNameLength);

		memcpy(this->serializedCreateAccountPacketBuffer + byteBuffer, &this->fName, this->accHead.firstNameLength);
		byteBuffer += sizeof(this->accHead.firstNameLength);


		memcpy(this->serializedCreateAccountPacketBuffer + byteBuffer, &this->lName, this->accHead.lastNameLength);
		byteBuffer += sizeof(this->accHead.lastNameLength);

		memcpy(this->serializedCreateAccountPacketBuffer + byteBuffer, &this->password, this->accHead.passwordLength);
		byteBuffer += sizeof(this->accHead.passwordLength);


	}

};