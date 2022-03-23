#include "pch.h"
#include "CppUnitTest.h"

#include "../Server/ChildPackets.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ServerTests_Packet
{
	TEST_CLASS(ServerTests)
	{
	public:
		
		TEST_METHOD(PKT_UNT_016_Create_Account_Packet)
		{
			bool isSame = true;

			char us[] = "Gabeele";
			char fis[] = "Gavin";
			char la[] = "Abeeleee";
			char pw[] = "Conestoga";
			char pic[] = "C://Hello.png";

			CreateAccountPacket* np = new CreateAccountPacket(us, fis, la, pw);

			np->serializeCreateAccountPacketTxBuffer();

			char* m = np->getSerializedTxBuffer();

			CreateAccountPacket* r = new CreateAccountPacket(m);


			if (strcmp(np->getFName(), r->getFName()) != 0) {
				isSame = false;
			}
			if (strcmp(np->getFName(), r->getFName()) != 0) {
				isSame = false;
			}
			if (strcmp(np->getFName(), r->getFName()) != 0) {
				isSame = false;
			}
			if (strcmp(np->getFName(), r->getFName()) != 0) {
				isSame = false;
			}
			

			Assert::IsTrue(isSame);
			

		}
	};
}
