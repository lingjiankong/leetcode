// ***
//
// Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
// The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
// Note: You can only put the bomb at an empty cell.
// 
// Example:
// 
// Input: [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
// Output: 3 
// Explanation: For the given grid,
// 
// 0 E 0 0 
// E 0 W E 
// 0 E 0 0
// 
// Placing a bomb at (1, 1) kills 3 enemies.
//
// ***
//
// The solution is long but intuitive:
// Using DP, keep four 2D arrays which stores the number of enemy to each side at position (i, j).
int maxKilledEnemies(vector<vector<char>>& grid)
{
	if (grid.empty() || grid[0].empty())
	{
		return 0;
	}

	int m = grid.size(), n = grid[0].size(), maxEnemy = 0;
	vector<vector<int>> leftToRight(m, vector<int>(n, 0));
	vector<vector<int>> rightToLeft(m, vector<int>(n, 0));
	vector<vector<int>> topToBottom(m, vector<int>(n, 0));
	vector<vector<int>> bottomToTop(m, vector<int>(n, 0));

	for (int i = 0; i < m; ++i)
	{
		// Each row from left to right
		for (int j = 0; j < n; ++j)
		{
			int val = (j == 0 || grid[i][j] == 'W') ? 0 : leftToRight[i][j - 1];
			leftToRight[i][j] = grid[i][j] == 'E' ? val + 1 : val;
		}
		// Each row from right to left
		for (int j = n - 1; j >= 0; --j)
		{
			int val = (j == n - 1 || grid[i][j] == 'W') ? 0 : rightToLeft[i][j + 1];
			rightToLeft[i][j] = grid[i][j] == 'E' ? val + 1 : val;
		}
	}
	for (int j = 0; j < n; ++j)
	{
		// Each column from top to bottom
		for (int i = 0; i < m; ++i)
		{
			int val = (i == 0 || grid[i][j] == 'W') ? 0 : topToBottom[i - 1][j];
			topToBottom[i][j] = grid[i][j] == 'E' ? val + 1 : val;
		}
		// Each bottom from bottom to top
		for (int i = m - 1; i >= 0; --i)
		{
			int val = (i == m - 1 || grid[i][j] == 'W') ? 0 : bottomToTop[i + 1][j];
			bottomToTop[i][j] = grid[i][j] == 'E' ? val + 1 : val;
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (grid[i][j] == '0')
			{
				maxEnemy = max(maxEnemy, leftToRight[i][j] + rightToLeft[i][j] + topToBottom[i][j] + bottomToTop[i][j]);
			}
		}
	}

	return maxEnemy;
}
