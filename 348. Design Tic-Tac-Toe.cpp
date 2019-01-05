// ***
//
// Design a Tic-tac-toe game that is played between two players on a n x n grid.
// 
// You may assume the following rules:
// 
// A move is guaranteed to be valid and is placed on an empty block.
// Once a winning condition is reached, no more moves is allowed.
// A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
// Example:
// Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.
// 
// TicTacToe toe = new TicTacToe(3);
// 
// toe.move(0, 0, 1); -> Returns 0 (no one wins)
// |X| | |
// | | | |    // Player 1 makes a move at (0, 0).
// | | | |
// 
// toe.move(0, 2, 2); -> Returns 0 (no one wins)
// |X| |O|
// | | | |    // Player 2 makes a move at (0, 2).
// | | | |
// 
// toe.move(2, 2, 1); -> Returns 0 (no one wins)
// |X| |O|
// | | | |    // Player 1 makes a move at (2, 2).
// | | |X|
// 
// toe.move(1, 1, 2); -> Returns 0 (no one wins)
// |X| |O|
// | |O| |    // Player 2 makes a move at (1, 1).
// | | |X|
// 
// toe.move(2, 0, 1); -> Returns 0 (no one wins)
// |X| |O|
// | |O| |    // Player 1 makes a move at (2, 0).
// |X| |X|
// 
// toe.move(1, 0, 2); -> Returns 0 (no one wins)
// |X| |O|
// |O|O| |    // Player 2 makes a move at (1, 0).
// |X| |X|
// 
// toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
// |X| |O|
// |O|O| |    // Player 1 makes a move at (2, 1).
// |X|X|X|
//
// ***
//
class TicTacToe
{

	public:

		TicTacToe(int n)
		{
			mBoard.resize(n, vector<int>(n, 0));   
		}

		int move(int row, int col, int player)
		{
			mBoard[row][col] = player;
			int i = 0, j = 0, n = mBoard.size();

			// Check current column and see if win.
			for (i = 1; i < n; ++i)
			{
				if (mBoard[i][col] != mBoard[i - 1][col])
				{
					break;
				}
			}
			if (i == n)
			{
				return player;
			}

			// Check current row and see if win.
			for (j = 1; j < n; ++j)
			{
				if (mBoard[row][j] != mBoard[row][j - 1])
				{
					break;
				}
			}
			if (j == n)
			{
				return player;
			}

			// Check upper left to lower right diagonal.
			if (row == col)
			{
				for (i = 1; i < n; ++i)
				{
					if (mBoard[i][i] != mBoard[i - 1][i - 1]) break;
				}
				if (i == n)
				{
					return player;
				}
			}
			
			// Check upper right to lower left diagonal.
			if (row + col == n - 1)
			{
				for (i = 1; i < n; ++i)
				{
					if (mBoard[n - i - 1][i] != mBoard[n - i][i - 1])
					{
						break;
					}
				}
				if (i == n)
				{
					return player;
				}
			}

			return 0;
		}
		
	private:

		vector<vector<int>> mBoard;

};
