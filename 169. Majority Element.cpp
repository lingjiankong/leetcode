class Solution {

public:
    // find the sorted nth element
    int majorityElement(vector<int>& nums) {
        // nth_element(): rearranges the elements in the range [first,last), in such a way that the element at the nth position is the element that would be in that position in a sorted sequence. The other elements are left without any specific order, except that none of the elements preceding nth are greater than it, and none of the elements following it are less.
        nth_element(nums.begin(), nums.begin()+nums.size()/2, nums.end());
        return nums[nums.size()/2];
    }

    // Moore voting algorithm: the idea is to repeatedly get rid of pairs of different element, after which the element left must be the majority element
    // note that, in the problem statement, a majority element is guaranteed to exist. If the majority element is not guaranteed to exist, we need another iteration over the nums to check whether res is actually a majority element
    int majorityElement2(vector<int>& nums) {
        int count = 0;
        int res = 0;

        // you may swap the position of if and else if in this problem if you want, however you cannot do that in 229. Majority Element II, see that question for reasons
        for (auto num : nums) {
            if (num == res) {
                ++count;
            } else if (count == 0) {
                res = num; // reset res to num, all subsequent iterations compare num with current res. If they are different, we get rid of a pair of (res, num) and --count, else we get another res and ++count
                count = 1;
            } else { // nums != res, thus we get rid of one pair of different number (res, num)
                --count;
            }
        }

        return res;
    }
};
