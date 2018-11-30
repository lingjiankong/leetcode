// ***
//
// A robot is located at the top-left corner of a m x n grid.
// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
// How many possible unique paths are there?
//
// ***
//
// Some math:
// Total steps must be m + n - 2, during each step, you can either move down or move right.
// Among these m + n - 2, you must choose exactly m - 1 steps to move down (therefore n - 1 steps to move right)
// Choosing m - 1 objects out of m + n - 2 objects is simply C(m + n - 2, m - 1) = C(m + n - 2, n - 1)
// = ( m + n - 2)! / (( m - 1)! * (n - 1)!)
//
int uniquePaths(int m, int n)
{
	// Remember to initialize the top row and left column to 1.
	vector<vector<int>> dp(m, vector<int>(n, 1));

	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}

	return dp[m-1][n-1];
}

// Bonus: return all all unique paths from top left to bottom right.
// Note: vector<string> current is NOT a reference.
// Side note: It seems in C++ back tracking problems, if you only have one operation in between
// current.push_back() and current.pop_back(), then parameter `current` can be a reference vector<string>& current.
// If you have two operations like this question does, then parameter `current` must be a non-reference value.
// This is because in the first dfs, current has changed, but in the second dfs we actually want the unchanged current.
class Solution
{
    
    public:

        int uniquePaths(int m, int n) 
        {
            vector<string> current;
            vector<vector<string>> all;

            dfs(0, 0, m, n, current, all);

            return 0;

        }

    private:

        void dfs(int i, int j, int m, int n, vector<string> current, vector<vector<string>>& all)
        {
            if (i == m || j == n)
            {
                return;
            }

            if (i == m - 1 && j == n - 1)
            {
                current.emplace_back("(" + to_string(i) + ", " + to_string(j) + ")");
                all.push_back(current);
                return;
            }

            current.emplace_back("(" + to_string(i) + ", " + to_string(j) + ")");

            dfs(i+1, j, m, n, current, all);
            dfs(i, j+1, m, n, current, all);

            current.pop_back();
        }

};
