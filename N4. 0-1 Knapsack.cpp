// ***
//
// You are given a knapsack which has weight capacity of W and item capacity of N.
// i.e. You can store at most N items, and the total weights should be no larger than W.
// You are given a list of items with weights and values
// Find the maximum value you can put in the knapsack.
//
// ***
//
// See labuladong book pp. 191.
// dp[i][w] max values you can get if you select from the first i items and their weights are no larger than w.
//
// base case:
// dp[i][0] = 0 since your weight capacity is 0
// dp[0][w] = 0 since you have no items.
int knapsack(int W, int N, const vector<int>& weights, const vector<int>& values) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1));

    for (int i = 1; i <= N; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (w - weights[i - 1] < 0) {
                // there is no enough space in the knapsack. You cannot put item i into the knapsack.
                dp[i][w] = dp[i - 1][w];
            } else {
                // either put the item i into the knapsack (and add its value), or not.
                dp[i][w] = max(dp[i - 1][w - weights[i - 1]] + values[i - 1], dp[i - 1][w]);
            }
        }
    }

    return dp[N][W];
}
