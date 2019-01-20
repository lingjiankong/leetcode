// ***
//
// According to the Wikipedia's article: "The Game of Life, also known simply as Life,
// is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
// 
// Given a board with m by n cells, each cell has an initial state live (1) or dead (0).
// Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
// 
// Any live cell with fewer than two live neighbors dies, as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population..
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
//
// Write a function to compute the next state (after one update) of the board given its current state.
// The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.
// 
// Example:
// 
// Input:
// [
//   [0,1,0],
//   [0,0,1],
//   [1,1,1],
//   [0,0,0]
// ]
//
// Output:
// [
//   [0,0,0],
//   [1,0,1],
//   [0,1,1],
//   [0,1,0]
// ]
//
// ***
void gameOfLife(vector<vector<int>>& board)
{
	if (board.empty() || board[0].empty())
	{
		return;
	}

	int m = board.size();
	int n = board[0].size();

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int lives = 0;

			// live is the total lives (including self (the center cell)) we have in a 3 by 3 window.
			// Because board[x][y] is binary, we can sum all board[x][y] bitwise & 0b00000001
			// in this 3 by 3 window to get the total number of live cells.
			//
			// The right most bit is the current state of board[x][y];
			// The second right most bit is the next state of board[x][y].
			//
			// Why do you need to bitwise &?
			// Because the current state of board[x][y] is stored at the right most bit, i.e. 0b00000001 or 0b00000000 (1 or 0),
			// but the next state of board[x][y] is stored at the second right most bit! i.e. 0b00000011 or 0b00000010 (3 or 2),
			// So to get the total *current* lives in a 3 by 3 window you should only look at the right most bit
			// You can't just do lives += board[x][y], this doesn't make sense (board[x][y] could be 3 or 4)
			//
			// The max and min here are very smart:
			// We do it so that we can check the entire grid and not worrying about out of bound problem
			// if we are at a cell on the edge of the grid
			for (int x = max(0, i-1); x < min(m, i+2); ++x)
			{
				for (int y = max(0, j-1); y < min(n, j+2); ++y)
				{
					lives += board[x][y] & 0b00000001;
				}
			}

			// The four rules on LeetCode can be summarized as:
			// if (lives == 3 || lives - board[i][j] == 3) then board[i][j] is live.
			// Well, you can just write the four rules explicitly.
			// We store whether board[i][j] is live using bitwise | with 0b00000010 and store the status in the second right most bit.
			// After we've processed all cells, we right shift every board[i][j] to get its current status
			if (lives == 3 || lives - board[i][j] == 3)
			{
				board[i][j] |= 0b00000010;
			}
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			board[i][j] >>= 1;
		}
	}
}
