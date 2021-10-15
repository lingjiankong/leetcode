// ***
//
// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
// Note: The solution set must not contain duplicate subsets.
//
// Example:
//
// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]
//
// ***
//
// To check for duplicate, you need to sort nums. Otherwise, only one line difference compare to 78. Subsets.
// See also 40. Combination Sum II. Very similar in the way they get rid of duplicate result.
//
// To check for duplicate elements, we add a condition if (i > startIndex && nums[i] == nums[i-1])
// inside the for loop. Note it is if (i > startIndex), NOT if (i > 0).
// We must process first element in the for loop regardess of it is a duplicate with previous
// because the previous one is not in current recursive loop so we do not care.

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> all;

        sort(nums.begin(), nums.end());

        int startIndex = 0;
        _backtrack(nums, startIndex, current, all);

        return all;
    }

private:
    void _backtrack(vector<int>& nums, int startIndex, vector<int>& current, vector<vector<int>>& all) {
        all.push_back(current);

        for (int i = startIndex; i < nums.size(); ++i) {
            if (i > startIndex && nums[i] == nums[i - 1]) {
                continue;
            }

            current.push_back(nums[i]);
            _backtrack(nums, i + 1, current, all);
            current.pop_back();
        }
    }
};
