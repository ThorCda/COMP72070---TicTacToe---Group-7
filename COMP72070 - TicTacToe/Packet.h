#pragma once

using namespace std;


static int PktSequence = 0; //Will iterate on each successive packet instantiation.
const int EmptyPktSize = 21; // 4 + 4 + 4 + 4 + 1 + 1 + 1 + 1 + 1

typedef struct Header {

	int destinationID;
	int sourceID;
	int sequenceNumber;
	int bodyLength;
	char finFlag;
	char ackFlag;
	char packetType;

};

typedef struct Body {

	char* msgPtr;

};

//Consider some type of checksum.
//typedef struct Tail {
//};

class Packet {

	Header pktHead;
	Body pktBody;
	//Tail pktTail;

	char* SerializedPacket = nullptr;

public:

	Packet();
	Packet(char* RxBuffer);
	~Packet();

	//Header Setter Methods
	void setHeaderDestinationID();
	void setHeaderSourceID();
	void setHeaderSequenceNumber();
	void setHeaderBodyLength();
	void setHeaderFinFlag();
	void setHeaderAckFlag();
	void setHeaderPacketType();

	//Header Getter Methods
	int getHeaderDestinationID();
	int getHeaderSourceID();
	int getHeadersequenceNumber();
	int getHeaderBodyLength();
	char getHeaderFinFlag();
	char getHeaderAckFlag();
	char getHeaderPacketType();

	//Body Setter Methods
	void setBodyMsgPtr();

	//Body Getter Methods
	char* getBodyMsgPtr();

	//Tail Setter Methods
	void setTailCheckSum();

	//Tail Getter Methods
	//void getTailCheckSum();
	
};