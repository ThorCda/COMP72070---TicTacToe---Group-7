#pragma once
#include <random>

class GameBoard
{
	char board[3][3] = { {'1','2','3'},
						 {'4','5','6'},
						 {'7','8','9'} }; // represents the 3 by 3 board of tic tac toe

	enum Status // temp enum placement
	{

	};

	Status currentStatus;
	int moveCounter;

	bool playerWin = false;
	bool computerWin = false;

public:

	GameBoard()
	{
		this->moveCounter = 0;
		// set status to something
	}

	bool getPlayerWin()
	{
		return this->playerWin;
	}

	bool getComputerWin()
	{
		return this->computerWin;
	}

	bool placePlayerMove(int move)
	{
		this->moveCounter++;
		if (validateMove(move, 0))
		{
			if (ifEnd())
			{
				this->playerWin = true;
			}
			return true;
		}
		return false;
	}

	bool placeComputerMove()
	{
		int move = rand() % 9;
		this->moveCounter++;
		if (validateMove(move, 0))
		{
			if (ifEnd())
			{
				this->computerWin = true;
			}
			return true;
		}
		return false;
	}

	bool ifEnd()
	{
		if (this->moveCounter < 9)
		{
			for (int i = 0; i <= 3; i++)
			{
				if (this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2])
				{
					return true;
				}
				if (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i])
				{
					return true;
				}
				if (this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2])
				{
					return true;
				}
				if (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0])
				{
					return true;
				}
			}
		}
		else
		{
			return true;
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

		if (this->board[row][col] == (char)move)
		{
			playMove(row, col, move, player);
			return true;
		}
		else
			return false;
	}

	void playMove(int row, int col, int move, int player)
	{
		if (player == 0)
		{
			this->board[row][col] = 'x';
		}
		else if (player == 1)
		{
			this->board[row][col] = '0';
		}
		return;
	}

	Status getStatus()
	{
		return this->currentStatus;
	}
};