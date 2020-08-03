// ***
//
// Given a collection of distinct integers, return all possible permutations.
//
// Example:
//
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
//
// ***
//
// See also 47. Permutations II.

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> all;

        vector<bool> visited(nums.size(), false);

        _backtrack(nums, visited, current, all);

        return all;
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

            visited[i] = true;
            current.push_back(nums[i]);
            _backtrack(nums, visited, current, all);
            current.pop_back();
            visited[i] = false;
        }
    }
};
