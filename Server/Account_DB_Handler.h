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


	Account login()
	{
		//temp we ask for user input to be done in GUI later
		string fName;
		string pw;
		cout << "\nEnter your login user name:\n";
		cin >> fName;

		cout << "\nEnter your login password:\n";
		cin >> pw;

		string query = "call Find_User (\"" + fName + "\",\"" + pw + "\")";

		const char* q2 = query.c_str();
		qstate = mysql_query(conn, q2);
		result = mysql_store_result(conn);
		row = mysql_fetch_row(result);

		if (mysql_num_rows(result) == 1) // better way to check if the row is there rather than checking if the query didnt have errors
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