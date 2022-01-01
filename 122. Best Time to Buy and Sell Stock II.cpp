// ***
//
// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and
// sell one share of the stock multiple times). Note: You may not engage in multiple transactions at the same time
// (i.e., you must sell the stock before you buy again).
//
// Example 1:
// Input: [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
//              Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
//
// Example 2:
// Input: [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
//              engaging multiple transactions at the same time. You must sell before buying again.
//
// Example 3:
// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
//
// ***

// DP solution
// Compare this one with 309. Best Time to Buy and Sell Stock with Cooldown
// This question is just 309 without cooldown.
//
// Also, compare this question with 121. Best Time to Buy and Sell Stock
// This question allows unlimited transactions, 121 allows only one transaction.
//
// In this question:
//
// sold is the maximum amount of money we have when we don't have any stock in hand.
// It doesn't matter if we've just sold our stock for the first time
// or if we've performed buy-sell actions for 100 times already.
//
// hold is the maximum amount of money when we have a stock in hand.
// Again, it doesn't matter if we've bought 100 times (and sold 99 times) before
// or if we are holding the stock that we've bought for the very first time.
//
// However, in 121:
//
// sold is the maximum amount of money when we've sold the stock that we've bought for THE FIRST TIME.
// hold is the maximum amount of money when we've are holding the stock that we bought for THE FIRST TIME.
// Therefore the dp transition in 121 limits us to perform only one buy-sell transaction.
//
// It is hard to explain in word, take a deeper look into the dp transition equations
// of the stock series problem, and look at the state transition graph you drew.
//
//
//              sell (+price)
//          ------------------->
// d/n HOLD                      SOLD d/n
//          <-------------------
//              buy (-price)
//
int maxProfit(vector<int>& prices) {
    int sold = 0;
    int hold = INT_MIN;

    for (int price : prices) {
        int newSold = max(sold, hold + price);
        int newHold = max(hold, sold - price);

        sold = newSold;
        hold = newHold;
    }

    return sold;
}

// Intuitive solution
int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) {
        return 0;
    }

    int maxProfit = 0;

    for (int i = 1; i < prices.size(); ++i) {
        int profit = prices[i] - prices[i - 1];

        if (profit > 0) {
            maxProfit += profit;
        }
    }

    return maxProfit;
}

