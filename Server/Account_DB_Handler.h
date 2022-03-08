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
		// this will take a account that does not exist in the databaes and inserts it into it as a new record
	}
	void updateStats(Account acc)
	{
		string query = "call UpdateStats (" + to_string(acc.getAccountID()) + "," + to_string(acc.getWins()) + "," + to_string(acc.getLoses()) + "," + to_string(acc.getDraws()) + ")";
		cout << query;
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
		// beef this up and add the new save values
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

	void deleteAccount(int id)
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

	void getAccounts()
	{
		string query = "SELECT * FROM account";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);

		if (!qstate)
		{
			result = mysql_store_result(conn);

			while (row = mysql_fetch_row(result))
			{
				cout << "\nID: " << row[0] << "\nFirst Name: " << row[1] << "\nLast Name: " << row[2] << "\nPath: " << row[3];
			}
		}
	}

	bool findAccount(string Name, string Password)
	{
		string query = "call Find_User (\"" + Name + "\",\"" + Password + "\")";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);

		if (!qstate)
		{
			return true;
		}

		return false;
	}

	Account login()
	{
		//temp we ask for user input to be done in GUI later
		string fName;
		string pw;
		cout << "\nEnter your login first name:\n";
		cin >> fName;

		cout << "\nEnter your login password:\n";
		cin >> pw;

		if (findAccount(fName, pw))
		{
			//stored procedure to find the account and join the stats and account table to then laod the information into the account
		/*	result = mysql_store_result(conn);
			row = mysql_fetch_row(result);
			Account ac((int)row[0],row[1], row[2], row[3], (int)row[4],(int)row[5], (int)row[6], true);*/
		}
		else
		{
			cout << "could not find account";
		}
	}
};