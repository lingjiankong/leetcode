// ***
//
// Given a 2D board and a word, find if the word exists in the grid.
// 
// The word can be constructed from letters of sequentially adjacent cell,
// where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
// 
// Example:
// 
// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
// 
// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.
//
// ***
class Solution
{

	public:

		bool exist(vector<vector<char>>& board, string word)
		{
			if (board.empty() || board[0].empty())
			{
				return false;
			}

			int m = board.size(), n = board[0].size();

			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (backtrack(board, word, 0, i, j))
					{
						return true;
					}
				}
			}

			return false;
		}
	
	private:

		bool backtrack(vector<vector<char>>& board, const string& word, int letterCount, int i, int j)
		{
			if (letterCount == word.size())
			{
				return true;
			}

			int m = board.size(), n = board[i].size();
			if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[letterCount])
			{
				return false;
			}

			char letter = board[i][j];
			board[i][j] = '#';
			bool res = backtrack(board, word, letterCount + 1, i - 1, j) 
				|| backtrack(board, word, letterCount + 1, i + 1, j)
				|| backtrack(board, word, letterCount + 1, i, j - 1)
				|| backtrack(board, word, letterCount + 1, i, j + 1);
			board[i][j] = letter;

			return res;
		}

};
