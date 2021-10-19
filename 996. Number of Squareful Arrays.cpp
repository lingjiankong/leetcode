// ***
//
// An array is squareful if the sum of every pair of adjacent elements is a perfect square.
//
// Given an integer array nums, return the number of permutations of nums that are squareful.
//
// Two permutations perm1 and perm2 are different if there is some index i such that perm1[i] != perm2[i].
//
//
// Example 1:
//
// Input: nums = [1,17,8]
// Output: 2
// Explanation: [1,8,17] and [17,8,1] are the valid permutations.
//
//
// Example 2:
//
// Input: nums = [2,2,2]
// Output: 1
//
//
// Constraints:
//
// 1 <= nums.length <= 12
// 0 <= nums[i] <= 10^9
//
// ***

// Almost exactly same as 47. Permutations.
// We just need to have an additional check if current pair is a perfect sqaure.
class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> all;

        vector<bool> visited(nums.size(), false);

        sort(nums.begin(), nums.end());

        _backtrack(nums, visited, current, all);

        return all.size();
    }

private:
    void _backtrack(vector<int>& nums, vector<bool>& visited, vector<int>& current, vector<vector<int>>& all) {
        if (current.size() == nums.size()) {
            all.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) {
                continue;
            }

            if (i > 0 and nums[i] == nums[i - 1] and visited[i - 1]) {
                continue;
            }

            // Check if current pair is a perfect square.
            if (not current.empty()) {
                double root = sqrt(current.back() + nums[i]);
                if (root - floor(root) != 0) {
                    continue;
                }
            }

            visited[i] = true;
            current.push_back(nums[i]);
            _backtrack(nums, visited, current, all);
            current.pop_back();
            visited[i] = false;
        }
    }
};
