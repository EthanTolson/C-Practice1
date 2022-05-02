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
				if (move[0] == redPieces[i] && possibleMoves(redPieces[i], move[1], false))
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
				if (move[0] == bluePieces[i] && possibleMoves(bluePieces[i], move[1], false))
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

	bool checkersGame::possibleMoves(int space, int move, bool jumpCheck)
	{
		//Checks if the piece moving is red or blue or a king to determine if they can move backwards or forwards
		//also checks for a blocking piece
		bool movingBackwards = false;
		bool movingForwards = false;
		if (jumpCheck)
		{
			movingBackwards = true;
			movingForwards = true;
		}
		else
		{
			movingBackwards = (position[space] == 2 || position[space] >= 3) && position[move] < 1;
			movingForwards = (position[space] == 1 || position[space] >= 3) && position[move] < 1;
		}
		//check if the player wants to jump
		if ((move - 4 > space || move + 4 < space) && position[move] == 0 && position[getJumpAfter(space,move)] != position[space])
		{
			if (jump(getJumpAfter(space, move), move, space))
			{
				return true;
			}
		}
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
		//first conditional is to handle normal moves that are checked for jumps
		if (space == 0)
		{
			return false;
		}
		if (possibleMoves(space, move, true))
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

	//returns the space in the middle of the jump
	int checkersGame::getJumpAfter(int space, int move)
	{
		if (space == 1 && move == 10 || space == 2 && move == 9 || space == 9 && move == 2 || move == 1 && space == 10)
		{
			return 5;
		}
		else if (space == 2 && move == 11 || space == 3 && move == 10|| space == 11 && move == 2 || space == 10 && move == 3)
		{
			return 6;
		}
		else if (space == 4 && move == 11 || space == 3 && move == 12 || space == 11 && move == 4 || space == 12 && move == 3)
		{
			return 7;
		}
		else if (space == 5 && move == 14 || space == 6 && move == 13 || space == 13 && move == 6 || space == 14 && move == 5)
		{
			return 10;
		}
		else if (space == 7 && move == 14 || space == 6 && move == 15 || space == 15 && move == 6 || space == 14 && move == 7)
		{
			return 11;
		}
		else if (space == 7 && move == 16 || space == 8 && move == 15 || space == 15 && move == 8 || space == 16 && move == 7)
		{
			return 12;
		}
		else if (space == 9 && move == 18 || space == 10 && move == 17 || space == 17 && move == 10 || space == 18 && move == 9)
		{
			return 13;
		}
		else if (space == 11 && move == 18 || space == 10 && move == 19 || space == 19 && move == 10 || space == 18 && move == 11)
		{
			return 14;
		}
		else if (space == 11 && move == 20 || space == 12 && move == 19 || space == 19 && move == 12 || space == 20 && move == 11)
		{
			return 15;
		}
		else if (space == 13 && move == 22 || space == 14 && move == 21 || space == 21 && move == 14 || space == 22 && move == 13)
		{
			return 18;
		}
		else if (space == 15 && move == 22 || space == 14 && move == 23 || space == 23 && move == 14 || space == 22 && move == 15)
		{
			return 19;
		}
		else if (space == 15 && move == 24 || space == 16 && move == 23 || space == 23 && move == 16 || space == 24 && move == 15)
		{
			return 20;
		}
		else if (space == 17 && move == 26 || space == 18 && move == 25 || space == 25 && move == 18 || space == 26 && move == 17)
		{
			return 21;
		}
		else if (space == 19 && move == 26 || space == 18 && move == 27 || space == 27 && move == 18 || space == 26 && move == 19)
		{
			return 22;
		}
		else if (space == 19 && move == 28 || space == 20 && move == 27 || space == 27 && move == 20 || space == 28 && move == 19)
		{
			return 23;
		}
		else if (space == 21 && move == 30 || space == 22 && move == 29 || space == 29 && move == 22 || space == 30 && move == 21)
		{
			return 26;
		}
		else if (space == 23 && move == 30 || space == 22 && move == 31 || space == 31 && move == 22 || space == 30 && move == 23)
		{
			return 27;
		}
		else if (space == 23 && move == 32 || space == 24 && move == 31 || space == 31 && move == 24 || space == 32 && move == 23)
		{
			return 28;
		}
		return 0;
	}