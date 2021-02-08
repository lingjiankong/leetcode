// ***
//
// Given an integer array nums, return the number of longest increasing subsequences.
// Notice that the sequence has to be strictly increasing.
//
// Example 1:
//
// Input: nums = [1,3,5,4,7]
// Output: 2
// Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
// Example 2:
//
// Input: nums = [2,2,2,2,2]
// Output: 5
// Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1,
// so output 5.
//
// ***
//
// The idea is to maintain two dp arrays:
// dpMaxLength[i] is the maximum length of increasing subsequence that ends with nums[i]
// dpMaxLengthCount[i] is the number of increasing subsequence of length dpMaxLength[i] that ends with nums[i]
// Didn't put too much comments since it can be confusing. Read the code and you should be able to understand.

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        // Everything below is initialized to 1 because a number itself is an increasing subsequence of length 1.
        vector<int> dpMaxLength(nums.size(), 1);
        vector<int> dpMaxLengthCount(nums.size(), 1);
        int maxLength = 1;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                // We only care when nums[i] is larger than nums[j] (i.e. forms an increasing sequence).
                if (nums[i] > nums[j]) {
                    if (dpMaxLength[i] == dpMaxLength[j] + 1) {
                        dpMaxLengthCount[i] += dpMaxLengthCount[j];
                    } else if (dpMaxLength[i] < dpMaxLength[j] + 1) {
                        dpMaxLength[i] = dpMaxLength[j] + 1;
                        dpMaxLengthCount[i] = dpMaxLengthCount[j];
                    }
                }
            }
            maxLength = max(maxLength, dpMaxLength[i]);
        }

        int totalLIS = 0;
        for (int i = 0; i < dpMaxLength.size(); ++i) {
            if (dpMaxLength[i] == maxLength) {
                totalLIS += dpMaxLengthCount[i];
            }
        }

        return totalLIS;
    }
};

