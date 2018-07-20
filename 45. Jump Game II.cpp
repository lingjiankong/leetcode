class Solution {
public:
    int jump(vector<int>& nums) {
        int totalJump = 0;
        int curEnd = 0; // the ending index of current window, you can jump to every index in this window in the same number of step from previous window
        int curFarthest = 0; // the farthest index we can jump from current window, this will be used to update curEnd when we've reached the end of current window.

        for (int i = 0; i < nums.size()-1; ++i) {
            curFarthest = max(curFarthest, i + nums[i]);
            // if we've reached the end of current window, this will trigger another jump from current window. Why we have ;i<nums.size()-1;? Because if we had ;i<nums.size();, we were including the last index, then another jump is triggered at last index, and our totalJump will be 1 greater than what it should have been
            if (i == curEnd) {
                ++totalJump;
                curEnd = curFarthest;
            }
        }

        return totalJump;
    }
};
