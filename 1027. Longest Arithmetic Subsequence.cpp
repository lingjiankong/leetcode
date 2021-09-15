// ***
//
// Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.
//
// Recall that a subsequence of an array nums is a list nums[i1], nums[i2], ..., nums[ik] with 0 <= i1 < i2 < ... < ik
// <= nums.length - 1, and that a sequence seq is arithmetic if seq[i+1] - seq[i] are all the same value (for 0 <= i <
// seq.length - 1).
//
//
// Example 1:
//
// Input: nums = [3,6,9,12]
// Output: 4
// Explanation:
// The whole array is an arithmetic sequence with steps of length = 3.
//
//
// Example 2:
//
// Input: nums = [9,4,7,2,10]
// Output: 3
// Explanation:
// The longest arithmetic subsequence is [4,7,10].
//
//
// Example 3:
//
// Input: nums = [20,1,15,3,10,5,8]
// Output: 4
// Explanation:
// The longest arithmetic subsequence is [20,15,10,5].
//
//
// Constraints:
//
// 2 <= nums.length <= 1000
// 0 <= nums[i] <= 500
//
// ***

// Correct method but TLE on OJ.
// dp[i][diff]: Length of the longest subsequnce in nums[0:i] with difference diff.
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        unordered_map<int, unordered_map<int, int>> dp;

        int maxLen = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j];

                if (not dp.count(j) or not dp[j].count(diff)) {
                    dp[j][diff] = 1;
                }

                dp[i][diff] = dp[j][diff] + 1;
                maxLen = max(maxLen, dp[i][diff]);
            }
        }

        return maxLen;
    }
};

// Same idea using array, no TLE.
// We are given that 0 <= nums[i] <= 500, meaning the diff can only between -500 and 500.
// However, since array indexing starts at 0, we need to add 1000 to diff to be able to index the array.
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2000, 1));

        maxLen = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j] + 1000;
                dp[i][diff] = dp[j][diff] + 1;
                maxLen = max(maxLen, dp[i][diff]);
            }
        }

        return maxLen;
    }
};
