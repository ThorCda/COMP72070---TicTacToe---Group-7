#pragma once


#include <cstdlib>
#include <cstring>

#define CLIENT_ID 0;
#define SERVER_ID 1;
#define DEFAULT_PACKET 10;

using namespace std;

//const int EmptyPktSize;

enum packetType {

	Accountp,
	CreateAccountp,
	Errorp,
	GameStatusp,
	Loginp,
	Logoutp,
	Movep,
	PacketPacket
};

typedef struct Header {

	int destinationID = SERVER_ID;
	int sourceID = CLIENT_ID;
	int bodyLength = 0;
	packetType packetType;
};

typedef struct Body {

	char* msgPtr = NULL;

};

//Consider some type of checksum.
//typedef struct Tail {
//};

class Packet {
protected:

	char* serializedPacketBuffer = NULL;
	Header pktHead;
	Body pktBody;
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
	void setHeaderBodyLength();

	//Header Getter Methods
	int getHeaderDestinationID();
	int getHeaderSourceID();
	int getHeadersequenceNumber();
	int getHeaderBodyLength();
	packetType getHeaderPacketType();

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