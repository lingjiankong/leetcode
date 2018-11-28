// ***
//
// There are a row of n houses, each house can be painted with one of the k colors.
// The cost of painting each house with a certain color is different.
// You have to paint all the houses such that no two adjacent houses have the same color.
// 
// The cost of painting each house with a certain color is represented by a n x k cost matrix.
// For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.
// 
// Note:
// All costs are positive integers.
// 
// Example:
// Input: [[1,5,3],[2,9,4]]
// Output: 5
// Explanation: Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5;
// Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5.
//
// ***
//
// Always keeping track of the index of first mininum cost and index of second minimum cost for previous houses.
// For current house, as long as it is not the same color as the one which has previous minimum cost, add previous minimum cost to current cost.
// Repeat the process.
int minCostII(vector<vector<int>>& costs)
{
	if (costs.empty() || costs[0].empty())
	{
		return 0;
	}

	vector<vector<int>> dp = costs;
	int numColors = costs[0].size();

	int firstMinIndex = -1;
	int secondMinIndex = -1;

	for (int i = 0; i < costs.size(); ++i)
	{
		int lastFirstMinIndex = firstMinIndex;
		int lastSecondMinIndex = secondMinIndex;
		 
		firstMinIndex = -1; 
		secondMinIndex = -1;
		for (int j = 0; j < numColors; ++j)
		{
			if (j == lastFirstMinIndex)
			{
				dp[i][j] += lastSecondMinIndex == -1 ? 0 : dp[i - 1][lastSecondMinIndex];
			}
			else
			{
				dp[i][j] += lastFirstMinIndex == -1 ? 0 : dp[i - 1][lastFirstMinIndex];
			}

			if (firstMinIndex == -1 || dp[i][j] < dp[i][firstMinIndex])
			{
				secondMinIndex = firstMinIndex;
				firstMinIndex = j;
			}	
			else if (secondMinIndex == -1 || dp[i][j] < dp[i][secondMinIndex])
			{
				secondMinIndex = j;
			}
		}
	}

	return dp.back()[firstMinIndex];						 
} 
