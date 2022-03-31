#pragma once

#include <mysql.h>
#include <iostream>
#include <string>
#include "Account.h"
#include "DB_Handler.h"
#include "GameRoom.h"

using namespace std;

class Game_DB_Handler : public Database_Handler
{
public:

	void createGame(GameRoom* g, Account* acc) // takes a game and creates a record in the database
	{
		string query = "call CreateGame (\"" + to_string(g->getGameBoard()->getStatus()) + "\",\"" + to_string(acc->getAccountID()) + "\"" + ")";
		const char* q = query.c_str();
		cout << query;
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			cout << "\Game Created\n";
		}
		else
		{
			cout << "\nError creating game\n";
		}
	}

	void deleteGame(int id) // takes a game id and deletes a record in the database
	{
		string query = "call DeleteGame (" + to_string(id) + ")";
		const char* q = query.c_str();

		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			cout << "\Game deleted\n";
		}
		else
		{
			cout << "\nError deleting game\n";
		}

	}

	void viewGames() // views all the games in the table, mostly for server side admin use
	{
		string query = "SELECT * FROM game";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);

		if (!qstate)
		{
			result = mysql_store_result(conn);

			while (row = mysql_fetch_row(result))
			{
				cout << "\nID: " << row[0] << "\nDate: " << row[1] << "\nWinner ID: " << row[2] << "\nStatus: " << row[3];
			}
			mysql_free_result(result);
		}

	}

	void viewSpecificGame(int id) // views a specific game at the users request. will have to send packet back later instead of console printing
	{
		string query = "SELECT * FROM game where gameID = " + id;
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);

		if (!qstate)
		{
			result = mysql_store_result(conn);
			cout << "\nID: " << row[0] << "\nDate: " << row[1] << "\nWinner ID: " << row[2] << "\nStatus: " << row[3];
			mysql_free_result(result);
		}
	}
};