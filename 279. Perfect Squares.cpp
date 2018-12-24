// ***
//
// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
// 
// Example 1:
// 
// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
//
// Example 2:
// 
// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
//
// ***
//
int numSquares(int n)
{
	// dp[i]: the least number of perfect square numbers which sum to i.
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = 0;

	for (int i = 1; i <= n; ++i)
	{
		// For number i, traverse through all perfect square numbers whose square is less than or equal to i.
		// For each i, it must be the sum of some number (i - j * j) and a perfect square number (j * j).
		for (int j = 1; j * j <= i; ++j)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	return dp[n];
}
