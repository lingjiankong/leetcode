class Solution {
public:
    // intuitive solution
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

    // dp solution. This builds the intuition for question 123. Best Time to Buy and Sell Stock III
    // at any day, we keep two state in dp:
    // 1. sell: the amount of money we have after we sell a stock
    // 2. buy: the amount of money we have after we buy a stock. Note here we have to spend money to buy a stock, therefore the amount of money is negative since we own other people money (we have to borrow money to buy a stock)
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int buy = INT_MIN;
            int sell = 0;
            for (auto price : prices) {
                sell = max(sell, buy + price);
                buy = max(buy, -price);
            }
            return sell;
        }
};
