// ***
//
// Given a binary array, find the maximum number of consecutive 1s in this array.
//
// Example 1:
// Input: [1,1,0,1,1,1]
// Output: 3
//
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s
// is 3.
//
// ***

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0;
        int curLen = 0;
        for (int num : nums) {
            curLen = num == 0 ? 0 : curLen + 1;  // reset curLen if num == 0, otherwise curLen += 1
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};
