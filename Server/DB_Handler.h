#include <mysql.h>
#include <iostream>

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
			cout << "Connection established";
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
		else
		{
			cout << "Error creating connection";
		}
	}

};