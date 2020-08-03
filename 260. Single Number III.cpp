// ***
//
// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear
// exactly twice. Find the two elements that appear only once.
//
// Example:
//
// Input:  [1,2,1,3,2,5]
// Output: [3,5]
// Note:
//
// The order of the result is not important. So in the above example, [5, 3] is also correct.
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
//
// ***

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Pass 1: Get the XOR of the two numbers we need to find
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());

        // Since the two numbers are distinct, there must be a set bit (that is, the bit with value "1") in the XOR
        // result. Find an arbitrary set bit (for example, the rightmost set bit).
        //
        // For example, binary of 3 is 00000011, binary of 5 is 00001001.
        // XOR them gives you diff = 00001010,
        // negate a signed number gives you -diff = 11110110,
        // diff &= -diff gives you 00000010, the second to last bit here is the right most set bit, indicating
        // the two numbers we want to find differ in this bit.
        diff &= -diff;

        // Pass 2: We divide all numbers into two groups, one with the aforementioned bit set, another with the
        // aforementinoed bit unset. Two different numbers we need to find must fall into thte two distrinct groups. XOR
        // numbers in each group (same logic as in 136. Single Number), we can find one number in each group.
        vector<int> results = {0, 0};  // this vector stores the two numbers we will return
        for (int num : nums) {
            if (num & diff) {
                results[0] ^= num;
            } else {
                results[1] ^= num;
            }
        }
        return results;
    }
};
