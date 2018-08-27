class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        if (prices.size() < 2) return 0;

        // same as saying we can perform unlimited transaction, the situation becomes the same as 122. Best Time to Buy and Sell Stock II, you just add all profit you can get
        if (k >= prices.size()/2) {
            int total = 0;
            for (int i = 1; i < prices.size(); ++i) {
                int diff = prices[i] - prices[i-1];
                if (diff > 0)
                    total += diff;
            }
            return total;
        }

        // if you are limited by k transactions, this situation becomes a generalization of solution to 123. Best Time to Buy and Sell Stock III, if you understand that question, then understanding this one is easy, otherwise you will be confused
        // why k+1? because you need sell[0] to update buy[1] = max(buy[1], sell[0] - prices[1]), sell[0] will always be 0 and buy[0] will always be INT_MIN. Note here the index i in buy/sell records the ith time you buy/sell
        vector<int> buy (k+1, INT_MIN); // the amount of money you have the ith time you buy (note i = 1 records the 1st time you buy)
        vector<int> sell (k+1, 0); // the amount of money you have the ith time you sell (note i = 1 records the 1st time you sell)

        for (int i = 0; i < prices.size(); ++i) {

            for (int j = k; j > 0; --j) {
                sell[j] = max(sell[j], buy[j] + prices[i]);
                buy[j] = max(buy[j], sell[j-1] - prices[i]);
            }
        }

        return sell[k];

    }
};

// Regardless of the actual number of transactions you have done (whether it is 1, 2, or k transactions, as long as it is less than or equal to k transactions), returning sell[k] will always give you the maximum possilbe profit you are able to get. For example, if you are allowed to do 30 transactions but you only have 10 days of stock, you can still return sell[k] to get the maximum profit. We see below that sell[n] never decreases. If you have actually done only 1 transaction sell[1], sell[2] and sell[3] will have the same value as sell[1]

//            {3,  5,  7,  0,  3,  2,  9,  1}

// buy[1]     -3, -3, -3,  0,  0,  0,  0,  0
// buy[2]     -3, -3, -3,  4,  4,  4,  4,  8
// buy[3]     -3, -3, -3,  4,  4,  5,  5,  12

// sell[1]     0,  2,  4,  4,  4,  4,  9,  9
// sell[2]     0,  2,  4,  4,  7,  7,  13, 13
// sell[3]     0,  2,  4,  4,  7,  7,  14, 14
