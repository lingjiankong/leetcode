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
    // 1. sell: the max amount of money you have so far after you've sold a stock (the max amount of money you have when you have no stock in hand)
    // this is the amount of money you have after you've sold your stock. If doesn't matter when you sold it. You could have sold it before or you can sell it now. The point here is that we have no stock in hand.
    // 2. buy: the max amount of money you have so far after you've bought a stock (the max amount of money you have when you have a stock in hand). Note here we have to spend money to buy a stock, therefore the amount of money is negative since we own other people money (we have to borrow money to buy a stock)
    // this is the amount of money you have after you've bought your stock. If doesn't matter when you bought it. You could have bought it before or you can buy it now. The point here is that we have a stock in hand.
    int maxProfit2(vector<int>& prices) {
        int buy = INT_MIN;
        int sell = 0;
        for (auto price : prices) {
            sell = max(sell, buy + price);
            buy = max(buy, -price);
        }
        return sell;
    }
    //       {3,  5,  7,  0,  3,  2,  9,  1}
    // buy   -3  -3  -3   0   0   0   0   0
    // sell   0   2   4   4   4   4   9   9
};
