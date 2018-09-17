// the solution to this hard question is easy. You initialize candies with all ones because each child needs at least one candy. In the first for loop, you iterate from left to right and make sure if right child has higher rating than left child, he gets one more candy than left child. In the second for loop, you iterate from right to left, and make sure if left child has higher rating than right child, he gets more candy than right child. It is possible that left child already has many candies (for example in the case of [1, 2, 3, 4, 5, 1], the child with rating of 5 already has 5 candies when we scan from left to right), thus we want candies[i] = max(candies[i], candies[i+1] + 1). Here, we are guaranteed that the condition in the first iteration (if right child has higher rating than left child, he gets more candy than left child) is still satisfied, because candies[i] = max(candies[i], candies[i+1] + 1) so new candies[i] will be no smaller than previous candies[i], so candies[i] must still be greater than candies[i-1] if child i has higher rating than i-1.


[3, 4, 5, 6, 4, 2, 3, 4, 5,

[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();
        vector<int> candies (n, 1);

        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }

        for (int i = n-2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }

        int total = 0;
        for (int val : candies) {
            total += val;
        }

        return total;
    }
};