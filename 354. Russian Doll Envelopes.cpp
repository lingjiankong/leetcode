// ***
//
// You have a number of envelopes with widths and heights given as a pair of integers (w, h).
// One envelope can fit into another if and only if both the width and height of one envelope is greater than the width
// and height of the other envelope.
//
// What is the maximum number of envelopes can you Russian doll? (put one inside other)
//
// Note:
// Rotation is not allowed.
//
// Example:
//
// Input: [[5,4],[6,4],[6,7],[2,3]]
// Output: 3
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
//
// ***
//
// This is the 2D version of 300. Longest Increasing Subsequence.
// Compare these two questions for intuition.
//
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // dp[i] stores the length of longest subsequence that ends at position i (i.e. number of envelopes).
        vector<int> dp(envelopes.size(), 1);
        int maxEnvelopes = 0;

        sort(envelopes.begin(), envelopes.end());

        for (int i = 0; i < envelopes.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            maxEnvelopes = max(maxEnvelopes, dp[i]);
        }

        return maxEnvelopes;
    }
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // dp[i] stores the length of longest subsequence that ends at position i (i.e. number of envelopes).
        vector<int> dp(envelopes.size(), 1);
        int maxEnvelopes = 0;

        // Sort the width in ascending order. If width is the same, then sort height in DESCENDING order.
        // Why sort width in ascending order but height in descending order? Because envelopes with the same width can't
        // fit into each other, so if you sort height in descending order when width is the same, then when you find
        // longest increasing subsequence (LIS) on all height values, you don't need to take care about the case when
        // width is the same.
        //
        // Let's suppose the values (width, height) are given as...
        // [2,3] [4,6] [3,7] [4,8]
        // 
        // After sorting we have
        // [2,3] [3,7] [4,8] [4,6]
        // 
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]);
        });

        // Now just do LIS on the all height values (you don't have to care about width anymore)
        for (int i = 0; i < envelopes.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            maxEnvelopes = max(maxEnvelopes, dp[i]);
        }

        return maxEnvelopes;
    }
};

// Binary search solution O(nlogn). This is almost the same as 300. Longest Increasing Subsequence.
// You would need to memorize it.
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> heightTails;

        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]);
        });

        for (int i = 0; i < envelopes.size(); ++i) {
            int height = envelopes[i][1];

            auto itr = lower_bound(heightTails.begin(), heightTails.end(), height);
            if (itr == heightTails.end()) {
                heightTails.push_back(height);
            } else {
                *itr = height;
            }
        }

        return heightTails.size();
    }
};
