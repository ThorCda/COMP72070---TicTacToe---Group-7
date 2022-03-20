#pragma once
#include "GameRoom.h"

class GameBoard
{
	int board[3][3]; // represents the 3 by 3 board of tic tac toe
	
	enum Status // temp enum placement
	{
		inProgress, Ended, Quit
	};

	Status currentStatus;

public:

	GameBoard()
	{

	}

	void placePlayerMove(Player p, int move)
	{

	}

	void placeComputerMove()
	{

	}

	void ifEnd()
	{

	}

	void validateMove(int move)
	{

	}

	Status getStatus()
	{
		return currentStatus;
	}
};