#pragma once
#include "Player.h"
#include "GameBoard.h"

using namespace std;

class GameRoom
{
	Player player;
	GameBoard* gameBoard;

public:

	GameRoom()
	{
		this->gameBoard = new GameBoard();
	}

	bool updateBoard(int move) // take a packet
	{
		if(!this->gameBoard->ifEnd())
		{
			if (this->gameBoard->validateMove(move, 0)) // player makes move
			{
				return true;
			}
			else
			{
				return false;
			}

		}
	}

	void NewBoard()
	{
		delete gameBoard;
		gameBoard = new GameBoard();
	}

	GameBoard* getGameBoard()
	{
		return this->gameBoard;
	}

	Player getPlayer()
	{
		return this->player;
	}
};