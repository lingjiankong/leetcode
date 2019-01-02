// ***
//
// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
// 
// Example:
// 
// Input: 4
// 
// Output: [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
// 
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
//
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
//
// ***
class Solution
{

	public:

		vector<vector<string>> solveNQueens(int n)
		{
			vector<string> current(n, string(n, '.'));
			vector<vector<string>> all;

			solveNQueens(all, current, 0, n);

			return all;
		}

	private:

		void solveNQueens(vector<vector<string>>& all, vector<string>& current, int row, int &n)
		{
			if (row == n)
			{
				all.push_back(current);
				return;
			}

			// Traverse every position of current row.
			for (int col = 0; col < n; ++col)
			{
				if (isValid(current, row, col, n))
				{
					current[row][col] = 'Q';
					solveNQueens(all, current, row + 1, n);
					current[row][col] = '.';
				}
				
			}
		}

		bool isValid(vector<string>& current, int row, int col, int &n)
		{
			// Check if the column had a queen before.
			for (int i = 0; i != row; ++i)
			{
				if (current[i][col] == 'Q')
				{
					return false;
				}
			}
			// Check if the 45° diagonal had a queen before.
			for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
			{
				if (current[i][j] == 'Q')
				{
					return false;
				}
			}
			// check if the 135° diagonal had a queen before.
			for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
			{
				if (current[i][j] == 'Q')
				{
					return false;
				}
				
			}
			return true;
		}

};
