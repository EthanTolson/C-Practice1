#pragma once
#include <string>

namespace checkers
{
	class checkersGame
	{
		public:
			bool blueWin = false;
			bool redWin = false;
			bool turn = true;
			int redPieces[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
			int bluePieces[12] = { 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};
			//1 is red piece 2 is blue piece 3 is red king 4 is blue king 0 is empty square
			int position[32] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
			void play();
			bool validMove(int move[]);
			bool possibleMoves(int space, int move, bool jumpCheck, bool isKing = false);
			bool jump(int space, int move, int previous);
			bool checkWin();
			int getJumpAfter(int space, int move);
			void checkPromotion();
			void printBoard();
		private:
	};
}