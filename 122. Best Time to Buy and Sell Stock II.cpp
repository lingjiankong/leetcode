// Intuitive solution
int maxProfit(vector<int>& prices)
{
	if (prices.size() == 0)
	{
		return 0;
	}

	int maxProfit = 0;
	
	for (int i = 1; i < prices.size(); ++i) 
	{
		int profit = prices[i] - prices[i-1];
		
		if (profit > 0)
		{
			maxProfit += profit;
		}

	}

	return maxProfit;
}

// DP solution, compare this one with 309. Best Time to Buy and Sell Stock with Cooldown
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
// Therefore the dp transition limits us to perform only one buy-sell transaction.
//
// It is hard to explain in word, take a deeper look into the dp transition equations
// of the stock series problem, and look at the state transition graph you drew.
int maxProfit2(vector<int>& prices)
{
	int hold = INT_MIN;
	int sold = 0;

	for (auto price : prices)
	{
		int prevSold = sold;
		int prevHold = hold;
		
		sold = max(prevSold, prevHold + price);
		hold = max(prevHold, prevSold - price);
	}

	return sold;
}
