#pragma once

#include <cstdlib>
#include <string.h>

#define CLIENT_ID 0;
#define SERVER_ID 1;

using namespace std;

enum packetType {

	Accountp,
	CreateAccountp,
	Errorp,
	GameStatusp,
	Loginp,
	Logoutp,
	Movep,
	Imagep,
	PacketPacket
};

// 16 bytes
typedef struct Header {

	int destinationID = SERVER_ID;
	int sourceID = CLIENT_ID;
	packetType packetType;
	int bodyLength = 0;
};

//Consider some type of checksum.
//typedef struct Tail {
//};

class Packet {
protected:

	char* serializedParentBuffer = NULL;
	char* serializedPacketBuffer = NULL;
	Header pktHead;
	//Tail pktTail;

public:

	Packet();
	Packet(char* RxBuffer);
	~Packet();

	//Header Setter Methods
	void setHeaderDestinationID(int);
	void setHeaderDestinationID();
	void setHeaderSourceID(int);
	void setHeaderSourceID();
	void setHeaderBodyLength(int);
	void swapHeaderDestAndSource();

	//Header Getter Methods
	int getHeaderDestinationID();
	int getHeaderSourceID();
	int getHeadersequenceNumber();
	int getHeaderBodyLength();
	packetType getHeaderPacketType();

	//Tail Setter Methods
	void setTailCheckSum();

	//Tail Getter Methods
	//void getTailCheckSum();

	//Serialized Packet Methods
	char* getSerializedTxBuffer();
	void serializeParentPacketTxBuffer();
	char* getSerializedParentTxBuffer();	
	
};