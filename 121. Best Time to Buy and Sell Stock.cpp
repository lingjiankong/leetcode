class Solution 
{

	public:

		// Intuitive solution
		int maxProfit(vector<int>& prices) 
		{
			if (prices.empty()) 
			{
				return 0;
			}
			
			int minPrice = prices[0];
			int maxProfit = 0;
			
			for (int i = 1; i < prices.size(); ++i) 
			{
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
		// If doesn't matter when you sold the stock. You could have sold it before or you can sell it now. 
		// The point here is that you have NO stock in hand.
		// 
		// 2. hold: the max amount of money you have when you are holding the stock.
		// (the max amount of money you have when you have the stock in hand). 
		// In order to hold the stock, of course you should have bought the stock at some point.
		// Note here we have to spend money to buy the stock, therefore the amount of money is negative 
		// since we own other people money (we have to borrow money to buy stock).
		// If doesn't matter when you bought the stock. You could have bought it before or you can buy it now. 
		// The point here is that you currently have stock in hand.
		int maxProfit2(vector<int>& prices) 
		{
			int hold = INT_MIN;
			int sold = 0;
			for (const auto& price : prices) 
			{
				// sold is the max of either:
				// sold <- you've sold the stock before and you currently have no stock in hand, and you do nothing
				// hold + price <- you are holding the stock in hand, and you sell the stock now
				sold = max(sold, hold + price);

				// hold is the max of either:
				// hold <- you've bought the stock before and is currently holding it now, and you do nothing
				// -price <- you buy the stock now
				hold = max(hold, -price);
			}
			return sold;
		}
		
		// Example
		//
		//		 {3,  5,  7,  0,  3,  2,  9,  1}
		// hold	 -3  -3  -3   0   0   0   0   0
		// sold   0   2   4   4   4   4   9   9

};
