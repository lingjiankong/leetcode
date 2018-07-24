// [0 1 2 3 4 5]
// [1 2 9 4 5 6] -> at position 2, we should get 3, but we didn't, therefore, first missing positive is 3

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        if (nums.size() == 0)
            return 1;

        for (int i = 0; i < nums.size(); ++i) {
            // we must have WHILE loop here instead of an IF statement, for example, if we have [3, 1, 4, -1], when i = 0, we swap nums[0] with nums[3-1] and get [4, 1, 3, -1]. Now, nums[0] = 4, we must now swap nums[0] with nums[4-1] and get [-1, 1, 3, 4].
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i]-1] != nums[i])
                swap(nums[i], nums[nums[i]-1]); // put nums[i] at the place it belongs to (nums[nums[i]-1])
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) // e.g. [1,99,3,4], 99 is not 2, then 2 is the first missing positive
                return i + 1;
        }

        return nums.size() + 1;
    }
};
