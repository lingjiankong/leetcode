// See the dp solution of 122. Best Time to Buy and Sell Stock.
// We just add the fee mechanism to the dp transition equation.

int maxProfit(vector<int>& prices, int fee)
{
	int hold = INT_MIN;
	int sold = 0;

	for (auto price : prices)
	{
		int prevSold = sold;
		int prevHold = hold;

		sold = max(prevSold, prevHold + price);
		hold = max(prevHold, prevSold - price - fee);
	}

	return sold;
}
