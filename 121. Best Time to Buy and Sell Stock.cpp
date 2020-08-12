// ***
//
// Say you have an array for which the ith element is the price of a given stock on day i.
//
// If you were only permitted to complete at most one transaction
// (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//
// Note that you cannot sell a stock before you buy one.
//
// Example 1:
//
// Input: [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Not 7-1 = 6, as selling price needs to be larger than buying price.
//
// Example 2:
// Input: [7,6,4,3,1]
// Output: 0
//
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
//
// ***

// Intuitive solution
int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); ++i) {
        int profit = prices[i] - minPrice;
        maxProfit = max(profit, maxProfit);
        minPrice = min(prices[i], minPrice);
    }

    return maxProfit;
}

// DP solution. This builds the intuition for question 123. Best Time to Buy and Sell Stock III
//
// At any day, we keep two state in dp:
//
// 1. sold: the max amount of money you have when you've sold the stock
// (the max amount of money you have when you have no stock in hand).
// It doesn't matter when you sold the stock. You could have sold it before or you can sell it now.
// The point here is that you have NO stock in hand.
//
// 2. hold: the max amount of money you have when you are holding the stock.
// (the max amount of money you have when you have the stock in hand).
// In order to hold the stock, of course you should have bought the stock at some point.
// Note here we have to spend money to buy the stock, therefore the amount of money is negative
// since we own other people money (we have to borrow money to buy stock).
// It doesn't matter when you bought the stock. You could have bought it before or you can buy it now.
// The point here is that you currently have stock in hand.
//
// Example
//
//		          {3,  5,  7,  1,  3,  2,  9,  1}
// sold        0   0   2   4   4   4   4   8   8
// hold	 INT_MIN  -3  -3  -3  -1  -1  -1  -1  -1
int maxProfit(vector<int>& prices) {
    int sold = 0;
    int hold = INT_MIN;

    for (int price : prices) {
        // sold is the max of either:
        // sold <- you've sold the stock before and you currently have no stock in hand, and you do nothing
        // hold + price <- you are holding the stock in hand, and you sell the stock now
        sold = max(sold, hold + price);

        // hold is the max of either:
        // hold <- you've bought the stock before and is currently holding it now, and you do nothing
        // -price <- you buy the stock now
        hold = max(hold, 0 - price);
    }

    return sold;
}

