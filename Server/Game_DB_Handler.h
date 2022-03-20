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

	void createGame() // takes a game and creates a record in the database
	{

	}

	void deleteGame() // takes a game id and deletes a record in the database
	{

	}

	void viewGame() // views all games in the database? views a specific game based on id?
	{

	}
};