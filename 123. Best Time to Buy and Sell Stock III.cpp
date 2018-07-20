// it takes me a very long time to understand this problem. Understanding this problem is critical to understanding the next problem 188. Best Time to Buy and Sell Stock IV
// this problem can be done via dp, there are four states we keep in our dp, see comments in code for what these four states represent. You need to keep in mind that all these states keep track of the AMOUNT OF MOENY we have after performing certain operation
//
// why update the states in this order (let's call it "decreasing order")
//     for (auto price : prices) {
//         sell2 = max(sell2, buy2 + price);
//         buy2 = max(buy2, sell1-price);
//         sell1 = max(sell1, buy1 + price);
//         buy1 = max(buy1, -price);
//
// rather than (let's call this "increasing order") ?
//     for (auto price : prices) {
//         buy1 = max(buy1, -price);
//         sell1 = max(sell1, buy1 + price);
//         buy2 = max(buy2, sell1-price);
//         sell2 = max(sell2, buy2 + price);
//
// because the transition relation is
//     buy1[i] = max(buy1[i-1], -prices[i])
//     sell1[i] = max(sell1[i-1], buy1[i-1]+price[i])
//     buy2[i] = max(buy2[i-1], sell1[i-1]-prices[i])
//     sell2[i] = max(sell2[i-1], buy2[i-1]+price[i])
//
// as shown in the transition relation, every state is updated w.r.t. current price [i] and states in *previous* day [i-1]. If you update in "increasing order", you ends up updating against state in today [i] instead of previous day [i-1], which is wrong. In the case of this problem, the code will still work if you were updating in increasing order, as if you were buying and selling stock on the same day, which result in useless transaction.
// this about an extreme case, say you are allowed to complete 100 transactions instead of 2. Then during the first, say, 50 days, there's no way for you to complete the 100th transaction yet. If you update your states in decreasing order, then sell100 or buy100 will not be affected until we get closer to the 100th day. However, if you update your states in increasing order, then sell100 and buy100 will be updated on day1, which doesn't make sense.

// See 121 for dp solution in the case when you are allowed to complete only 1 transaction instead of 2.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // these are the four states we keep in our dp
        int buy1 = INT_MIN; // amount of money we have after buying the first stock
        int sell1 = 0; // amount of money we have after selling the first stock (occurs after first stock has been bought)
        int buy2 = INT_MIN; // amount of money we have after buying the second stock (occurs after the first stock has been sold)
        int sell2 = 0; // amount of money we have after selling the second stock (occurs after second stock has been bought)
        for (auto price : prices) {
            sell2 = max(sell2, buy2 + price);
            buy2 = max(buy2, sell1-price);
            sell1 = max(sell1, buy1 + price);
            buy1 = max(buy1, -price);
        }
        return sell2;
    }
};
