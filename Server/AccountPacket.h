#include "../COMP72070 - TicTacToe/Packet.h"
#include "../Server/Account.h"

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
	char* serializedAccountPacketBuffer;	//17

public:

	AccountPacket(Account* account) {

		//Free memory that may have been allocated by OS.
		if (this->serializedAccountPacketBuffer != NULL) {
			delete this->serializedAccountPacketBuffer;
		}

		//Ensure safe state of ptr.
		this->serializedAccountPacketBuffer = NULL;

		//Ensure safe state of header lengths.
		this->accHead.userNameLength = 0;
		this->accHead.firstNameLength = 0;
		this->accHead.lastNameLength = 0;

		//Set the account pointer to the Account object to be sent across the network.
		this->accountPtr = account;

		//Assign header values based on the Account field string lengths.
		this->accHead.userNameLength = this->accountPtr->getUserName().length();
		this->accHead.firstNameLength = this->accountPtr->getFirstname().length();
		this->accHead.lastNameLength = this->accountPtr->getLastname().length();

	}

	AccountPacket(char* rxBuffer) {

		//Free memory that may have been allocated by OS.
		if (this->serializedAccountPacketBuffer != NULL) {
			delete this->serializedAccountPacketBuffer;
		}

		//Ensure safe state of txBuffer.
		this->serializedAccountPacketBuffer = NULL;

		//Assign header values
		memcpy(&this->accHead.userNameLength, rxBuffer, sizeof(this->accHead.userNameLength));
		memcpy(&this->accHead.firstNameLength, rxBuffer + sizeof(this->accHead.userNameLength), sizeof(this->accHead.firstNameLength));
		memcpy(&this->accHead.lastNameLength, rxBuffer + sizeof(this->accHead.userNameLength) + sizeof(this->accHead.firstNameLength), sizeof(this->accHead.lastNameLength));

		this->accountPtr = new Account(rxBuffer + sizeof(AccountPacketHeader), this->accHead.userNameLength, this->accHead.firstNameLength, this->accHead.lastNameLength);

	}

	~AccountPacket() {

		delete this->accountPtr;
		delete this;

	}


	 char* getSerializedAccountPacketBuffer() {

		return this->serializedAccountPacketBuffer;

	}

	void serializeAccountPacketTxBuffer() {

		//Allocate memory for the entire size of the Account object, plus the packet overhead.
		this->serializedAccountPacketBuffer = new char[sizeof(AccountPacketHeader) + this->accHead.userNameLength + 
			this->accHead.lastNameLength + this->accHead.firstNameLength + 17
		]; //Does sizeof(*this->accountPtr return the dynamically sized account or simply the sizeof an empty account???

		cout << sizeof(serializedAccountPacketBuffer);
		cout << sizeof(char*);

		int byteBuffer = 0;

		memcpy(this->serializedAccountPacketBuffer, &this->accHead.userNameLength, sizeof(this->accHead.userNameLength));
		byteBuffer += sizeof(this->accHead.userNameLength);

		memcpy(this->serializedAccountPacketBuffer + byteBuffer, &this->accHead.firstNameLength, sizeof(this->accHead.firstNameLength));
		byteBuffer += sizeof(this->accHead.firstNameLength);

		memcpy(this->serializedAccountPacketBuffer + byteBuffer, &this->accHead.lastNameLength, sizeof(this->accHead.lastNameLength));
		byteBuffer += sizeof(this->accHead.lastNameLength);

		string un = this->accountPtr->getUserName();
		memcpy(this->serializedAccountPacketBuffer + byteBuffer, un.c_str(), sizeof(this->accountPtr->getUserName()));
		byteBuffer += sizeof(this->accountPtr->getUserName());

		string fn = this->accountPtr->getFirstname();
		memcpy(this->serializedAccountPacketBuffer + byteBuffer, fn.c_str(), sizeof(this->accountPtr->getFirstname()));
		byteBuffer += sizeof(this->accountPtr->getFirstname());

		string ln = this->accountPtr->getLastname();
		memcpy(this->serializedAccountPacketBuffer + byteBuffer, ln.c_str(), sizeof(this->accountPtr->getLastname()));
		byteBuffer += sizeof(this->accountPtr->getLastname());

		int accountID = this->accountPtr->getAccountID();
		memcpy(this->serializedAccountPacketBuffer + byteBuffer, &accountID, sizeof(this->accountPtr->getAccountID()));
		byteBuffer += sizeof(this->accountPtr->getAccountID());

		int wins = this->accountPtr->getWins();
		memcpy(this->serializedAccountPacketBuffer + byteBuffer, &wins, sizeof(this->accountPtr->getWins()));
		byteBuffer += sizeof(this->accountPtr->getWins());

		int draws = this->accountPtr->getDraws();
		memcpy(this->serializedAccountPacketBuffer + byteBuffer, &draws, sizeof(this->accountPtr->getDraws()));
		byteBuffer += sizeof(this->accountPtr->getDraws());

		int losses = this->accountPtr->getLoses();
		memcpy(this->serializedAccountPacketBuffer + byteBuffer, &losses, sizeof(this->accountPtr->getLoses()));
		byteBuffer += sizeof(this->accountPtr->getLoses());

	}

};