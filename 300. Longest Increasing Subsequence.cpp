// ***
//
// Given an unsorted array of integers, find the length of longest increasing subsequence.
//
// Example:
//
// Input: [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
//
// ***
//
// This question asks about the longest sequence, NOT the longeset *consesutive* sequence.
// See also 128. Longest Consecutive Sequence. In that question, order of element does not matter.
//
// This is the 1D version of 354. Russian Doll Envelopes.
// Compare these two questions for intuition.

// DP solution. O(n2).
int lengthOfLIS(vector<int>& nums) {
    // dp[i]: the length of longest subsequence that ends at position i (nums[i] must be used).
    // All elements in dp are initialized to 1 because a single number itself is a subsequence of length 1.
    vector<int> dp(nums.size(), 1);

    int maxLen = 0;

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
}

// Binary search O(nlogn).
// This algorithm is not intuitive. No need to understand it.
// See labuladong book pp. 101 for drawing.
//
// Traverse through nums:
// 1. If nums[i] > the right most element in piles, then add nums[i] to the end of piles (now piles.size() has
// increased by 1).
//
// 2. If nums[i] < the left most element in piles, replace the leftmost element with nums[i] (note piles.size()
// does not change in this case).
//
// 3. Otherwise, find lower_bound(nums[i]) in piles, and replace that element with nums[i] (note piles.size() does
// not change in this case).
//
// Finally, piles.size() is the length of longest increasing subsequence.
// Note that element in piles might not be a real LIS (we only need the size of piles).
//
// piles doesn't contain the actual LIS, only it's length is valid.
// For each num we are traversing in nums we have 2 options:
// if it's the highest found value, we push it back, since a high value obviously makes our increasing sequence longer
// if it's not the highest found value, then it could be a nice start (or continuation) of a shorter sequence.
//
// [1,2,7,8,3,4,5,9,0]
// 1 -> [1]
// 2 -> [1,2]
// 7 -> [1,2,7]
// 8 -> [1,2,7,8]
// 3 -> [1,2,3,8] // we replaced 7 with 3, since for the longest sequence we need only the last number and 1,2,3 is our
// new shorter sequence
//
// 4 -> [1,2,3,4] // we replaced 8 with 4, since the max length is the same but 4 has more chances for longer sequence
// 5 -> [1,2,3,4,5]
// 9 -> [1,2,3,4,5,9]
// 0 -> [0,2,3,4,5,9] // we replaced 1 with 0, so that it can become a new sequence
int lengthOfLIS(vector<int>& nums) {
    vector<int> piles;

    for (int i = 0; i < nums.size(); ++i) {
        auto itr = lower_bound(piles.begin(), piles.end(), nums[i]);
        if (itr == piles.end()) {
            piles.push_back(nums[i]);
        } else {
            *itr = nums[i];
        }
    }

    return piles.size();
}
