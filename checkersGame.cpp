#include "checkersGame.h"
#include <iostream>

using namespace std;
using namespace checkers;


	void checkersGame::play()
	{
		int move[2] = { 0,0 };
		if (turn)
		{
			int i = 0;
			while (!validMove(move) && i < 12)
			{
				if (i)
				{
					cout << "That is not a valid move try again!\n\n";
				}
				cout << "\nRed's turn!\nWhich piece would you like to move? ";
				cin >> move[0];
				cout << "\nWhere would you like to move that piece? ";
				cin >> move[1];
				i++;
			}
		}
		else
		{
			int i = 0;
			while (!validMove(move) && i < 12)
			{
				if (i)
				{
					cout << "That is not a valid move try again!\n\n";
				}
				cout << "\nBlue's turn!\nWhich piece would you like to move? ";
				cin >> move[0];
				cout << "\nWhere would you like to move that piece? ";
				cin >> move[1];
				i++;
			}
		}
		turn = !turn;
	}

	//executes valid moves by editing the position and piece
	bool checkersGame::validMove(int move[])
	{
		//turn keeps track of red and blues turns 
		if (turn)
		{
			for (int i = 0; i < sizeof(redPieces); i++)
			{
				//makes sure move is valid
				if (move[0] == redPieces[i] && possibleMoves(redPieces[i], move[1]))
				{
					int change = position[redPieces[i]];
					position[redPieces[i]] = 0;
					position[move[1]] = change;
					redPieces[i] = move[1];
					return true;
					break;
				}
			}
		}
		else if (!turn)
		{
			for (int i = 0; i < sizeof(bluePieces); i++)
			{
				//makes sure move is valid
				if (move[0] == bluePieces[i] && possibleMoves(bluePieces[i], move[1]))
				{
					int change = position[bluePieces[i]];
					position[bluePieces[i]] = 0;
					position[move[1]] = change;
					bluePieces[i] = move[1];
					return true;
					break;
				}
			}
		}
		//if the move is invalid return false
		return false;
	}

	bool checkersGame::possibleMoves(int space, int move)
	{
		//Checks if the piece moving is red or blue or a king to determine if they can move backwards or forwards
		//also checks for a blocking piece
		bool movingBackwards = (position[space] == 2 || position[space] >= 3) && position[move] < 1;
		bool movingForwards = (position[space] == 1 || position[space] >= 3) && position[move] < 1;
		//position 1 and 32 only have 1 space to move to
		if (space == 1 && move == 5 && position[move] < 1)
		{
			return true;
		}
		else if (space == 32 && move == 28 && position[move] < 1)
		{
			return true;
		}
		//checks each space's valid moves excluding 1 and 32 which are coded above
		for (int i = 2; i < 32; i++)
		{
			if (i != 9 && i != 17 && i != 25 && i != 8 && i != 16 && i != 24)
			{
				if (i - 4 <= 0)
				{
					if (space == i && (move == i + 3 || move == i + 4))
					{
						return true;
						break;
					}
				}
				else if (i - 8 <= 0)
				{

					if (space == i && (move == i - 3 || move == i - 4) && movingBackwards)
					{
						return true;
						break;
					}
					else if ((space == i && (move == i + 4 || move == i + 5) && movingForwards))
					{
						return true;
					}
				}
				else if (i - 12 <= 0)
				{

					if (space == i && (move == i - 4 || move == i - 5) && movingBackwards)
					{
						return true;
						break;
					}
					else if ((space == i && (move == i + 3 || move == i + 4) && movingForwards))
					{
						return true;
					}
				}
				else if (i - 16 <= 0)
				{

					if (space == i && (move == i - 3 || move == i - 4) && movingBackwards)
					{
						return true;
						break;
					}
					else if ((space == i && (move == i + 4 || move == i + 5) && movingForwards))
					{
						return true;
					}
				}
				else if (i - 20 <= 0)
				{

					if (space == i && (move == i - 4 || move == i - 5) && movingBackwards)
					{
						return true;
						break;
					}
					else if ((space == i && (move == i + 3 || move == i + 4) && movingForwards))
					{
						return true;
					}
				}
				else if (i - 24 <= 0)
				{

					if (space == i && (move == i - 3 || move == i - 4) && movingBackwards)
					{
						return true;
						break;
					}
					else if ((space == i && (move == i + 4 || move == i + 5) && movingForwards))
					{
						return true;
					}
				}
				else if (i - 28 <= 0)
				{

					if (space == i && (move == i - 4 || move == i - 5) && movingBackwards)
					{
						return true;
						break;
					}
					else if ((space == i && (move == i + 3 || move == i + 4) && movingForwards))
					{
						return true;
					}
				}
				else
				{
					if (space == i && (move == i - 3 || move == i - 4))
					{
						return true;
						break;
					}
				}
			}
			else
			{
				if (space == i && (move == i + 4) && movingForwards)
				{
					return true;
					break;
				}
				else if (space == i && (move == i - 4) && movingBackwards)
				{
					return true;
					break;
				}
			}
		}
		//return false if move is invalid
		return false;
	}

	//returns true if either player wins
	//print message of winning player
	bool checkersGame::checkWin()
	{
		bool redHasPieces = false;
		bool blueHasPieces = false;
		for (int i = 0; i < sizeof(redPieces); i++)
		{
			if (redPieces[i] > 0)
			{
				redHasPieces = true;
			}
			
			if (bluePieces[i] > 0)
			{
				blueHasPieces = true;
			}
		}

		if (blueHasPieces && redHasPieces)
		{
			return false;
		}
		else if (redHasPieces)
		{
			cout << "\nCongratulations Red Wins!!\n\n\n";
			return true;
		}
		else
		{
			cout << "\nCongratulations Blue Wins!!\n\n\n";
			return true;
		}
	}

	bool checkersGame::jump(int space, int move, int previous)
	{
		if (position[space] != previous && possibleMoves(space, move))
		{
			if (position[space] == 1)
			{
				for (int i = 0; i < 12; i++)
				{
					if (redPieces[i] == space)
					{
						redPieces[i] = 0;
					}
				}
			}
			else if (position[space] == 2)
			{
				for (int i = 0; i < 12; i++)
				{
					if (bluePieces[i] == space)
					{
						bluePieces[i] = 0;
					}
				}
			}
			position[space] = 0;
			
			return true;
		}
		return false;
	}