#pragma once
#include <mysql.h>
#include <iostream>
#include <string>

using namespace std;

class Database_Handler
{
protected:
	MYSQL* conn = mysql_init(0);
	MYSQL_ROW row;
	MYSQL_RES* result;
	int qstate;

public:

	Database_Handler()
	{
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


	~Database_Handler()
	{
		mysql_close(conn);
	}



};