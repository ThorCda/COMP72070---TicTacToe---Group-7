#pragma once

#include <string>

using namespace std;

class Account {

private:
	int accountID;
	string first_name;
	string last_name;
	string avatar_loc;
	string UserName;
	int wins;
	int loses;
	int draws;
	bool isOnline;

public:
	//Builds the account into a safe state
	Account() {
		this->accountID = -1;
		this->first_name = "NULL";
		this->last_name = "NULL";
		this->avatar_loc = "NULL";
		this->UserName = "NULL";
		this->wins = -1;
		this->loses = -1;
		this->draws = -1;
		this->isOnline = false;

	}

	//Paramierized constructor for 
	Account(int id, string fName, string lName, string pictureloc, string UserName, int w, int l, int d, bool online) {
		this->accountID = id;
		this->first_name = fName;
		this->last_name = lName;
		this->UserName = UserName;
		this->avatar_loc = pictureloc;
		this->wins = w;
		this->loses = l;
		this->draws = d;
		this->isOnline = online;

	}

	int getAccountID() { return accountID; }
	void setAccountID(int accountID) { this->accountID = accountID; }

	string getFirstname() { return first_name; }
	void setFirstname(string firstname) { first_name = firstname; }

	string getLastname() { return last_name; }
	void setLastname(string lastname) { last_name = lastname; }

	string getUserName() { return UserName; }
	void setUserName(string User_Name) { UserName = User_Name; }

	string getAvatarloc() { return avatar_loc; }
	void setAvatarloc(string avatarloc) { avatar_loc = avatarloc; }

	int getWins() { return wins; }
	void setWins(int wins) { this->wins = wins; }

	int getLoses() { return loses; }
	void setLoses(int loses) { this->loses = loses; }

	int getDraws() { return draws; }
	void setDraws(int draws) { this->draws = draws; }

	bool getIsOnline() { return isOnline; }
	void setIsOnline(bool isOnline) { this->isOnline = isOnline; }

};