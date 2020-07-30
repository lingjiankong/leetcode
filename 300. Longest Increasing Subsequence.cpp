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

// DP solution. O(n2).
int lengthOfLIS(vector<int>& nums) {
    // dp[i] stores the length of longest subsequence that ends at position i (nums[i] must be used).
    // Remember to initialize all elements in dp to 1 because a single number itself is a subsequence of length 1.
    vector<int> dp(nums.size(), 1);

    int longestLength = 0;

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                // In this case, the longest subsequence that ends at position i, must be the larger one of
                // the longest subsequence that ends at position j, then + 1 (since nums[j] < nums[i]),
                // or the current longest subsequence that ends at position i.
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        longestLength = max(longestLength, dp[i]);
    }

    return longestLength;
}

// Binary search. Not straightfoward to understand.
//
// Traverse through nums:
// 1. If nums[i] > the right most element in elements, then add nums[i] to the end of elements (now elements.size() has
// increased by 1).
//
// 2. If nums[i] < the left most element in elements, replace the leftmost element to nums[i] (note elements.size() does
// not change in this case).
//
// 3. Otherwise, find lower_bound(nums[i]) in elements, and replace that element with nums[i] (note elements.size() does
// not change in this case).
//
// Finally, elements.size() is the length of longest increasing subsequence.
// Note that element in elements might not be a real LIS (we only need the size of elements).
//
// elements doesn't contain the actual LIS, only it's length is valid.
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
    vector<int> elements;

    for (int i = 0; i < nums.size(); ++i) {
        auto itr = lower_bound(elements.begin(), elements.end(), nums[i]);
        if (itr == elements.end()) {
            elements.push_back(nums[i]);
        } else {
            *itr = nums[i];
        }
    }

    return elements.size();
}
