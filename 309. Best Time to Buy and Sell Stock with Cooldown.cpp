// This DP problem can be modeled as a MDP, You will understand everything once you
// see the MDP diagram is Huahua's video:
// http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-309-best-time-to-buy-and-sell-stock-with-cooldown/

// At any day, we keep three states (shown below):
// Three actions that we can perform to transit between these states are: buy, sell, do nothing

// hold[i]: the amount of money you have if on day i you hold the stock you've bought.
// hold = max(prev_hold, prev_rest - price):
// You can transit to hold from previous hold via doing nothing,
// or you can transit to hold from previous rest via buying a stock (that's why we have -price)

// sold[i]: the amount of money you have if on day i you sell the stock that you've bought,
// sold = prev_hold + price: you can transit to sold only via selling the stock you have (that's why we have +price)

// rest[i]: the amount of money you have if on day i you rest (with no stock on hand),
// rest = max(prev_rest, prev_sold): you can transit to rest either from previous rest by doing nothing,
// or from previous sold by doing nothing (i.e. cooldown)

// In the end, the maximum profit only occurs either in state sold or rest.
// Because if you hold any stock on hand, that stock has not been cashed!

int maxProfit(vector<int>& prices)
{
	int hold = INT_MIN;
	int sold = 0;
	int rest = 0;

	for (auto price : prices)
	{
		int prevHold = hold;
		int prevSold = sold;
		int prevRest = rest;

		hold = max(prevHold, prevRest - price);
		sold = prevHold + price;
		rest = max(prevRest, prevSold);
	}

	return max(sold, rest);
}
