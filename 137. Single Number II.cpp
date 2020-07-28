// ***
//
// Given a non-empty array of integers, every element appears three times except for one, which appears exactly once.
// Find that single one.
//
// Note:
//
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//
// Example 1:
//
// Input: [2,2,3,2]
// Output: 3
// Example 2:
//
// Input: [0,1,0,1,0,1,99]
// Output: 99
//
// ***

// This question is tricky.
// Construct a 32 bit word. For every bit position i in word, traverse all nums j, and sum up
// the number of times 1 appears in all nums[j]'s bit position i. Think of it this way: If only numbers which appear
// three time has that bit toggled, then sum % 3 = 0, so any remainder of sum % 3 is the number which appears only once.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int word = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j) {
                sum += (nums[j] >> i) & 1;
            }
            word |= (sum % 3) << i;
        }
        return word;
    }
};
