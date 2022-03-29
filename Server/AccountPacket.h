#pragma once

#include "../COMP72070 - TicTacToe/Packet.h"
#include "Account.h"

using namespace std;

typedef struct AccountPacketHeader {

	int userNameLength;
	int firstNameLength;
	int lastNameLength;

} AccPktHead;

class AccountPacket : public Packet {

private:

	AccPktHead accHead;	//12
	Account* accountPtr; // 4 byes  (pointer)?

public:

	AccountPacket(Account* account) {

		//Update Parent Packet information

		//Free memory that may have been allocated by OS.
		if (this->serializedPacketBuffer != NULL) {
			delete this->serializedPacketBuffer;
		}
		
		this->pktHead.packetType = Accountp;

		//Ensure safe state of ptr.
		this->serializedPacketBuffer = NULL;

		//Ensure safe state of header lengths.
		this->accHead.userNameLength = 0;
		this->accHead.firstNameLength = 0;
		this->accHead.lastNameLength = 0;

		//Set the account pointer to the Account object to be sent across the network.
		this->accountPtr = account;

		//Assign header values based on the Account field string lengths.
		this->accHead.userNameLength = strlen(this->accountPtr->getUserName()) + 1;
		this->accHead.firstNameLength = strlen(this->accountPtr->getFirstName()) + 1;
		this->accHead.lastNameLength = strlen(this->accountPtr->getLastName()) + 1;

	}

	AccountPacket(char* rxBuffer) {

		//Free memory that may have been allocated by OS.
		if (this->serializedPacketBuffer != NULL) {
			delete this->serializedPacketBuffer;
		}

		this->pktHead.packetType = Accountp;

		//Ensure safe state of txBuffer.
		this->serializedPacketBuffer = NULL;

		//Assign header values
		memcpy(&this->accHead.userNameLength, rxBuffer, sizeof(this->accHead.userNameLength));
		memcpy(&this->accHead.firstNameLength, rxBuffer + sizeof(this->accHead.userNameLength), sizeof(this->accHead.firstNameLength));
		memcpy(&this->accHead.lastNameLength, rxBuffer + sizeof(this->accHead.userNameLength) + sizeof(this->accHead.firstNameLength), sizeof(this->accHead.lastNameLength));

		this->accountPtr = new Account(rxBuffer + sizeof(AccountPacketHeader), this->accHead.userNameLength, this->accHead.firstNameLength, this->accHead.lastNameLength);

	}

	Account* getAccount() {
		return this->accountPtr;
	}

	~AccountPacket() {

		delete this->accountPtr;
		delete this;

	}


	 char* getSerializedAccountPacketBuffer() {

		return this->serializedPacketBuffer;

	}

	void serializeAccountPacketTxBuffer() {

		//Allocate memory for the entire size of the Account object, plus the packet overhead.
		int packetSize = sizeof(AccountPacketHeader) + sizeof(Account) - CHARPTRSIZE + this->accHead.firstNameLength + this->accHead.lastNameLength + this->accHead.userNameLength;
		
		this->serializedPacketBuffer = new char[packetSize] {};
	
		int byteBuffer = 0;

		memcpy(this->serializedPacketBuffer, &this->accHead.userNameLength, sizeof(this->accHead.userNameLength));
		byteBuffer += sizeof(this->accHead.userNameLength);

		memcpy(this->serializedPacketBuffer + byteBuffer, &this->accHead.firstNameLength, sizeof(this->accHead.firstNameLength));
		byteBuffer += sizeof(this->accHead.firstNameLength);

		memcpy(this->serializedPacketBuffer + byteBuffer, &this->accHead.lastNameLength, sizeof(this->accHead.lastNameLength));
		byteBuffer += sizeof(this->accHead.lastNameLength);

		char* tempUserName = this->accountPtr->getUserName();
		memcpy(this->serializedPacketBuffer + byteBuffer, tempUserName, this->accHead.userNameLength);
		byteBuffer += this->accHead.userNameLength;

		char* tempFirstName = this->accountPtr->getFirstName();
		memcpy(this->serializedPacketBuffer + byteBuffer, tempFirstName, this->accHead.firstNameLength);
		byteBuffer += this->accHead.firstNameLength;

		char* tempLastName = this->accountPtr->getLastName();
		memcpy(this->serializedPacketBuffer + byteBuffer, tempLastName, this->accHead.lastNameLength);
		byteBuffer += this->accHead.lastNameLength;

		int accountID = this->accountPtr->getAccountID();
		memcpy(this->serializedPacketBuffer + byteBuffer, &accountID, sizeof(this->accountPtr->getAccountID()));
		byteBuffer += sizeof(this->accountPtr->getAccountID());

		int wins = this->accountPtr->getWins();
		memcpy(this->serializedPacketBuffer + byteBuffer, &wins, sizeof(this->accountPtr->getWins()));
		byteBuffer += sizeof(this->accountPtr->getWins());

		int draws = this->accountPtr->getDraws();
		memcpy(this->serializedPacketBuffer + byteBuffer, &draws, sizeof(this->accountPtr->getDraws()));
		byteBuffer += sizeof(this->accountPtr->getDraws());

		int losses = this->accountPtr->getLoses();
		memcpy(this->serializedPacketBuffer + byteBuffer, &losses, sizeof(this->accountPtr->getLoses()));
		byteBuffer += sizeof(this->accountPtr->getLoses());

	}

};