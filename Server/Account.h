 #pragma once

#include <string>

const int CHARPTRSIZE = 32;

using namespace std;

class Account {

private:
	int accountID;
	char* first_name;
	char* last_name;
	char* avatar_loc;
	char* UserName;
	int wins;
	int loses;
	int draws;
	bool isOnline;

public:
	//Builds the account into a safe state
	Account() {

		this->accountID = -1;
		this->first_name = NULL;
		this->last_name = NULL;
		this->avatar_loc = NULL;
		this->UserName = NULL;
		this->wins = -1;
		this->loses = -1;
		this->draws = -1;
		this->isOnline = false;

	}

	//Paramierized constructor for 
	Account(int id, char* fName, char* lName, char* pictureloc, char* UserName, int w, int l, int d, bool online) {
		
		this->accountID = id;

		this->first_name = new char[strlen(fName)];
		this->first_name = fName;

		this->last_name = new char[strlen(lName)];
		this->last_name = lName;

		this->UserName = new char[strlen(UserName)];
		this->UserName = UserName;

		this->avatar_loc = new char[strlen(pictureloc)];
		this->avatar_loc = pictureloc;
		
		this->wins = w;
		this->loses = l;
		this->draws = d;
		this->isOnline = online;

	}

	Account(Account* act) {

		this->accountID = act->accountID;
		this->first_name = act->first_name;
		this->last_name = act->last_name;
		this->UserName = act->UserName;
		this->avatar_loc = act->avatar_loc;
		this->wins = act->wins;
		this->loses = act->loses;
		this->draws = act->draws;
		this->isOnline = act->isOnline;
		
	}

	Account(char* buffer, int uLen, int fnLen, int lnLen) {

		this->UserName = new char[uLen];
		memcpy(this->UserName, buffer, uLen);

		this->first_name = new char[fnLen];
		memcpy(this->first_name, buffer + uLen, fnLen);

		this->last_name = new char[lnLen];
		memcpy(this->last_name, buffer + uLen + fnLen, lnLen);

		memcpy(&this->accountID, buffer + uLen + fnLen + lnLen, sizeof(accountID));
		memcpy(&this->wins, buffer + uLen + fnLen + lnLen + sizeof(accountID), sizeof(wins));
		memcpy(&this->draws, buffer + uLen + fnLen + lnLen + sizeof(accountID) + sizeof(wins), sizeof(draws));
		memcpy(&this->loses, buffer + uLen + fnLen + lnLen + sizeof(accountID) + sizeof(wins) + sizeof(draws), sizeof(loses));

		this->avatar_loc = nullptr;

	}


	Account(char* fName, char* lName, char* username, char* password) {


		this->accountID = -1;

		this->first_name = new char[strlen(fName)];
		this->first_name = fName;

		this->last_name = new char[strlen(lName)];
		this->last_name = lName;

		this->UserName = new char[strlen(username)];
		this->UserName = username;

		//this->avatar_loc = new char[strlen(pictureloc)];
		//this->avatar_loc = pictureloc;

		this->wins = 0;
		this->loses = 0;
		this->draws = 0;
		this->isOnline = false;

	}

	int getAccountID() { return accountID; }
	void setAccountID(int accountID) { this->accountID = accountID; }

	char* getFirstName() { return first_name; }
	void setFirstName(char* firstname) { first_name = firstname; }

	char* getLastName() { return last_name; }
	void setLastName(char* lastname) { last_name = lastname; }

	char* getUserName() { return UserName; }
	void setUserName(char* User_Name) { UserName = User_Name; }

	char* getAvatarloc() { return avatar_loc; }
	void setAvatarloc(char* avatarloc) { avatar_loc = avatarloc; }

	int getWins() { return wins; }
	void setWins(int wins) { this->wins = wins; }

	int getLoses() { return loses; }
	void setLoses(int loses) { this->loses = loses; }

	int getDraws() { return draws; }
	void setDraws(int draws) { this->draws = draws; }

	bool getIsOnline() { return isOnline; }
	void setIsOnline(bool isOnline) { this->isOnline = isOnline; }
	
};