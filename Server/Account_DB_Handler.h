#include <mysql.h>
#include <iostream>
#include <string>
#include "Account.h"
#include "DB_Handler.h"

using namespace std;

class Account_DB_Handler : public Database_Handler
{
public:
	void createAccount(Account acc)
	{
		string query = "call CreateAccount (" + acc.getFirstname() + "\",\"" + acc.getLastname() + "\",\"" + acc.getAvatarloc() + "\",\"" + acc.getUserName() + "\"" + ")";
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
	}

	void updateStats(Account acc)
	{
		string query = "call UpdateStats (" + to_string(acc.getAccountID()) + "," + to_string(acc.getWins()) + "," + to_string(acc.getLoses()) + "," + to_string(acc.getDraws()) + ")";
		const char* q = query.c_str();

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
		string query = "call UpdateAccount (" + to_string(acc.getAccountID()) + ",\"" + acc.getFirstname() + "\",\"" + acc.getLastname() + "\",\"" + acc.getAvatarloc() + "\",\"" + acc.getUserName() + "\"" + ")";
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


	Account login(string username, string password)
	{
		string query = "call Find_User (\"" + username + "\",\"" + password + "\")";

		const char* q2 = query.c_str();
		qstate = mysql_query(conn, q2);
		result = mysql_store_result(conn);
		row = mysql_fetch_row(result);

		if (mysql_num_rows(result) == 1) 
		{
			Account ac(atoi(row[0]), (string)row[1], (string)row[2], (string)row[3], (string)row[4], atoi(row[5]), atoi(row[6]), atoi(row[7]), true);

			cout << "Account loaded";
			return ac;
		}
		else
		{
			Account ac;
			cout << "\nError loading account\n";
			return ac;
		}
	}
};
