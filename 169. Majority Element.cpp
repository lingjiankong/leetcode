
// Rearranges the elements in the range [first,last), in such a way that the element at the nth position is the element that would be in that position in a sorted sequence.

// The other elements are left without any specific order, except that none of the elements preceding nth are greater than it, and none of the elements following it are less.

class Solution {

public:
    // find the sorted nth element
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin()+nums.size()/2, nums.end());
        return nums[nums.size()/2];
    }

    // Moore voting algorithm
    // in the problem statement, a majority element is guaranteed to exist
    // if the majority element is not guaranteed to exist, we need another iteration over the nums to check whether res is actually a majority element
    int majorityElement2(vector<int>& nums) {
        int count = 0;
        int res = 0;
        for (const int& num : nums) {
            if (count == 0) {
                res = num;
                count = 1;
            } else if (num != res) {
                --count; // getting rid of one pair of different number
            } else {
                ++count;
            }
        }
        return res;
    }
};
