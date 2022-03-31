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
		return this->gameBoard->placePlayerMove(move);
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