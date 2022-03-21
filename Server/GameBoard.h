#pragma once
#include <random>
#include "GameRoom.h"

class GameBoard
{
	char board[3][3] = { {'1','2','3'}, 
						 {'4','5','6'}, 
					     {'7','8','9'} }; // represents the 3 by 3 board of tic tac toe
	
	enum Status // temp enum placement
	{
		inProgress, Ended, Quit
	};

	Status currentStatus;

public:

	GameBoard()
	{
					
	}

	void placePlayerMove(int move)
	{
		while(!validateMove(move,1))
		{
			ifEnd();
			// some sort of confirmation move was played and initiation of response to the player
		}
	}

	void placeComputerMove()
	{
		int temp = rand() % 9;

		while (!validateMove(temp, 0))
		{
			ifEnd();
			// some sort of confirmation move was played and initiation of response to the player
		}

	}

	void ifEnd()
	{
		for (int i = 0; i <= 3, i++;)
		{
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
			{
			
			}
			for (int j = 0; j <= 3, j++;)
			{
				if (board[i][j] == board[i][j] && board[i][j] == board[i][j])
				{

				}
			}
		}
	}

	bool validateMove(int move, int player)
	{	
		int col = 0;
		int row = 0;
		if (move <= 3)
		{
			col = move - 1;
		}
		else if (move <= 6)
		{
			row = 1;
			col = move - 4;
		}
		else if (move <= 9)
		{
			row = 2;
			col = move - 7;
		}

		if (board[row][col] == (char)move)
		{
			if (player == 0)
			{
				board[row][col] = 'x';
			}
			else if (player == 1)
			{
				board[row][col] = '0';
			}
			return true;
		}
		else
			return false;
	}

	Status getStatus()
	{
		return currentStatus;
	}
};