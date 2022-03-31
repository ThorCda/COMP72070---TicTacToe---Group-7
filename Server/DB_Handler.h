#pragma once
#include <mysql.h>
#include <iostream>
#include <string>

using namespace std;

class Database_Handler
{
protected:
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* result;
	int qstate;

public:

	Database_Handler()
	{

	}
	~Database_Handler()
	{
	}

	void createConnection()
	{
		conn = mysql_init(0);
		conn = mysql_real_connect(this->conn, "tictactoedbv3.cjzonevwncmb.us-east-2.rds.amazonaws.com", "admin", "Conestoga", "tictactoeDB", 3306, NULL, 0);
		if (conn)
		{
			cout << "\nConnection established\n";
		}
		else
		{
			cout << "\nError creating connection\n";
		}
	}

	void terminate()
	{
		mysql_close(conn);
	}

};