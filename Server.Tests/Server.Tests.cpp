#include "pch.h"
#include "CppUnitTest.h"

#include "../Server/ChildPackets.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ServerTests_Packet
{
	TEST_CLASS(ServerTests)
	{
	public:

		TEST_METHOD(Create_Account_Packet)	//PKT_UNT_016 through 020
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
			if (strcmp(np->getLName(), r->getLName()) != 0) {
				isSame = false;
			}
			if (strcmp(np->getPassword(), r->getPassword()) != 0) {
				isSame = false;
			}
			if (strcmp(np->getUsername(), r->getUsername()) != 0) {
				isSame = false;
			}

			Assert::IsTrue(isSame);

		}

		TEST_METHOD(Account_Packet)	//PKT-UNT-016 through 020

		{
			bool isSame = true;

			char us[] = "Gabeele";
			char fis[] = "Gavin";
			char la[] = "Abeele";
			char pic[] = "C://Hello.png";

			Account a = new Account(1, fis, la, pic, us, 1, 2, 1, true);

			AccountPacket np(&a);

			np.serializeAccountPacketTxBuffer();

			char* m = np.getSerializedAccountPacketBuffer();

			AccountPacket* r = new AccountPacket(m);

			Account* actual = np.getAccount();
			Account* result = r->getAccount();

			if (actual->getAccountID() == result->getAccountID()) {
				isSame = false;
			}
			if (strcmp(actual->getUserName(), result->getUserName()) != 0) {
				isSame = false;
			}
			if (strcmp(actual->getFirstName(), result->getFirstName()) != 0) {
				isSame = false;
			}
			if (strcmp(actual->getLastName(), result->getLastName()) != 0) {
				isSame = false;
			}
			if (strcmp(actual->getAvatarloc(), result->getAvatarloc()) != 0) {
				isSame = false;
			}
			if (actual->getWins() == result->getWins()) {
				isSame = false;
			}
			if (actual->getLoses() == result->getLoses()) {
				isSame = false;
			}
			if (actual->getDraws() == result->getDraws()) {
				isSame = false;
			}

			Assert::IsTrue(isSame);

		}

		TEST_METHOD(Error_Packet) {		//PKT-UNT-036 through 040

			int xx = 2;
			ErrorPacket* x = new ErrorPacket(xx);

			x->serializeErrorPacketTxBuffer();

			char* xxx = x->getSerializedTxBuffer();

			ErrorPacket* xxxx = new ErrorPacket(xxx);

			Assert::AreEqual(x->getErrorCode(), xxxx->getErrorCode());
		}


	};
}
