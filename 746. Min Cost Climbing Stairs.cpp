// ***
//
// On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
// 
// Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor,
// and you can either start from the step with index 0, or the step with index 1.
// 
// Example 1:
// Input: cost = [10, 15, 20]
// Output: 15
//
// Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
//
// Example 2:
// Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
// Output: 6
//
// Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
//
// Note:
// - cost will have a length in the range [2, 1000].
// - Every cost[i] will be an integer in the range [0, 999].
//
// ***
//
// dp[i]: How much it cost when you *jump from* stair i.
int minCostClimbingStairs(vector<int>& cost)
{
	vector<int> dp(cost.size(), 0);
	dp[0] = cost[0];
	dp[1] = cost[1];

	for (int i = 2; i < cost.size(); ++i)
	{
		dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
	}

	return min(dp[n], dp[n-1]);
}



// Similar idea: dp[i]: How much it cost when you *reach* stair i (without jumping form it).
int minCostClimbingStairs(vector<int>& cost)
{
	// dp vector has one more element that cost element
	// because we must reach one step beyond the last step
	vector<int> dp(cost.size() + 1, 0);

	for (int i = 2; i < cost.size() + 1; ++1)
	{
		dp[i] = min(dp[i-2] + cost[i-2], dp[i-1] + cost[i-1]);
	}

	return dp.back();
}
