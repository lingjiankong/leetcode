// ***
//
// Today, the bookstore owner has a store open for customers.length minutes. Every minute, some number of customers
// (customers[i]) enter the store, and all those customers leave after the end of that minute.
//
// On some minutes, the bookstore owner is grumpy. If the bookstore owner is grumpy on the i-th minute, grumpy[i] = 1,
// otherwise grumpy[i] = 0.  When the bookstore owner is grumpy, the customers of that minute are not satisfied,
// otherwise they are satisfied.
//
// The bookstore owner knows a secret technique to keep themselves not grumpy for X minutes straight, but can only use
// it once.
//
// Return the maximum number of customers that can be satisfied throughout the day.
//
//
//
// Example 1:
//
// Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
// Output: 16
// Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes.
// The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.
//
// ***

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int left = 0, right = 0;

        int already_satisfied = 0;

        // additional customers that you can satified if you were not grumpy in sliding window of size X
        int additional_satisfied = 0;

        int max_additional_satisfied = 0;

        while (right < customers.size()) {
            already_satisfied += grumpy[right] ? 0 : customers[right];
            additional_satisfied += grumpy[right] ? customers[right] : 0;
            ++right;

            while (right - left == X) {
                max_additional_satisfied = max(max_additional_satisfied, additional_satisfied);
                additional_satisfied -= grumpy[left] ? customers[left] : 0;
                ++left;
            }
        }

        return already_satisfied + max_additional_satisfied;
    }
};
