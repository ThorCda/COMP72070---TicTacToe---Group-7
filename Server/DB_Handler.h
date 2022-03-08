#include <mysql.h>
#include <iostream>
#include <string>

using namespace std;

class Database_Info
{
private:
	
	MYSQL* conn = mysql_init(0);
	MYSQL_ROW row;
	MYSQL_RES* result;
	int qstate;

public:

	void connect()
	{
		conn = mysql_real_connect(this->conn, "tictactoedb.ceijv7dodlt6.us-east-1.rds.amazonaws.com", "admin", "Conestoga", "tictactoeDB", 3306, NULL, 0);
		if (conn)
		{
			cout << "\nConnection established\n";
		}
		else
		{
			cout << "\nError creating connection\n";
		}
	}

	void saveAccount(Account acc)
	{
		string query = "call SaveToAccount (\"" + acc.getFirstname() + "\",\"" + acc.getLastname() + "\",\"" + acc.getAvatarloc() + "\")";
		cout << query;
		const char* q = query.c_str();

		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			cout << "\nAccount Saved\n";
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
};