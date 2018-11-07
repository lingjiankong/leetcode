// It takes me a very long time to understand this problem.
// Understanding this problem is critical to understanding the next problem 188. Best Time to Buy and Sell Stock IV.
// This problem can be done via dp, there are four states we keep in our dp, see comments in code for what these four states represent.
// You need to keep in mind that all these states keep track of the MAX AMOUNT OF MOENY we have in each state.
//
// Why update the states in this order (let's call it "decreasing order")
//	   for (const auto& price : prices) {
//		   sold2 = max(sold2, hold2 + price);
//		   hold2 = max(hold2, sold1 - price);
//		   sold1 = max(sold1, hold1 + price);
//		   hold1 = max(hold1, -price);
//     }
//
// Rather than (let's call this "increasing order") ?
//	   for (const auto& price : prices) {
//		   hold1 = max(hold1, -price);
//		   sold1 = max(sold1, hold1 + price);
//		   hold2 = max(hold2, sold1 - price);
//		   sold2 = max(sold2, hold2 + price);
//     }
//
// Because the transition relation is
//	   hold1[i] = max(hold1[i-1], -prices[i])
//	   sold1[i] = max(sold1[i-1], hold1[i-1] + prices[i])
//	   hold2[i] = max(hold2[i-1], sold1[i-1] - prices[i])
//	   sold2[i] = max(sold2[i-1], hold2[i-1] + prices[i])
//
// As shown in the transition relation, every state is updated w.r.t. current price [i] and states in *previous* day [i-1].
// If you update in "increasing order", you ends up updating against state in today [i] instead of previous day [i-1], which is wrong.
// In the case of this problem, the code will still work if you were updating in increasing order,
// as if you were buying and selling stock on the same day, which result in useless transaction.
//
// See 121 for dp solution in the case when you are allowed to complete only 1 transaction instead of 2.

int maxProfit(vector<int>& prices)
{
	// These are the four states we keep in our dp
	int hold1 = INT_MIN; // Max amount of money we have when we are holding the first stock
	int sold1 = 0; // Max amount of money we have when we've sold the first stock (occurs after first stock has been bought (i.e. hold))
	int hold2 = INT_MIN; // Max amount of money we have when we are holding the second stock (occurs after the first stock has been sold)
	int sold2 = 0; // Max amount of money we have when we've sold the second stock (occurs after second stock has been bought (i.e. hold))

	for (auto price : prices)
	{
		sold2 = max(sold2, hold2 + price);
		hold2 = max(hold2, sold1 - price);
		sold1 = max(sold1, hold1 + price);
		hold1 = max(hold1, -price);
	}

	return sold2;
}

// Regardless of the actual number of transactions you have done
// (whether it is 1, 2, or k transactions, as long as it is less than or equal to k transactions),
// returning sold[k] will always give you the maximum possilbe profit you are able to get.
// Think of it like you buy and sell and buy and sell a stock on the same day for 100 times, it is the same
// as if you were just buy and sell on the same day for 1 time.
//
// For example, if you are allowed to do 30 transactions but you only have 10 days of stock,
// you can still return sold[k] to get the maximum profit.
//
// We see below that sold[n] never decreases. If you have actually done only 1 transaction,
// sold[1], sold[2] and sold[3] will have the same value as sold[1]

//			  {3,  5,  7,  0,  3,  2,  9,  1}
//
// hold[1]	  -3, -3, -3,  0,  0,  0,  0,  0
// hold[2]	  -3, -3, -3,  4,  4,  4,  4,  8
// hold[3]	  -3, -3, -3,  4,  4,  5,  5,  12
//
// sold[1]	   0,  2,  4,  4,  4,  4,  9,  9
// sold[2]	   0,  2,  4,  4,  7,  7,  13, 13
// sold[3]	   0,  2,  4,  4,  7,  7,  14, 14
