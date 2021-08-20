// ***
//
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Example:
//
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
//
// ***

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            seen[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int numToFind = target - nums[i];
            if (seen.count(numToFind) && seen[numToFind] != i) {
                return {i, seen[numToFind]};
            }
        }

        return {0, 0};
    }
};

// Same idea.
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;  // number : index

    for (int i = 0; i < nums.size(); ++i) {
        int numToFind = target - nums[i];

        if (seen.count(numToFind)) {
            return {seen[numToFind], i};
        }

        seen[nums[i]] = i;
    }

    return {0, 0};
}
