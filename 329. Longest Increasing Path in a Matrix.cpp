// ***
//
// Given an integer matrix, find the length of the longest increasing path.
// 
// From each cell, you can either move to four directions: left, right, up or down.
// You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
// 
// Example 1:
// Input: nums =
// [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ]
// Output: 4
// Explanation: The longest increasing path is [1, 2, 6, 9].
// 
// Example 2:
// Input: nums =
// [
//   [3,4,5],
//   [3,2,6],
//   [2,2,1]
// ]
// Output: 4
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
//
// ***
//
// cache[i][j] is the longest increasing path which starts in i, j.
class Solution
{

	public:

		int longestIncreasingPath(vector<vector<int>>& matrix)
		{
			if (matrix.empty() || matrix[0].empty())
			{
				return 0;
			}

			int m = matrix.size(), n = matrix[0].size();
			vector<vector<int>> cache(m, vector<int>(n, 0));

			int maxLength = 1;
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					maxLength = max(maxLength, dfs(matrix, cache, i, j, directions));
				}
			}

			return maxLength;
		}
	
	private:

		vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

		int dfs(vector<vector<int>>& matrix, vector<vector<int>>& cache, int x, int y, vector<vector<int>>& directions)
		{
			if (cache[x][y])
			{
				return cache[x][y];
			}

			int m = matrix.size(), n = matrix[0].size();

			int maxLength = 1;
			for (auto direction : directions)
			{
				int newX = x + direction[0], newY = y + direction[1];
				if (newX < 0 || newX >= m || newY < 0 || newY >= n || matrix[newX][newY] <= matrix[x][y])
				{
					continue;
				}
				int currentLength = 1 + dfs(matrix, cache, newX, newY, directions);
				maxLength = max(maxLength, currentLength);
			}

			cache[x][y] = maxLength;
			return maxLength;
		}

};
