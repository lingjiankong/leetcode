// ***
//
// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
// 
// A region is captured by flipping all 'O's into 'X's in that surrounded region.
// 
// Example:
// X X X X
// X O O X
// X X O X
// X O X X
//
// After running your function, the board should be:
// X X X X
// X X X X
// X X X X
// X O X X
//
// Explanation:
// Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'.
// Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'.
// Two cells are connected if they are adjacent cells connected horizontally or vertically.
// 
// ***
//
// First traverse the four edges for 'O', dfs the 'O's and change all 'O' to '$'.
// Now, all 'O' left (those that have not been dfs) are surrounded by 'X'. Change them to 'X'.
// Change the '$'s to 'O'.
class Solution
{

	public:

		void solve(vector<vector<char> >& board)
		{
			for (int i = 0; i < board.size(); ++i)
			{
				for (int j = 0; j < board[i].size(); ++j)
				{
					if ((i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1) && board[i][j] == 'O')
					{
						dfs(board, i, j);
					}
				}
			}

			for (int i = 0; i < board.size(); ++i)
			{
				for (int j = 0; j < board[i].size(); ++j)
				{
					if (board[i][j] == 'O')
					{
						board[i][j] = 'X';
					}
					if (board[i][j] == '$')
					{
						board[i][j] = 'O';
					}
				}
			}
		}
	
	private:

		void dfs(vector<vector<char>>& board, int i, int j)
		{
			if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O')
			{
				return;
			}
				board[i][j] = '$';
				dfs(board, i + 1, j);
				dfs(board, i - 1, j);
				dfs(board, i, j + 1);
				dfs(board, i, j - 1);
		}

};
