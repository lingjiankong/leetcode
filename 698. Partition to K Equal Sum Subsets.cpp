// ***
//
// Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty
// subsets whose sums are all equal.
//
//
// Example 1:
//
// Input: nums = [4,3,2,3,5,2,1], k = 4
// Output: true
// Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
//
//
// Example 2:
//
// Input: nums = [1,2,3,4], k = 3
// Output: false
//
//
// Constraints:
//
// 1 <= k <= nums.length <= 16
// 1 <= nums[i] <= 104
// The frequency of each element is in the range [1, 4].
//
// ***

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) {
            return false;
        }
        vector<bool> visited(nums.size());
        return _backtrack(nums, k, sum / k, 0, 0, visited);
    }

private:
    bool _backtrack(vector<int>& nums, int k, int target, int startIndex, int curSum, vector<bool>& visited) {
        // We have found k times such that curSum == target (that's why k can eventually become 0),
        // meaning nums can be devided into k non-empty subsets (target * k = sum)
        // Note we've already tested that sum % k == 0 and set sum / k == target.
        if (k == 0) {
            return true;
        }

        if (curSum == target) {
            return _backtrack(nums, k - 1, target, 0, 0, visited);
        }

        for (int i = startIndex; i < nums.size(); ++i) {
            if (visited[i]) {
                continue;
            }

            visited[i] = true;
            if (_backtrack(nums, k, target, i + 1, curSum + nums[i], visited)) {
                return true;
            }
            visited[i] = false;
        }

        return false;
    }
};
