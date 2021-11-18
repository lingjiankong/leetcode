// ***
//
// You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some
// error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number
// and loss of another number.
//
// You are given an integer array nums representing the data status of this set after the error.
//
// Find the number that occurs twice and the number that is missing and return them in the form of an array.
//
//
// Example 1:
//
// Input: nums = [1,2,2,4]
// Output: [2,3]
//
//
// Example 2:
//
// Input: nums = [1,1]
// Output: [1,2]
//
// ***

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> expected(nums.size(), INT_MAX);

        int missing = INT_MAX, duplicate = INT_MAX;
        for (int num : nums) {
            if (expected[num - 1] != INT_MAX) {
                duplicate = num;
            }
            expected[num - 1] = num;
        }

        for (int i = 0; i < expected.size(); ++i) {
            if (expected[i] == INT_MAX) {
                missing = i + 1;
            }
        }

        return {duplicate, missing};
    }
};
