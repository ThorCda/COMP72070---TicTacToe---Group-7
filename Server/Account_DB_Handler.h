#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "Account.h"
#include "DB_Handler.h"

using namespace std;

class Account_DB_Handler : public Database_Handler
{
public:
	Account* createAccount(char* cusername, char* cfirstname, char* clastname, char* password)
	{
		string username(cusername);
		string firstname(cfirstname);
		string lastname(clastname);
		string avatar = "NotSet";
		string pw(password);

		string query = "call CreateAccount (\"" + firstname + "\",\"" + lastname + "\",\"" + avatar + "\",\"" + username + "\",\"" + pw + "\"" + ")";
		cout << query;
		const char* q = query.c_str();

		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			cout << "\Account Created\n";
		}
		else
		{
			cout << "\nError creating account\n";
		}

		return login(username, pw);
	}

	void updateStats(Account acc)
	{
		string query = "call UpdateStats (" + to_string(acc.getAccountID()) + "," + to_string(acc.getWins()) + "," + to_string(acc.getLoses()) + "," + to_string(acc.getDraws()) + ")";
		const char* q = query.c_str();
		cout << query;
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			cout << "\nStats Updated\n";
		}
		else
		{
			cout << "\nError saving account\n";
		}
	}

	void updateAccount(Account acc)
	{
		string username(acc.getUserName());
		string firstname(acc.getFirstName());
		string lastname(acc.getLastName());
		string avatar(acc.getAvatarloc());

		string query = "call UpdateAccount (" + to_string(acc.getAccountID()) + ",\"" + firstname + "\",\"" + lastname + "\",\"" + avatar + "\",\"" + username + "\"" + ")";
		const char* q = query.c_str();

		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			cout << "\nAccount Updated\n";
			updateStats(acc);
		}
		else
		{
			cout << "\nError saving account\n";
		}
	}

	void deleteUser(int id)
	{
		string query = "call DeleteAccount(" + to_string(id) + ")";
		const char* q = query.c_str();

		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			cout << "\nAccount Deleted\n";
		}
		else
		{
			cout << "\nError deleting account\n";
		}
	}

	void insertImage(char* username, char* picloc)
	{
		string un(username);
		string path(picloc);

		string query = "call InsertImage(\"" + un + "\",\"" + path + "\"" + ")";
		const char* q = query.c_str();

		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			cout << "\nAvatar path updated\n";
		}
		else
		{
			cout << "\nError updating avatar path\n";
		}
	}

	char* getImage(char* username)
	{
		string un(username);

		string query = "call FindImage (\"" + un +"\")";

		const char* q2 = query.c_str();
		qstate = mysql_query(conn, q2);
		result = mysql_store_result(conn);
		row = mysql_fetch_row(result);

		if (mysql_num_rows(result) == 1)
		{
			char* picloc = row[0];
			return picloc;
		}
		else
		{
			return nullptr;
		}
	}

	Account* login(string username, string password)
	{
		
		string query = "call Find_User (\"" + username + "\",\"" + password + "\")";

		const char* q2 = query.c_str();
		qstate = mysql_query(conn, q2);
		result = mysql_store_result(conn);
		row = mysql_fetch_row(result);

		if (mysql_num_rows(result) == 1)
		{
			Account* ac = new Account(atoi(row[0]), (char*)row[1], (char*)row[2], (char*)row[3], (char*)row[4], atoi(row[5]), atoi(row[6]), atoi(row[7]), true);

			cout << "Account loaded";
			mysql_free_result(result);
			return ac;
		}
		else
		{
			cout << "\nError loading account\n";
			mysql_free_result(result);
			terminate();
			return nullptr;
		}
	}
};