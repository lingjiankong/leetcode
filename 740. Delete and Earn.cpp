// ***
//
// You are given an integer array nums. You want to maximize the number of points you get by performing the following
// operation any number of times:
//
// Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1
// and every element equal to nums[i] + 1. Return the maximum number of points you can earn by applying the above
// operation some number of times.
//
//
// Example 1:
//
// Input: nums = [3,4,2]
// Output: 6
// Explanation: You can perform the following operations:
// - Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
// - Delete 2 to earn 2 points. nums = [].
// You earn a total of 6 points.
//
//
// Example 2:
//
// Input: nums = [2,2,3,3,3,4]
// Output: 9
// Explanation: You can perform the following operations:
// - Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
// - Delete a 3 again to earn 3 points. nums = [3].
// - Delete a 3 once more to earn 3 points. nums = [].
// You earn a total of 9 points.
//
//
// Constraints:
//
// 1 <= nums.length <= 2 * 10^4
// 1 <= nums[i] <= 10^4
//
// ***

// 其实这道题跟之前那道House Robber的本质是一样的，那道题小偷不能偷相邻的房子，这道题相邻的数字不能累加积分，是不是一个道理？
// dp[i]: maximum points you can have when you are visiting number i.
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // Given 1 <= nums[i] <= 10^4
        int N = 10001;

        vector<int> values(N);
        for (int num : nums) {
            values[num] += num;
        }

        vector<int> dp(N);
        dp[0] = values[0];
        dp[1] = max(values[0], values[1]);

        for (int i = 2; i < dp.size(); ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + values[i]);
        }

        return dp.back();
    }
};
