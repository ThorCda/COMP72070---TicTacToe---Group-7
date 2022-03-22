#pragma once
#include "Player.h"
#include "GameBoard.h"

using namespace std;

class GameRoom
{
	Player player;
	GameBoard gameBoard;

public:

	GameRoom(Player p)
	{
		
	}

	bool playGame() // take a newtwork handler
	{
		// playing moves
		// 
		//while(game is not over)
		// 
		// while(place player is false) we play until true
		// if (place player is true and no win) then computer turn 

		// while(place computer is false) we play until true
		// if (place computer is true and no win) then player turn 
	}

	void exitRoom()
	{

	}

	GameBoard getGameBoard()
	{
		return this->gameBoard;
	}

	Player getPlayer()
	{
		return this->player;
	}
};