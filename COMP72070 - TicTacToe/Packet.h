#pragma once

#include <cstdlib>
#include <cstring>

#define CLIENT_ID 0;
#define SERVER_ID 1;
#define DEFAULT_PACKET 10;

using namespace std;

const int EmptyPktSize = 21; //4 + 4 + 4 + 4 + 1 + 1 + 1 + 1 + 1

typedef struct Header {

	int destinationID = SERVER_ID;
	int sourceID = CLIENT_ID;
	int bodyLength = 0;
	char packetType = DEFAULT_PACKET;

};

typedef struct Body {

	char* msgPtr = NULL;

};

//Consider some type of checksum.
//typedef struct Tail {
//};

class Packet {

	Header pktHead;
	Body pktBody;
	//Tail pktTail;

	char* serializedPacketBuffer = NULL;

public:

	Packet();
	Packet(char* RxBuffer);
	~Packet();

	//Header Setter Methods
	void setHeaderDestinationID(int);
	void setHeaderDestinationID();
	void setHeaderSourceID(int);
	void setHeaderSourceID();
	void setHeaderBodyLength();
	void setHeaderPacketType(char);

	//Header Getter Methods
	int getHeaderDestinationID();
	int getHeaderSourceID();
	int getHeadersequenceNumber();
	int getHeaderBodyLength();
	char getHeaderPacketType();

	//Body Setter Methods
	void setBodyMsgPtr(char*);

	//Body Getter Methods
	char* getBodyMsgPtr();

	//Tail Setter Methods
	void setTailCheckSum();

	//Tail Getter Methods
	//void getTailCheckSum();

	//Serialized Packet Methods
	char* getSerializedTxBuffer();
	void serializePacketTxBuffer();
	
};