class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;

        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int profit = prices[i] - prices[i-1];
            if (profit > 0)
                maxProfit += profit;
        }
        return maxProfit;
    }
};
