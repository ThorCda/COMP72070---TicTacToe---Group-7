#pragma once
#include "Player.h"
#include "GameBoard.h"

class GameRoom
{
	Player player;
	GameBoard board;

public:

	GameRoom(Player p)
	{
		
	}

	bool playGame() // take a newtwork handler
	{

	}

	void exitRoom()
	{

	}

	GameBoard getGameBoard()
	{
		return board;
	}

	Player getPlayer()
	{
		return player;
	}
};