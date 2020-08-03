// ***
//
// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
// Example:
//
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]
//
// ***
//
// See also 46. Permutations, and compare their difference.
//
// In this question, we need to check if the number is a duplicate, AND
// if the number is a duplicate, whether the duplicated number has been visited before at current recursive level.
// If so then we shall skip this duplicate number.

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> all;

        vector<bool> visited(nums.size(), false);

        sort(nums.begin(), nums.end());

        backtrack(nums, visited, current, all);

        return all;
    }

private:
    void backtrack(vector<int>& nums, vector<bool>& visited, vector<int>& current, vector<vector<int>>& all) {
        if (current.size() == nums.size()) {
            all.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) {
                continue;
            }

            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1]) {
                continue;
            }

            visited[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, visited, current, all);
            current.pop_back();
            visited[i] = false;
        }
    }
};
