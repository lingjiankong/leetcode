// the code is easy, but the thinking process is hard. Once you get the intuition, it is ok.

// Ed's video is confusing. The following is edited based on Stephan's post in LeetCode discussion:

// Let miss be the smallest sum in [0, n] that we might be missing. Meaning we already know we can build all sums in [0, miss). Then if we have a number num <= miss in the given array, we can add it to those smaller sums to build all sums in [0, miss + num). If we don't, then we must add such a number to the array, and it's best to add miss itself, to maximize the reach. If you add something smaller than miss, you ends up building only [0, miss + num_smaller_than_miss], which is not as efficient as extending it to [0, miss + miss). You can't add a num larger than miss though, or you will end up with [0, miss) + [num_bigger_than_miss, miss + num_bigger_than_miss]. You'll miss the numbers in between.

// Example: Let's say the input is nums = [1, 2, 4, 13, 46] and n = 100. We need to ensure that all sums in the range [1,100] are possible.

// Using the given numbers 1, 2 and 4, we can already build all sums from 0 to 7, i.e., the range [0, 8). But we can't build the sum 8, and the next given number (13) is too large. So we insert 8 into the array. Then we can build all sums in [0, 8) + 8 -> [0, 16).

// Now, do we need to insert 16 into the array? No! Because the next num is 13, which is smaller than 16. We can add 13 to all sums [0, 16) we are able to build so far, extending our range to [0, 16) + 13 -> [0, 29).

// And so on. Now, the given 46 is too large to help with sum 29, so we must insert 29 into our array. This extends our range to [0, 29) + 29 -> [0, 58). Then 46 becomes useful and expands our range to [0, 58) + 46 -> [0, 104), which includes everything in [0, 100], now we're done.

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {

        int i = 0;
        int res = 0;
        long miss = 1;

        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                ++res;
            }
        }

        return res;
    }
};
