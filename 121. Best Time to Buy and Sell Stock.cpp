class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int profit = prices[i] - minPrice;
            maxProfit = max(profit, maxProfit);
            minPrice = min(prices[i], minPrice);
        }
        return maxProfit;
    }
};
