#pragma once
#include <mysql.h>
#include <iostream>
#include <string>

using namespace std;

class Database_Handler
{

public:

	MYSQL* conn = NULL;

	Database_Handler()
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
	~Database_Handler()
	{

	}

	void createConnection()
	{
		//conn = mysql_init(NULL);
		////mysql_init(conn);
		//if (!mysql_real_connect(conn, "tictactoedbv3.cjzonevwncmb.us-east-2.rds.amazonaws.com", "admin", "Conestoga", "tictactoeDB", 3306, NULL, 0))
		//{
		//	fprintf(stderr, "Failed to connect to database: Error: %s\n",
		//	mysql_error(conn));
		//}
		/*conn = mysql_init(0);
		conn = mysql_real_connect(this->conn, "tictactoedbv3.cjzonevwncmb.us-east-2.rds.amazonaws.com", "admin", "Conestoga", "tictactoeDB", 3306, NULL, 0);
		if (conn)
		{
			cout << "\nConnection established\n";
		}
		else
		{
			cout << "\nError creating connection\n";
		}*/
	}

	void terminate()
	{
		if (conn)
		{
			mysql_close(conn);

		}
	}

};