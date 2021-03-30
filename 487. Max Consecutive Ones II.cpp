// ***
//
// Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.
//
// Example 1:
// Input: [1,0,1,1,0]
// Output: 4
// Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
//     After flipping, the maximum number of consecutive 1s is 4.
// Note:
//
// The input array will only contain 0 and 1.
// The length of input array is a positive integer and will not exceed 10,000
// Follow up:
// What if the input numbers come in one by one as an infinite stream? In other words, you can't store all numbers
// coming from the stream as it's too large to hold in memory. Could you solve it efficiently?
//
// ***
//
// Exactly same as 1004. Max Consecutive Ones III

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> window(2, 0);

        int left = 0, right = 0;
        int maxLen = 0;

        while (right < nums.size()) {
            int num = nums[right++];
            ++window[num];

            while (window[0] > 1) {
                int num = nums[left++];
                --window[num];
            }

            maxLen = max(maxLen, right - left);
        }

        return maxLen;
    }
};

