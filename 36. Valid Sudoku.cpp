// ***
//
// Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
// - Each row must contain the digits 1-9 without repetition.
// - Each column must contain the digits 1-9 without repetition.
// - Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// 
// A partially filled sudoku which is valid.
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
// 
// Example 1:
// 
// Input:
// [
//   ["5","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// Output: true
//
// Example 2:
// 
// Input:
// [
//   ["8","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// Output: false
//
// Explanation: Same as Example 1, except with the 5 in the top left corner being 
// modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
//
// Note:
// 
// - A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// - Only the filled cells need to be validated according to the mentioned rules.
// - The given board contain only digits 1-9 and the character '.'.
// - The given board size is always 9x9.
//
// ***
//
// Here, k = 3 * (i / 3) + j / 3 will map all (i, j) that belongs to the same subbox to the same k.
// Top left subbox is 0, top middle subbox is 1, top right subbox is 2,
// Mid left subbis is 3, mid middle subbox is 4, mid right subbox is 5,
// Low left subbis is 6, low middle subbox is 7, low right subbox is 8,
bool isValidSudoku(vector<vector<char>>& board)
{
	if (board.empty() || board[0].empty())
	{
		return false;
	}

	int m = board.size(), n = board[0].size();

	vector<vector<bool>> rowFlag(m, vector<bool>(n, false));
	vector<vector<bool>> colFlag(m, vector<bool>(n, false));
	vector<vector<bool>> subboxFlag(m, vector<bool>(n, false));

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (board[i][j] >= '1' && board[i][j] <= '9')
			{
				int num = board[i][j] - '1';
				int k = 3 * (i / 3) + j / 3;
				if (rowFlag[i][num] || colFlag[num][j] || subboxFlag[k][num])
				{
					return false;
				}

				rowFlag[i][num] = true;
				colFlag[num][j] = true;
				subboxFlag[k][num] = true;
			}
		}
	}

	return true;
}
